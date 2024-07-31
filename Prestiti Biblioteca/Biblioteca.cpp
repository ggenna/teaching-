#include <cstdlib>
#include <iostream>
#include "Biblioteca.h"
#include "Libro.h"
#include "Utente.h"

using namespace std;


Biblioteca::Biblioteca(int num_libri, int num_utenti)
{
    i_libri=0;
    if(num_libri<0) num_libri=3000;
    maxlibri=num_libri;
    
    i_utenti=0;
    if(num_utenti<0) num_utenti=100;
    maxutenti=100;
    
    libri=new Libro[maxlibri];
    utenti=new Utente[maxutenti];
}


Biblioteca::Biblioteca(const Biblioteca& x){
	maxlibri=x.getMaxLibri();
	maxutenti=x.getMaxUtenti();
	i_libri=x.getNumLibri();
	i_utenti=x.getNumUtenti();
	
}

Biblioteca::~Biblioteca(){
	delete[] libri;
	delete[] utenti;
}

void Biblioteca::setMaxLibri(int x)
{
     if(x>=0) maxlibri=x;
}

void Biblioteca::setMaxUtenti(int x)
{
     if(x>=0) maxutenti=x;
}
    
    
    
void Biblioteca::AggiungiLibro(){
	//sarebbe buono inserire un messaggio che indica che siamo in fase di inserimento dati di un libro
	cout << "Inserire il codice isbn del libro: ";
	string isbn;
	cin >> isbn;
	cout << "Inserire l'autore del libro: ";
	string autore, titolo, casa_editrice;
	cin >> autore;
	cout << "Inserire il titolo del libro: ";
	cin >> titolo;
	cout << "Inserire la casa editrice del libro: ";
	cin >> casa_editrice;

	Libro* l = new Libro(isbn, autore, titolo, casa_editrice);
//	l->rendiDisponibile();
	libri[i_libri++]=*l;
	cout << endl << "Libro inserito con successo!!" << endl;
}//qua si potrebbe porre tutto in un ciclo limitato dal numero di libri massimo che si possono inserire; raggiunto il massimo, il metodo non esegue più nessuna istruzione
void Biblioteca::AggiungiUtente(){
	//sarebbe buono inserire un messaggio che indica che siamo in fase di inserimento dati di un utente
	cout << "Inserire il codice dell'utente: ";
	string codice;
	cin >> codice;
	cout << "Inserire il nome dell'utente: ";
	 string nome, cognome, data_nascita, telefono;
	cin >> nome;
	cout << "Inserire il cognome dell'utente: ";
	cin >> cognome;
	cout << "Inserire la data di nascita dell'utente: ";
	cin >> data_nascita;
	cout << "Inserire il numero di telefono dell'utente: ";
	cin >> telefono;

	Utente* u = new Utente(codice, nome, cognome, data_nascita, telefono);
	u->setNumLibriPresi(0);
	utenti[i_utenti++]=*u;
	cout << endl << "Utente inserito con successo!!" << endl;
}//qua si potrebbe porre tutto in un ciclo limitato dal numero di utenti massimo che si possono inserire; raggiunto il massimo, il metodo non esegue più nessuna istruzione
void Biblioteca::Prestito(){
	cout << "Inserisci il codice utente cui si vuole effettuare il prestito: ";
	string codice;
	cin >> codice;
	int i;
	for(i=0; i<i_utenti; i++) {		//servirebbe un controllo che indichi se l'utente effettivamente esista o meno
		if(utenti[i].getCodice()==codice) {
			utenti[i].stampa();
			break;
		}
	}		//utente trovato
	char cc='\0';
	for(int j=0; j<i_libri && cc!='n'; j++) {
	//aggiungere il controllo che il libro richiesto sia prestabile
		libri[j].stampa();
		cout << endl << "E' questo il libro da prestare? (y/n) ";
		cin >> cc;
		if(cc=='y') { //effettua il prestito
			libri[j].rendiNonDisponibile();
			utenti[i].prendiLibro(&libri[i_libri]);
			cout << endl << "Prestito effettuato con successo!!" << endl;
		}
	}
}
void Biblioteca::restituzione(){
	cout << "Inserisci il codice dell'utente di cui si vuole far restituire il prestito: ";
	string codice;
	cin >> codice;
	int i;
	for(i=0; i<i_utenti; i++) {		//servirebbe un controllo che indichi se l'utente effettivamente esista o meno
		if(utenti[i_utenti].getCodice()==codice) {
			utenti[i_utenti].stampa();
			break;
		}
	}		//utente trovato
	char cc='\0';
	for(int j=0; j<utenti[i].getNumLibriPresi() && cc!='n'; j++) {
		utenti[i].stampaLibro(j);
		cout << endl << "E' questo il libro da prestare? (y/n) ";
		cin >> cc;
		if(cc=='y') { //effettua la restituzione
			utenti[i].restituisciLibro(j);
			cout << endl << "Restituzione libro effettuato con successo!!" << endl;
			break;
		}
	}
}
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
