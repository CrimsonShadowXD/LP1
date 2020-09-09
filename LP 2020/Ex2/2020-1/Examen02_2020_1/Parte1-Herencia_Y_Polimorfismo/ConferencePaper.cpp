/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConferencePaper.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 21 de julio de 2020, 08:12 AM
 */

#include "ConferencePaper.h"

ConferencePaper::ConferencePaper() {
    conference_name=NULL;
    host_country=NULL;
}

ConferencePaper::ConferencePaper(const ConferencePaper& orig) {
    conference_name=NULL;
    host_country=NULL;
    *this=orig;
}

ConferencePaper::~ConferencePaper() {
    if (conference_name != NULL) delete conference_name;
    if (host_country != NULL) delete host_country;
}

ConferencePaper::ConferencePaper(const char*nom,const char*pais){ 
    setConference_name(nom);
    setHost_country(pais);
}

void ConferencePaper::setHost_country(const char* cad) {
    if (cad == NULL) return;
    if (host_country != NULL) delete host_country;
    host_country = new char[strlen(cad) + 1];
    strcpy(host_country, cad); 
}

void ConferencePaper::getHost_country(char* cad) const {
    if (host_country == NULL)
        return;
    strcpy(cad, host_country); 
}

void ConferencePaper::setConference_name(const char* cad) {
    if (cad == NULL) return;
    if (conference_name != NULL) delete conference_name;
    conference_name = new char[strlen(cad) + 1];
    strcpy(conference_name, cad); 
}

void ConferencePaper::getConference_name(char* cad) const {
    if (conference_name == NULL)
        return;
    strcpy(cad, conference_name); 
}

void ConferencePaper::leerDatos(ifstream&in){ 
    char cad[250];
    int numero,ano;
    in>>numero;
    SetId(numero);
    if(in.eof())return;
    in.get(); 
    in.getline(cad,250,';');
    SetAuthor_name(cad);
    in>>ano;
    in.get();
    SetPublication_year(ano); 
    in.getline(cad,250,';');
    SetTitle(cad); 
    in.getline(cad,250,';');
    setConference_name(cad);
    in.getline(cad,250,'\n');
    setHost_country(cad); 
}

void ConferencePaper::citar(ofstream&out){
    char cad[250];
    GetAuthor_name(cad);
    out<<cad<<' ';
    out<<'('<<GetPublication_year()<<')'<<". ";
    GetTitle(cad);
    out<<cad<<". ";
    getConference_name(cad);
    out<<cad<<". ";
    getHost_country(cad);
    out<<cad<<'.'<<endl;
}
