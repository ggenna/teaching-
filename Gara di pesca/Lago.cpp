#include"Lago.h"

const int Lago::X_SIZE = 90;
const int Lago::Y_SIZE= 90;
const int Lago::PROFO= 4;
Lago::Lago()
{
	for(int i=0;i<90;i++)
	{
		for(int j=0;j<90;j++)
		{
	         m[i][j] = VUOTO;
		}
	}
	 m[45][1] =P1;
	 m[88][45] = P2;
	 m[45][88] =P3;
	 m[1][45] = P4;


}
