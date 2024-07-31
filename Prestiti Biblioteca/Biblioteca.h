#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
//using namespace std;
//#include <cstdlib>
//#include <iostream>

#include "Utente.h"
#include "Libro.h"

class Biblioteca
{
      private:
              Libro* libri;
              Utente* utenti;
              int i_libri;
              int i_utenti;
              int maxlibri;
              int maxutenti;
      public:
             Biblioteca(int=3000, int=100);
             Biblioteca(const Biblioteca&);
             ~Biblioteca();
     	     void setMaxLibri(int);
             void setMaxUtenti(int);
		     int getMaxLibri() const{ return maxlibri;}
		     int getMaxUtenti() const{ return maxutenti;}
		     int getNumLibri() const{ return i_libri;}		//restituisce il numero di libri inseriti
		     int getNumUtenti() const{ return i_utenti;}
             void AggiungiLibro();
             void AggiungiUtente();
             void Prestito();
             void restituzione();
           //  void stampa();

};


#endif








