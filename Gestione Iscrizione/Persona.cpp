#include<iostream>
#include<cstdlib>

using namespace std;
#include "Persona.h"

Persona::Persona(string n,string c,string d)
{
     nome=n;
     cognome=c;
     datan=d;
}

void Persona::print() const{
     cout<<cognome<<" "<<nome;
     cout<<endl;
}


ostream& operator<<(ostream& os, const Persona& p)
{
         os<<p.cognome<<" "<<p.nome<<" "<<p.datan;
         return os;
}
