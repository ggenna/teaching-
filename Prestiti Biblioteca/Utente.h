#include <cstdlib>
#include <iostream>
#include "Libro.h"
#include <vector>
using std::vector;

using namespace std;

#ifndef UTENTE_H
#define UTENTE_H

class Utente
{
      private:
              string cod,nome,cognome,data,telefono;
              int numlibripresi;
              vector<Libro*> LibriPresi;
      public:
             Utente(string="",string="",string="",string="",string="");
             void setCodice(string);
	       	 void setNome(string);
   	         void setCognome(string);
		     void setDataNascita(string);
		     void setTelefono(string);
		     void setNumLibriPresi(int);
		     string getCodice() const{ return cod;}
		     string getNome() const{ return nome;}
		     string getCognome() const{ return cognome;}
		     string getDataNascita() const{ return data;}
		     string getTelefono() const{ return telefono;}
		     int getNumLibriPresi() const{ return numlibripresi;}
		
		     void prendiLibro(Libro*);		//prende libro in prestito
		     void stampaLibro(int);		//stampa il libro int preso in prestito
		     void restituisciLibro(int);	//restituisce il libro int preso in prestito, rendendolo di nuovo disponibile tramite il puntatore contenuto in libriPresi
				
		     void stampa() const;
		     
};

#endif
