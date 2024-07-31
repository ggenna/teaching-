#include <cstdlib>
#include <iostream>
#include "Biblioteca.h"

using namespace std;

int main(int argc, char *argv[])
{
    Biblioteca bb(10, 4);
	while(1) {
		bb.AggiungiLibro();
		cout << endl << endl;
		bb.AggiungiUtente();
		cout << endl << endl;
		bb.Prestito();
		cout << endl << endl;
		bb.restituzione();
		cout << endl << endl;
	}
    system("PAUSE");
    return EXIT_SUCCESS;
}
