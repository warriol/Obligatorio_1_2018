// Estructuras de Datos y Algoritmos - Curso 2018
// Tecnologo en Informatica FIng - CETP
//
// Trabajo Obligatorio
// columna.c
// Modulo de Implementación de Base de Datos.

#include <iostream>
#include <string.h>

//#include "tabla.h"
#include "columna.h"
#include "tupla.h"

using namespace std;

struct nodo_columna{
	int cant;
	char* nomCo;
	tupla x;
	c sig;
};

/*
 * Wilson Arriola
 * 11/10/2018
 */
bool dime_si_nomCol_en_nomTbl(c col, char * nombreCol){
// Si nombreColumna pertenece a NombreTabla devuelve True, sino False
// Pre: nombreTabla debe existir en la DB
	// se asume que no existe
	bool retorno = false;
	
	while ( (col != NULL) && (strcmp(col->nomCo, nombreCol) != 0) ){
		// mientras nomCo no sea NULL, comparo los nombre
		col->sig;
	}
	
	if (strcmp(col->nomCo, nombreCol) == 0)
		// si existe devuelvo verdadero
		retorno = true;
		
	return retorno;
}


/*TipoRet addCol (t & t,char *nombreTabla,char *nombreCol){
	//cout << " - addCol " << nombreTabla << " " << NombreCol << endl;;
	bool existe, existeCol = false;
	if (t==NULL){		//Si no hay tablas devuelvo error
		return ERROR;
	}else{
		while ((t!= NULL) && (!existe)){		//Mientras existan tablas y la tabla no exista
			if (strcmp(t->nomTa,nombreTabla)==0){		//Si la tabla existe busco dentro para crear la columna
				existe = true;
				if (c==NULL){		//Si no hay columnas creo
					c = new(nodo_columna);
    					strcpy(c->nomCo,nombreCol);
    					c->sig = NULL;
					return OK;
				}else{
					while ((c!= NULL) && (!existeCol)){		//Mientras existan columnas y la columna a crear no exista
						if (strcmp(c->nomCo,nombreCol)==0){		//Si la columna existe devuelvo error sino sigo buscando
							existeCol = true;
							return ERROR;
						}else{
							c = c->sig;
						}
					}
			
				}
			}else{
				t = t->sig;
			}
			if (!existeCol){					//Si no existe la columna a crear, la creo. Sino error
				c = new(nodo_columna);
    				strcpy(c->nomCo,nombreCol);
    				c->sig = NULL;
				return OK;
			}else{
				return ERROR;
			}
		}
	}
}*/



