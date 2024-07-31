#ifndef DOCENTE_H
#define DOCENTE_H

#include<iostream>
#include<cstdlib>
#include "Persona.h"

using namespace std;

class Docente:public Persona
{
      private:
              string settore;
              friend ostream& operator<<(ostream&, const Docente&);
      public:
             Docente(string,string,string,string);
             virtual void print();
             void setsettore(string);
             string getsettore(){return settore;}
             
             
};

#endif
             

