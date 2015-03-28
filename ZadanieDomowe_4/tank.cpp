#include"tank.h"

using namespace std;



void cCzolg::DrawRectangle(float  w, float h)		//rysowanie porstokata
{

	
	glPushMatrix();
	// TODO
	// test functions below (glTranslated, glRotated, glColor3d) - what happen when you change their arguments?
	// does their order change the result?
	glTranslated(0, 0, 0.0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(0, 0.0, 0.0, 1.0);

	glColor3d(1.0, 0.0, 0.0);

	glBegin(GL_POLYGON);
	{
		glVertex3d(-w / 2, h / 2, 0);
		glVertex3d(w / 2, h / 2, 0);
		glVertex3d(w / 2, -h / 2, 0);
		glVertex3d(-w / 2, -h / 2, 0);
	}
	glEnd();
	glPopMatrix();
}

void cCzolg::draw()		//rysowanie czolgu z prostokatow
{
	glPushMatrix();
	glTranslated(przesunieciex + pozycjax, pozycjay , 0);
	DrawRectangle(width, height/2);
	glPushMatrix();
	glTranslated(0, 0.5, 0);
	DrawRectangle(width/2, height/2);
	glPushMatrix();
	glRotated(angle, 0, 0, 1.0);
	glTranslated(0.5, 0, 0);
	DrawRectangle(width/2, height/10);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

}

void cCzolg::steruj(char key, char prawo, char lewo,char dol,char gora)		//sterowanie czolgiem
{
	if (key == prawo)		//czolg w prawo
	{
		pozycjax += 0.05;
	}
	else if (key == lewo)		//czolg w lewo
	{
		pozycjax -= 0.05;
	}
	else if (key == dol)		//lufa w dol
	{
		if (angle > 0)		//ograniczenie zeby nie kreci³a sie lufa w kolko
		{

			angle -= 2;
		}
	}
	else if (key == gora)		//lufa w gore
	{
		if (angle < 180)		//ograniczenie zeby lufa nie krecial sie w kolko
		{

			angle += 2;
		}
	}
}

