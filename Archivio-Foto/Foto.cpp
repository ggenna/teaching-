#include <cstdlib>
#include <iostream>

using namespace std;

#include "Foto.h"

Foto::Foto(string n,string d,int xpos,int ypos)
{
     nome=n;
     data=d;
     x=xpos;
     y=ypos;
cout<<"Costruttore Foto"<<endl;

}

void Foto::stampa()
{
     cout<<"Nome File: "<<nome<<endl;
     cout<<"data creazione: "<<data<<endl;
     cout<<"Risoluzione x: "<<x<<endl;
     cout<<"Risoluzione y: "<<y<<endl;
}

void Foto::modifica()
{
     cout<<"Nome file: "<<nome<<endl;
     cout<<"Inserisci nuovo valore: ";
     cin>>nome;
     cout<<"Data creazione: "<<data<<endl;
     cout<<"Inserisci nuovo valore: ";
     cin>>data;
     cout<<"Risoluzione x: "<<x<<endl;
     cout<<"Inserisci nuovo valore: ";
     cin>>x;
     cout<<"Risoluzione y: "<<y<<endl;
     cin>>y;
}
     
     
     
     
