#include <GL/freeglut.h>

using namespace std;

#ifndef TANK
#define TANK
class cCzolg
{
public:
	float angle;
	float przesunieciex;
	float pozycjax, pozycjay;
	float width, height;
	int punkty;
	cCzolg()
	{
		angle = 20;
		przesunieciex = 0;
		pozycjax = 0;
		pozycjay = 0;
		width = 1;
		height = 1;
		punkty = 0;
	};

	void DrawRectangle(float w,float h);	//rysownie prostokatow
	void draw();		//rysowanie czolgu z prostokatow
	void steruj(char key, char prawo, char lewo, char dol, char gora);		//sterowanie czolgiem

};
#endif