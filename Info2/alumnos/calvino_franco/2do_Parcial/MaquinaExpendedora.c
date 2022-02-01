#include "MaquinaExpendedora.h"
#include "funcionesMaquina.h"

extern uint8_t ID, credito, tecladoActivo, tecla;
uint8_t temp10S;

static uint8_t MDE_MaquinaExpendedora_REPOSO (uint8_t);
static uint8_t MDE_MaquinaExpendedora_VALIDODATOSTARJETA (uint8_t);
static uint8_t MDE_MaquinaExpendedora_SELECCIONOBEBIDA (uint8_t);
static uint8_t MDE_MaquinaExpendedora_RECARGA (uint8_t);
static uint8_t MDE_MaquinaExpendedora_BEBIDAOK (uint8_t);
static uint8_t MDE_MaquinaExpendedora_ERROR (uint8_t);

static uint8_t (*MDE_MaquinaExpendedora[]) (uint8_t) = {
    MDE_MaquinaExpendedora_REPOSO,
    MDE_MaquinaExpendedora_VALIDODATOSTARJETA,
    MDE_MaquinaExpendedora_SELECCIONOBEBIDA,
    MDE_MaquinaExpendedora_RECARGA,
    MDE_MaquinaExpendedora_BEBIDAOK,
    MDE_MaquinaExpendedora_ERROR
};

uint8_t MDE_MaquinaExpendedora_REPOSO (uint8_t status)
{
    if (s_Tarjeta)
    {
        f_validoTramaDatos();
        status = VALIDODATOSTARJETA;
    }

    return status;
}

uint8_t MDE_MaquinaExpendedora_VALIDODATOSTARJETA (uint8_t status)
{
    if (ID > 0 && ID < 50 && credito > 0)
    {
        tecladoActivo = 1;
        t_procesoOK();
        t_LV_ON();
        f_actualizoDisplay();
        status = SELECCIONOBEBIDA;
    }
    else if (ID > 0 && ID < 50 && CREDITO <= 0)
    {
        f_verificoSaldo();
        f_actualizoDisplay();
        status = RECARGA;
    }
    else if (ID < 0 || ID > 50)
    {
        m_LR_ON();
        f_displayEntero();
        status = ERROR;
    }

    return status;
}

uint8_t MDE_MaquinaExpendedora_SELECCIONOBEBIDA (uint8_t status)
{
    if (tecla < 6)
    {
        tecladoActivo = 0;
        credito -= 1;
        t_liberoBotella_010_S();
        f_despachoNuevoDato();
        f_actualizoDisplay();
        status = BEBIDAOK;
    }

    return status;
}

uint8_t MDE_MaquinaExpendedora_RECARGA (uint8_t status)
{
    if (credito > 0)
    {
        tecladoActivo = 1;
        t_procesoOK_005_D();
        m_LV_ON();
        f_actualizoDisplay();
        status = SELECCIONOBEBIDA;
    }
    else if (credito <= 0)
    {
        m_LR_ON();
        f_displayEntero();
        f_ErrorCredito_003_S();
        status = ERROR;
    }

    return status;
}

uint8_t MDE_MaquinaExpendedora_BEBIDAOK (uint8_t status)
{
    if (temp10S == 1)
    {
        m_LV_ON();
        t_procesoOK_005_stop();
        f_apagoDisplay();
        m_Exp_Tjta_ON();
        t_ExpTjta_001_S();
        status = REPOSO;
    }

    return status;
}
uint8_t MDE_MaquinaExpendedora_ERROR (uint8_t status)
{
    if (tecla == 6)
    {
        t_ErrorCredito_003_stop();
        m_LV_ON();
        m_LR_OFF();
        tecladoActivo = 0;
        f_apagoDisplay();
        m_Exp_Tjta_ON();
        t_ExpTjta_001_S();
        status = REPOSO;
    }

    return status;
}

void MaquinaEXpendedora(void)
{
    static uint8_t estado = REPOSO;

    estado = (*MDE_MaquinaExpendedora[estado])(estado);
}
