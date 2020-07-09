#include "glew.h"
#include "freeglut.h"
//#include "GL/glew.h"
//#include "GL/freeglut.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int skor = 0;
int kalanhak = 3;
int h_speed_boost = 1;  // helikopterin ekstra hýzý 

//helikopterlerin mesafe
float _distance_helicopter = 0;
float _distance_helicopter_iki = 0;
float _distance_helicopter_üc = 0;
float _distance_helicopter_dört = 0;

//int score = 0;
//1. helikopter üst pervane 
float h1_upper_left1x = 22 , h1_upper_left1y = 320, h1_upper_left2x = 0, h1_upper_left2y = 330, h1_upper_right1x= 22, h1_upper_right1y= 330, h1_upper_right2x= 0, h1_upper_right2y= 320;
float h1_upper_xspeed = 0, h1_upper_yspeed = 0;
float h1_upper_xspeed1 = 0, h1_upper_yspeed1 = 0;
//1.helikopter alt pervane
float h1_lower_left1x = 50, h1_lower_left1y = 304, h1_lower_left2x = 39, h1_lower_left2y = 310, h1_lower_right1x = 50, h1_lower_right1y = 310, h1_lower_right2x = 39, h1_lower_right2y = 304;
float h1_lower_xspeed = 0, h1_lower_yspeed = 0;
float h1_lower_xspeed1 = 0, h1_lower_yspeed1 = 0;
//2.helikopterin üst pervane
float h2_upper_left1x = 50, h2_upper_left1y = 410, h2_upper_left2x = 28, h2_upper_left2y = 420, h2_upper_right1x = 50, h2_upper_right1y = 420, h2_upper_right2x = 28, h2_upper_right2y = 410;
float h2_upper_xspeed = 0, h2_upper_yspeed = 0;
float h2_upper_xspeed1 = 0, h2_upper_yspeed1 = 0;
//2.helikopterin alt pervane
float h2_lower_left1x = 10, h2_lower_left1y = 394, h2_lower_left2x = 1, h2_lower_left2y = 400, h2_lower_right1x = 10, h2_lower_right1y = 400, h2_lower_right2x = 1, h2_lower_right2y = 394;
float h2_lower_xspeed = 0, h2_lower_yspeed = 0;
float h2_lower_xspeed1 = 0, h2_lower_yspeed1 = 0;
//3.helikopterin üst pervane
float h3_upper_left1x = 22, h3_upper_left1y = 500, h3_upper_left2x = 0, h3_upper_left2y = 510, h3_upper_right1x = 22, h3_upper_right1y = 510, h3_upper_right2x = 0, h3_upper_right2y = 500;
float h3_upper_xspeed = 0, h3_upper_yspeed = 0;
float h3_upper_xspeed1 = 0, h3_upper_yspeed1 = 0;
//3.helikopterin alt pervane
float h3_lower_left1x = 50, h3_lower_left1y = 484, h3_lower_left2x = 39, h3_lower_left2y = 490, h3_lower_right1x = 50, h3_lower_right1y = 490, h3_lower_right2x = 39, h3_lower_right2y = 484;
float h3_lower_xspeed = 0, h3_lower_yspeed = 0;
float h3_lower_xspeed1 = 0, h3_lower_yspeed1 = 0;
//4.helikopterin üst pervane
float h4_upper_left1x = 50, h4_upper_left1y = 590, h4_upper_left2x = 28, h4_upper_left2y = 600, h4_upper_right1x = 50, h4_upper_right1y = 600, h4_upper_right2x = 28, h4_upper_right2y = 590;
float h4_upper_xspeed = 0, h4_upper_yspeed = 0;
float h4_upper_xspeed1 = 0, h4_upper_yspeed1 = 0;
//4.helikopterin alt pervane
float h4_lower_left1x = 10, h4_lower_left1y = 574, h4_lower_left2x = 1, h4_lower_left2y = 580, h4_lower_right1x = 10, h4_lower_right1y = 580, h4_lower_right2x = 1, h4_lower_right2y = 574;
float h4_lower_xspeed = 0, h4_lower_yspeed = 0;
float h4_lower_xspeed1 = 0, h4_lower_yspeed1 = 0;

float xr = 0, yr = 0;
//helikopterlerin baþlangýc hýzlarý
float helicopter_speed = 430;
float helicopter_speed_iki = 0;
float helicopter_speed_üc = 430;
float helicopter_speed_dört = 0;
//ucak ve helikopterlerin orta noktalarý
float ucakortax;
float ucakortay;
float h1ortax;
float h1ortay = 305; //280 + 25 
float h2ortax;
float h2ortay = 395; // 370 + 25
float h3ortax;
float h3ortay = 485;  // 460 +25
float h4ortax;
float h4ortay = 575;  //550 +25

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 480.0, 0.0, 640.0);
	glMatrixMode(GL_MODELVIEW);
}

void key_input(int key, int x, int y) {

	switch (key)
	{
	case GLUT_KEY_UP:
		if (yr < 590)
		{
			yr = yr + 10;
			cout << yr << endl;
		}
		break;
	case GLUT_KEY_DOWN:
		if (yr > 0)
		{
			yr = yr - 10;
			cout << yr << endl;
		}
		break;
	case GLUT_KEY_LEFT:
		if (xr > 0)
		{
			xr = xr - 10;
			cout << xr << endl;
		}
		break;
	case GLUT_KEY_RIGHT:
		if (xr < 430)
		{
			xr = xr + 10;
			cout << xr << endl;
		}
		break;

	}
}

