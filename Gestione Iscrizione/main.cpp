#include <cstdlib>
#include <iostream>
#include "Esame.h"
#include "Studente.h"
#include "Docente.h"
#include "StudenteS.h"
#include "Persona.h"

using namespace std;

int main(int argc, char *argv[])
{
    
    Studente s1("Mario","Rossi","14/08/1986","Ingegneria Informatica");
    Studente s2("Luca","Neri","13/12/1982","Ingegneria Elettronica");
    Studente s3("Giovanni","Zambrotta","26/03/1988","Ingegneria Chimica");
    StudenteS s4("Antonio","Ingrassia","24/07/1990","Ingegneria Informatica","Ingegneria Informatica");
    Docente d("Roberto","Di Girolamo","21/11/1960","Fisica-Matematica");
    cout <<s1<< endl;
	cout <<s2<< endl;
	cout <<s3<< endl;
	cout <<s4<< endl;
	cout <<d<< endl;  
	cout<<endl<<endl;
    Esame e("Fisica",d,"14/01/04");
    cout<<endl<<endl;
    e.iscrivi(s1);
    e.iscrivi(s2);
    e.iscrivi(s3);
    e.iscrivi(s4);    
    e.stampa();  
    system("PAUSE");
    return EXIT_SUCCESS;
}
