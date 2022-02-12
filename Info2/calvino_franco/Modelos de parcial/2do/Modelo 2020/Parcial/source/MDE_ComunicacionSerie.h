/*
 * MDE_Serie.h
 *
 *  Created on: 20 nov. 2021
 *      Author: franco
 */

#ifndef MDE_SERIE_H_
#define MDE_SERIE_H_

enum estadoSerie {REPOSO = 0, ESPERO_LETRA = 1, RESET = 2, FINALIZACION = 3};

void MDE_ComunicacionSerie(void);

#endif /* MDE_SERIE_H_ */
