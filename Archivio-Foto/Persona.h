#include <cstdlib>
#include <iostream>

using namespace std;

#ifndef PERSONA_H
#define PERSONA_H

//#include "Ritratto.h"

class Persona
{
      friend ostream& operator<<(ostream&, const Persona&);
      protected:
              string nomep,cognome,nascita;
              
      public:
             Persona(string=" ",string=" ",string=" ");
             void setnome(string n){ nomep=n;}
             void setcognome(string c){ cognome=c;}
             void setnascita(string na){ nascita=na;}
             string getnome(){ return nomep;}
             string getcognome(){ return cognome;}
             string getnascita(){ return nascita;}
             void modifica();
             void stampa();
             
};

#endif
