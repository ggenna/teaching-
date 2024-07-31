#include <cstdlib>
#include <iostream>

using namespace std;

#ifndef PANORAMA_H
#define PANORAMA_H

#include "Foto.h"

class Panorama:public Foto
{
      private:
              string luogo;
              
      public:
             Panorama(string=" ",string=" ",int=0,int=0,string=" ");
             string getluogo(){ return luogo;}
             virtual void stampa();
             virtual void modifica();
             virtual bool cercaLuogo(string);
             virtual bool cercaPersona(string,string);
             
};

#endif
