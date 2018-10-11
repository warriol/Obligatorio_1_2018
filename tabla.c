// Estructuras de Datos y Algoritmos - Curso 2018
// Tecnologo en Informatica FIng - CETP
//
// Trabajo Obligatorio
// tabla.c
// Modulo de Implementación de Base de Datos.

#include <iostream>
#include <string.h>

#include "tabla.h"
#include "columna.h"

using namespace std;


struct nodo_tabla{
	char * nomTa;
	c x;
	t sig;
};

/*
 * Wilson Arriola
 * 11/10/2018
 */
void creo_DB_de_prueba(t & tbl){
// Para realizar testeo durante el desarrollo se crea una base de prueba
	tbl = new (nodo_tabla);
	tbl->nomTa = new (char);
	strcpy(tbl->nomTa, "Personas");
	creo_DB_de_prueba_c(tbl->x);
	tbl->sig = NULL;
}


/*
 * Wilson Arriola
 * 11/10/2018
 */
void mostrar_Msj_Error(int id, char * dato1, char * dato2){
// Muestra los mensajes de error de acuerdo a un codigo interno
	switch(id){
		case 100:
			// ERROR: tabla vacia
			cout << " - la tabla que hace referencia <" << dato1 << "> NO EXISTE!!! " << endl;
		break;
		default :
			cout << " - ocurrio un error general. " << endl;
	}
}


t createTa(){
	//
	return NULL;
}

TipoRet createTable (t & tbl, char * nombreTabla){
	//cout << " - createTable " << nombreTabla << endl;;
	bool existe = false;
	if (tbl== NULL){			//Si no hay ninguna tabla
		tbl = new(nodo_tabla);
		tbl->nomTa = new (char);
    		strcpy(tbl->nomTa, nombreTabla);
    		tbl->sig = NULL;
		return OK;
	}else{
		while ((tbl!= NULL) && (!existe)){		//Mientras existan tablas y la tabla a crear no exista
			if (strcmp(tbl->nomTa,nombreTabla)==0){		//Si la tabla existe devuelvo error sino sigo buscando
				existe = true;
				return ERROR;
			}else{
				tbl = tbl->sig;
			}
		}
		if (!existe){					//Si no existe la tabla a crear, la creo. Sino error
			tbl = new(nodo_tabla);
    			strcpy(tbl->nomTa,nombreTabla);
    			tbl->sig = NULL;
			return OK;
		}else{
			return ERROR;
		}
	}
			
	

}

/*
 *	profe
 */
 
TipoRet addCol (t & tbl,char *nombreTabla,char *nombreCol){
/*
	t aux = t;
	while ((aux != NULL) && strcmp(t->nomTa, nombreTabla) != 0){
		aux = aux->sig;
	}
	if ((aux != NULL) && (strcmp(aux->nomTa, nombreTabla) == 0)){
		//addCol_final(aux->x, char *nombreCol)
		return OK;
	}
	else
		return ERROR;
*/
	return NO_IMPLEMENTADA;
}


TipoRet dropTable (t & t,char *nombreTabla){
	//cout << " - dropTable " << nombreTabla << endl;;
	return NO_IMPLEMENTADA;
}

/*
 * Wilson Arriola
 * 11/10/2018
 */
TipoRet dropCol (t & tbl, char * nombreTabla, char * nombreCol){
// Elimina de la tabla de nombre nombreTabla, si ésta existe, la columna de nombre
// nombreCol, si ésta existe. Si la tabla tiene tuplas, entonces se eliminará de éstas
// el campo correspondiente a la columna eliminada. Si la tabla posee una única columna
// de nombre nombreColentonces quedará como tabla vacía. Si la columna a eliminar es la
// PRIMARY KEY, la operación resultará inválida, salvo que ésta sea la única columna de
// la tabla, en cuyo caso quedará como tabla vacía, como se describió previamente.

	//cout << " - dropCol " << nombreTabla << " " << NombreCol << endl;;
	
	t aux = tbl;								// tabla auxiliar
	if (tbl == NULL){							// tabla VACIA
		mostrar_Msj_Error(100, nombreTabla, nombreCol);			// mensaje al usuario
		return ERROR;							// ERROR y salgo
	}else
		while ( (aux != NULL) && (strcmp(tbl->nomTa, nombreTabla) != 0) ){// mientras aux no sea nulo y nombrTa diferente sigo buscando
			aux = aux->sig;
		}
		if (strcmp(aux->nomTa, nombreTabla) == 0){			// ENCONTRE nombreTabla
			// Verifico si nombreColumna existe en NombreTabla
			dime_si_nomCol_en_nomTbl(aux->x, nombreCol);
			return OK;
		}
		else								// la tabla NO esta vacìa pero NombreTabla no existe
			return ERROR;						// ERROR y salgo
		
	//return NO_IMPLEMENTADA;
}

TipoRet printdatatable (t tbl, char *NombreTabla){
	cout << tbl->nomTa << endl;
	cout << tbl->x->nomCo << ":" << tbl->x->x->datoTu << endl;
	/*
	cout << tbl->sig->x->nomCo << ":" << tbl->sig->x->x->datoTu << endl;
	cout << tbl->sig->sig->x->nomCo << ":" << tbl->sig->sig->x->x->datoTu << endl;
	*/
	return NO_IMPLEMENTADA;
}

TipoRet insertInto (t & t, char *nombreTabla, char *valoresTupla){
	//cout << " - insertInto " << nombreTabla << " " << valoresTupla<< endl;;
	return NO_IMPLEMENTADA;
}

TipoRet deleteFrom (t & t, char *nombreTabla, char *condicionEliminar){
	//cout << " - deletefrom " << nombreTabla << " " << condicionEliminar << endl;;
	return NO_IMPLEMENTADA;
}

TipoRet update(t & t, char * nombreTabla, char * condicionModificar, char * columnaModificar, char * valorModificar){
	//cout << " - update " << nombreTabla << " " << condicionModificar << " " << columnaModificar << " " << valorModificar << endl;
	return NO_IMPLEMENTADA;
}

t destroyTa(t & t){
	//
	return NULL;
}
