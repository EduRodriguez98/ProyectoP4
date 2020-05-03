/*
 * main.cpp
 *
 *  Created on: 27 Apr 2020
 *      Author: Edu, Diego & Adolfo
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include<stdlib.h>
#include<time.h>
#include"DeustoHoteles.h"
#define LONGITUD 30


extern "C" {
#include "sqlite3.h"
}

using namespace std;



int main() {

	menuInicio();

	sqlite3 *dhdb;

	int result = sqlite3_open("DeustoHotelesBD.s3db", &dhdb);
	if (result != SQLITE_OK) {
		printf("Error al abrir la base de datos\n");
		return result;
	}
	printf("Base de datos abierta correctamente\n");

	result = registrarUsuarios(dhdb);

	if (result != SQLITE_OK) {
		printf("Error al insertar datos\n");
		printf("%s\n", sqlite3_errmsg(dhdb));
		return result;
	}

	printf("Base de datos cerrada correctamente\n");

	result = sqlite3_close(dhdb);

	getch();
	return 0;
}

void menuInicio() {

	char s[1];

	system("cls");
	cout << "Bienvenido a DeustoHoteles\n\n" << endl;

	cout << "1. Iniciar Sesion\n" << endl;
	cout << "2. Registrar nuevo usuario\n" << endl;
	cout << "3. Entrar sin registrar\n" << endl;
	cout << "4. Salir\n" << endl;

	cin >> s;
	fflush(stdin);

	while (s[0] < '1' || s[0] > '4') {

		system("cls");
		cout << "Bienvenido a DeustoHoteles\n\n" << endl;

		cout << "1. Iniciar Sesion\n" << endl;
		cout << "2. Registrar nuevo usuario\n" << endl;
		cout << "3. Entrar sin registrar\n" << endl;
		cout << "4. Salir\n" << endl;

		cin >> s;
		fflush(stdin);
	}

	switch (atoi(s)) {
	case 1:
		iniciarSesion();
		break;
	case 2:
		//registrarUsuario();		Falta implementaci�n
		break;
	case 3:
		seleccionHotel();
		break;
	case 4:
		cout << "Vuelva cuando quiera" << endl;
		exit(0);
		break;

	}

}

void iniciarSesion() { //Para iniciar sesi�n consideramos que hacerlo desde C ser�a m�s complicado que en c++ asi pues hemos dejado esta funcionalidad para m�s adelante

	char s1[15], s2[15];
	char nombreUsuario[15];
	char password[9];

	int intentos = 0;
	usuario nuevo;

	strcpy(nuevo.nombre, nombreUsuario);
	strcpy(nuevo.password, password);

	do {
		system("cls");
		cout << "Inicio de Sesion\n\n" << endl;

		cout << "1. Introduzca el nombre de usuario: \n" << endl;
		cin >> s1;
		fflush(stdin);
		cout << "2. Introduzca la password: \n" << endl;
		int i = 0;
		char caracter;

		//tiene que ir despues de hacer log in succesfully
		registrarLogIn(s1);

		while ((caracter = getch())) {
			if (caracter == 13) {//caracter == 13 es la tecla enter, que rompe el bucle
				s2[i] = '\0';
				break;

			} else if (caracter == 8) {
				if (i > 0) {
					i--;
					printf("\b \b");
				}
			} else {
				if (i < LONGITUD) {
					printf("*");
					s2[i] = caracter;
					i++;
				}
			}
		}
		fflush(stdin);
		seleccionHotel();
		//printf("3. Atras\n");

		//Comparar con la base de datos la entrada del usuario NOMUSUARIO y PASSWORD
		/*if(strcmp(s1,nombreUsuario) == 0 && strcmp(s2,password) == 0){
		 registrarLogIn(s1);
		 seleccionHotel();

		 }else{
		 printf("El usuario o la password no son correctos, vuelva a intentarlo ");
		 scanf("%s",s1);
		 fflush(stdin);
		 scanf("%s",s2);
		 fflush(stdin);
		 intentos ++;
		 getchar();//si esto no funciona usar system("pause");
		 } */

	} while (intentos < 3);

	cout << "No ha sido posible la identificacion intentelo mas tarde\n"
			<< endl;

	if (strcmp(s1, "3") == 0) {
		menuInicio();
	}

}

