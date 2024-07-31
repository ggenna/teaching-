#include <cstdlib>
#include <iostream>

using namespace std;

#ifndef FOTO_H
#define FOTO_H

class Foto
{
      protected:
              string nome,data;
              int x,y;
              
      public:
             Foto(string=" ",string=" ",int=0,int=0);
             string getnomefile(){ return nome;}
             virtual void stampa();
             virtual void modifica();
             virtual bool cercaLuogo(string)=0;
             virtual bool cercaPersona(string,string)=0;
};

#endif
             
