

/* 
 * File:   EntidadReguladora.cpp
 * Author: Rodrigo
 * 
 * Created on 8 de diciembre de 2019, 05:53 PM
 */

#include "EntidadReguladora.h"
#include <fstream>
#include "NodoC.h"


EntidadReguladora::EntidadReguladora() {
}

EntidadReguladora::procesarDatos(){
    ifstream in("Conductores.csv",ios::in);    ifstream inFaltas("Registro_de_faltas.csv",ios::in);    ifstream inInf("Infracciones.csv",ios::in);
    ofstream out("PruebaConductores.txt",ios::out);   ofstream outInf("PruebaInfracciones.txt",ios::out); ofstream rep("ReporteMontos.txt",ios::out);
        
    conductores.crear(in); conductores.lecturaMultas(inFaltas);  conductores.imprimir(out); 
    infracciones.leer(inInf); infracciones.imprimir(outInf,(int)1); 
    conductores.imprimirMultas(rep,infracciones);
    
    
}

EntidadReguladora::~EntidadReguladora() {
}

