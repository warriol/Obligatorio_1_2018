// Estructuras de Datos y Algoritmos - Curso 2018
// Tecnologo en Informatica FIng - CETP
//
// Trabajo Obligatorio
// bd.c
// Modulo de Implementación de Base de Datos.

#include <iostream>

#include "bd.h"

using namespace std;

struct nodo_bd{
	//
	char * nombreBD;
	tabla t;
	bd * sig;
};

struct nodo_tabla{
	int datoTa_i;
	char* datoTa_c;
	columna x;
	tabla* sig;
};

struct nodo_columna{
	int datoCo_i;
	char* datoCo_c;
	tupla x;
	columna* sig;
};

struct nodo_tupla {
	int datoTu_i;
	char* datoTu_c;
	tupla* sig;
};

bd createBD(){
	//
	return NULL;
}


TipoRet createTable (t & t, char *nombreTabla){
	//cout << " - createTable " << nombreTabla << endl;;
	bool existe = false;
	if (t== NULL){			//Si no hay ninguna tabla
		t = new(nodo_tabla);
    	t->datoTa_c == nombreTabla;
    	t->sig = NULL;
		return OK;
	}else{
		while ((t!= NULL) && (!existe)){		//Mientras existan tablas y la tabla a crear no exista
			if (t->datoTa_c = nombreTabla){		//Si la tabla existe devuelvo error sino sigo buscando
				existe = true;
				return ERROR;
			}else{
				t = t->sig;
			}
		}
		if (!existe){					//Si no existe la tabla a crear, la creo. Sino error
			t = new(nodo_tabla);
    		t->datoTa_c = nombreTabla;
    		t->sig = NULL;
			return OK;
		}else{
			return ERROR;
		}
	}
			
	

}

TipoRet dropTable (bd & bd,char *nombreTabla){
// Elimina de la base de datos la tabla de nombre nombreTabla, y las tuplas
// que la misma posee, si nombreTabla existe.
	// cout << " - dropTable " << nombreTabla << endl;
	return NO_IMPLEMENTADA;
}

TipoRet addCol (t & t,char *nombreTabla,char *NombreCol){
	//cout << " - addCol " << nombreTabla << " " << NombreCol << endl;;
	bool existe, existeCol = false;
	if (t==NULL){		//Si no hay tablas devuelvo error
		return ERROR;
	}else{
		while ((t!= NULL) && (!existe)){		//Mientras existan tablas y la tabla no exista
			if (t->datoTa_c = nombreTabla){		//Si la tabla existe busco dentro para crear la columna
				existe = true;
				if (c==NULL){		//Si no hay columnas creo
					c = new(nodo_columna);
    				c->datoCo_c == nombreCol;
    				c->sig = NULL;
					return OK;
				}else{
					while ((c!= NULL) && (!existeCol)){		//Mientras existan columnas y la columna a crear no exista
						if (c->datoCo_c = nombreCol){		//Si la columna existe devuelvo error sino sigo buscando
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
    			c->datoCo_c = nombreCol;
    			c->sig = NULL;
				return OK;
			}else{
				return ERROR;
			}
		}
	}
}

TipoRet dropCol (bd & bd, char *nombreTabla, char *NombreCol){
	//cout << " - dropCol " << nombreTabla << " " << NombreCol << endl;;
	return NO_IMPLEMENTADA;
}

TipoRet insertInto (bd & bd, char *nombreTabla, char *valoresTupla){
	//cout << " - insertInto " << nombreTabla << " " << valoresTupla<< endl;;
	return NO_IMPLEMENTADA;
}

TipoRet deleteFrom (bd & bd, char *nombreTabla, char *condicionEliminar){
	//cout << " - deletefrom " << nombreTabla << " " << condicionEliminar << endl;;
	return NO_IMPLEMENTADA;
}

TipoRet update(bd & bd, char * nombreTabla, char * condicionModificar, char * columnaModificar, char * valorModificar){
	//cout << " - update " << nombreTabla << " " << condicionModificar << " " << columnaModificar << " " << valorModificar << endl;
	return NO_IMPLEMENTADA;
}

TipoRet printdatatable (bd bd, char *NombreTabla){
	//cout << NombreTabla << endl;
	return NO_IMPLEMENTADA;
}

bd destroyBD(bd & bd){
	//
	return NULL;
}

