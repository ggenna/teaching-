#include <cstdlib>
#include <iostream>

using namespace std;

#ifndef RITRATTO_H
#define RITRATTO_H

#include "Foto.h"
#include "Persona.h"

class Ritratto:public Foto
{
      private:
              Persona soggetto;
              
      public:
             Ritratto(string=" ",string=" ",int=0,int=0,string=" ",string=" ",string=" ");
             virtual void stampa();
             virtual void modifica();
             virtual bool cercaLuogo(string);
             virtual bool cercaPersona(string,string);
             
};

#endif
             
