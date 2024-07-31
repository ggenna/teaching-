#include<iostream>
#include<cstdlib>
#include "StudenteS.h"


using namespace std;

StudenteS::StudenteS(string n,string c,string d,string cl,string l):Studente(n,c,d,cl)

{
    laurea=l;
}

void StudenteS:: print() const{

     
   cout<<"Dott: ";
   Persona::print();
}


ostream& operator<<(ostream& os, const StudenteS& ss)
{
         os<<"Dott."<<" "<<ss.laurea<<" "<<ss.getnome()<<" "<<ss.getcognome()<<" ";
         os<<"nato il "<<ss.getdatan()<<"-"<<"Corso di laurea Magistrale in ";
        // os<<ss.getCdL();
         return os;
}