void enter(unsigned char key, int x, int y) {
	if (key == 13 && kalanhak == 0)
	{
		kalanhak = 3;
		skor = 0;
		xr = 0;
		yr = 0;
		h_speed_boost = 1;
		glutPostRedisplay();
	}
}

void airplane () {
	glLoadIdentity();
	srand(time(0));
	glColor3ub(rand() % 255, rand() % 255, rand() % 255);
	glBegin(GL_QUADS);

	glVertex2f(21 +xr, 0+yr);
	glVertex2f(21 +xr, 50+yr);
	glVertex2f(29 +xr, 50+yr);
	glVertex2f(29 +xr, 0+yr);

	glVertex2f(0+xr, 32+yr);
	glVertex2f(50+xr, 32+yr);
	glVertex2f(50+xr, 40+yr);
	glVertex2f(0+xr, 40+yr);

	glVertex2f(15+xr, 5+yr);
	glVertex2f(15+xr, 13+yr);
	glVertex2f(35+xr,5+yr);
	glVertex2f(35+xr, 13+yr);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1.5f);
	glBegin(GL_POINTS);
	glVertex2f(25 +xr , 25 +yr);
	glEnd();
	glutPostRedisplay();

	if (yr > 550)
	{
		xr = 430 - xr ;
		yr = 0;
		skor = skor + 10;
		h_speed_boost = h_speed_boost + 1;
	}
}

