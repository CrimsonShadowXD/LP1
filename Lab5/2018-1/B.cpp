/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "B.h"
using namespace std;

void leer(char **especialidad,char ****medicos){
    char c,*cod,*nomDoct,*espec,*tarifa;
    int nd,tam,cantDoct[N]={0},tamDoct[N]={0};
    especialidad=NULL;
    medicos=NULL;
    nd = tam =0;
    while(1){
        if(c=cin.peek()=='\n')break;
        if(nd==tam)
            incEspacios(especialidad,medicos,nd, tam);
        cod=leeCadena(',');
        nombDoct=leeNombDoct();
        espec=leeCadena(',');
        tarifa=leeCadena('\n');
        insertarDatos(especialidad,medicos,cod,nombDoct,espec,tarifa,nd,cantDoct,tamDoct);
    }
    cin.get();
}

void impr(char **esp,char ****med){
    
}