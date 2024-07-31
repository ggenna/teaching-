#include <cstdlib>
#include <iostream>

using namespace std;

#include "Panorama.h"
#include "Foto.h"

Panorama::Panorama(string n,string d,int xpos,int ypos,string l):Foto(n,d,xpos,ypos)
{
    luogo=l;
}

void Panorama::modifica()
{
     Foto::modifica();
     cout<<"Luogo: "<<luogo<<endl;
     cout<<"Inserisci nuovo valore: ";
     cin>>luogo;
}

void Panorama::stampa()
{
     Foto::stampa();
     cout<<"Luogo: "<<luogo<<endl;
}

bool Panorama::cercaLuogo(string l)
{
     
     if(luogo==l)
      return true;
     else
     return false;
}

bool Panorama::cercaPersona(string n,string c)
{
     return false;
}
     
     
     
     
     
     
