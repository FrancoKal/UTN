################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/MDE_ComunicacionSerie.c \
../source/Parcial.c \
../source/PuertoSerie.c \
../source/adc.c \
../source/display7seg.c \
../source/dr_gpio.c \
../source/ejercicio2.c \
../source/ejercicio3.c \
../source/inicializacion.c \
../source/mtb.c \
../source/semihost_hardfault.c \
../source/teclado.c \
../source/timer.c 

OBJS += \
./source/MDE_ComunicacionSerie.o \
./source/Parcial.o \
./source/PuertoSerie.o \
./source/adc.o \
./source/display7seg.o \
./source/dr_gpio.o \
./source/ejercicio2.o \
./source/ejercicio3.o \
./source/inicializacion.o \
./source/mtb.o \
./source/semihost_hardfault.o \
./source/teclado.o \
./source/timer.o 

C_DEPS += \
./source/MDE_ComunicacionSerie.d \
./source/Parcial.d \
./source/PuertoSerie.d \
./source/adc.d \
./source/display7seg.d \
./source/dr_gpio.d \
./source/ejercicio2.d \
./source/ejercicio3.d \
./source/inicializacion.d \
./source/mtb.d \
./source/semihost_hardfault.d \
./source/teclado.d \
./source/timer.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_LPC845M301JBD48 -DCPU_LPC845M301JBD48_cm0plus -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/home/franco/UTN/Informatica_II/Practicando/Modelos de parcial/2do/Modelo 2020/Parcial/board" -I"/home/franco/UTN/Informatica_II/Practicando/Modelos de parcial/2do/Modelo 2020/Parcial/source" -I"/home/franco/UTN/Informatica_II/Practicando/Modelos de parcial/2do/Modelo 2020/Parcial/drivers" -I"/home/franco/UTN/Informatica_II/Practicando/Modelos de parcial/2do/Modelo 2020/Parcial/component/uart" -I"/home/franco/UTN/Informatica_II/Practicando/Modelos de parcial/2do/Modelo 2020/Parcial/utilities" -I"/home/franco/UTN/Informatica_II/Practicando/Modelos de parcial/2do/Modelo 2020/Parcial/CMSIS" -I"/home/franco/UTN/Informatica_II/Practicando/Modelos de parcial/2do/Modelo 2020/Parcial/device" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