void helicopter (){      // Y Ekseni 280 - 330 1.helikopter 
	glLoadIdentity();
	helicopter_speed = helicopter_speed - 0.009 * h_speed_boost;
	glTranslated(helicopter_speed, 0.0, 0.0);

	if (helicopter_speed < 0)
	{
		helicopter_speed = 430;
	}
	
	glBegin(GL_POLYGON);  //1 Gövdesi
	glColor3f(255, 255, 0);

	glPointSize(10.0f);
	glVertex2i(3, 294);
	glVertex2i(3, 316);
	glVertex2i(25, 316);
	glVertex2i(25, 294);
	glEnd();

	glBegin(GL_QUADS);  //2 gövdesinin iç karesi
	glColor3f(1, 1, 1);
	glPointSize(10.0f);
	glVertex2i(5, 305);
	glVertex2i(5, 314);
	glVertex2i(15, 314);
	glVertex2i(15, 305);
	glEnd();

	glBegin(GL_QUADS);   //3 üstü
	glColor3f(255, 255, 0);
	glPointSize(10.0f);
	glVertex2i(12,316);
	glVertex2i(12, 324);
	glVertex2i(16, 324);
	glVertex2i(16, 316);
	glEnd();

	glBegin(GL_QUADS);   // 4
	glColor3f(255, 255, 0);
	glPointSize(10.0f);
	glVertex2i(25, 302);
	glVertex2i(25, 308);
	glVertex2i(45, 308);
	glVertex2i(45, 302);
	glEnd();

	glBegin(GL_QUADS);  // 5
	glColor3f(255, 255, 0);
	glPointSize(10.0f);
	glVertex2i(43, 303);
	glVertex2i(43, 307);
	glVertex2i(47, 307);
	glVertex2i(47, 303);
	glEnd();

	glBegin(GL_QUADS);  //6
	glColor3f(0, 0, 0);
	glPointSize(10.0f);
	glVertex2i(3, 280);
	glVertex2i(3, 284);
	glVertex2i(25, 284);
	glVertex2i(25, 280);
	glEnd();

	glBegin(GL_QUADS); //7
	glColor3f(0, 0, 0);
	glPointSize(10.0f);
	glVertex2i(7, 284);
	glVertex2i(7, 298);
	glVertex2i(11, 298);
	glVertex2i(11, 284);
	glEnd();

	glBegin(GL_QUADS); // 8
	glColor3f(0, 0, 0);
	glPointSize(10.0f);
	glVertex2i(17, 284);
	glVertex2i(17, 298);
	glVertex2i(21, 298);
	glVertex2i(21, 284);
	glEnd();

	glBegin(GL_LINES); //ÜSt pervane Siyah renk
	glColor3f(0, 0, 0);
	glVertex2f(h1_upper_right1x, h1_upper_right1y); // x1,y1
	glVertex2f(h1_upper_right2x, h1_upper_right2y); // x2 , y2

	glVertex2f(h1_upper_left1x, h1_upper_left1y);
	glVertex2f(h1_upper_left2x, h1_upper_left2y);
	glEnd();

	glBegin(GL_LINES); // alt pervane Siyah renk
	glColor3f(0, 0, 0);
	glVertex2f(h1_lower_left1x, h1_lower_left1y);
	glVertex2f(h1_lower_left2x, h1_lower_left2y);

	glVertex2f(h1_lower_right1x, h1_lower_right1y);
	glVertex2f(h1_lower_right2x, h1_lower_right2y);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1.5f);
	glBegin(GL_POINTS);
	glVertex2f(25, h1ortay);
	glEnd();
	
	//üst pervane sað için
	if (h1_upper_right2x == 22 && h1_upper_right2y == 320)
	{
		h1_upper_xspeed1 = -2.5;
		h1_upper_yspeed1 = 0;
	}
	else if (h1_upper_right2x == 0 && h1_upper_right2y == 330) {
		h1_upper_xspeed1 = 0;
		h1_upper_yspeed1 = -2.5;
	}
	else if (h1_upper_right2x == 22 && h1_upper_right2y == 330) {
		h1_upper_xspeed1 = 2.5;
		h1_upper_yspeed1 = 0;
	}
	else if (h1_upper_right2x == 0 && h1_upper_right2y == 320)
	{
		h1_upper_xspeed1 = 0;
		h1_upper_yspeed1 = 2.5;
	}
	h1_upper_right2x = h1_upper_right2x + h1_upper_xspeed1;
	h1_upper_right2y = h1_upper_right2y + h1_upper_yspeed1;

	h1_upper_right1x = h1_upper_right1x - h1_upper_xspeed1;
	h1_upper_right1y = h1_upper_right1y - h1_upper_yspeed1;

	//üst pervane sol için
	if (h1_upper_left2x == 22 && h1_upper_left2y == 320)
	{
		h1_upper_xspeed = -2.5;
		h1_upper_yspeed = 0;
	}
	else if (h1_upper_left2x == 0 && h1_upper_left2y == 330) {
		h1_upper_xspeed = 0;
		h1_upper_yspeed = -2.5;
	}
	else if (h1_upper_left2x == 22 && h1_upper_left2y == 330) {
		h1_upper_xspeed = 2.5;
		h1_upper_yspeed = 0;
	}
	else if (h1_upper_left2x == 0 && h1_upper_left2y == 320)
	{
		h1_upper_xspeed = 0;
		h1_upper_yspeed = 2.5;
	}
	h1_upper_left2x = h1_upper_left2x + h1_upper_xspeed;
	h1_upper_left2y = h1_upper_left2y + h1_upper_yspeed;

	h1_upper_left1x = h1_upper_left1x - h1_upper_xspeed;
	h1_upper_left1y = h1_upper_left1y - h1_upper_yspeed;

	// alt pervane sag için

	if (h1_lower_right2x == 50 && h1_lower_right2y == 304)
	{
		h1_lower_xspeed1 = -1;
		h1_lower_yspeed1 = 0;
	}
	else if (h1_lower_right2x == 39 && h1_lower_right2y == 310) {
		h1_lower_xspeed1 = 0;
		h1_lower_yspeed1 = -1;
	}
	else if (h1_lower_right2x == 50 && h1_lower_right2y == 310) {
		h1_lower_xspeed1 = 1;
		h1_lower_yspeed1 = 0;
	}
	else if (h1_lower_right2x == 39 && h1_lower_right2y == 304)
	{
		h1_lower_xspeed1 = 0;
		h1_lower_yspeed1 = 1;
	}
	h1_lower_right2x = h1_lower_right2x + h1_lower_xspeed1;
	h1_lower_right2y = h1_lower_right2y + h1_lower_yspeed1;

	h1_lower_right1x = h1_lower_right1x - h1_lower_xspeed1;
	h1_lower_right1y = h1_lower_right1y - h1_lower_yspeed1;

	// alt pervane sol için

	if (h1_lower_left2x == 50 && h1_lower_left2y == 304)
	{
		h1_lower_xspeed = -1;
		h1_lower_yspeed = 0;
	}
	else if (h1_lower_left2x == 39 && h1_lower_left2y == 310) {
		h1_lower_xspeed = 0;
		h1_lower_yspeed = -1;
	}
	else if (h1_lower_left2x == 50 && h1_lower_left2y == 310) {
		h1_lower_xspeed = 1;
		h1_lower_yspeed = 0;
	}
	else if (h1_lower_left2x == 39 && h1_lower_left2y == 304)
	{
		h1_lower_xspeed = 0;
		h1_lower_yspeed = 1;
	}
	h1_lower_left2x = h1_lower_left2x + h1_lower_xspeed;
	h1_lower_left2y = h1_lower_left2y + h1_lower_yspeed;

	h1_lower_left1x = h1_lower_left1x - h1_lower_xspeed;
	h1_lower_left1y = h1_lower_left1y - h1_lower_yspeed;
}

