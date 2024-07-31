#ifndef STUDENTES_H
#define STUDENTES_H

#include<iostream>
#include<cstdlib>
#include "Persona.h"
#include "Studente.h"

using namespace std;

class StudenteS: public Studente
{
      private:
              string laurea;
              friend ostream& operator<<(ostream&, const StudenteS&);
      public:
             StudenteS(string,string,string,string,string);
             virtual void print() const;
             string getlaurea()const {return laurea;}

};

#endif
             
