/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Author.h
 * Author: Daniela
 *
 * Created on 22 de noviembre de 2017, 04:30 PM
 */
//20150008 Daniela Alexandra Cisneros Muñoz
#ifndef AUTHOR_H
#define AUTHOR_H
#include <iostream>
using namespace std;
class Author {
public:
    Author();
    Author(int , char* , char* );
    Author(const Author& a);
    virtual ~Author();
    void SetNum_papers(int num_papers);
    int GetNum_papers() const;
    void SetLast_name(char* last_name);
    void GetLast_name(char *) const;
    void SetFirst_name(char* first_name);
    void GetFirst_name(char *) const;
    void SetId(int id);
    int GetId() const;
    friend istream& operator >>(istream &,  Author&);
    friend ostream& operator <<(ostream &, const Author&);
    bool operator < ( const Author &);
    bool operator > ( const Author &);
    bool operator == ( const Author &);

private:
    int id;
    char* first_name;
    char* last_name;
    int num_papers;
};

#endif /* AUTHOR_H */