void seleccionHotel() {

	char s3[1];

	while (s3[0] < '1' || s3[0] > '4') {

		system("cls");
		cout << "Bienvenid@\n\n" << endl;

		cout << "1. Seleccione la ciudad del hotel que desea reservar\n"
				<< endl;
		cout << "2. Modificar reserva\n" << endl;
		cout << "3. Ofertas\n" << endl;
		cout << "4. Atras\n" << endl;

		cin >> s3;
		fflush(stdin);
	}

	switch (atoi(s3)) {

	case 1:
		seleccionCiudad();
		break;
	case 2:
		//Modificar reserva
		break;
	case 3:
		//buscarOferta();
		break;
	case 4:
		iniciarSesion();
		break;
	}

}

void seleccionCiudad() {

	char s4[1], s5[1], s6[1], s7[1], s8[1], s9[1], s10[1], s11[1], s12[1],
			s13[1], s14[1], s15[1], s16[1];

	while (s4[0] < '1' || s4[0] > '7') {

		system("cls");
		cout << "Seleccione una ciudad: \n\n" << endl;

		cout << "1. Madrid\n" << endl;
		cout << "2. Barcelona\n" << endl;
		cout << "3. Bilbao\n" << endl;
		cout << "4. Valencia\n" << endl;
		cout << "5. Gijon\n" << endl;
		cout << "6. Leon\n" << endl;
		cout << "7. Atras\n" << endl;

		cin >> s4;
		fflush(stdin);
	}

	switch (atoi(s4)) {

	case 1:

		while (s5[0] < '1' || s5[0] > '3') {

			system("cls");
			cout << "Madrid: \n\n" << endl;

			cout << "1. Seleccione una fecha\n" << endl;
			cout << "2. Seleccione tipo de actividad\n" << endl;
			cout << "3. Atras\n" << endl;

			cin >> s5;
			fflush(stdin);
		}

		switch (atoi(s5)) {

		case 1:
			//Seleccionar fecha?? //igual mejor introduzca una fecha, las fechas se leen como strings %s
			// time_t tiempoAhora;
			// time(&tiempoAhora);
			// struct tm *miTiempo = localtime(&tiempoAhora);
			// printf("%d/%d/%d ", miTiempo -> tm_mday, miTiempo -> tm_mon + 1, miTiempo -> tm_year + 1900);
			//
			break;
		case 2:

			while (s6[0] < '1' || s6[0] > '3') {

				system("cls");
				cout << "Seleccione una actividad: \n\n" << endl;

				cout << "1. Visita cultural\n" << endl;
				cout << "2. Ruta de SPAs\n" << endl;
				cout << "3. Atras\n" << endl;

				cin >> s6;
				fflush(stdin);
			}

			switch (atoi(s6)) {

			case 1:
				cout
						<< "Su reserva en el hotel de Madrid y actividad visita cultural se ha realizado con exito!\n"
						<< endl;
				break;
			case 2:
				cout
						<< "Su reserva en el hotel de Madrid y actividad ruta de SPAs se ha realizado con exito!\n"
						<< endl;
				break;
			case 3:
				seleccionCiudad();
				break;
			}
			system("pause");
			seleccionHabitacion();
			break;
		case 3:
			seleccionCiudad();
			break;
		}
		break;

	case 2:

		while (s7[0] < '1' || s7[0] > '3') {

			system("cls");
			cout << "Barcelona: \n\n" << endl;

			cout << "1. Seleccione una fecha\n" << endl;
			cout << "2. Seleccione tipo de actividad\n" << endl;
			cout << "3. Atras\n" << endl;

			cin >> s7;
			fflush(stdin);
		}

		switch (atoi(s7)) {

		case 1:
			//Seleccionar fecha??
			break;
		case 2:

			while (s8[0] < '1' || s8[0] > '5') {

				system("cls");
				cout << "Seleccione una actividad: \n\n" << endl;

				cout << "1. Visita cultural\n" << endl;
				cout << "2. Ruta de SPAs\n" << endl;
				cout << "3. Actividad maritima\n" << endl;
				cout << "4. Ruta ligera, por monte\n" << endl;
				cout << "5. Atras\n" << endl;

				cin >> s8;
				fflush(stdin);
			}

			switch (atoi(s8)) {

			case 1:
				cout
						<< "Su reserva en el hotel de Barcelona y actividad visita cultural se ha realizado con exito!\n"
						<< endl;
				break;
			case 2:
				cout
						<< "Su reserva en el hotel de Barcelona y actividad ruta de SPAs se ha realizado con exito!\n"
						<< endl;
				break;
			case 3:
				cout
						<< "Su reserva en el hotel de Barcelona y actividad maritima se ha realizado con exito!\n"
						<< endl;
				break;
			case 4:
				cout
						<< "Su reserva en el hotel de Barcelona y actividad ruta ligera, por monte se ha realizado con exito!\n"
						<< endl;
				break;
			case 5:
				seleccionCiudad();
				break;
			}
			system("pause");
			seleccionHabitacion();
			break;
		case 3:
			seleccionCiudad();
			break;
		}
		break;

	case 3:

		while (s9[0] < '1' || s9[0] > '3') {

			system("cls");
			cout << "Bilbao: \n\n" << endl;

			cout << "1. Seleccione una fecha\n" << endl;
			cout << "2. Seleccione tipo de actividad\n" << endl;
			cout << "3. Atras\n" << endl;

			cin >> s9;
			fflush(stdin);
		}

		switch (atoi(s9)) {

		case 1:
			//Seleccionar fecha??
			break;
		case 2:

			while (s10[0] < '1' || s10[0] > '6') {

				system("cls");
				cout << "Seleccione una actividad: \n\n" << endl;

				cout << "1. Visita cultural\n" << endl;
				cout << "2. Ruta de SPAs\n" << endl;
				cout << "3. Actividad maritima\n" << endl;
				cout << "4. Ruta ligera, por monte\n" << endl;
				cout << "5. Ruta dura, por monta�a\n" << endl;
				cout << "6. Atras\n" << endl;

				cin >> s10;
				fflush(stdin);
			}

			switch (atoi(s10)) {

			case 1:
				cout
						<< "Su reserva en el hotel de Bilbao y actividad visita cultural se ha realizado con exito!\n"
						<< endl;
				break;
			case 2:
				cout
						<< "Su reserva en el hotel de Bilbao y actividad ruta de SPAs se ha realizado con exito!\n"
						<< endl;
				break;
			case 3:
				cout
						<< "Su reserva en el hotel de Bilbao y actividad maritima se ha realizado con exito!\n"
						<< endl;
				break;
			case 4:
				cout
						<< "Su reserva en el hotel de Bilbao y actividad ruta ligera, por monte se ha realizado con exito!\n"
						<< endl;
				break;
			case 5:
				cout
						<< "Su reserva en el hotel de Bilbao y actividad ruta dura, por monta�a se ha realizado con exito!\n"
						<< endl;
				break;
			case 6:
				seleccionCiudad();
				break;
			}
			system("pause");
			seleccionHabitacion();
			break;

		case 3:
			seleccionCiudad();
			break;
		}
		break;
	case 4:

		while (s11[0] < '1' || s11[0] > '3') {

			system("cls");
			cout << "Valencia: \n\n" << endl;

			cout << "1. Seleccione una fecha\n" << endl;
			cout << "2. Seleccione tipo de actividad\n" << endl;
			cout << "3. Atras\n" << endl;

			cin >> s11;
			fflush(stdin);
		}

		switch (atoi(s11)) {

		case 1:
			//Seleccionar fecha??
			break;
		case 2:

			while (s12[0] < '1' || s12[0] > '5') {

				system("cls");
				cout << "Seleccione una actividad: \n\n" << endl;

				cout << "1. Visita cultural\n" << endl;
				cout << "2. Ruta de SPAs\n" << endl;
				cout << "3. Actividad maritima\n" << endl;
				cout << "4. Ruta ligera, por monte\n" << endl;
				cout << "5. Atras\n" << endl;

				cin >> s12;
				fflush(stdin);
			}

			switch (atoi(s12)) {

			case 1:
				cout
						<< "Su reserva en el hotel de Valencia y actividad visita cultural se ha realizado con exito!\n"
						<< endl;
				break;
			case 2:
				cout
						<< "Su reserva en el hotel de Valencia y actividad ruta de SPAs se ha realizado con exito!\n"
						<< endl;
				break;
			case 3:
				cout
						<< "Su reserva en el hotel de Valencia y actividad maritima se ha realizado con exito!\n"
						<< endl;
				break;
			case 4:
				cout
						<< "Su reserva en el hotel de Valencia y actividad ruta ligera, por monte se ha realizado con exito!\n"
						<< endl;
				break;
			case 5:
				seleccionCiudad();
				break;
			}
			system("pause");
			seleccionHabitacion();
			break;
		case 3:
			seleccionCiudad();
			break;
		}
		break;
	case 5:

		while (s13[0] < '1' || s13[0] > '3') {

			system("cls");
			cout << "Gijon: \n\n" << endl;

			cout << "1. Seleccione una fecha\n" << endl;
			cout << "2. Seleccione tipo de actividad\n" << endl;
			cout << "3. Atras\n" << endl;

			cin >> s13;
			fflush(stdin);
		}

		switch (atoi(s13)) {

		case 1:
			//Seleccionar fecha??
			break;
		case 2:

			while (s14[0] < '1' || s14[0] > '4') {

				system("cls");
				cout << "Seleccione una actividad: \n\n" << endl;

				cout << "1. Ruta de SPAs\n" << endl;
				cout << "2. Actividad maritima\n" << endl;
				cout << "3. Ruta ligera, por monte\n" << endl;
				cout << "4. Atras\n" << endl;

				cin >> s14;
				fflush(stdin);
			}

			switch (atoi(s14)) {

			case 1:
				cout
						<< "Su reserva en el hotel de Gijon y actividad ruta de SPAs se ha realizado con exito!\n"
						<< endl;
				break;
			case 2:
				cout
						<< "Su reserva en el hotel de Gijon y actividad maritima se ha realizado con exito!\n"
						<< endl;
				break;
			case 3:
				cout
						<< "Su reserva en el hotel de Gijon y actividad ruta ligera, por monte se ha realizado con exito!\n"
						<< endl;
				break;
			case 4:
				seleccionCiudad();
				break;
			}
			system("pause");
			seleccionHabitacion();
			break;
		case 3:
			seleccionCiudad();
			break;
		}
		break;
	case 6:

		while (s15[0] < '1' || s15[0] > '3') {

			system("cls");
			cout << "Leon: \n\n" << endl;

			cout << "1. Seleccione una fecha\n" << endl;
			cout << "2. Seleccione tipo de actividad\n" << endl;
			cout << "3. Atras\n" << endl;

			cin >> s15;
			fflush(stdin);
		}

		switch (atoi(s15)) {

		case 1:
			//Seleccionar fecha??
			break;
		case 2:

			while (s16[0] < '1' || s16[0] > '5') {

				system("cls");
				cout << "Seleccione una actividad: \n\n" << endl;

				cout << "1. Visita cultural\n" << endl;
				cout << "2. Ruta de SPAs\n" << endl;
				cout << "3. Ruta dura, por monta�a\n" << endl;
				cout << "4. Atras\n" << endl;

				cin >> s16;
				fflush(stdin);
			}

			switch (atoi(s16)) {

			case 1:
				cout
						<< "Su reserva en el hotel de Leon y actividad visita cultural se ha realizado con exito!\n"
						<< endl;
				break;
			case 2:
				cout
						<< "Su reserva en el hotel de Leon y actividad ruta de SPAs se ha realizado con exito!\n"
						<< endl;
				break;
			case 4:
				cout
						<< "Su reserva en el hotel de Leon y actividad ruta ligera, por monte se ha realizado con exito!\n"
						<< endl;
				break;
			case 5:
				seleccionCiudad();
				break;
			}
			system("pause");
			seleccionHabitacion();
			break;
		case 3:
			seleccionCiudad();
			break;
		}
		break;
	case 7:
		seleccionHotel();
		break;
	}

}

