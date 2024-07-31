//#include <cstdlib>
//#include <iostream>

//using namespace std;

#ifndef LIBRO_H
#define LIBRO_H

#include <string>
using std::string;

class Libro
{
      private:
              string ISBN,autore,titolo,editrice;
              bool disponibile;
      public:
             Libro(string="",string="",string="",string="");
             void setISBN(string);
             void setautore(string);
             void settitolo(string);
             void seteditrice(string);
             string getISBN() const{ return ISBN;}
             string getautore() const{ return autore;}
             string gettitolo() const{ return titolo;}
             string geteditrice() const{ return editrice;}
             void rendiDisponibile();
	       	 void rendiNonDisponibile();
             void stampa() const;
             
};

#endif
             
             
