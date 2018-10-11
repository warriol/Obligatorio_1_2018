#ifndef COLUMNA_H
#define COLUMNA_H

// Estructuras de Datos y Algoritmos - Curso 2018
// Tecnologo en Informatica FIng - CETP
//
// Trabajo Obligatorio
// columna.h
// Modulo de Definición de Base de Datos.

#include "define.h"

typedef struct nodo_columna* c;

/*
 * Wilson Arriola
 * 11/10/2018
 */
bool dime_si_nomCol_en_nomTbl(c col, char * nombreCol);
// Si nombreColumna pertenece a NombreTabla devuelve True, sino False
// Pre: nombreTabla debe existir en la DB


#endif