void seleccionHabitacion() {

	char s17[1];

	while (s17[0] < '1' || s17[0] > '4') {

		system("cls");
		cout << "Seleccione el tipo de habitacion que desea: \n\n" << endl;

		cout << "1. Individual\n" << endl;
		cout << "2. Doble\n" << endl;
		cout << "3. Suite\n" << endl;
		cout << "4. Atras\n" << endl;

		cin >> s17;
		fflush(stdin);
	}

	switch (atoi(s17)) {

	case 1:
		cout << "Habitacion individual seleccionada, reserva completada"
				<< endl;
		break;
	case 2:
		cout << "Habitacion doble seleccionada, reserva completada" << endl;
		break;
	case 3:
		cout
				<< "La suite ha sido satisfactoriamente seleccionada, reserva completada"
				<< endl;
		break;
	case 4:
		seleccionCiudad();
		break;
	}

}

void registrarLogIn(char username[]) {
	time_t horalogin;
	time(&horalogin);

	FILE *fichero;

	fichero = fopen("LogInLogs.txt", "a");

	if (fichero == NULL) {
		cout << "error en la apertura del archivo" << endl;
	} else {

		fputs(username, fichero);
		fprintf(fichero, "%s", ", ");
		fprintf(fichero, "%s", ctime(&horalogin));

		fflush(fichero);
		fclose(fichero);
	}
}