void helicopter_iki() {     //370 - 420 2. helikopter
	glLoadIdentity();
	helicopter_speed_iki = helicopter_speed_iki + 0.009 * h_speed_boost;
	glTranslated(helicopter_speed_iki, 0.0, 0.0);
	if (helicopter_speed_iki > 430) {
		
		helicopter_speed_iki = 0;
	}

	glBegin(GL_POLYGON);  //1 Gövdesi
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(10.0f);
	glVertex2i(25, 384);
	glVertex2i(25, 406);
	glVertex2i(47, 406);
	glVertex2i(47, 384);
	glEnd();

	glBegin(GL_QUADS);  //2 gövdesinin iç karesi
	glColor3f(1, 1, 1);
	glPointSize(10.0f);
	glVertex2i(36, 395);
	glVertex2i(36, 404);
	glVertex2i(45, 404);
	glVertex2i(45, 395);
	glEnd();

	glBegin(GL_QUADS);   //3 üstü
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(10.0f);
	glVertex2i(34, 406);
	glVertex2i(34, 414);
	glVertex2i(38, 414);
	glVertex2i(38, 406);
	glEnd();

	glBegin(GL_QUADS);   // 4
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(10.0f);
	glVertex2i(5, 392);
	glVertex2i(5, 398);
	glVertex2i(25, 398);
	glVertex2i(25, 392);
	glEnd();

	glBegin(GL_QUADS);  // 5
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(10.0f);
	glVertex2i(3, 393);
	glVertex2i(3, 397);
	glVertex2i(7, 397);
	glVertex2i(7, 393);
	glEnd();

	glBegin(GL_QUADS);  //6
	glColor3f(0, 0, 0);
	glPointSize(10.0f);
	glVertex2i(25, 370);
	glVertex2i(25, 374);
	glVertex2i(47, 374);
	glVertex2i(47, 370);
	glEnd();

	glBegin(GL_QUADS); //7
	glColor3f(0, 0, 0);
	glPointSize(10.0f);
	glVertex2i(29, 374);
	glVertex2i(29, 388);
	glVertex2i(33, 388);
	glVertex2i(33, 374);
	glEnd();

	glBegin(GL_QUADS); // 8
	glColor3f(0, 0, 0);
	glPointSize(10.0f);
	glVertex2i(39, 374);
	glVertex2i(39, 388);
	glVertex2i(43, 388);
	glVertex2i(43, 374);
	glEnd();

	glBegin(GL_LINES); //ÜSt pervane Siyah renk
	glColor3f(0, 0, 0);
	glVertex2f(h2_upper_right1x, h2_upper_right1y);
	glVertex2f(h2_upper_right2x, h2_upper_right2y);

	glVertex2f(h2_upper_left1x, h2_upper_left1y);
	glVertex2f(h2_upper_left2x, h2_upper_left2y);
	glEnd();

	glBegin(GL_LINES); //Sol pervane Siyah renk
	glColor3f(0, 0, 0);
	glVertex2f(h2_lower_left1x, h2_lower_left1y);
	glVertex2f(h2_lower_left2x, h2_lower_left2y);

	glVertex2f(h2_lower_right1x, h2_lower_right1y);
	glVertex2f(h2_lower_right2x, h2_lower_right2y);
	glEnd();
	
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1.5f);
	glBegin(GL_POINTS);
	glVertex2f(25, h2ortay);
	glEnd();

	//üst pervane sað için
	if (h2_upper_right2x == 50 && h2_upper_right2y == 410)
	{
		h2_upper_xspeed1 = -2.5;
		h2_upper_yspeed1 = 0;
	}
	else if (h2_upper_right2x == 28 && h2_upper_right2y == 420) {
		h2_upper_xspeed1 = 0;
		h2_upper_yspeed1 = -2.5;
	}
	else if (h2_upper_right2x == 50 && h2_upper_right2y == 420) {
		h2_upper_xspeed1 = 2.5;
		h2_upper_yspeed1 = 0;
	}
	else if (h2_upper_right2x == 28 && h2_upper_right2y == 410)
	{
		h2_upper_xspeed1 = 0;
		h2_upper_yspeed1 = 2.5;
	}
	h2_upper_right2x = h2_upper_right2x + h2_upper_xspeed1;
	h2_upper_right2y = h2_upper_right2y + h2_upper_yspeed1;

	h2_upper_right1x = h2_upper_right1x - h2_upper_xspeed1;
	h2_upper_right1y = h2_upper_right1y - h2_upper_yspeed1;

	//üst pervane sol için
	if (h2_upper_left2x == 50 && h2_upper_left2y == 410)
	{
		h2_upper_xspeed = -2.5;
		h2_upper_yspeed = 0;
	}
	else if (h2_upper_left2x == 28 && h2_upper_left2y == 420) {
		h2_upper_xspeed = 0;
		h2_upper_yspeed = -2.5;
	}
	else if (h2_upper_left2x == 50 && h2_upper_left2y == 420) {
		h2_upper_xspeed = 2.5;
		h2_upper_yspeed = 0;
	}
	else if (h2_upper_left2x == 28 && h2_upper_left2y == 410)
	{
		h2_upper_xspeed = 0;
		h2_upper_yspeed = 2.5;
	}
	h2_upper_left2x = h2_upper_left2x + h2_upper_xspeed;
	h2_upper_left2y = h2_upper_left2y + h2_upper_yspeed;

	h2_upper_left1x = h2_upper_left1x - h2_upper_xspeed;
	h2_upper_left1y = h2_upper_left1y - h2_upper_yspeed;

	// alt pervane sag için

	if (h2_lower_right2x == 10 && h2_lower_right2y == 394)
	{
		h2_lower_xspeed1 = -1;
		h2_lower_yspeed1 = 0;
	}
	else if (h2_lower_right2x == 1 && h2_lower_right2y == 400) {
		h2_lower_xspeed1 = 0;
		h2_lower_yspeed1 = -1;
	}
	else if (h2_lower_right2x == 10 && h2_lower_right2y == 400) {
		h2_lower_xspeed1 = 1;
		h2_lower_yspeed1 = 0;
	}
	else if (h2_lower_right2x == 1 && h2_lower_right2y == 394)
	{
		h2_lower_xspeed1 = 0;
		h2_lower_yspeed1 = 1;
	}
	h2_lower_right2x = h2_lower_right2x + h2_lower_xspeed1;
	h2_lower_right2y = h2_lower_right2y + h2_lower_yspeed1;

	h2_lower_right1x = h2_lower_right1x - h2_lower_xspeed1;
	h2_lower_right1y = h2_lower_right1y - h2_lower_yspeed1;

	// alt pervane sol için

	if (h2_lower_left2x == 10 && h2_lower_left2y == 394)
	{
		h2_lower_xspeed = -1;
		h2_lower_yspeed = 0;
	}
	else if (h2_lower_left2x == 1 && h2_lower_left2y == 400) {
		h2_lower_xspeed = 0;
		h2_lower_yspeed = -1;
	}
	else if (h2_lower_left2x == 10 && h2_lower_left2y == 400) {
		h2_lower_xspeed = 1;
		h2_lower_yspeed = 0;
	}
	else if (h2_lower_left2x == 1 && h2_lower_left2y == 394)
	{
		h2_lower_xspeed = 0;
		h2_lower_yspeed = 1;
	}
	h2_lower_left2x = h2_lower_left2x + h2_lower_xspeed;
	h2_lower_left2y = h2_lower_left2y + h2_lower_yspeed;

	h2_lower_left1x = h2_lower_left1x - h2_lower_xspeed;
	h2_lower_left1y = h2_lower_left1y - h2_lower_yspeed;
}

