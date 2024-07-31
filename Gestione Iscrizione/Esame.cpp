#include<iostream>
#include<cstdlib>
#include "Esame.h"

using namespace std;

Esame:: Esame(string i,Docente& d,string dat)
{
        ins=i;
        doc=&d;
        data=dat;
        for(int i=0;i<200;i++)
        iscritti[i]=0;
}

void Esame::iscrivi(Studente& s)
{
     for(int i=0;i<200;i++)
     if(iscritti[i]==0)
     {
         iscritti[i]=&s;
         return;
     }
}

void Esame::stampa()
{
     cout<<"Elenco degli iscritti all'esame di "<<ins<<" "<<"in data "<<data<<endl<<endl;
    for(int i=0;i<200;i++)
      if(iscritti[i]!=0){
      iscritti[i]->print();
      cout<<endl;
      }   
      
}
        

