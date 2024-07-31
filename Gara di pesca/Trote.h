#ifndef TROTE_H
#define TROTE_H

#include<iostream>
#include <string>
#include "Pesce.h"

using namespace std;

class Trote:public Pesce
{
public:
	Trote(char *n,const int profondita,const int peso,const int numero,const int velocita);
    
	virtual void nuota();
private:
	static const int PROFO;
	static const int PESO;
	static const int NUM;
	static const int VEL;
};
#endif
