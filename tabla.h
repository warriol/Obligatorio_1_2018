#ifndef TABLA_H
#define TABLA_H


#include "define.h"

typedef struct nodo_tabla* t;

/*
 * Wilson Arriola
 * 11/10/2018
 */
void creo_DB_de_prueba(t & tbl);
// Para realizar testeo durante el desarrollo se crea una base de prueba

/*
 * Wilson Arriola
 * 11/10/2018
 */
void mostrar_Msj_Error(int id, char * dato1, char * dato2);
// Muestra los mensajes de error de acuerdo a un codigo interno

t createTa();
// Crea la base de datos vacía.

TipoRet createTable (t & tbl,char *nombreTabla);
// Crea una nueva tabla vacía (sin columnas ni tuplas) en la base de datos
// con nombre nombreTabla, siempre que no exista ya una tabla con dicho nombre.

TipoRet dropTable (t & t,char *nombreTabla);
// Elimina de la base de datos la tabla de nombre nombreTabla, y las tuplas
// que la misma posee, si nombreTabla existe.

TipoRet printdatatable (t t,char *NombreTabla);
// Imprime las tuplas de la tabla de nombre nombreTabla, si ésta existe. Los nombres y los valores
// de las columnas se expresan en el formato columna1:columna2: … :columnan. Las tuplas se muestran
// ordenadas ascendentemente por la PRIMARY KEY. Primero se imprime el nombre de la tabla, luego los
// nombres de las columnas, separados con (:), y por último las tuplas, cuyos campos se separan
// también con (:).

TipoRet addCol (t & t,char * nombreTabla,char *nombreCol);
// Agrega a la tabla de nombre nombreTabla, si ésta existe, una nueva columna al
// final de nombre nombreCol, si ésta no existe. Si la tabla tiene tuplas la
// operación no resultará válida. Si esta es la primera columna que se agrega a la
// tabla su calificador será PRIMARY KEY. El tipo de datos de la nueva columna es string.

TipoRet dropCol (t & tbl,char *nombreTabla,char *nombreCol);
// Elimina de la tabla de nombre nombreTabla, si ésta existe, la columna de nombre
// nombreCol, si ésta existe. Si la tabla tiene tuplas, entonces se eliminará de éstas
// el campo correspondiente a la columna eliminada. Si la tabla posee una única columna
// de nombre nombreColentonces quedará como tabla vacía. Si la columna a eliminar es la
// PRIMARY KEY, la operación resultará inválida, salvo que ésta sea la única columna de
// la tabla, en cuyo caso quedará como tabla vacía, como se describió previamente.

TipoRet insertInto (t & t,char *nombreTabla,char *valoresTupla);
// Inserta en la tabla de nombre nombreTabla, si ésta existe, una tupla con los valores
// dados en valoresTuplapara las columnas. La correspondencia de los valores con las
// columnas definidas, en la habitualmente llamada metadata, es posicional. Los valores
// de valoresTuplase separan con el uso del carácter dos puntos (:).
// Si no se indican todas las columnas la operación resultará inválida. También será
// inválida si no hay al menos una columna en la tabla nombreTabla o si la tupla a insertar
// pertenece a la tabla o si el valor de la columna PRIMARY KEY ya existe.

TipoRet deleteFrom (t & t,char *nombreTabla,char *condicionEliminar);
// Elimina de la tabla de nombre nombreTabla, si éste existe, todas las tuplas que cumplen
// la condición condiciónEliminar. En caso de que la condición sea “”, se eliminan todas
// las tuplas de la tabla. Si ninguna tupla cumple la condición, la operación no tendrá
// efecto. El formato de las condiciones es: columna operador valor (sin espacios en blanco
// intermedios). Los operadores a utilizar son: = “igual”, ! “Distinto”, > “Mayor” , < “Menor”
// y * “Igual Prefijo”

TipoRet update(t & t,char * nombreTabla,char * condicionModificar,char * columnaModificar,char * valorModificar);
// Modifica en la tabla de nombre nombreTabla, si éste existe, el valor de las tuplas en la
// columna de nombre columnaModificar, si éste existe, que cumplen la condición condiciónModificar.
// En la columna especificada de las tuplas que cumplen la condición se asigna el valor valorModificar,
// siempre que este valor sea del tipo adecuado y satisfaga el calificador de la columna especificada.
// La condición respeta el formato descrito para condiciones.

t destroyTa(t & t);
// Destruye bd y libera la memoria asociada.

#endif
