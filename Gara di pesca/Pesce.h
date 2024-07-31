#ifndef PESCE_H
#define PESCE_H

#include<iostream>
#include<string>
#include"Lago.h"

using namespace std;

class Pesce
{
//	friend class Lago;
public:
	Pesce(char *nome ,const int profondita,const int peso,const int numero,const int vel);

    virtual void nuota();
	void pescato(){vivo = false;}
	bool if_vivo ()const{return vivo;}

protected:
    const int profondita,peso,numero,velocita;
	int angolo, posX,posY;

private:
    char  *nome;
	bool vivo;
};
#endif

