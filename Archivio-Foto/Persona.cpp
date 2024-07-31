#include <cstdlib>
#include <iostream>

using namespace std;

#include "Persona.h"

Persona::Persona(string n,string c,string na)
{
    setnome(n);
    setcognome(c);
    setnascita(na);
}

void Persona::stampa()
{
     cout<<"Dati Persona: "<<endl<<endl;
     cout<<"Nome: "<<nomep<<endl;
     cout<<"Cognome: "<<cognome<<endl;
     cout<<"Data di nascita: "<<nascita<<endl;
}

ostream& operator<<(ostream& os, const Persona& p)
{
     os<<"Dati Persona: "<<endl<<endl;
     os<<"Nome: "<<p.nomep<<endl;
     os<<"Cognome: "<<p.cognome<<endl;
     os<<"Data di nascita: "<<p.nascita<<endl;
}

void Persona::modifica()
{
     
     cout<<"Inserisci nuovo valore nome: ";
     cin>>nomep;
     cout<<"Inserisci nuovo valore cognome: ";
     cin>>cognome;
     cout<<"Inserisci nuovo valore data di nascita: ";
     cin>>nascita;
}
         
