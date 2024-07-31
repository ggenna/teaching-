#include"Pesce.h"

Pesce::Pesce(char *n,const int pr,const int pe,const int num,const int vel)
:profondita(pr),peso(pe),numero(num),velocita(vel),vivo(true)
{
	nome =new char[30];
	angolo = rand() % 360;
	posX = Lago::X_SIZE;
	posY = Lago::Y_SIZE;

}
//void Pesce::nuota()
//{
