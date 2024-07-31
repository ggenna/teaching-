#ifndef STUDENTE_H
#define STUDENTE_H

#include<iostream>
#include<cstdlib>
#include "Persona.h"

using namespace std;

class Studente:public Persona
{
      private:
              string CDL;
              friend ostream& operator<<(ostream&, const Studente&);
      public:
             Studente(string,string,string,string);
             virtual void print() const;
             void setCDL(string);
             string getCDL() const {return CDL;}
};

#endif
