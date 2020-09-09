
/* 
 * File:   ListaNotas.cpp
 * Author: Rodrigo Agama
 * 
 * Created on 5 de julio de 2020, 14:46
 */

#include <cstring>
#include "Nota.h"
#include "NodoNota.h"
#include "ListaNotas.h"
#include <fstream>

using namespace std;

ListaNotas::ListaNotas() {
    lista=nullptr;
}


ListaNotas::~ListaNotas() {
    NodoNota *recorrido, *sale;
    
    recorrido = lista;
    while (recorrido){
        sale=recorrido;
        delete sale;
        recorrido=recorrido->sig;        
    }
}

void ListaNotas::agregarNota(Nota &entrada){
    NodoNota *nuevo = new NodoNota;
nuevo->elem.SetCodigo(entrada.GetCodigo()); //Sobrecargar =
nuevo->elem.SetNota(entrada.GetNota());
nuevo->elem.SetSemestre(entrada.GetSemestre());
NodoNota *p=lista, *ant=nullptr;
while(p){
    
    if (strcmp(p->elem.GetCodigo(),nuevo->elem.GetCodigo())==0) //Se actualiza el curso 
        if (strcmp(p->elem.GetSemestre(),nuevo->elem.GetSemestre())<0) break;
    
    else if (strcmp(p->elem.GetCodigo(), nuevo->elem.GetCodigo())<0) //Curso nuevo.
        break;
    
    ant=p;
    p=p->sig;
}
if (ant==nullptr){
    lista=nuevo;
}
else {
    ant->sig=nuevo;
    nuevo->sig=p;    
}

}

void ListaNotas::imprimirLista(ofstream &out){
    NodoNota *p=lista;
    out<<"LISTADO DE NOTAS"<<endl;
    out<<"CODIGO      NOTA      SEMESTRE"<<endl;
    while(p){
        p->elem.imprimir(out);
        p=p->sig;
    }
    out<<endl;
}

