

/* 
 * File:   Nodo.h
 * Author: Rodrigo
 *
 * Created on 7 de diciembre de 2019, 07:26 PM
 */

#include <fstream>

using namespace std;

#ifndef NODO_H
#define NODO_H

template <typename T> class ListaDoble;
template <typename T> 
class Nodo{
    private:
        T elem;        
        Nodo<T> *sig;
        Nodo<T> *ant;
        
        friend class ListaDoble<T>;
        
        public:
            Nodo();           
};

template <typename T>
Nodo<T>::Nodo(){
    sig = NULL;
    ant = NULL;
}



#endif /* NODO_H */

