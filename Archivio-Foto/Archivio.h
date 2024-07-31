#include <cstdlib>
#include <iostream>

using namespace std;

#ifndef ARCHIVIO_H
#define ARCHIVIO_H

#include "Foto.h"
#include "Panorama.h"
#include "Ritratto.h"
#include "Persona.h"

class Archivio
{
      private:
              Foto** immagini;
              int max;
              int pos;
              
      public:
             Archivio(int=5000);
             ~Archivio();
             void addRitratto();
             void addPanorama();
             void modificafoto();
             void ricercaluogo();
             void ricercasoggetto();
             void stampa();
             
};

#endif


