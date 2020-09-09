/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: crimson
 *
 * Created on July 9, 2020, 6:54 PM
 */

#include "Administrativo.h"
#include "Docente.h"
#include "Alumno.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ofstream archA("A.txt",ios::out);
    if(!archA){
        cout << "No se puede abrir";
        exit(1);
    }
    ofstream archAd("Ad.txt",ios::out);
    if(!archAd){
        cout << "No se puede abrir";
        exit(1);
    }
    ofstream archD("D.txt",ios::out);
    if(!archD){
        cout << "No se puede abrir";
        exit(1);
    }
    Administrativo p3;
    Alumno p2;
    Docente p1;
    
    p1.setCodigo(2016011);
    p1.setNombre("Castro/sdfsdfs");
    p1.setDistrito("JM");
    p1.setDedicacion("ladron");
    p1.setCategoria("MIerda");
    p1.setSeccion("Infwfw");
    p1.setGrado("Maldito");
    p1.setSueldo(300.50);
    
    p1.imprimir(archD);
    
    
    return 0;
}

