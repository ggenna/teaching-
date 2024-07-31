#include<iostream>
#include<cstdlib>

using namespace std;

#include "Studente.h"

Studente::Studente(string n,string c,string d,string cl): Persona(n,c,d)
{
      setCDL(cl);
}


void Studente:: setCDL(string cl)
{
     CDL=cl;
}

void Studente:: print() const{
     
cout<<"Sig"<<" ";
Persona::print();

}

ostream& operator<<(ostream& os, const Studente& s)
{        
         os<<"Sig. "<<" ";
         os<<s.getcognome()<<" "<<s.getnome()<<" "<<"nato il "<<s.getdatan()<<" "<<s.CDL;
      return os;
}