int registrarUsuarios(sqlite3 *dhdb) {

	char dniR[9];
	char apellidosR[15];
	char nombreUsuarioR[15];
	char emailR[30];
	bool adminR = false;
	char passwordR[15];
	char usernameR[15];

	cout << "Introduzca su DNI: " << endl;
	cin >> dniR;
	cout << "Introduzca su apellido: " << endl;
	cin >> apellidosR;
	cout << "Introduzca su nombre: " << endl;
	cin >> nombreUsuarioR;
	cout << "Introduzca su correo: " << endl;
	cin >> emailR;
	cout << "Introduzca una password: " << endl;
	cin >> passwordR;
	cout << "Escriba el nombre de usuario que desea tener: " << endl;
	cin >> usernameR;

	sqlite3_stmt *stmt;

	char sql[] =
			"insert into Usuario (dni, nombre, apellidos, email, admin, password, username) values (?, ?, ?, ?, ?, ?, ?)";

	int result = sqlite3_prepare_v2(dhdb, sql, strlen(sql) + 1, &stmt, NULL);

	if (result != SQLITE_OK) {
		printf("Error en la preparacion de la consulta (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(dhdb));
		return result;
	}

	printf("consulta SQL preparada (INSERT)\n");

	result = sqlite3_bind_text(stmt, 1, dniR, strlen(dniR), SQLITE_STATIC);
	result = sqlite3_bind_text(stmt, 2, nombreUsuarioR, strlen(nombreUsuarioR),
			SQLITE_STATIC);
	result = sqlite3_bind_text(stmt, 3, apellidosR, strlen(apellidosR),
			SQLITE_STATIC);
	result = sqlite3_bind_text(stmt, 4, emailR, strlen(emailR), SQLITE_STATIC);
	result = sqlite3_bind_int(stmt, 5, adminR);
	result = sqlite3_bind_text(stmt, 6, passwordR, strlen(passwordR),
			SQLITE_STATIC);
	result = sqlite3_bind_text(stmt, 7, usernameR, strlen(usernameR),
			SQLITE_STATIC);

	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(dhdb));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error al insertar los nuevos datos en la tabla\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error al finalizar la consulta(INSERT)\n");
		printf("%s\n", sqlite3_errmsg(dhdb));
		return result;
	}

	printf("consulta preparada finalizada (INSERT)\n");

	return SQLITE_OK;

}