void helicopter_üc() {   //460-510 3. helikopter
	glLoadIdentity();
	helicopter_speed_üc = helicopter_speed_üc - 0.009 * h_speed_boost;
	glTranslated(helicopter_speed_üc, 0.0, 0.0);
	if (helicopter_speed_üc < 0)
	{
		helicopter_speed_üc = 430;
	}
	glBegin(GL_POLYGON);  //1 Gövdesi
	glColor3f(0, 1, 0);
	glPointSize(10.0f);
	glVertex2i(3, 474);
	glVertex2i(3, 496);
	glVertex2i(25, 496);
	glVertex2i(25, 474);
	glEnd();

	glBegin(GL_QUADS);  //2 gövdesinin iç karesi
	glColor3f(1, 1, 1);
	glPointSize(10.0f);
	glVertex2i(5, 485);
	glVertex2i(5, 494);
	glVertex2i(15, 494);
	glVertex2i(15, 485);
	glEnd();

	glBegin(GL_QUADS);   //3 üstü
	glColor3f(0, 1, 0);
	glPointSize(10.0f);
	glVertex2i(12, 496);
	glVertex2i(12, 504);
	glVertex2i(16, 504);
	glVertex2i(16, 496);
	glEnd();

	glBegin(GL_QUADS);   // 4
	glColor3f(0, 1, 0);
	glPointSize(10.0f);
	glVertex2i(25, 482);
	glVertex2i(25, 488);
	glVertex2i(45, 488);
	glVertex2i(45, 482);
	glEnd();

	glBegin(GL_QUADS);  // 5
	glColor3f(1, 0, 0);
	glPointSize(10.0f);
	glVertex2i(43, 483);
	glVertex2i(43, 487);
	glVertex2i(47, 487);
	glVertex2i(47, 483);
	glEnd();

	glBegin(GL_QUADS);  //6
	glColor3f(0, 0, 0);
	glPointSize(10.0f);
	glVertex2i(3, 460);
	glVertex2i(3, 464);
	glVertex2i(25, 464);
	glVertex2i(25, 460);
	glEnd();

	glBegin(GL_QUADS); //7
	glColor3f(0, 0, 0);
	glPointSize(10.0f);
	glVertex2i(7, 464);
	glVertex2i(7, 478);
	glVertex2i(11, 478);
	glVertex2i(11, 464);
	glEnd();

	glBegin(GL_QUADS); // 8
	glColor3f(0, 0, 0);
	glPointSize(10.0f);
	glVertex2i(17, 464);
	glVertex2i(17, 478);
	glVertex2i(21, 478);
	glVertex2i(21, 464);
	glEnd();

	glBegin(GL_LINES); //ÜSt pervane Siyah renk
	glColor3f(0, 0, 0);
	glVertex2f(h3_upper_right1x, h3_upper_right1y);
	glVertex2f(h3_upper_right2x, h3_upper_right2y);

	glVertex2f(h3_upper_left1x, h3_upper_left1y);
	glVertex2f(h3_upper_left2x, h3_upper_left2y);
	glEnd();

	glBegin(GL_LINES); //Sol pervane Siyah renk
	glColor3f(0, 0, 0);
	glVertex2f(h3_lower_left1x, h3_lower_left1y);
	glVertex2f(h3_lower_left2x, h3_lower_left2y);

	glVertex2f(h3_lower_right1x, h3_lower_right1y);
	glVertex2f(h3_lower_right2x, h3_lower_right2y);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1.5f);
	glBegin(GL_POINTS);
	glVertex2f(25, h3ortay);
	glEnd();

	//üst pervane sað için
	if (h3_upper_right2x == 22 && h3_upper_right2y == 500)
	{
		h3_upper_xspeed1 = -2.5;
		h3_upper_yspeed1 = 0;
	}
	else if (h3_upper_right2x == 0 && h3_upper_right2y == 510) {
		h3_upper_xspeed1 = 0;
		h3_upper_yspeed1 = -2.5;
	}
	else if (h3_upper_right2x == 22 && h3_upper_right2y == 510) {
		h3_upper_xspeed1 = 2.5;
		h3_upper_yspeed1 = 0;
	}
	else if (h3_upper_right2x == 0 && h3_upper_right2y == 500)
	{
		h3_upper_xspeed1 = 0;
		h3_upper_yspeed1 = 2.5;
	}
	h3_upper_right2x = h3_upper_right2x + h3_upper_xspeed1;
	h3_upper_right2y = h3_upper_right2y + h3_upper_yspeed1;

	h3_upper_right1x = h3_upper_right1x - h3_upper_xspeed1;
	h3_upper_right1y = h3_upper_right1y - h3_upper_yspeed1;

	//üst pervane sol için
	if (h3_upper_left2x == 22 && h3_upper_left2y == 500)
	{
		h3_upper_xspeed = -2.5;
		h3_upper_yspeed = 0;
	}
	else if (h3_upper_left2x == 0 && h3_upper_left2y == 510) {
		h3_upper_xspeed = 0;
		h3_upper_yspeed = -2.5;
	}
	else if (h3_upper_left2x == 22 && h3_upper_left2y == 510) {
		h3_upper_xspeed = 2.5;
		h3_upper_yspeed = 0;
	}
	else if (h3_upper_left2x == 0 && h3_upper_left2y == 500)
	{
		h3_upper_xspeed = 0;
		h3_upper_yspeed = 2.5;
	}
	h3_upper_left2x = h3_upper_left2x + h3_upper_xspeed;
	h3_upper_left2y = h3_upper_left2y + h3_upper_yspeed;

	h3_upper_left1x = h3_upper_left1x - h3_upper_xspeed;
	h3_upper_left1y = h3_upper_left1y - h3_upper_yspeed;

	// alt pervane sag için

	if (h3_lower_right2x == 50 && h3_lower_right2y == 484)
	{
		h3_lower_xspeed1 = -1;
		h3_lower_yspeed1 = 0;
	}
	else if (h3_lower_right2x == 39 && h3_lower_right2y == 490) {
		h3_lower_xspeed1 = 0;
		h3_lower_yspeed1 = -1;
	}
	else if (h3_lower_right2x == 50 && h3_lower_right2y == 490) {
		h3_lower_xspeed1 = 1;
		h3_lower_yspeed1 = 0;
	}
	else if (h3_lower_right2x == 39 && h3_lower_right2y == 484)
	{
		h3_lower_xspeed1 = 0;
		h3_lower_yspeed1 = 1;
	}
	h3_lower_right2x = h3_lower_right2x + h3_lower_xspeed1;
	h3_lower_right2y = h3_lower_right2y + h3_lower_yspeed1;

	h3_lower_right1x = h3_lower_right1x - h3_lower_xspeed1;
	h3_lower_right1y = h3_lower_right1y - h3_lower_yspeed1;

	// alt pervane sol için

	if (h3_lower_left2x == 50 && h3_lower_left2y == 484)
	{
		h3_lower_xspeed = -1;
		h3_lower_yspeed = 0;
	}
	else if (h3_lower_left2x == 39 && h3_lower_left2y == 490) {
		h3_lower_xspeed = 0;
		h3_lower_yspeed = -1;
	}
	else if (h3_lower_left2x == 50 && h3_lower_left2y == 490) {
		h3_lower_xspeed = 1;
		h3_lower_yspeed = 0;
	}
	else if (h3_lower_left2x == 39 && h3_lower_left2y == 484)
	{
		h3_lower_xspeed = 0;
		h3_lower_yspeed = 1;
	}
	h3_lower_left2x = h3_lower_left2x + h3_lower_xspeed;
	h3_lower_left2y = h3_lower_left2y + h3_lower_yspeed;

	h3_lower_left1x = h3_lower_left1x - h3_lower_xspeed;
	h3_lower_left1y = h3_lower_left1y - h3_lower_yspeed;
}

