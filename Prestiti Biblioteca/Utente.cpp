#include <string>
using std::string;
#include <vector>
using std::vector;
#include "Utente.h"
#include "Libro.h"
#include <iostream>
using std::cout;
using std::endl;


Utente::Utente(string c,string n,string cg,string d,string t)
{
        setCodice(c);
        setNome(n);
        setCognome(cg);
        setDataNascita(d);
        setTelefono(t);
        
        numlibripresi=0;
}

void Utente::setCodice(string c)
{
     cod=c;
}

void Utente::setNome(string n)
{
     nome=n;
}

void Utente::setCognome(string cg)
{
     cognome=cg;
}

void Utente::setDataNascita(string d)
{
     data=d;
}

void Utente::setTelefono(string t)
{
     telefono=t;
}

void Utente::setNumLibriPresi(int l)
{
      numlibripresi=l;
}

void Utente::prendiLibro(Libro* l){
	LibriPresi.resize(LibriPresi.size()+1);
	LibriPresi.at(numlibripresi++)=l;
	//LibriPresi.push_back(l);
}//prende libro in prestito

void Utente::stampaLibro(int x){
	LibriPresi.at(x)->stampa();
}//stampa il libro int preso in prestito

void Utente::restituisciLibro(int x){
	LibriPresi.at(x)->rendiDisponibile();
	LibriPresi.at(x)=LibriPresi.at(--numlibripresi);
	LibriPresi.resize(numlibripresi);
}


 
 
void Utente::stampa() const
{
     cout<<"----------------"<<endl;
     cout<<"Dettagli Utente: "<<endl;
     cout<<cod<<" "<<nome<<" "<<cognome<<" "<<data<<" "<<telefono<<endl;
     cout<<"Libri Presi: "<<numlibripresi<<endl;
     
}
