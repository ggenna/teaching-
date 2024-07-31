#include <cstdlib>
#include <iostream>

using namespace std;

#include "Ritratto.h"
#include "Persona.h"

Ritratto::Ritratto(string n,string d,int xpos,int ypos,string no,string co,string na):Foto(n,d,xpos,ypos),soggetto(no,co,na){;}

void Ritratto::stampa()
{
     Foto::stampa();
    cout<<"Persona: "<<soggetto<<endl;
    
}

void Ritratto::modifica()
{
     Foto::modifica();
     soggetto.modifica();
}

bool Ritratto::cercaLuogo(string l)
{
     return false;
}

bool Ritratto::cercaPersona(string n,string c)
{
     if(soggetto.getnome()==n && soggetto.getcognome()==c)
       return true;
     else
     return false;
}








