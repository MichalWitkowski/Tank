#include"cBullet.h"


cBullet::cBullet(float P1, float P2, float _kat)
{
	x = P1;
	y = P2;
	kat = _kat;
	czyistnieje = 0;
}

void cBullet::draw()		//rysowanie pocisku
{
	if (czyistnieje == 1)	
	{

		float width = 0.05;		//wymiary pocisku
		float height = 0.05;
		glPushMatrix();

		glTranslated(x, y, 0.0);

		glRotated(kat, 0.0, 0.0, 1.0);

		glColor3d(0.0, 0.0, 1.0);

		glBegin(GL_POLYGON);
		{
			glVertex3d(-width / 2, height / 2, 0);
			glVertex3d(width / 2, height / 2, 0);
			glVertex3d(width / 2, -height / 2, 0);
			glVertex3d(-width / 2, -height / 2, 0);
		}
		glEnd();
		glPopMatrix();

	}
}

void cBullet::move()		//poruszanie sie pocisku
{
	if (czyistnieje == 1)
	{
		x += 0.05*cos((kat/180.0)*3.14);		//po osi x zgodnie z zasada rzutu ukosniego
		y += 0.05*sin((kat/180.0)*3.14);		//po osi y zgodnie z zasada rzutu ukosniego

		if (x > 5 || x<-5 || y>5 || y < -5)		//jak wyjdzie poza ekran to przestaje istniec
		{
			czyistnieje = 0;
			x = 0;
			y = 0;

		}
	}
}

