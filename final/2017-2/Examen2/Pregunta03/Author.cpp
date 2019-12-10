/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Author.cpp
 * Author: Daniela
 * 
 * Created on 22 de noviembre de 2017, 04:30 PM
 */
//20150008 Daniela Alexandra Cisneros Muñoz
#include "Author.h"
#include <iostream>
#include <cstring>
#include "Paper.h"
using namespace std;
Author::Author() {
    first_name=NULL;
    last_name=NULL;
    num_papers=0;
    
}
Author::Author(int cod, char* primer, char* ultimo) {
    SetId(cod);
    SetFirst_name(primer);
    SetLast_name(ultimo);
    num_papers=0;
}
Author::Author(const Author& a) {
    first_name=NULL;
    last_name=NULL;
    num_papers=0;
    SetFirst_name(a.first_name);
    SetLast_name(a.last_name);
    SetId(a.id);
    SetNum_papers(a.num_papers);
}

Author::~Author() {
    if(first_name) delete [] first_name;
    if(last_name) delete [] last_name;
}

void Author::SetNum_papers(int num_papers) {
    this->num_papers = num_papers;
}

int Author::GetNum_papers() const {
    return num_papers;
}

void Author::SetLast_name(char* c) {
    if(last_name) delete last_name;
    last_name= new char [strlen(c)+1];
    strcpy(last_name,c);
}

void Author::GetLast_name(char* c) const {
    strcpy(c,last_name);
}


void Author::SetFirst_name(char* c) {
    if(first_name) delete first_name;
    first_name= new char [strlen(c)+1];
    strcpy(first_name,c);
}

void Author::GetFirst_name(char* c) const {
    strcpy(c,first_name);
}


void Author::SetId(int id) {
    this->id = id;
}

int Author::GetId() const {
    return id;
}

istream& operator>>(istream& arch,  Author& aut) {
    arch>>aut.id;
    if(arch.eof()) return arch;
    char aux1[200],aux2[200];
    arch.get();
    arch.getline(aux1,200,',');
    arch.getline(aux2,200);
   
    aut.SetFirst_name(aux1);
    aut.SetLast_name(aux2);
    aut.SetNum_papers(0);
    return arch;
}

ostream& operator<<(ostream& arch, const Author& aut) {
   
    arch<<"Id Author: "<<aut.id<<endl;
    arch<<"First Name: "<<aut.first_name<<endl;
    arch<<"Last Name: "<<aut.last_name<<endl;
    arch<<"Num Papers: "<<aut.num_papers<<endl<<endl;
}

bool Author::operator<(const Author& a) {
    return id<a.id;
}

bool Author::operator==(const Author& a) {
    return id==a.id;
}

bool Author::operator>(const Author& a) {
    return id>a.id;
}

void Author::operator=(Author& a) {
    SetFirst_name(a.first_name);
    SetLast_name(a.last_name);
    SetId(a.id);
    SetNum_papers(a.num_papers);
}


