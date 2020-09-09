/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.h
 * Author: Author: Alexis Johan Andres Avelino Campos 20155470
 *
 * Created on 10 de diciembre de 2019, 08:20 AM
 */
#include <fstream>
using namespace std;
#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente {
public:
    Cliente();
    virtual ~Cliente();
    
    void SetNombre(char* nom);
    void GetNombre(char* nom) const;
    void SetDni(int dni);
    int GetDni() const;
    void SetTiempoTransaccion(double tiempoTransaccion);
    double GetTiempoTransaccion() const;
    void SetSegundoLlegada(int segundoLlegada);
    int GetSegundoLlegada() const;
    void SetMinutoLlegada(int minutoLlegada);
    int GetMinutoLlegada() const;
    void SetHoraLlegada(int horaLlegada);
    int GetHoraLlegada() const;
    
    void operator =(Cliente&cli);
    
    
private:
    int dni;
    char* nombre;
    int horaLlegada;
    int minutoLlegada;
    int segundoLlegada;
    double tiempoTransaccion;
};

void operator<<(ofstream&,Cliente&);
void operator>>(ifstream&,Cliente&);


#endif /* CLIENTE_H */

