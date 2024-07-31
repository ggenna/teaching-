#ifndef PERSONA_H
#define PERSONA_H

#include<iostream>
#include<cstdlib>

using namespace std;

class Persona
{
      private:
              string nome;
              string cognome;
              string datan;
              friend ostream& operator<<(ostream&, const Persona&);
      public:
             Persona(string,string,string);
             virtual void print() const;
             string getnome() const {return nome;}
             string getcognome() const {return cognome;}
             string getdatan() const {return datan;}
             
             
};

#endif
             
