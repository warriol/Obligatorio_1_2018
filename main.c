// Estructuras de Datos y Algoritmos - Curso 2018
// Tecnologo en Informatica FIng - CETP
//
// Trabajo Obligatorio
// main.h
// Consola para ingreso de datos.

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "bd.h"
#include "columna.h"
#include "tupla.h"
#include "tabla.h"

using namespace std;

int main()
{
	bd bd = createBD();
	char * comando = new (char[MAX_COMANDO]);
	char * pch, * pch1, * pch2, *pch3;
	TipoRet ret;
	bool ejecutado = false;

	bool salir = false;
	
	do{
		cout << "\tcreateTable (nombreTabla)\n";
		cout << "\tdropTable (nombreTabla)\n";
		cout << "\taddCol (nombreTabla, NombreCol)\n";
		cout << "\tdropCol (nombreTabla, NombreCol)\n";
		cout << "\tinsertInto (nombreTabla, valoresTupla)\n";
		cout << "\tdeleteFrom (nombreTabla, condicionEliminar)\n";
		cout << "\tupdate(nombreTabla, condicionModificar, columnaModificar, valorModificar)\n";
		cout << "\tprintdatatable (NombreTabla)\n";
		cout << "\tsalir\n\n";
		cout << "> ";
		fflush( stdin );				// limpia el bufer de basura
		ejecutado = false;
		
		/*
		 * Lee de la entrada estandar
		 * guarda en un string llamado comando
		 * realiza dicha tarea hasta que llegue un fin de lina o MAX?COMANDO
		 */
		fgets (comando, MAX_COMANDO, stdin);
		
		/*
		 * El string comando es dividido segun el patron "( ,)"
		 * la primer division se guarda en pch
		 */
		pch = strtok (comando,"( ,)");
		
		/*
		 * Primer escala de if anidados
		 * strcmp compara dos string
		 * si pch es igual a alguno de los comando verificamos que los pch* tenga la informacion adecuada para seguir
		 */
		if (strcmp (pch, "createTable") == 0){
			/*
			 * En este punto el primer pch tenia como comando crear tabla, ahora el segundo pch tendra el nombre
			 * createTable (nombreTabla)
			 * pch = createTable
			 * pch = nombreTabla
			 */
			pch = strtok (NULL, "( ,)");
			if (pch != NULL){
				ret = createTable (bd, pch);
				ejecutado = true;
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}
		else if (strcmp (pch, "dropTable") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL){
				ret = dropTable (bd, pch);
				ejecutado = true;
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}
		else if (strcmp (pch, "addCol") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL){
				pch1 = strtok (NULL, "( ,)");
				if (pch1 != NULL){
					ret = addCol (bd, pch, pch1);
					ejecutado = true;
				}
				else
					cout << " - ERROR: Faltan Parametros.\n";
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}
		else if (strcmp (pch, "dropCol") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL)
			{
				pch1 = strtok (NULL, "( ,)");
				if (pch1 != NULL){
					ret = dropCol (bd, pch, pch1);
					ejecutado = true;
				}
				else
					cout << " - ERROR: Faltan Parametros.\n";
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}
		else if (strcmp (pch, "insertInto") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL){
				pch1 = strtok (NULL, "( ,)");
				if (pch1 != NULL){
					ret = insertInto (bd, pch, pch1);
					ejecutado = true;
				}
				else
					cout << " - ERROR: Faltan Parametros.\n";
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}
		else if (strcmp (pch, "deleteFrom") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL){
				pch1 = strtok (NULL, "( ,)");
				if (pch1 != NULL){
					ret = deleteFrom (bd, pch, pch1);
					ejecutado = true;
				}
				else
					cout << " - ERROR: Faltan Parametros.\n";
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}
		else if (strcmp (pch, "update") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL){
				pch1 = strtok (NULL, "( ,)");
				if (pch1 != NULL){
					pch2 = strtok (NULL, "( ,)");
					if (pch2 != NULL){
						pch3 = strtok (NULL, "( ,)");
						if (pch3 != NULL){
							ret = update (bd, pch, pch1, pch2, pch3);
							ejecutado = true;
						}
						else
							cout << " - ERROR: Faltan Parametros.\n";
					}
					else
						cout << " - ERROR: Faltan Parametros.\n";
				}
				else
					cout << " - ERROR: Faltan Parametros.\n";
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}
		else if (strcmp (pch, "printdatatable") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL){
				ret =  printdatatable (bd, pch);
				ejecutado = true;
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}
		else if (strcmp (pch, "salir") == 0){
			salir = true;
		}
		else
			cout << " - Comando Incorrecto\n";
		if (ejecutado){
				if (ret == OK)
					cout << " - OK\n";
				else if (ret == ERROR)
					cout << " - ERROR\n";
				else
					cout << " - NO IMPLEMENTADA\n";
		}
	}while (!salir);
	cout << "\n\n - CHAUU!!!!\n";

	bd = destroyBD(bd);
	delete [] comando;
}
