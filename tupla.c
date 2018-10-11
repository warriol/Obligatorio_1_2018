// Estructuras de Datos y Algoritmos - Curso 2018
// Tecnologo en Informatica FIng - CETP
//
// Trabajo Obligatorio
// tupla.c
// Modulo de Implementación de Base de Datos.

#include <iostream>
#include <string.h>

#include "tupla.h"

using namespace std;

struct nodo_tupla {
	char* datoTu;
	tupla sig;
};

/*
 * Wilson Arriola
 * 11/10/2018
 */
void creo_DB_de_prueba_c_t(tupla & t){
// crea columna de prueba
	t = new (nodo_tupla);
	t->datoTu = new (char);
	strcpy(t->datoTu,"111111");
	t->sig = new (nodo_tupla);
	t->sig->datoTu = new (char);
	strcpy(t->sig->datoTu,"wil");
	t->sig->sig = new (nodo_tupla);
	t->sig->sig->datoTu = new (char);
	strcpy(t->sig->sig->datoTu,"arr");
	t->sig->sig->sig = NULL;
}
