#ifndef LAGO_H
#define LAGO_H

#include<iostream>

using namespace std;


class Lago
{
	friend class Pesce;
public:
	Lago();

/*	void setPescatore1();
	void setPescatore2();
	void setPescatore3();
	void setPescatore4();
*/
	static const int X_SIZE;
    static const int Y_SIZE;
	static const int PROFO;

private:
	enum Pescatore {P1,P2,P3,P4,VUOTO};
	Pescatore m[90][90];
	const int profondita;
	
};
#endif