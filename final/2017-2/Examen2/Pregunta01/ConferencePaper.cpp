/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConferencePaper.cpp
 * Author: Daniela
 * 
 * Created on 22 de noviembre de 2017, 04:08 PM
 */
//20150008 Daniela Alexandra Cisneros Muñoz
#include "ConferencePaper.h"
#include <iostream>
#include <cstring>
#include "Paper.h"
using namespace std;
ConferencePaper::ConferencePaper(){
    conference_name=NULL;
    host_country=NULL;
}
ConferencePaper::ConferencePaper(int id, char* title, int idAut, int pub, char* nombre , int ed, char* pais) :Paper(id,title,idAut,pub){
   conference_name=NULL;
   host_country=NULL;
   SetConference_name(nombre);
   SetEdition(ed);
   SetHost_country(pais);
   SetTipo('C');
}
ConferencePaper::ConferencePaper(const ConferencePaper& orig) {
  
    conference_name=NULL;
    host_country=NULL;
    
    SetId(orig.GetId());
    SetId_author(orig.GetId_author());
    SetPublication_year(orig.GetPublication_year());
    SetEdition(orig.GetEdition());
    
    char titulo[200],nombreCon[200],pais[200];
    orig.GetTitle(titulo);
    orig.GetConference_name(nombreCon);
    orig.GetHost_country(pais);
    SetTitle(titulo);
    SetConference_name(nombreCon);
    SetHost_country(pais);
}

ConferencePaper::~ConferencePaper() {
    if(conference_name) delete [] conference_name;
    if(host_country) delete [] host_country;
}

void ConferencePaper::SetHost_country(char* c) {
    if(host_country) delete host_country;
    host_country= new char [strlen(c)+1];
    strcpy(host_country,c);
}

void ConferencePaper::GetHost_country(char *c) const {
    strcpy(c,host_country);
}

void ConferencePaper::SetEdition(int edition) {
    this->edition = edition;
}

int ConferencePaper::GetEdition() const {
    return edition;
}

void ConferencePaper::SetConference_name(char* c) {
    if(conference_name) delete conference_name;
    conference_name= new char [strlen(c)+1];
    strcpy(conference_name,c);
}

void ConferencePaper::GetConference_name(char *c) const {
    strcpy(c,conference_name);
}

void ConferencePaper::leerDatos(istream& arch) {
    int ed;
    char nombreCon[300],pais[200];
    Paper::leerDatos(arch);
    
    arch.getline(nombreCon,300,';');
    arch>>ed;
    arch.get();
    arch.getline(pais,200);
    
    SetConference_name(nombreCon);
    SetEdition(ed);
    SetHost_country(pais);
}

void ConferencePaper::citar(ostream& arch) {
int cod,pub,ed;
    char titulo[200];
    GetTitle(titulo);

    arch<<GetId_author()<<" ("<<GetPublication_year()<<"). "<< titulo
         <<". In Proceddings of the "<<edition<<"th "<<conference_name<<". "<<host_country<<". "<<endl; 
}

