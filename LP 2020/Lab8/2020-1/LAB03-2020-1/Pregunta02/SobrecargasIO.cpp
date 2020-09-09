
/* 
 * File:   SobrecargasIO.h
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 * Created on 3 de julio de 2020, 09:30
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Alumno.h"
#include "Persona.h"
#include "Profesor.h"
#include "Miembro.h"
#include "SobrecargasIO.h"

using namespace std;

ifstream & operator>>(ifstream &in, Profesor &entrada){
    entrada.leer(in);    
    return in;
}
ifstream & operator>>(ifstream &in, Alumno &entrada){
    entrada.leer(in);
        return in;
}
ifstream & operator>>(ifstream &in, Miembro &entrada){
    while(1){
        entrada.leerMiembro(in);
        if (in.eof()) break;
    }
        return in;
}

ofstream & operator<<(ofstream &out, Profesor &salida){
        out<<"Codigo profesor: "<<salida.GetCodigo()<<endl;
    out<<"Nombre del Alumno: "<<salida.GetNombre()<<endl;
    out<<"Distrito: "<<salida.GetDistrito()<<endl;
    out<<"Categoria: "<<salida.GetCategoria()<<endl;
    out<<"Dedicacion: "<<salida.GetDedicacion()<<endl;
    out<<"Seccion: "<<salida.GetSeccion()<<endl;
    out<<"Grado Academico: "<<salida.GetGrado()<<endl;
    out<<endl;
        return out;
}
ofstream & operator<<(ofstream &out, Alumno &salida){
    out<<"Codigo Alumno: "<<salida.GetCodigo()<<endl;
    out<<"Nombre del Alumno: "<<salida.GetNombre()<<endl;
    out<<"Distrito: "<<salida.GetDistrito()<<endl;
    out<<"Escala de Pago: "<<salida.GetEscala()<<endl;
    out<<"Especialidad: "<<salida.GetEspecialidad()<<endl;
    out<<"Facultad: "<<salida.GetFacultad()<<endl;
    out<<endl;
        return out;
}
