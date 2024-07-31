#include <cstdlib>
#include <iostream>
#include "Libro.h"

using namespace std;



Libro::Libro(string is,string a,string t,string e)
{
        setISBN(is);
        setautore(a);
        settitolo(t);
        seteditrice(e);
}

void Libro::setISBN(string is)
{
     ISBN=is;
}

void Libro::setautore(string a)
{
     autore=a;
}

void Libro::settitolo(string t)
{
     titolo=t;
}

void Libro::seteditrice(string e)
{
     editrice=e;
}

void Libro::rendiDisponibile()
{
     disponibile=true;
}

void Libro::rendiNonDisponibile()
{
     disponibile=false;
}

void Libro::stampa() const
{
     cout<<"----------------"<<endl;
     cout<<"Dettagli Libro: "<<endl;
     cout<<ISBN<<" "<<autore<<" "<<titolo<<" "<<editrice<<endl;
     cout<<"Disponibilita': ";
     cout<<(disponibile?"si":"no")<<endl;
     
     
}
     