/*
 void buscarOferta(){

 FILE *f;
 int c;

 f = fopen ("ReservaDH.txt", "r");//rb dice en el video que es m�s r�pido, usamos la que prefirais

 if(f == NULL){
 printf("No se ha podido habrir el fichero");
 seleccionHotel();
 }

 while(feof(f)==0){
 c = fgetc(f);
 printf("%c ", c);
 }

 fclose(f);

 }


 char temp[50];
 int cont = 0;
 int i, j, o,p;
 char aux;


 reserva *oferta;

 FILE *f;

 f = fopen ("ReservaDH.txt", "r");

 if(f == NULL){
 printf("No se ha podido abrir el fichero");
 seleccionHotel();
 }

 while(!feof(f)){

 fgets(temp, 50, f);
 cont++;

 }

 rewind(f);

 oferta = (reserva*)malloc(cont*sizeof(reserva));

 if(oferta == NULL){

 printf("No se ha podido reservar la memoria");
 seleccionHotel();

 }

 for (i = 0; !feof(f); i++){
 vaciar(temp);
 aux = '0';
 for(j=0; aux != ','; j++){
 aux = 	fgetc(f);
 if(aux != ','){
 temp[j] = aux;
 }
 }

 copiar (temp, i);

 }

 ordenar(la matriz que leamos de los precios);

 }

 void vaciar(char temp[]){

 int i;

 for(i = 0; i<50; i++){
 temp[i] = '\0';
 }

 }

 void copiar(char temp[], int i){

 int n = strlen(temp) + 1;

 }*/

//void ordenar(int a[]){
//	int i,j,aux;
/*	for(i = 0; o <lo que sea[i]; o++){

 for(j = 0; p < lo que sea[i]; p++){

 if(a[i]>a[j]){
 aux = a[i];
 a[i] = a[j];
 a[j] = aux;
 }
 }
 }
 */

//}

