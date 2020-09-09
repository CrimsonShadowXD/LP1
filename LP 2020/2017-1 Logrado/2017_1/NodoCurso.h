/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoCurso.h
 * Author: Rodrigo
 *
 * Created on 9 de diciembre de 2019, 11:47 AM
 */
#include "Curso.h"

#ifndef NODOCURSO_H
#define NODOCURSO_H

class NodoCurso {
public:
    NodoCurso();
    virtual ~NodoCurso();
private:
class Curso elem;
NodoCurso *sig;

friend class ListaCursos;
};

#endif /* NODOCURSO_H */