void helicopter_dört() {  //550 - 600  4. helikopter
	glLoadIdentity();
	helicopter_speed_dört = helicopter_speed_dört + 0.009 * h_speed_boost;
	glTranslated(helicopter_speed_dört, 0.0, 0.0);
	if (helicopter_speed_dört > 430) {

		helicopter_speed_dört = 0;
	}
	glBegin(GL_POLYGON);  //1 Gövdesi
	glColor3f(0, 0, 1);
	glPointSize(10.0f);
	glVertex2i(25, 564);
	glVertex2i(25, 586);
	glVertex2i(47, 586);
	glVertex2i(47, 564);
	glEnd();

	glBegin(GL_QUADS);  //2 gövdesinin iç karesi
	glColor3f(1, 1, 1);
	glPointSize(10.0f);
	glVertex2i(36, 575);
	glVertex2i(36, 584);
	glVertex2i(45, 584);
	glVertex2i(45, 575);
	glEnd();

	glBegin(GL_QUADS);   //3 üstü
	glColor3f(0, 0, 1);
	glPointSize(10.0f);
	glVertex2i(34, 586);
	glVertex2i(34, 594);
	glVertex2i(38, 594);
	glVertex2i(38, 586);
	glEnd();

	glBegin(GL_QUADS);   // 4
	glColor3f(0, 0, 1);
	glPointSize(10.0f);
	glVertex2i(5, 572);
	glVertex2i(5, 578);
	glVertex2i(25, 578);
	glVertex2i(25, 572);
	glEnd();

	glBegin(GL_QUADS);  // 5
	glColor3f(0, 0, 1);
	glPointSize(10.0f);
	glVertex2i(3, 573);
	glVertex2i(3, 577);
	glVertex2i(7, 577);
	glVertex2i(7, 573);
	glEnd();

	glBegin(GL_QUADS);  //6
	glColor3f(0, 0, 0);
	glPointSize(10.0f);
	glVertex2i(25, 550);
	glVertex2i(25, 554);
	glVertex2i(47, 554);
	glVertex2i(47, 550);
	glEnd();

	glBegin(GL_QUADS); //7
	glColor3f(0, 0, 0);
	glPointSize(10.0f);
	glVertex2i(29, 554);
	glVertex2i(29, 568);
	glVertex2i(33, 568);
	glVertex2i(33, 554);
	glEnd();

	glBegin(GL_QUADS); // 8
	glColor3f(0, 0, 0);
	glPointSize(10.0f);
	glVertex2i(39, 554);
	glVertex2i(39, 568);
	glVertex2i(43, 568);
	glVertex2i(43, 554);
	glEnd();

	glBegin(GL_LINES); //ÜSt pervane Siyah renk
	glColor3f(0, 0, 0);
	glVertex2f(h4_upper_right1x, h4_upper_right1y);
	glVertex2f(h4_upper_right2x, h4_upper_right2y);

	glVertex2f(h4_upper_left1x, h4_upper_left1y);
	glVertex2f(h4_upper_left2x, h4_upper_left2y);
	glEnd();

	glBegin(GL_LINES); //Sol pervane Siyah renk
	glColor3f(0, 0, 0);
	glVertex2f(h4_lower_left1x, h4_lower_left1y);
	glVertex2f(h4_lower_left2x, h4_lower_left2y);

	glVertex2f(h4_lower_right1x, h4_lower_right1y);
	glVertex2f(h4_lower_right2x, h4_lower_right2y);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1.5f);
	glBegin(GL_POINTS);
	glVertex2f(25, h4ortay);
	glEnd();

	//üst pervane sað için
	if (h4_upper_right2x == 50 && h4_upper_right2y == 590)
	{
		h4_upper_xspeed1 = -2.5;
		h4_upper_yspeed1 = 0;
	}
	else if (h4_upper_right2x == 28 && h4_upper_right2y == 600) {
		h4_upper_xspeed1 = 0;
		h4_upper_yspeed1 = -2.5;
	}
	else if (h4_upper_right2x == 50 && h4_upper_right2y == 600) {
		h4_upper_xspeed1 = 2.5;
		h4_upper_yspeed1 = 0;
	}
	else if (h4_upper_right2x == 28 && h4_upper_right2y == 590)
	{
		h4_upper_xspeed1 = 0;
		h4_upper_yspeed1 = 2.5;
	}
	h4_upper_right2x = h4_upper_right2x + h4_upper_xspeed1;
	h4_upper_right2y = h4_upper_right2y + h4_upper_yspeed1;

	h4_upper_right1x = h4_upper_right1x - h4_upper_xspeed1;
	h4_upper_right1y = h4_upper_right1y - h4_upper_yspeed1;

	//üst pervane sol için
	if (h4_upper_left2x == 50 && h4_upper_left2y == 590)
	{
		h4_upper_xspeed = -2.5;
		h4_upper_yspeed = 0;
	}
	else if (h4_upper_left2x == 28 && h4_upper_left2y == 600) {
		h4_upper_xspeed = 0;
		h4_upper_yspeed = -2.5;
	}
	else if (h4_upper_left2x == 50 && h4_upper_left2y == 600) {
		h4_upper_xspeed = 2.5;
		h4_upper_yspeed = 0;
	}
	else if (h4_upper_left2x == 28 && h4_upper_left2y == 590)
	{
		h4_upper_xspeed = 0;
		h4_upper_yspeed = 2.5;
	}
	h4_upper_left2x = h4_upper_left2x + h4_upper_xspeed;
	h4_upper_left2y = h4_upper_left2y + h4_upper_yspeed;

	h4_upper_left1x = h4_upper_left1x - h4_upper_xspeed;
	h4_upper_left1y = h4_upper_left1y - h4_upper_yspeed;

	// alt pervane sag için

	if (h4_lower_right2x == 10 && h4_lower_right2y == 574)
	{
		h4_lower_xspeed1 = -1;
		h4_lower_yspeed1 = 0;
	}
	else if (h4_lower_right2x == 1 && h4_lower_right2y == 580) {
		h4_lower_xspeed1 = 0;
		h4_lower_yspeed1 = -1;
	}
	else if (h4_lower_right2x == 10 && h4_lower_right2y == 580) {
		h4_lower_xspeed1 = 1;
		h4_lower_yspeed1 = 0;
	}
	else if (h4_lower_right2x == 1 && h4_lower_right2y == 574)
	{
		h4_lower_xspeed1 = 0;
		h4_lower_yspeed1 = 1;
	}
	h4_lower_right2x = h4_lower_right2x + h4_lower_xspeed1;
	h4_lower_right2y = h4_lower_right2y + h4_lower_yspeed1;

	h4_lower_right1x = h4_lower_right1x - h4_lower_xspeed1;
	h4_lower_right1y = h4_lower_right1y - h4_lower_yspeed1;

	// alt pervane sol için

	if (h4_lower_left2x == 10 && h4_lower_left2y == 574)
	{
		h4_lower_xspeed = -1;
		h4_lower_yspeed = 0;
	}
	else if (h4_lower_left2x == 1 && h4_lower_left2y == 580) {
		h4_lower_xspeed = 0;
		h4_lower_yspeed = -1;
	}
	else if (h4_lower_left2x == 10 && h4_lower_left2y == 580) {
		h4_lower_xspeed = 1;
		h4_lower_yspeed = 0;
	}
	else if (h4_lower_left2x == 1 && h4_lower_left2y == 574)
	{
		h4_lower_xspeed = 0;
		h4_lower_yspeed = 1;
	}
	h4_lower_left2x = h4_lower_left2x + h4_lower_xspeed;
	h4_lower_left2y = h4_lower_left2y + h4_lower_yspeed;

	h4_lower_left1x = h4_lower_left1x - h4_lower_xspeed;
	h4_lower_left1y = h4_lower_left1y - h4_lower_yspeed;
} 

