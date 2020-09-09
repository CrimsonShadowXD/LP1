/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: crimson
 *
 * Created on July 19, 2020, 12:20 PM
 */

#include "PlArbol.h"
#include "Libro.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream i("Libreria-LP1.csv", ios::in);
    ofstream o("prueba0.txt", ios::out);
    if (!i) {
        cerr << "Error al abrir el archivo de autores" << endl;
        exit(1);
    }

    if (!o) {
        cerr << "Error al abrir el archivo de salida" << endl;
        exit(1);
    }
    
    PlArbol<Libro> p;
    p.crear(i);
    p.imprimir(o);
    
    
    
    
    ifstream archIn("Autores-LP1.csv", ios::in);
    ofstream archOut("prueba.txt", ios::out);
    if (!archIn) {
        cerr << "Error al abrir el archivo de autores" << endl;
        exit(1);
    }

    if (!archOut) {
        cerr << "Error al abrir el archivo de salida" << endl;
        exit(1);
    }
    int dni,lon;
    char nom[100],buff[7],*cLib;
    Libro auxL;
    while(1){
        archIn>>dni;
        if(archIn.eof())break;
        archIn.get();
        archIn.getline(nom,100,',');
        while(1){
            archIn.get(buff,7);
            char c=archIn.get();
            auxL.SetCodigo(buff);
            auxL=p.buscar(auxL);
            if(auxL.GetPrecio()>0){                
                cout<<buff<<','<<endl;
                Autor auxA;
                auxA.SetDni(dni);
                auxA.SetNombre(nom);
                auxL.MeterLibro(auxA);
                p.modificar(auxL);
            }
            if(c==13 || c=='\n'){
               break; 
            }
        }
        cout<<endl;
    }
    
    p.imprimir(archOut);
    
    
    ifstream inx("Ventas-Libreria-LP1.csv", ios::in);
    ofstream outx("completo.txt", ios::out);
    if (!inx) {
        cerr << "Error al abrir el archivo de autores" << endl;
        exit(1);
    }

    if (!outx) {
        cerr << "Error al abrir el archivo de salida" << endl;
        exit(1);
    }
    
    int numero;
    char sep,cad[7];
    while(1){
        inx>>numero>>sep;
        if(inx.eof())break;
        inx>>numero>>sep;
        inx>>numero>>sep;
        inx>>numero>>sep;
        inx>>numero>>sep;
        inx>>numero>>sep;
        sep=13;
        inx.getline(cad,7,sep);  
        cout<<cad<<';'<<endl;
        auxL.SetCodigo(cad);
        auxL=p.buscar(auxL);
        if(auxL.GetPrecio()>0)++auxL;
        p.modificar(auxL);
    }
    p.imprimir(outx);
    return 0;
}

