#ifndef ESAME_H
#define ESAME_H

#include<iostream>
#include<cstdlib>
#include "Docente.h"
#include "Studente.h"

using namespace std;

class Esame
{
      private:
              string ins;
              Docente* doc;
              string data;
              Studente* iscritti[200];
      public:
             Esame(string,Docente&,string);
             void stampa();
             void iscrivi(Studente&);
};

#endif
