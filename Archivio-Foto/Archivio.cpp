#include <cstdlib>
#include <iostream>

using namespace std;

#include "Foto.h"
#include "Panorama.h"
#include "Ritratto.h"
#include "Persona.h"
#include "Archivio.h"

Archivio::Archivio(int n)
{
    max=n;
    pos=0;
    
    immagini=new Foto*[max];
    for(int i=0;i<max;i++)
    immagini[i]=0;
    
};

Archivio::~Archivio()
{
     for(int i=0;i<pos;i++)
     delete immagini[i];
     delete[] immagini;
}


void Archivio::addRitratto()
{
     string f,d,n,c,na;
     int xpos,ypos;
     
     cout<<"Nome File: ";
     cin>>f;
     cout<<"Data creazione: ";
     cin>>d;
      cout<<"risx: ";
     cin>>xpos;
     cout<<"risy: ";
     cin>>ypos;
     cout<<"Nome soggetto: ";
     cin>>n;
     cout<<"Cognome soggetto: ";
     cin>>c;
     cout<<"Data di nascita soggetto: ";
     cin>>na;
     
     if(pos<max)
         immagini[pos++]=new Ritratto(f,d,xpos,ypos,n,c,na);
         
}

void Archivio::addPanorama()
{
     string f,d,l;
     int xpos,ypos;
     
     cout<<"Nome File: ";
     cin>>f;
     cout<<"Data creazione: ";
     cin>>d;
     cout<<"risx: ";
     cin>>xpos;
     cout<<"risy: ";
     cin>>ypos;
     cout<<"Luogo: ";
     cin>>l;

     
     if(pos<max)
         immagini[pos++]=new Ritratto(f,d,xpos,ypos,l);
         
}


void Archivio::modificafoto()
{
     string nf;
     Foto* f=0;
     cout<<"Nome file: ";
     cin>>nf;
     for(int i=0;i<pos;i++)
     {
             if(immagini[i]!=0)
               if(nf==immagini[i]->getnomefile())
               { cout<<"Foto Trovata"<<endl;
                 immagini[i]->stampa();
                                                 
               f=immagini[i];
               break; }
     }
     
     if(f==0){
     cout<<"Foto non trovata"<<endl;
     return; }
     f->modifica();
 
}

void Archivio::ricercaluogo()      
{
     string l;
     cout<<"Inserisci luogo: ";
     cin>>l;
     for(int i=0;i<pos;i++)
     {
        if(immagini[i]->cercaLuogo(l))
           immagini[i]->stampa();
     }
}

void Archivio::ricercasoggetto()
{
     string no,co;
     cout<<"Inserisci il nome del soggetto: ";
     cin>>no;
     cout<<"Inserisci il cognome del soggetto: ";
     cin>>co;
     for(int i=0;i<pos;i++)
     {
             if(immagini[i]->cercaPersona(no,co))
             immagini[i]->stampa();
     }
}
   
   
void Archivio::stampa()        
{
     for(int i=0;i<pos;i++)
     immagini[i]->stampa();
}     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
