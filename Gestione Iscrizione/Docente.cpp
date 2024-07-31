#include<iostream>
#include<cstdlib>
#include "Docente.h"

using namespace std;


Docente::Docente(string n,string c,string d,string s): Persona(n,c,d)
{
   setsettore(s);
}


void Docente::setsettore(string s)
{
     settore=s;
}

void Docente::print(){
     
cout<<"Prof. ";
Persona::print();

}

ostream& operator<<(ostream& os, const Docente& d)
{
os<<"Prof. "<<d.getnome()<<" "<<d.getcognome()<<" "<<"nato il "<<d.getdatan()<<" ";
os<<"settore: "<<d.settore;
         return os;
}