void basla() {
	glLoadIdentity();
	 glColor3f(0.0, 0.0, 0.0);
	 glRasterPos2f(250, 580);
	 char Puan[] = "Puan :";
	 for (int i = 0; i < strlen(Puan); i++)
	 {
	 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, Puan[i]);
	 }

	 std::string skor1 = std::to_string(skor);
	 glColor3f(1.0, 0.0, 0.0);
	 glRasterPos2f(310, 580);
	 for (int i = 0; i < skor1.length(); i++)
	 {
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, skor1[i]);
	 }

	 glColor3f(0.0, 0.0, 0.0);
	 glRasterPos2f(355, 580);
	 char kalan_hak[] = "Kalan Hak :";
	 for (int i = 0; i < strlen(kalan_hak); i++)
	 {
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, kalan_hak[i]);
	 }

	 std::string Kalan_hak = std::to_string(kalanhak);

	 glColor3f(1.0, 0.0, 0.0);
	 glRasterPos2f(450,580);
	 for (int i = 0; i < Kalan_hak.length(); i++)
	 {
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, Kalan_hak[i]);
	 }
}

void crash() {
	ucakortax = 25 + xr;
	ucakortay = 25 + yr;
	h1ortax = 25 + helicopter_speed;
	h2ortax = 25 + helicopter_speed_iki;
	h3ortax = 25 + helicopter_speed_üc;
	h4ortax = 25 + helicopter_speed_dört;
	_distance_helicopter = sqrt(pow((h1ortax - ucakortax), 2) + pow((h1ortay - ucakortay), 2));
	_distance_helicopter_iki = sqrt(pow((h2ortax - ucakortax), 2) + pow((h2ortay - ucakortay), 2));
	_distance_helicopter_üc = sqrt(pow((h3ortax - ucakortax), 2) + pow((h3ortay - ucakortay), 2));
	_distance_helicopter_dört = sqrt(pow((h4ortax - ucakortax), 2) + pow((h4ortay - ucakortay), 2));

	if (_distance_helicopter <= 50) {
		kalanhak = kalanhak - 1;
		xr = 50;
		yr = 50;
	}
	else if (_distance_helicopter_iki <= 50) {
		kalanhak = kalanhak - 1;
		xr = 50;
		yr = 50;
	}
	else if (_distance_helicopter_üc <= 50) {
		kalanhak = kalanhak - 1;
		xr = 50;
		yr = 50;
	}
	else if (_distance_helicopter_dört <= 50) {
		kalanhak = kalanhak - 1;
		xr = 50;
		yr = 50;
	}

	//std::cout << _distance_helicopter << std::endl;
}

