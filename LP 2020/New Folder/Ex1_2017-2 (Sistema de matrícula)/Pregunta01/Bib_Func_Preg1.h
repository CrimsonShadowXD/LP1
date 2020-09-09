
/* 
 * File:   Bib_Func_Preg1.h
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 * Created on 1 de junio de 2020, 17:43
 */

#include <fstream>

using namespace std;

#ifndef BIB_FUNC_PREG1_H
#define BIB_FUNC_PREG1_H

void imprimeLinea(ofstream &out,char car);
char* sacaPalabra(ifstream &in, char c);
int* leeRequisitos(ifstream &in);
void leerCursos(int *&codCur,char **&cursos,int **&requisitos);
void imprimirCursos(int *codCur,char **cursos,int **requisitos);



#endif /* BIB_FUNC_PREG1_H */

