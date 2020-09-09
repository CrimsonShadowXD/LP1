/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Npersona.h
 * Author: cueva
 *
 * Created on 7 de julio de 2020, 11:16 AM
 */

#ifndef NPERSONA_H
#define NPERSONA_H

class Npersona{
    private:
        class Persona *pers;
        class Npersona *sig;
   
    public:
        Npersona();
        friend class Lpersona;
    
};

#endif /* NPERSONA_H */

