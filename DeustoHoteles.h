/*
 * DeustoHoteles.h
 *
 *  Created on: 27 Mar 2020
 *      Author: Edu
 */

#ifndef DEUSTOHOTELES_H_
#define DEUSTOHOTELES_H_
#include <stdio.h>
#include "sqlite3.h"

typedef struct{
	int idUsuario;
	char nombre[15];
	char apellido[15];
	char dni[9];
	char correo[30];
	char password[9];
} usuario;

typedef struct{
	int idReserva;
	char ciudad[15];//podria ser un int referido a la id de cada ciudad
	//fecha llegada
	//fecha salida
	int tipoHabitacion;
	int tipoActividad;
	double precio;
} reserva;


void menuInicio();
void iniciarSesion();
void seleccionHotel();
void seleccionCiudad();
void seleccionHabitacion();
void registrarLogIn(char username[]);
int registrarUsuarios(sqlite3 *dhdb);
void vaciar();
void copiar();

#endif /* DEUSTOHOTELES_H_ */
