#include <iostream>
#include"tank.h"
#include"cBullet.h"

#include <GL/freeglut.h>


cCzolg czolg1,czolg2;
cBullet pocisk1(0, 0, 30), pocisk2(0, 0, 0);

/* GLUT callback Handlers */
static void resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

static void idle(void)
{
	glutPostRedisplay();
}

static void display(void)
{
	// clear the scene
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();

	glPushMatrix();
	pocisk1.draw();
	czolg1.draw();
	
	glPopMatrix();

	glPushMatrix();
	
	czolg2.draw();
	pocisk2.draw();
	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}
void keyboard(unsigned char key, int ,int )			//obsluga klawiatury 
{
	czolg1.steruj(key, 'd', 'a','s','w');
	czolg2.steruj(key, 'l', 'j','i','k');
	if (key == 'x'&&pocisk1.czyistnieje == 0)			//wystrzelenie pocisku dla czolgu pierwszego, moze byc jeden pocisk chyba ze wyjdzie poza ekran to dany czolg moze wystrzelic ponownie
	{
		pocisk1.czyistnieje = 1;			// pocisk istnieje
		pocisk1.x = czolg1.pozycjax+czolg1.przesunieciex+0.75*cos(czolg1.angle/180.0*3.14);			//pocisk po osi x
		pocisk1.y = czolg1.pozycjay +0.5+ (0.75*sin(czolg1.angle / 180.0*3.14));		//pocisk po osi y
		pocisk1.kat = czolg1.angle;		//kat pocisku
		
	}

	if (key == 'n'&&pocisk2.czyistnieje == 0)		// pocisk tak samo jak dla pierwszego czolgu
	{
		pocisk2.czyistnieje = 1;
		pocisk2.x = czolg2.pozycjax + czolg2.przesunieciex + 0.75*cos(czolg2.angle / 180.0*3.14);
		pocisk2.y = czolg2.pozycjay + 0.5 + (0.75*sin(czolg2.angle / 180.0*3.14));
		pocisk2.kat = czolg2.angle;

	}
}

void gameLogic(int)
{
	pocisk1.move();		//ruch pocisku pierwszego
	pocisk2.move();		//ruch pocisku drugiego
	

	if (pocisk1.czyistnieje&& pocisk1.x > czolg2.pozycjax+czolg2.przesunieciex - czolg2.width / 4 && pocisk1.x<czolg2.pozycjax +czolg2.przesunieciex + czolg2.width / 4 && pocisk1.y>czolg2.pozycjay + czolg2.height/2 - czolg2.height / 4 && pocisk1.y  < czolg2.pozycjay + czolg2.height/2 + czolg2.height / 4)	//kolizja dla pierwszego czolgu
	{  
		
		
		pocisk1.czyistnieje = 0;		//jak trafi o moze wystrzelic pocisk kolejny
		czolg1.punkty++;		//dodanie punktow czolgowi ktory trafi³
		cout << "Czolg 1 ma punktow: " << czolg1.punkty << endl;		//wyswietlenie punktow danego czolgu
	}

		//kolizja, wszystko tak samo tylko ze dla drugiego czolgu 
	if (pocisk2.czyistnieje&& pocisk2.x > czolg1.pozycjax + czolg1.przesunieciex - czolg1.width / 4 && pocisk2.x<czolg1.pozycjax + czolg1.przesunieciex + czolg1.width / 4 && pocisk2.y>czolg1.pozycjay + czolg1.height / 2 - czolg1.height / 4 && pocisk2.y  < czolg1.pozycjay + czolg1.height / 2 + czolg1.height / 4)
	{

		
		pocisk2.czyistnieje = 0;
		czolg2.punkty++;
		cout << "Czolg 2 ma punktow: "<<czolg2.punkty << endl;
	}
	glutTimerFunc(25, gameLogic, 0);
}

int main(int argc, char *argv[])
{
	// it's still possible to use console to print messages
	printf("Hello openGL world!\n");
	// the same can be done with cout / cin
	czolg1.przesunieciex = -2;		//poczatkowa pozycja czolgu pierwszego
	czolg2.przesunieciex = 2;		//poczatkowa pozycja czolgu drugiego
	czolg2.angle = 160;			//polozenie lufy czolgu pierwszego
	czolg2.width = 2;			//zmana szerokosci dla czolgu drugiego

	
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(40, 40);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow("OpenGLUT Shapes");

	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(25, gameLogic, 0);

	// set white as the clear colour
	glClearColor(1, 1, 1, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glutMainLoop();

	return 0;
}