#include <cstdlib>
#include <iostream>

using namespace std;

#include "Foto.h"
#include "Panorama.h"
#include "Ritratto.h"
#include "Persona.h"
#include "Archivio.h"

int main(int argc, char *argv[])
{
    
    Archivio aa;
    char cc;
    
    while(1)
    {
           cout<<"1)Aggiungi nuovo Panorama"<<endl;
           cout<<"2)Aggiungi nuovo Ritratto"<<endl;
           cout<<"3)Modifica Foto"<<endl;
           cout<<"4)Ricerca per Luogo"<<endl;
           cout<<"5)Ricerca per Soggetto"<<endl;
           cout<<"6)Stampa Tutto"<<endl;
           cout<<"7)Esci"<<endl;
           
           cin>>cc;
           
           switch(cc)
           {
                     case '1':
                          aa.addRitratto();
                          break;
                     case '2':
                          aa.addPanorama();
                          break;
                     case '3':
                          aa.modificafoto();
                          break;
                     case '4':
                          aa.ricercaluogo();
                          break;
                     case '5':
                          aa.ricercasoggetto();
                          break;
                     case '6':
                          aa.stampa();
                          break;
                     case '7':
                          return 0;
                     
                     default:
                             cout<<"Scelta non disponibile"<<endl;
                             system("pause");
                             break;
           }
           
     }
     
 
            
            
                    
    system("PAUSE");
    return EXIT_SUCCESS;
}