void KalanHak() {
	//kalan hak 0 ise 
	if (kalanhak == 0) {
		xr = 0;
		yr = 0;

		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2f(150, 450);
		char puan[]("PUANINIZ: ");

		for (int i = 0; i < strlen(puan); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, puan[i]);
		}

		std::string sayi = std::to_string(skor);

		glColor3f(1, 0, 0);
		glRasterPos2f(280, 450);
		for (int i = 0; i < sayi.length(); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, sayi[i]);
		}

		glColor3f(0, 0, 0);
		glRasterPos2f(60, 400);
		char mesaj[]("Tekrar oynamak icin enter tusuna basiniz ");

		for (int i = 0; i < strlen(mesaj); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, mesaj[i]);
		}
	}
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	KalanHak();
	crash();
	airplane();
	helicopter();
	helicopter_iki();
	helicopter_üc();
	helicopter_dört();
	basla();
	glutKeyboardFunc(enter);

	glBegin(GL_LINES);
	glColor3f(0.0,0.0,1.0);
	glVertex2f(0, 240);
	glVertex2f(480, 240);
	glEnd();

	glutSwapBuffers(); 
	glFlush();
}
void welcomeDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1.0, 0.0, 0.0);
	glRasterPos2f(100, 450);
	char welcome[]("Helikopter Oyununa Hosgeldiniz");

	for (int i = 0; i < strlen(welcome); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, welcome[i]);
	}

	glColor3f(0.0, 0.0, 1.0);
	glRasterPos2f(70, 350);
	char welcome1[]("Oyuna baslamak icin 'x' tusuna basiniz");

	for (int i = 0; i < strlen(welcome1); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, welcome1[i]);
	}

	glutSwapBuffers();
}

void keys(unsigned char key, int x, int y) {
	if (key == 'x')
	{
		glutDisplayFunc(display);
	}
	glutPostRedisplay();
}
int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(200, 50);
	glutInitWindowSize(480, 640);
	glutCreateWindow("Serkan YÜZBAÞIOÐLU 160322015");
	glutDisplayFunc(welcomeDisplay);
	glutKeyboardFunc(keys);
	glutSpecialFunc(key_input);
	init();
	glutMainLoop();
	return 0;

}