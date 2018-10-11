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


#include "columna.h"
#include "tupla.h"
#include "tabla.h"

using namespace std;

int main()
{
	t t = createTa();
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
		fflush( stdin );
		ejecutado = false;
		
		fgets (comando, MAX_COMANDO, stdin);

		pch = strtok (comando,"( ,)");

		if (strcmp (pch, "createTable") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL){
				ret = createTable (t, pch);
				ejecutado = true;
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}
		else if (strcmp (pch, "dropTable") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL){
				ret = dropTable (t, pch);
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
					ret = addCol (t, pch, pch1);
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
					ret = dropCol (t, pch, pch1);
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
					ret = insertInto (t, pch, pch1);
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
					ret = deleteFrom (t, pch, pch1);
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
							ret = update (t, pch, pch1, pch2, pch3);
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
				ret =  printdatatable (t, pch);
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

	t = destroyt(t);
	delete [] comando;
}
