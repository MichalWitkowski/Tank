
#ifndef BULLET
#define BULLET

#include <GL/freeglut.h>
#include <math.h>

class cBullet
{
public:
	float x, y;
	float kat;


	bool czyistnieje;		//sprawdzenie czy istnieje pocisk
	cBullet(float P1, float P2, float _kat);		

	void move();		//ruch pocisku
	void draw();		//rysowanie  pocisku
};

#endif