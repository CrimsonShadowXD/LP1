
/* 
 * File:   Bib_Func_Preg3.h
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 * Created on 1 de junio de 2020, 18:31
 */

#include <fstream>

using namespace std;

#ifndef BIB_FUNC_PREG3_H
#define BIB_FUNC_PREG3_H

template <typename T>
    void incrementar(T *&arreglo, int &n, int &capacidad){
        T* aux;        
        capacidad+=5;
        if (arreglo==nullptr){ //OTRA OPCION SI NO HAY INICIALIZACION es (n==0)
            arreglo=new T[capacidad];
            arreglo[0]=nullptr;
            n++;
        }
        else {
        aux = new T[capacidad];
        for(int i=0;i<n;i++) aux[i]=arreglo[i]; 
        delete arreglo;
        arreglo=aux;}
        return;        
    }

void leeNotas(int *&codAlum,int ***&notas);
void imprimirNotas(int *codAlum,char **alumnos,int ***notas);



#endif /* BIB_FUNC_PREG3_H */

