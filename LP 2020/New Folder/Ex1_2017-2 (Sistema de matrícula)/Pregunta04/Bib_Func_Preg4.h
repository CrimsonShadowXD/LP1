
/* 
 * File:   Bib_Func_Preg4.h
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 * Created on 1 de junio de 2020, 18:52
 */
#include <fstream>

using namespace std;

#ifndef BIB_FUNC_PREG4_H
#define BIB_FUNC_PREG4_H

void reporteDeMatricula(int *codCur,char **cursos,int **requisitos,int *codAlum,char **alumnos,int ***notas);
bool verificar(int *requisitos, int **notas);

#endif /* BIB_FUNC_PREG4_H */

