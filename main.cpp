#include <windows.h>
#include<cstdio>
#include<iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#include<mmsystem.h>
#include <unistd.h>
#define PI 3.1415926;
using namespace std;

GLfloat cloud_position=0.0;
GLfloat cloud_speed= 0.01;
GLfloat sun_position=0.0;
GLfloat sun_speed=0.0075;
GLfloat rain_position = 0.0f;
GLfloat rain_speed = 0.02f;
GLfloat plane_position=0.0;
GLfloat plane_speed=0.02;

GLfloat manr_position=0.0;
GLfloat manr_speed=0.01;
GLfloat manl_position = 0.0f;
GLfloat manl_speed = 0.01f;

void updateRain(int value)
{   if(rain_position <-0.05f)
        rain_position = 0.0f;
rain_position -= rain_speed;
glutPostRedisplay();
glutTimerFunc(100, updateRain, 0);
}

void updateCloud(int value)
{   if(cloud_position<-2.1)
cloud_position=1.0;
cloud_position-=cloud_speed;
glutPostRedisplay();
glutTimerFunc(100,updateCloud,0);
}
void updateSun(int value)
{   if(sun_position>1.0)
sun_position=-0.7;
sun_position+=sun_speed;
glutPostRedisplay();
glutTimerFunc(100,updateSun,0);
}

void updateManR(int value)
{   if(manr_position <-1.0)
        manr_position = 0.2f;
manr_position -= manr_speed;
glutPostRedisplay();
glutTimerFunc(100, updateManR, 0);
}

void updateManL(int value)
{   if(manl_position >0.5f)
        manl_position = -0.9f;
manl_position += manl_speed;
glutPostRedisplay();
glutTimerFunc(100, updateManL, 0);
}

void updatePlane(int value)
{   if(plane_position>1.5)
plane_position=-1.0;
plane_position+=plane_speed;
glutPostRedisplay();
glutTimerFunc(100,updatePlane,0);

}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DAY VIEW ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void day() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2.0);

	glBegin(GL_POLYGON);//sky
	glColor3ub(128, 204, 255);
	glVertex2f(1.0,1.0);
	glVertex2f(-1.0,1.0);
	glVertex2f(-1.0,-0.2);
	glVertex2f(1.0,-0.2);
    glEnd();
//*******************************  SUN  **************************
   //glPushMatrix();
   //glTranslatef(0,sun_position,0);
   int i;
    GLfloat amount= 30;
    GLfloat twoPi=2*PI;
    GLfloat xs=0.845; GLfloat ys=0.845; GLfloat rs=0.145;
    glBegin(GL_TRIANGLE_FAN);//Sun
	glColor3ub(255, 219, 77);
		glVertex2f(xs, ys); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xs+ (rs* cos(i*twoPi / amount)),
			    ys + (rs * sin(i * twoPi / amount))
			);
		}
	glEnd();
	//glLoadIdentity();
	//glPopMatrix();
//###############################################  CLOUD  #########################################
glPushMatrix();
glTranslatef(cloud_position,0,0);
 GLfloat xc=-0.84; GLfloat yc=0.8; GLfloat rc=0.045;
    glBegin(GL_TRIANGLE_FAN);//Cloud 1
	glColor3ub(255, 255, 255);
		glVertex2f(xc, yc); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc+ (rc* cos(i*twoPi / amount)),
			    yc + (rc * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.05,0.03,0);
glBegin(GL_TRIANGLE_FAN);//Sun
	glColor3ub(255, 255, 255);
		glVertex2f(xc, yc); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc+ (rc* cos(i*twoPi / amount)),
			    yc + (rc * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.05,-0.05,0);
glBegin(GL_TRIANGLE_FAN);//Sun
	glColor3ub(255, 255, 255);
		glVertex2f(xc, yc); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc+ (rc* cos(i*twoPi / amount)),
			    yc + (rc * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(-0.05,-0.03,0);
glBegin(GL_TRIANGLE_FAN);//Sun
	glColor3ub(255, 255, 255);
		glVertex2f(xc, yc); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc+ (rc* cos(i*twoPi / amount)),
			    yc + (rc * sin(i * twoPi / amount))
			);
		}
	glEnd();
	//glLoadIdentity();

	GLfloat xc1=-0.6; GLfloat yc1=0.805; GLfloat rc1=0.045;
    glBegin(GL_TRIANGLE_FAN);//Cloud 2
	glColor3ub(255, 255, 255);
		glVertex2f(xc1, yc1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc1+ (rc1* cos(i*twoPi / amount)),
			    yc1 + (rc1 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.05,0.03,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 2
	glColor3ub(255, 255, 255);
		glVertex2f(xc1, yc1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc1+ (rc1* cos(i*twoPi / amount)),
			    yc1 + (rc1 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.05,-0.05,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 2
	glColor3ub(255, 255, 255);
		glVertex2f(xc1, yc1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc1+ (rc1* cos(i*twoPi / amount)),
			    yc1 + (rc1 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(-0.05,-0.03,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 2
	glColor3ub(255, 255, 255);
		glVertex2f(xc1, yc1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc1+ (rc1* cos(i*twoPi / amount)),
			    yc1 + (rc1 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	//glLoadIdentity();

	GLfloat xc2=0.0; GLfloat yc2=0.81; GLfloat rc2=0.045;
    glBegin(GL_TRIANGLE_FAN);//Cloud 3.1
	glColor3ub(255, 255, 255);
		glVertex2f(xc2, yc2); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc2+ (rc2* cos(i*twoPi / amount)),
			    yc2 + (rc2 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.05,0.03,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 3.2
	glColor3ub(255, 255, 255);
		glVertex2f(xc2, yc2); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc2+ (rc2* cos(i*twoPi / amount)),
			    yc2 + (rc2 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.05,-0.05,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 3.3
	glColor3ub(255, 255, 255);
		glVertex2f(xc2, yc2); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc2+ (rc2* cos(i*twoPi / amount)),
			    yc2 + (rc2 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(-0.05,-0.03,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 3.4
	glColor3ub(255, 255, 255);
		glVertex2f(xc2, yc2); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc2+ (rc2* cos(i*twoPi / amount)),
			    yc2 + (rc2 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	GLfloat xc3=0.55; GLfloat yc3=0.801; GLfloat rc3=0.045;
    glBegin(GL_TRIANGLE_FAN);//Cloud 4.1
	glColor3ub(255, 255, 255);
		glVertex2f(xc3, yc3); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc3+ (rc3* cos(i*twoPi / amount)),
			    yc3 + (rc3 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.05,0.03,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 4.2
	glColor3ub(255, 255, 255);
		glVertex2f(xc3, yc3); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc3+ (rc3* cos(i*twoPi / amount)),
			    yc3 + (rc3 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.05,-0.05,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 4.3
	glColor3ub(255, 255, 255);
		glVertex2f(xc3, yc3); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc3+ (rc3* cos(i*twoPi / amount)),
			    yc3 + (rc3 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(-0.05,-0.03,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 4.4
	glColor3ub(255, 255, 255);
		glVertex2f(xc3, yc3); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc3+ (rc3* cos(i*twoPi / amount)),
			    yc3 + (rc3 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLoadIdentity();
	glPopMatrix();

	   //******************Plane****
glPushMatrix();
glTranslatef(plane_position,0,0);


	GLfloat xp=-0.4f; GLfloat yp=0.75f; GLfloat rp =0.025f;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 64);
		glVertex2f(xp, yp);
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xp + (rp * cos(i *  twoPi / amount)),
			    yp + (rp * sin(i * twoPi /amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);//body
	glColor3ub(255, 0, 64);
	glVertex2f(-0.39,0.725);
	glVertex2f(-0.6,0.725);
	glVertex2f(-0.65,0.765);
	glVertex2f(-0.65,0.8);
	glVertex2f(-0.43,0.8);
	glVertex2f(-0.39,0.775);
	glEnd();

	glBegin(GL_TRIANGLES);//wing behind
	glColor3ub(0, 153, 153);
	glVertex2f(-0.645,0.8);
	glVertex2f(-0.6,0.8);
	glVertex2f(-0.645,0.845);
	//glVertex2f();
	glEnd();

	glBegin(GL_POLYGON);//wing up
	glColor3ub(0, 153, 153);
	glVertex2f(-0.54,0.8);
	glVertex2f(-0.50,0.8);
	glVertex2f(-0.52,0.85);
	glVertex2f(-0.56,0.85);
	glEnd();

	glBegin(GL_POLYGON);//wing down
	glColor3ub(0, 153, 153);
	glVertex2f(-0.54,0.725);
	glVertex2f(-0.50,0.725);
	glVertex2f(-0.52,0.675);
	glVertex2f(-0.56,0.675);
	glEnd();

	glBegin(GL_POLYGON);//door
	glColor3ub(102, 153, 204);
	glVertex2f(-0.435,0.765);
	glVertex2f(-0.45,0.765);
	glVertex2f(-0.45,0.725);
	glVertex2f(-0.435,0.725);
	glEnd();


	glTranslatef(-0.033,0,0);
	glBegin(GL_POLYGON);//window
	glColor3ub(102, 153, 204);
	glVertex2f(-0.435,0.755);
	glVertex2f(-0.45,0.755);
	glVertex2f(-0.45,0.775);
	glVertex2f(-0.435,0.775);
	glEnd();

	glTranslatef(-0.033,0,0);
	glBegin(GL_POLYGON);//window
	glColor3ub(102, 153, 204);
	glVertex2f(-0.435,0.755);
	glVertex2f(-0.45,0.755);
	glVertex2f(-0.45,0.775);
	glVertex2f(-0.435,0.775);
	glEnd();


	glTranslatef(-0.033,0,0);
	glBegin(GL_POLYGON);//window
	glColor3ub(102, 153, 204);
	glVertex2f(-0.435,0.755);
	glVertex2f(-0.45,0.755);
	glVertex2f(-0.45,0.775);
	glVertex2f(-0.435,0.775);
	glEnd();


	glTranslatef(-0.033,0,0);
	glBegin(GL_POLYGON);//window
	glColor3ub(102, 153, 204);
	glVertex2f(-0.435,0.755);
	glVertex2f(-0.45,0.755);
	glVertex2f(-0.45,0.775);
	glVertex2f(-0.435,0.775);
	glEnd();
	glTranslatef(-0.033,0,0);
	glBegin(GL_POLYGON);//window
	glColor3ub(102, 153, 204);
	glVertex2f(-0.435,0.755);
	glVertex2f(-0.45,0.755);
	glVertex2f(-0.45,0.775);
	glVertex2f(-0.435,0.775);
	glEnd();
glLoadIdentity();
	glPopMatrix();

//****************************************************************************
glBegin(GL_POLYGON);//ground
	glColor3ub(0, 179, 60);
	glVertex2f(1.0,-1.0);
	glVertex2f(-1.0,-1.0);
	glVertex2f(-1.0,-0.2);
	glVertex2f(1.0,-0.2);
    glEnd();
    //red road
    glBegin(GL_POLYGON);//red road
	glColor3ub(255, 140, 102);
	glVertex2f(1.0,-0.2);
	glVertex2f(-1.0,-0.2);
	glVertex2f(-1.0,-0.325);
	glVertex2f(1.0,-0.325);
	glEnd();

glBegin(GL_POLYGON);//mosjid builduing tall
	glColor3ub(255, 255, 230);
	glVertex2f(0.41,-0.25);
	glVertex2f(-0.41,-0.25);
	glVertex2f(-0.41,0.9);
	glVertex2f(0.41,0.9);
    glEnd();
glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(0.41,-0.25);
glVertex2f(0.41,0.9);
glVertex2f(0.41,0.9);
glVertex2f(-0.41,0.9);
glVertex2f(-0.41,0.9);
glVertex2f(-0.41,-0.25);
glEnd();
glBegin(GL_POLYGON);//mosjid builduing longest
	glColor3ub(255, 255, 179);
	glVertex2f(0.88,-0.25);
	glVertex2f(-0.88,-0.25);
	glVertex2f(-0.88,0.1875);
	glVertex2f(0.88,0.1875);
    glEnd();
glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(0.88,0.1875);
glVertex2f(0.88,-0.25);
glVertex2f(0.88,-0.25);
glVertex2f(-0.88,-0.25);
glVertex2f(-0.88,-0.25);
glVertex2f(-0.88,0.1875);
glEnd();

    glBegin(GL_POLYGON);//mosjid builduing roof
	glColor3ub(204, 204, 179);
	glVertex2f(0.84,0.25);
	glVertex2f(-0.84,0.25);
	glVertex2f(-0.88,0.1875);
	glVertex2f(0.88,0.1875);
    glEnd();

glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(0.84,0.25);
glVertex2f(-0.84,0.25);
glVertex2f(-0.84,0.25);
glVertex2f(-0.88,0.1875);
glVertex2f(-0.88,0.1875);
glVertex2f(0.88,0.1875);
glVertex2f(0.88,0.1875);
glVertex2f(0.84,0.25);
glEnd();

glBegin(GL_POLYGON);//mosjid builduing black block 1
	glColor3ub(0,0,0);
	glVertex2f(0.41,0.65);
	glVertex2f(-0.41,0.65);
	glVertex2f(-0.41,0.675);
	glVertex2f(0.41,0.675);
    glEnd();
    glTranslatef(0,0.05,0);
    glBegin(GL_POLYGON);//mosjid builduing black block 2
	glColor3ub(0,0,0);
	glVertex2f(0.41,0.65);
	glVertex2f(-0.41,0.65);
	glVertex2f(-0.41,0.675);
	glVertex2f(0.41,0.675);
    glEnd();
    glTranslatef(0,-0.1,0);
    glBegin(GL_POLYGON);//mosjid builduing black block 3
	glColor3ub(0,0,0);
	glVertex2f(0.41,0.65);
	glVertex2f(-0.41,0.65);
	glVertex2f(-0.41,0.675);
	glVertex2f(0.41,0.675);
    glEnd();
    glLoadIdentity();
    //***********************************mosjid room block

    GLfloat x=-0.845; GLfloat y=0.135; GLfloat r=0.015;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();

    glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
    glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
    glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
    glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();

           glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
    glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();

glLoadIdentity();
////////////////////////////////////////////////////////////////////////////////////
GLfloat x1=-0.81; GLfloat y1=-0.1; GLfloat r1=0.035;
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();
glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glTranslatef(0.1,0,0);
   glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glTranslatef(0.1,0,0);

    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glLoadIdentity();
//*****************************************************
    glBegin(GL_POLYGON);//mosjid builduing door
	glColor3ub(255, 255, 230);
	glVertex2f(0.167,-0.1);
	glVertex2f(-0.167,-0.1);
	glVertex2f(-0.148,0.3375);
	glVertex2f(0.148,0.3375);
    glEnd();
glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(0.167,-0.1);
glVertex2f(-0.167,-0.1);
glVertex2f(-0.167,-0.1);
glVertex2f(-0.148,0.3375);
glVertex2f(-0.148,0.3375);
glVertex2f(0.148,0.3375);
glVertex2f(0.148,0.3375);
glVertex2f(0.167,-0.1);
glEnd();

GLfloat x2=-0.105; GLfloat y2=0.15; GLfloat r2=0.035;
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x2, y2); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x2+ (r2* cos(i *twoPi / amount)),
			    y2 + (r2 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.14,0.15);
	glVertex2f(-0.07,0.15);
	glVertex2f(-0.07,-0.05);
	glVertex2f(-0.14,-0.05);
    glEnd();

    glTranslatef(0.2,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x2, y2); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x2+ (r2* cos(i *twoPi / amount)),
			    y2 + (r2 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.14,0.15);
	glVertex2f(-0.07,0.15);
	glVertex2f(-0.07,-0.05);
	glVertex2f(-0.14,-0.05);
    glEnd();
    glLoadIdentity();

    glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.05,0.15);
	glVertex2f(0.04,0.15);
	glVertex2f(0.04,-0.05);
	glVertex2f(-0.05,-0.05);
    glEnd();

    GLfloat x3=-0.005; GLfloat y3=0.16; GLfloat r3=0.055;
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x3, y3); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x3+ (r3* cos(i *twoPi / amount)),
			    y3 + (r3 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.0325,0.21);
	glVertex2f(0.0225,0.21);
	glVertex2f(-0.005,0.245);

    glEnd();


    glBegin(GL_POLYGON);//mosjid builduing door stair
	glColor3ub(223, 191, 159);
	glVertex2f(0.17,-0.1);
	glVertex2f(-0.17,-0.1);
	glVertex2f(-0.25,-0.26);
	glVertex2f(0.25,-0.26);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.17,-0.1);
	glVertex2f(-0.17,-0.1);
	glVertex2f(-0.17,-0.1);
	glVertex2f(-0.25,-0.26);
	glVertex2f(-0.25,-0.26);
	glVertex2f(0.25,-0.26);
	glVertex2f(0.25,-0.26);
	glVertex2f(0.17,-0.1);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.19,-0.14);
	glVertex2f(-0.19,-0.14);
	glVertex2f(0.21,-0.18);
	glVertex2f(-0.21,-0.18);
	glVertex2f(0.23,-0.22);
	glVertex2f(-0.23,-0.22);
	glEnd();

	//***************************Water Pool in front of mosque*********************************************
	glBegin(GL_POLYGON);//pool fringe road both side
	glColor3ub(255, 140, 102);
	glVertex2f(-0.25,-0.26);
	glVertex2f(0.25,-0.26);
	glVertex2f(0.45,-1.0);
	glVertex2f(-0.45,-1.0);
	glEnd();
	glBegin(GL_POLYGON);//pool fringe
	glColor3ub(191, 191, 191);
	glVertex2f(-0.1,-0.34);
	glVertex2f(0.1,-0.34);
	glVertex2f(0.2,-0.8);
	glVertex2f(-0.2,-0.8);
	glEnd();

	glBegin(GL_POLYGON);//shadow
	glColor3ub(64, 64, 64);
	glVertex2f(-0.095,-0.355);
	glVertex2f(0.095,-0.355);
	glVertex2f(0.18,-0.78);
	glVertex2f(-0.18,-0.78);
	glEnd();
	glBegin(GL_POLYGON);//water
	glColor3ub(179, 217, 255);
	glVertex2f(-0.092,-0.365);
	glVertex2f(0.092,-0.365);
	glVertex2f(0.165,-0.76);
	glVertex2f(-0.165,-0.76);
	glEnd();

	//****************************************Trees and LampPost*******************************
	glBegin(GL_POLYGON);//Tree Left1
	glColor3ub(96, 64, 32);
	glVertex2f(-0.73,-0.6);
	glVertex2f(-0.73,-0.5);
	glVertex2f(-0.70,-0.5);
	glVertex2f(-0.70,-0.6);
	glEnd();

    GLfloat xtl=-0.715; GLfloat ytl=-0.38; GLfloat rtl=0.12;
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(64,255,0);
		glVertex2f(xtl, ytl); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xtl+ (rtl* cos(i*twoPi / amount)),
			    ytl + (rtl * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(-0.125,-0.2,0);
glBegin(GL_POLYGON);//Tree Left2
	glColor3ub(96, 64, 32);
	glVertex2f(-0.73,-0.6);
	glVertex2f(-0.73,-0.5);
	glVertex2f(-0.70,-0.5);
	glVertex2f(-0.70,-0.6);
	glEnd();
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(187,255,51);
		glVertex2f(xtl, ytl); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xtl+ (rtl* cos(i*twoPi / amount)),
			    ytl + (rtl * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLoadIdentity();

	glBegin(GL_POLYGON);//Tree Right1
	glColor3ub(96, 64, 32);
	glVertex2f(0.73,-0.6);
	glVertex2f(0.73,-0.5);
	glVertex2f(0.70,-0.5);
	glVertex2f(0.70,-0.6);
	glEnd();

    GLfloat xtr=0.715; GLfloat ytr=-0.38; GLfloat rtr=0.12;
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(187,255,51);
		glVertex2f(xtr, ytr); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xtr+ (rtr* cos(i*twoPi / amount)),
			    ytr + (rtr * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.125,-0.2,0);
glBegin(GL_POLYGON);//Tree Right2
	glColor3ub(96, 64, 32);
	glVertex2f(0.73,-0.6);
	glVertex2f(0.73,-0.5);
	glVertex2f(0.70,-0.5);
	glVertex2f(0.70,-0.6);
	glEnd();
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(64,255,0);
		glVertex2f(xtr, ytr); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xtr+ (rtr* cos(i*twoPi / amount)),
			    ytr + (rtr * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLoadIdentity();

	//----------------------------- LampPost -----------------------------------
	glBegin(GL_POLYGON);//Lamp Left
	glColor3ub(89, 89, 89);
	glVertex2f(-0.33,-0.4);
	glVertex2f(-0.33,-0.25);
    glVertex2f(-0.3,-0.25);
    glVertex2f(-0.3,-0.4);
	glEnd();
	GLfloat xll=-0.315; GLfloat yll=-0.24; GLfloat rll=0.03;
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(242, 242, 242);
		glVertex2f(xll, yll); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xll+ (rll* cos(i*twoPi / amount)),
			    yll + (rll * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glTranslatef(-0.65,0,0);
	glBegin(GL_POLYGON);//Lamp Left
	glColor3ub(89, 89, 89);
	glVertex2f(-0.33,-0.4);
	glVertex2f(-0.33,-0.25);
    glVertex2f(-0.3,-0.25);
    glVertex2f(-0.3,-0.4);
	glEnd();

    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(242, 242, 242);
		glVertex2f(xll, yll); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xll+ (rll* cos(i*twoPi / amount)),
			    yll + (rll * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLoadIdentity();

	glTranslatef(0.64,0,0);
	glBegin(GL_POLYGON);//Lamp Left
	glColor3ub(89, 89, 89);
	glVertex2f(-0.33,-0.4);
	glVertex2f(-0.33,-0.25);
    glVertex2f(-0.3,-0.25);
    glVertex2f(-0.3,-0.4);
	glEnd();

    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(242, 242, 242);
		glVertex2f(xll, yll); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xll+ (rll* cos(i*twoPi / amount)),
			    yll + (rll * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLoadIdentity();

	glTranslatef(1.28,0,0);
	glBegin(GL_POLYGON);//Lamp Left
	glColor3ub(89, 89, 89);
	glVertex2f(-0.33,-0.4);
	glVertex2f(-0.33,-0.25);
    glVertex2f(-0.3,-0.25);
    glVertex2f(-0.3,-0.4);
	glEnd();

    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(242, 242, 242);
		glVertex2f(xll, yll); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xll+ (rll* cos(i*twoPi / amount)),
			    yll + (rll * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLoadIdentity();

glBegin(GL_POLYGON);//Lamp Right
	glColor3ub(89, 89, 89);
	glVertex2f(-0.49,-0.95);
	glVertex2f(-0.49,-0.8);
    glVertex2f(-0.46,-0.8);
    glVertex2f(-0.46,-0.95);
	glEnd();
	GLfloat xlr=-0.475; GLfloat ylr=-0.79; GLfloat rlr=0.03;
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(242, 242, 242);
		glVertex2f(xlr, ylr); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xlr+ (rlr* cos(i*twoPi / amount)),
			    ylr + (rlr * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.935,0,0);
	glBegin(GL_POLYGON);//Lamp Right
	glColor3ub(89, 89, 89);
	glVertex2f(-0.49,-0.95);
	glVertex2f(-0.49,-0.8);
    glVertex2f(-0.46,-0.8);
    glVertex2f(-0.46,-0.95);
	glEnd();
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(242, 242, 242);
		glVertex2f(xlr, ylr); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xlr+ (rlr* cos(i*twoPi / amount)),
			    ylr + (rlr * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLoadIdentity();

	//++++++++++++++++++++++++ Man  ++++++++++++++++++++++++++++++++++++++++++++++++++
	glPushMatrix();
	glTranslatef(0.001,manr_position,0);
	glBegin(GL_POLYGON);//Man Right
	glColor3ub(92, 138, 138);
	glVertex2f(0.27,-0.35);
	glVertex2f(0.27,-0.45);
    glVertex2f(0.23,-0.45);
    glVertex2f(0.23,-0.35);
	glEnd();
	GLfloat xmr=0.25; GLfloat ymr=-0.34; GLfloat rmr=0.015;
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(0,0,0);
		glVertex2f(xmr, ymr); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xmr+ (rmr* cos(i*twoPi / amount)),
			    ymr + (rmr * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLineWidth(3.0);
	glBegin(GL_LINES);//Man Right
	glColor3ub(0,0,0);
	glVertex2f(0.27,-0.37);
	glVertex2f(0.2775,-0.37);
    glVertex2f(0.23,-0.37);
    glVertex2f(0.2225,-0.37);
	glEnd();
	glLoadIdentity();
	glPopMatrix();
glPushMatrix();
glTranslatef(0,manl_position,0);
	glBegin(GL_POLYGON);//Man Left
	glColor3ub(255, 153, 255);
	glVertex2f(-0.27,-0.7);
	glVertex2f(-0.27,-0.8);
    glVertex2f(-0.23,-0.8);
    glVertex2f(-0.23,-0.7);
	glEnd();
	GLfloat xml=-0.25; GLfloat yml=-0.69; GLfloat rml=0.015;
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(0,0,0);
		glVertex2f(xml, yml); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xml+ (rml* cos(i*twoPi / amount)),
			    yml + (rml * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLineWidth(3.0);
	glBegin(GL_LINES);//Man Left
	glColor3ub(0,0,0);
	glVertex2f(-0.27,-0.72);
	glVertex2f(-0.2775,-0.72);
    glVertex2f(-0.23,-0.72);
    glVertex2f(-0.2225,-0.72);
	glEnd();
	glLoadIdentity();
	glPopMatrix();


glFlush();
}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ RAIN VIEW ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void rain() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2.5);

	glBegin(GL_POLYGON);//sky
	glColor3ub(204, 204, 204);
	glVertex2f(1.0,1.0);
	glVertex2f(-1.0,1.0);
	glVertex2f(-1.0,-0.2);
	glVertex2f(1.0,-0.2);
    glEnd();
//*******************************  SUN  **************************
  // glPushMatrix();
 //  glTranslatef(0,sun_position,0);
   int i;
    GLfloat amount= 30;
    GLfloat twoPi=2*PI;
    GLfloat xs=0.845; GLfloat ys=0.845; GLfloat rs=0.145;
    glBegin(GL_TRIANGLE_FAN);//Sun
	glColor3ub(255, 219, 77);
		glVertex2f(xs, ys); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xs+ (rs* cos(i*twoPi / amount)),
			    ys + (rs * sin(i * twoPi / amount))
			);
		}
	glEnd();
	//glLoadIdentity();
	//glPopMatrix();
//###############################################  CLOUD  #########################################
glPushMatrix();
glTranslatef(cloud_position,0,0);
 GLfloat xc=-0.84; GLfloat yc=0.8; GLfloat rc=0.045;
    glBegin(GL_TRIANGLE_FAN);//Cloud 1
	glColor3ub(115, 115, 115);
		glVertex2f(xc, yc); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc+ (rc* cos(i*twoPi / amount)),
			    yc + (rc * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.05,0.03,0);
glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(115, 115, 115);
		glVertex2f(xc, yc); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc+ (rc* cos(i*twoPi / amount)),
			    yc + (rc * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.05,-0.05,0);
glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(115, 115, 115);
		glVertex2f(xc, yc); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc+ (rc* cos(i*twoPi / amount)),
			    yc + (rc * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(-0.05,-0.03,0);
glBegin(GL_TRIANGLE_FAN);//Sun
	glColor3ub(115, 115, 115);
		glVertex2f(xc, yc); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc+ (rc* cos(i*twoPi / amount)),
			    yc + (rc * sin(i * twoPi / amount))
			);
		}
	glEnd();
	//glLoadIdentity();

	GLfloat xc1=-0.6; GLfloat yc1=0.805; GLfloat rc1=0.045;
    glBegin(GL_TRIANGLE_FAN);//Cloud 2
	glColor3ub(115, 115, 115);
		glVertex2f(xc1, yc1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc1+ (rc1* cos(i*twoPi / amount)),
			    yc1 + (rc1 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.05,0.03,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 2
	glColor3ub(115, 115, 115);
		glVertex2f(xc1, yc1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc1+ (rc1* cos(i*twoPi / amount)),
			    yc1 + (rc1 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.05,-0.05,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 2
	glColor3ub(115, 115, 115);
		glVertex2f(xc1, yc1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc1+ (rc1* cos(i*twoPi / amount)),
			    yc1 + (rc1 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(-0.05,-0.03,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 2
	glColor3ub(115, 115, 115);
		glVertex2f(xc1, yc1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc1+ (rc1* cos(i*twoPi / amount)),
			    yc1 + (rc1 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	//glLoadIdentity();

	GLfloat xc2=0.0; GLfloat yc2=0.81; GLfloat rc2=0.045;
    glBegin(GL_TRIANGLE_FAN);//Cloud 3.1
	glColor3ub(115, 115, 115);
		glVertex2f(xc2, yc2); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc2+ (rc2* cos(i*twoPi / amount)),
			    yc2 + (rc2 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.05,0.03,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 3.2
	glColor3ub(115, 115, 115);
		glVertex2f(xc2, yc2); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc2+ (rc2* cos(i*twoPi / amount)),
			    yc2 + (rc2 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.05,-0.05,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 3.3
	glColor3ub(115, 115, 115);
		glVertex2f(xc2, yc2); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc2+ (rc2* cos(i*twoPi / amount)),
			    yc2 + (rc2 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(-0.05,-0.03,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 3.4
	glColor3ub(115, 115, 115);
		glVertex2f(xc2, yc2); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc2+ (rc2* cos(i*twoPi / amount)),
			    yc2 + (rc2 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	GLfloat xc3=0.55; GLfloat yc3=0.801; GLfloat rc3=0.045;
    glBegin(GL_TRIANGLE_FAN);//Cloud 4.1
	glColor3ub(115, 115, 115);
		glVertex2f(xc3, yc3); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc3+ (rc3* cos(i*twoPi / amount)),
			    yc3 + (rc3 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.05,0.03,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 4.2
	glColor3ub(115, 115, 115);
		glVertex2f(xc3, yc3); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc3+ (rc3* cos(i*twoPi / amount)),
			    yc3 + (rc3 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.05,-0.05,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 4.3
	glColor3ub(115, 115, 115);
		glVertex2f(xc3, yc3); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc3+ (rc3* cos(i*twoPi / amount)),
			    yc3 + (rc3 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(-0.05,-0.03,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 4.4
	glColor3ub(115, 115, 115);
		glVertex2f(xc3, yc3); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc3+ (rc3* cos(i*twoPi / amount)),
			    yc3 + (rc3 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLoadIdentity();
	glPopMatrix();


		   //******************Plane****
glPushMatrix();
glTranslatef(plane_position,0,0);


	GLfloat xp=-0.4f; GLfloat yp=0.75f; GLfloat rp =0.025f;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(41, 163, 41);
		glVertex2f(xp, yp);
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xp + (rp * cos(i *  twoPi / amount)),
			    yp + (rp * sin(i * twoPi /amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);//body
	glColor3ub(41, 163, 41);
	glVertex2f(-0.39,0.725);
	glVertex2f(-0.6,0.725);
	glVertex2f(-0.65,0.765);
	glVertex2f(-0.65,0.8);
	glVertex2f(-0.43,0.8);
	glVertex2f(-0.39,0.775);
	glEnd();

	glBegin(GL_TRIANGLES);//wing behind
	glColor3ub(204, 0, 0);
	glVertex2f(-0.645,0.8);
	glVertex2f(-0.6,0.8);
	glVertex2f(-0.645,0.845);
	//glVertex2f();
	glEnd();

	glBegin(GL_POLYGON);//wing up
	glColor3ub(204, 0, 0);
	glVertex2f(-0.54,0.8);
	glVertex2f(-0.50,0.8);
	glVertex2f(-0.52,0.85);
	glVertex2f(-0.56,0.85);
	glEnd();

	glBegin(GL_POLYGON);//wing down
	glColor3ub(204, 0, 0);
	glVertex2f(-0.54,0.725);
	glVertex2f(-0.50,0.725);
	glVertex2f(-0.52,0.675);
	glVertex2f(-0.56,0.675);
	glEnd();

	glBegin(GL_POLYGON);//door
	glColor3ub(102, 153, 204);
	glVertex2f(-0.435,0.765);
	glVertex2f(-0.45,0.765);
	glVertex2f(-0.45,0.725);
	glVertex2f(-0.435,0.725);
	glEnd();


	glTranslatef(-0.033,0,0);
	glBegin(GL_POLYGON);//window
	glColor3ub(102, 153, 204);
	glVertex2f(-0.435,0.755);
	glVertex2f(-0.45,0.755);
	glVertex2f(-0.45,0.775);
	glVertex2f(-0.435,0.775);
	glEnd();

	glTranslatef(-0.033,0,0);
	glBegin(GL_POLYGON);//window
	glColor3ub(102, 153, 204);
	glVertex2f(-0.435,0.755);
	glVertex2f(-0.45,0.755);
	glVertex2f(-0.45,0.775);
	glVertex2f(-0.435,0.775);
	glEnd();


	glTranslatef(-0.033,0,0);
	glBegin(GL_POLYGON);//window
	glColor3ub(102, 153, 204);
	glVertex2f(-0.435,0.755);
	glVertex2f(-0.45,0.755);
	glVertex2f(-0.45,0.775);
	glVertex2f(-0.435,0.775);
	glEnd();


	glTranslatef(-0.033,0,0);
	glBegin(GL_POLYGON);//window
	glColor3ub(102, 153, 204);
	glVertex2f(-0.435,0.755);
	glVertex2f(-0.45,0.755);
	glVertex2f(-0.45,0.775);
	glVertex2f(-0.435,0.775);
	glEnd();
	glTranslatef(-0.033,0,0);
	glBegin(GL_POLYGON);//window
	glColor3ub(102, 153, 204);
	glVertex2f(-0.435,0.755);
	glVertex2f(-0.45,0.755);
	glVertex2f(-0.45,0.775);
	glVertex2f(-0.435,0.775);
	glEnd();
glLoadIdentity();
	glPopMatrix();


//****************************************************************************
glBegin(GL_POLYGON);//ground
	glColor3ub(0, 179, 60);
	glVertex2f(1.0,-1.0);
	glVertex2f(-1.0,-1.0);
	glVertex2f(-1.0,-0.2);
	glVertex2f(1.0,-0.2);
    glEnd();
    //red road
    glBegin(GL_POLYGON);//red road
	glColor3ub(255, 140, 102);
	glVertex2f(1.0,-0.2);
	glVertex2f(-1.0,-0.2);
	glVertex2f(-1.0,-0.325);
	glVertex2f(1.0,-0.325);
	glEnd();

glBegin(GL_POLYGON);//mosjid builduing tall
	glColor3ub(255, 255, 230);
	glVertex2f(0.41,-0.25);
	glVertex2f(-0.41,-0.25);
	glVertex2f(-0.41,0.9);
	glVertex2f(0.41,0.9);
    glEnd();
glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(0.41,-0.25);
glVertex2f(0.41,0.9);
glVertex2f(0.41,0.9);
glVertex2f(-0.41,0.9);
glVertex2f(-0.41,0.9);
glVertex2f(-0.41,-0.25);
glEnd();
glBegin(GL_POLYGON);//mosjid builduing longest
	glColor3ub(255, 255, 179);
	glVertex2f(0.88,-0.25);
	glVertex2f(-0.88,-0.25);
	glVertex2f(-0.88,0.1875);
	glVertex2f(0.88,0.1875);
    glEnd();
glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(0.88,0.1875);
glVertex2f(0.88,-0.25);
glVertex2f(0.88,-0.25);
glVertex2f(-0.88,-0.25);
glVertex2f(-0.88,-0.25);
glVertex2f(-0.88,0.1875);
glEnd();

    glBegin(GL_POLYGON);//mosjid builduing roof
	glColor3ub(204, 204, 179);
	glVertex2f(0.84,0.25);
	glVertex2f(-0.84,0.25);
	glVertex2f(-0.88,0.1875);
	glVertex2f(0.88,0.1875);
    glEnd();

glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(0.84,0.25);
glVertex2f(-0.84,0.25);
glVertex2f(-0.84,0.25);
glVertex2f(-0.88,0.1875);
glVertex2f(-0.88,0.1875);
glVertex2f(0.88,0.1875);
glVertex2f(0.88,0.1875);
glVertex2f(0.84,0.25);
glEnd();

glBegin(GL_POLYGON);//mosjid builduing black block 1
	glColor3ub(0,0,0);
	glVertex2f(0.41,0.65);
	glVertex2f(-0.41,0.65);
	glVertex2f(-0.41,0.675);
	glVertex2f(0.41,0.675);
    glEnd();
    glTranslatef(0,0.05,0);
    glBegin(GL_POLYGON);//mosjid builduing black block 2
	glColor3ub(0,0,0);
	glVertex2f(0.41,0.65);
	glVertex2f(-0.41,0.65);
	glVertex2f(-0.41,0.675);
	glVertex2f(0.41,0.675);
    glEnd();
    glTranslatef(0,-0.1,0);
    glBegin(GL_POLYGON);//mosjid builduing black block 3
	glColor3ub(0,0,0);
	glVertex2f(0.41,0.65);
	glVertex2f(-0.41,0.65);
	glVertex2f(-0.41,0.675);
	glVertex2f(0.41,0.675);
    glEnd();
    glLoadIdentity();
    //***********************************mosjid room block

    GLfloat x=-0.845; GLfloat y=0.135; GLfloat r=0.015;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();

    glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
    glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
    glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
    glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();

           glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
    glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();

glLoadIdentity();
////////////////////////////////////////////////////////////////////////////////////
GLfloat x1=-0.81; GLfloat y1=-0.1; GLfloat r1=0.035;
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();
glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glTranslatef(0.1,0,0);
   glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glTranslatef(0.1,0,0);

    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glLoadIdentity();
//*****************************************************
    glBegin(GL_POLYGON);//mosjid builduing door
	glColor3ub(255, 255, 230);
	glVertex2f(0.167,-0.1);
	glVertex2f(-0.167,-0.1);
	glVertex2f(-0.148,0.3375);
	glVertex2f(0.148,0.3375);
    glEnd();
glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(0.167,-0.1);
glVertex2f(-0.167,-0.1);
glVertex2f(-0.167,-0.1);
glVertex2f(-0.148,0.3375);
glVertex2f(-0.148,0.3375);
glVertex2f(0.148,0.3375);
glVertex2f(0.148,0.3375);
glVertex2f(0.167,-0.1);
glEnd();

GLfloat x2=-0.105; GLfloat y2=0.15; GLfloat r2=0.035;
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x2, y2); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x2+ (r2* cos(i *twoPi / amount)),
			    y2 + (r2 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.14,0.15);
	glVertex2f(-0.07,0.15);
	glVertex2f(-0.07,-0.05);
	glVertex2f(-0.14,-0.05);
    glEnd();

    glTranslatef(0.2,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x2, y2); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x2+ (r2* cos(i *twoPi / amount)),
			    y2 + (r2 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.14,0.15);
	glVertex2f(-0.07,0.15);
	glVertex2f(-0.07,-0.05);
	glVertex2f(-0.14,-0.05);
    glEnd();
    glLoadIdentity();

    glBegin(GL_POLYGON);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.05,0.15);
	glVertex2f(0.04,0.15);
	glVertex2f(0.04,-0.05);
	glVertex2f(-0.05,-0.05);
    glEnd();

    GLfloat x3=-0.005; GLfloat y3=0.16; GLfloat r3=0.055;
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x3, y3); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x3+ (r3* cos(i *twoPi / amount)),
			    y3 + (r3 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(51, 51, 51);
	glVertex2f(-0.0325,0.21);
	glVertex2f(0.0225,0.21);
	glVertex2f(-0.005,0.245);

    glEnd();


    glBegin(GL_POLYGON);//mosjid builduing door stair
	glColor3ub(223, 191, 159);
	glVertex2f(0.17,-0.1);
	glVertex2f(-0.17,-0.1);
	glVertex2f(-0.25,-0.26);
	glVertex2f(0.25,-0.26);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.17,-0.1);
	glVertex2f(-0.17,-0.1);
	glVertex2f(-0.17,-0.1);
	glVertex2f(-0.25,-0.26);
	glVertex2f(-0.25,-0.26);
	glVertex2f(0.25,-0.26);
	glVertex2f(0.25,-0.26);
	glVertex2f(0.17,-0.1);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.19,-0.14);
	glVertex2f(-0.19,-0.14);
	glVertex2f(0.21,-0.18);
	glVertex2f(-0.21,-0.18);
	glVertex2f(0.23,-0.22);
	glVertex2f(-0.23,-0.22);
	glEnd();

	//***************************Water Pool in front of mosque*********************************************
	glBegin(GL_POLYGON);//pool fringe road both side
	glColor3ub(255, 140, 102);
	glVertex2f(-0.25,-0.26);
	glVertex2f(0.25,-0.26);
	glVertex2f(0.45,-1.0);
	glVertex2f(-0.45,-1.0);
	glEnd();
	glBegin(GL_POLYGON);//pool fringe
	glColor3ub(191, 191, 191);
	glVertex2f(-0.1,-0.34);
	glVertex2f(0.1,-0.34);
	glVertex2f(0.2,-0.8);
	glVertex2f(-0.2,-0.8);
	glEnd();

	glBegin(GL_POLYGON);//shadow
	glColor3ub(64, 64, 64);
	glVertex2f(-0.095,-0.355);
	glVertex2f(0.095,-0.355);
	glVertex2f(0.18,-0.78);
	glVertex2f(-0.18,-0.78);
	glEnd();
	glBegin(GL_POLYGON);//water
	glColor3ub(179, 217, 255);
	glVertex2f(-0.092,-0.365);
	glVertex2f(0.092,-0.365);
	glVertex2f(0.165,-0.76);
	glVertex2f(-0.165,-0.76);
	glEnd();




    //****************************************Trees and LampPost*******************************
	glBegin(GL_POLYGON);//Tree Left1
	glColor3ub(96, 64, 32);
	glVertex2f(-0.73,-0.6);
	glVertex2f(-0.73,-0.5);
	glVertex2f(-0.70,-0.5);
	glVertex2f(-0.70,-0.6);
	glEnd();

    GLfloat xtl=-0.715; GLfloat ytl=-0.38; GLfloat rtl=0.12;
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(64,255,0);
		glVertex2f(xtl, ytl); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xtl+ (rtl* cos(i*twoPi / amount)),
			    ytl + (rtl * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(-0.125,-0.2,0);
glBegin(GL_POLYGON);//Tree Left2
	glColor3ub(96, 64, 32);
	glVertex2f(-0.73,-0.6);
	glVertex2f(-0.73,-0.5);
	glVertex2f(-0.70,-0.5);
	glVertex2f(-0.70,-0.6);
	glEnd();
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(187,255,51);
		glVertex2f(xtl, ytl); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xtl+ (rtl* cos(i*twoPi / amount)),
			    ytl + (rtl * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLoadIdentity();

	glBegin(GL_POLYGON);//Tree Right1
	glColor3ub(96, 64, 32);
	glVertex2f(0.73,-0.6);
	glVertex2f(0.73,-0.5);
	glVertex2f(0.70,-0.5);
	glVertex2f(0.70,-0.6);
	glEnd();

    GLfloat xtr=0.715; GLfloat ytr=-0.38; GLfloat rtr=0.12;
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(187,255,51);
		glVertex2f(xtr, ytr); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xtr+ (rtr* cos(i*twoPi / amount)),
			    ytr + (rtr * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.125,-0.2,0);
glBegin(GL_POLYGON);//Tree Right2
	glColor3ub(96, 64, 32);
	glVertex2f(0.73,-0.6);
	glVertex2f(0.73,-0.5);
	glVertex2f(0.70,-0.5);
	glVertex2f(0.70,-0.6);
	glEnd();
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(64,255,0);
		glVertex2f(xtr, ytr); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xtr+ (rtr* cos(i*twoPi / amount)),
			    ytr + (rtr * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLoadIdentity();

	//----------------------------- LampPost -----------------------------------
	glBegin(GL_POLYGON);//Lamp Left
	glColor3ub(89, 89, 89);
	glVertex2f(-0.33,-0.4);
	glVertex2f(-0.33,-0.25);
    glVertex2f(-0.3,-0.25);
    glVertex2f(-0.3,-0.4);
	glEnd();
	GLfloat xll=-0.315; GLfloat yll=-0.24; GLfloat rll=0.03;
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(242, 242, 242);
		glVertex2f(xll, yll); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xll+ (rll* cos(i*twoPi / amount)),
			    yll + (rll * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glTranslatef(-0.65,0,0);
	glBegin(GL_POLYGON);//Lamp Left
	glColor3ub(89, 89, 89);
	glVertex2f(-0.33,-0.4);
	glVertex2f(-0.33,-0.25);
    glVertex2f(-0.3,-0.25);
    glVertex2f(-0.3,-0.4);
	glEnd();

    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(242, 242, 242);
		glVertex2f(xll, yll); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xll+ (rll* cos(i*twoPi / amount)),
			    yll + (rll * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLoadIdentity();

	glTranslatef(0.64,0,0);
	glBegin(GL_POLYGON);//Lamp Left
	glColor3ub(89, 89, 89);
	glVertex2f(-0.33,-0.4);
	glVertex2f(-0.33,-0.25);
    glVertex2f(-0.3,-0.25);
    glVertex2f(-0.3,-0.4);
	glEnd();

    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(242, 242, 242);
		glVertex2f(xll, yll); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xll+ (rll* cos(i*twoPi / amount)),
			    yll + (rll * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLoadIdentity();

	glTranslatef(1.28,0,0);
	glBegin(GL_POLYGON);//Lamp Left
	glColor3ub(89, 89, 89);
	glVertex2f(-0.33,-0.4);
	glVertex2f(-0.33,-0.25);
    glVertex2f(-0.3,-0.25);
    glVertex2f(-0.3,-0.4);
	glEnd();

    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(242, 242, 242);
		glVertex2f(xll, yll); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xll+ (rll* cos(i*twoPi / amount)),
			    yll + (rll * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLoadIdentity();

glBegin(GL_POLYGON);//Lamp Right
	glColor3ub(89, 89, 89);
	glVertex2f(-0.49,-0.95);
	glVertex2f(-0.49,-0.8);
    glVertex2f(-0.46,-0.8);
    glVertex2f(-0.46,-0.95);
	glEnd();
	GLfloat xlr=-0.475; GLfloat ylr=-0.79; GLfloat rlr=0.03;
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(242, 242, 242);
		glVertex2f(xlr, ylr); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xlr+ (rlr* cos(i*twoPi / amount)),
			    ylr + (rlr * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.935,0,0);
	glBegin(GL_POLYGON);//Lamp Right
	glColor3ub(89, 89, 89);
	glVertex2f(-0.49,-0.95);
	glVertex2f(-0.49,-0.8);
    glVertex2f(-0.46,-0.8);
    glVertex2f(-0.46,-0.95);
	glEnd();
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(242, 242, 242);
		glVertex2f(xlr, ylr); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xlr+ (rlr* cos(i*twoPi / amount)),
			    ylr + (rlr * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLoadIdentity();

	//++++++++++++++++++++++++ Man  ++++++++++++++++++++++++++++++++++++++++++++++++++
	glPushMatrix();
	glTranslatef(0.0,manr_position,0);
	glBegin(GL_POLYGON);//Man Right
	glColor3ub(92, 138, 138);
	glVertex2f(0.27,-0.35);
	glVertex2f(0.27,-0.45);
    glVertex2f(0.23,-0.45);
    glVertex2f(0.23,-0.35);
	glEnd();
	GLfloat xmr=0.25; GLfloat ymr=-0.34; GLfloat rmr=0.015;
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(0,0,0);
		glVertex2f(xmr, ymr); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xmr+ (rmr* cos(i*twoPi / amount)),
			    ymr + (rmr * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLineWidth(5.0);
	glBegin(GL_LINES);//Man Right
	glColor3ub(0,0,0);
	glVertex2f(0.27,-0.37);
	glVertex2f(0.2775,-0.37);
    glVertex2f(0.23,-0.37);
    glVertex2f(0.2225,-0.37);
	glEnd();

	glLineWidth(3.0);
	glBegin(GL_LINES);//Man Right umbrella stick
	glColor3ub(0,0,0);
	glVertex2f(0.2775,-0.37);
	glVertex2f(0.2775,-0.3);
    glEnd();
    glBegin(GL_POLYGON);//Man Right umbrella
	glColor3ub(153, 0, 77);
	glVertex2f(0.22,-0.33);
	glVertex2f(0.31,-0.33);
    glVertex2f(0.28,-0.3);
    glVertex2f(0.25,-0.3);
	glEnd();

	glLoadIdentity();
	glPopMatrix();
glPushMatrix();
glTranslatef(0,manl_position,0);
	glBegin(GL_POLYGON);//Man Left
	glColor3ub(255, 153, 255);
	glVertex2f(-0.27,-0.7);
	glVertex2f(-0.27,-0.8);
    glVertex2f(-0.23,-0.8);
    glVertex2f(-0.23,-0.7);
	glEnd();
	GLfloat xml=-0.25; GLfloat yml=-0.69; GLfloat rml=0.015;
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(0,0,0);
		glVertex2f(xml, yml); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xml+ (rml* cos(i*twoPi / amount)),
			    yml + (rml * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLineWidth(5.0);
	glBegin(GL_LINES);//Man Left
	glColor3ub(0,0,0);
	glVertex2f(-0.27,-0.72);
	glVertex2f(-0.2775,-0.72);
    glVertex2f(-0.23,-0.72);
    glVertex2f(-0.2225,-0.72);
	glEnd();

	glLineWidth(3.0);
	glBegin(GL_LINES);//Man Left umbrella stick
	glColor3ub(0,0,0);
	glVertex2f(-0.2225,-0.72);
	glVertex2f(-0.2225,-0.65);
    glEnd();
    glBegin(GL_POLYGON);//Man Left umbrella
	glColor3ub(153, 51, 51);
	glVertex2f(-0.21,-0.66);
	glVertex2f(-0.28,-0.66);
    glVertex2f(-0.26,-0.63);
    glVertex2f(-0.23,-0.63);
	glEnd();

	glLoadIdentity();
	glPopMatrix();



	//------------------------------------- Rain -------------------------------
glPushMatrix();
glTranslatef(rain_position,rain_position,0);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-0.98,0.93);
	glVertex2f(-0.96,0.99);
    glVertex2f(-0.92,0.93);
	glVertex2f(-0.90,0.99);
    glVertex2f(-0.86,0.93);
	glVertex2f(-0.84,0.99);
    glVertex2f(-0.80,0.93);
	glVertex2f(-0.78,0.99);
    glVertex2f(-0.74,0.93);
	glVertex2f(-0.72,0.99);
    glVertex2f(-0.68,0.93);
	glVertex2f(-0.66,0.99);
    glVertex2f(-0.62,0.93);
	glVertex2f(-0.60,0.99);
    glVertex2f(-0.56,0.93);
	glVertex2f(-0.54,0.99);
    glVertex2f(-0.50,0.93);
	glVertex2f(-0.48,0.99);
    glVertex2f(-0.44,0.93);
	glVertex2f(-0.42,0.99);
    glVertex2f(-0.38,0.93);
	glVertex2f(-0.36,0.99);
    glVertex2f(-0.32,0.93);
	glVertex2f(-0.30,0.99);
    glVertex2f(-0.26,0.93);
	glVertex2f(-0.24,0.99);
    glVertex2f(-0.20,0.93);
	glVertex2f(-0.18,0.99);
    glVertex2f(-0.14,0.93);
	glVertex2f(-0.12,0.99);
    glVertex2f(-0.08,0.93);
	glVertex2f(-0.06,0.99);
    glVertex2f(-0.02,0.93);
	glVertex2f(-0.00,0.99);
    glVertex2f(0.04,0.93);
	glVertex2f(0.06,0.99);
    glVertex2f(0.1,0.93);
	glVertex2f(0.12,0.99);
    glVertex2f(0.16,0.93);
	glVertex2f(0.18,0.99);
    glVertex2f(0.22,0.93);
	glVertex2f(0.24,0.99);
    glVertex2f(0.28,0.93);
	glVertex2f(0.30,0.99);
    glVertex2f(0.34,0.93);
	glVertex2f(0.36,0.99);
    glVertex2f(0.40,0.93);
	glVertex2f(0.42,0.99);
    glVertex2f(0.46,0.93);
	glVertex2f(0.48,0.99);
    glVertex2f(0.52,0.93);
	glVertex2f(0.54,0.99);
    glVertex2f(0.58,0.93);
	glVertex2f(0.60,0.99);
    glVertex2f(0.64,0.93);
	glVertex2f(0.66,0.99);
    glVertex2f(0.70,0.93);
	glVertex2f(0.72,0.99);
    glVertex2f(0.76,0.93);
	glVertex2f(0.78,0.99);
    glVertex2f(0.82,0.93);
	glVertex2f(0.84,0.99);
    glVertex2f(0.88,0.93);
	glVertex2f(0.90,0.99);
    glVertex2f(0.94,0.93);
	glVertex2f(0.96,0.99);
    glVertex2f(1.0,0.93);
	glVertex2f(1.02,0.99);
    glEnd();
glTranslatef(0,-0.125,0);
    glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-0.98,0.93);
	glVertex2f(-0.96,0.99);
    glVertex2f(-0.92,0.93);
	glVertex2f(-0.90,0.99);
    glVertex2f(-0.86,0.93);
	glVertex2f(-0.84,0.99);
    glVertex2f(-0.80,0.93);
	glVertex2f(-0.78,0.99);
    glVertex2f(-0.74,0.93);
	glVertex2f(-0.72,0.99);
    glVertex2f(-0.68,0.93);
	glVertex2f(-0.66,0.99);
    glVertex2f(-0.62,0.93);
	glVertex2f(-0.60,0.99);
    glVertex2f(-0.56,0.93);
	glVertex2f(-0.54,0.99);
    glVertex2f(-0.50,0.93);
	glVertex2f(-0.48,0.99);
    glVertex2f(-0.44,0.93);
	glVertex2f(-0.42,0.99);
    glVertex2f(-0.38,0.93);
	glVertex2f(-0.36,0.99);
    glVertex2f(-0.32,0.93);
	glVertex2f(-0.30,0.99);
    glVertex2f(-0.26,0.93);
	glVertex2f(-0.24,0.99);
    glVertex2f(-0.20,0.93);
	glVertex2f(-0.18,0.99);
    glVertex2f(-0.14,0.93);
	glVertex2f(-0.12,0.99);
    glVertex2f(-0.08,0.93);
	glVertex2f(-0.06,0.99);
    glVertex2f(-0.02,0.93);
	glVertex2f(-0.00,0.99);
	glVertex2f(0.04,0.93);
	glVertex2f(0.06,0.99);
    glVertex2f(0.1,0.93);
	glVertex2f(0.12,0.99);
    glVertex2f(0.16,0.93);
	glVertex2f(0.18,0.99);
    glVertex2f(0.22,0.93);
	glVertex2f(0.24,0.99);
    glVertex2f(0.28,0.93);
	glVertex2f(0.30,0.99);
    glVertex2f(0.34,0.93);
	glVertex2f(0.36,0.99);
    glVertex2f(0.40,0.93);
	glVertex2f(0.42,0.99);
    glVertex2f(0.46,0.93);
	glVertex2f(0.48,0.99);
    glVertex2f(0.52,0.93);
	glVertex2f(0.54,0.99);
    glVertex2f(0.58,0.93);
	glVertex2f(0.60,0.99);
    glVertex2f(0.64,0.93);
	glVertex2f(0.66,0.99);
    glVertex2f(0.70,0.93);
	glVertex2f(0.72,0.99);
    glVertex2f(0.76,0.93);
	glVertex2f(0.78,0.99);
    glVertex2f(0.82,0.93);
	glVertex2f(0.84,0.99);
    glVertex2f(0.88,0.93);
	glVertex2f(0.90,0.99);
    glVertex2f(0.94,0.93);
	glVertex2f(0.96,0.99);
    glVertex2f(1.0,0.93);
	glVertex2f(1.02,0.99);
    glEnd();
glTranslatef(0,-0.125,0);
    glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-0.98,0.93);
	glVertex2f(-0.96,0.99);
    glVertex2f(-0.92,0.93);
	glVertex2f(-0.90,0.99);
    glVertex2f(-0.86,0.93);
	glVertex2f(-0.84,0.99);
    glVertex2f(-0.80,0.93);
	glVertex2f(-0.78,0.99);
    glVertex2f(-0.74,0.93);
	glVertex2f(-0.72,0.99);
    glVertex2f(-0.68,0.93);
	glVertex2f(-0.66,0.99);
    glVertex2f(-0.62,0.93);
	glVertex2f(-0.60,0.99);
    glVertex2f(-0.56,0.93);
	glVertex2f(-0.54,0.99);
    glVertex2f(-0.50,0.93);
	glVertex2f(-0.48,0.99);
    glVertex2f(-0.44,0.93);
	glVertex2f(-0.42,0.99);
    glVertex2f(-0.38,0.93);
	glVertex2f(-0.36,0.99);
    glVertex2f(-0.32,0.93);
	glVertex2f(-0.30,0.99);
    glVertex2f(-0.26,0.93);
	glVertex2f(-0.24,0.99);
    glVertex2f(-0.20,0.93);
	glVertex2f(-0.18,0.99);
    glVertex2f(-0.14,0.93);
	glVertex2f(-0.12,0.99);
    glVertex2f(-0.08,0.93);
	glVertex2f(-0.06,0.99);
    glVertex2f(-0.02,0.93);
	glVertex2f(-0.00,0.99);
    glVertex2f(0.04,0.93);
	glVertex2f(0.06,0.99);
    glVertex2f(0.1,0.93);
	glVertex2f(0.12,0.99);
    glVertex2f(0.16,0.93);
	glVertex2f(0.18,0.99);
    glVertex2f(0.22,0.93);
	glVertex2f(0.24,0.99);
    glVertex2f(0.28,0.93);
	glVertex2f(0.30,0.99);
    glVertex2f(0.34,0.93);
	glVertex2f(0.36,0.99);
    glVertex2f(0.40,0.93);
	glVertex2f(0.42,0.99);
    glVertex2f(0.46,0.93);
	glVertex2f(0.48,0.99);
    glVertex2f(0.52,0.93);
	glVertex2f(0.54,0.99);
    glVertex2f(0.58,0.93);
	glVertex2f(0.60,0.99);
    glVertex2f(0.64,0.93);
	glVertex2f(0.66,0.99);
    glVertex2f(0.70,0.93);
	glVertex2f(0.72,0.99);
    glVertex2f(0.76,0.93);
	glVertex2f(0.78,0.99);
    glVertex2f(0.82,0.93);
	glVertex2f(0.84,0.99);
    glVertex2f(0.88,0.93);
	glVertex2f(0.90,0.99);
    glVertex2f(0.94,0.93);
	glVertex2f(0.96,0.99);
    glVertex2f(1.0,0.93);
	glVertex2f(1.02,0.99);
    glEnd();
glTranslatef(0,-0.125,0);
    glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-0.98,0.93);
	glVertex2f(-0.96,0.99);
    glVertex2f(-0.92,0.93);
	glVertex2f(-0.90,0.99);
    glVertex2f(-0.86,0.93);
	glVertex2f(-0.84,0.99);
    glVertex2f(-0.80,0.93);
	glVertex2f(-0.78,0.99);
    glVertex2f(-0.74,0.93);
	glVertex2f(-0.72,0.99);
    glVertex2f(-0.68,0.93);
	glVertex2f(-0.66,0.99);
    glVertex2f(-0.62,0.93);
	glVertex2f(-0.60,0.99);
    glVertex2f(-0.56,0.93);
	glVertex2f(-0.54,0.99);
    glVertex2f(-0.50,0.93);
	glVertex2f(-0.48,0.99);
    glVertex2f(-0.44,0.93);
	glVertex2f(-0.42,0.99);
    glVertex2f(-0.38,0.93);
	glVertex2f(-0.36,0.99);
    glVertex2f(-0.32,0.93);
	glVertex2f(-0.30,0.99);
    glVertex2f(-0.26,0.93);
	glVertex2f(-0.24,0.99);
    glVertex2f(-0.20,0.93);
	glVertex2f(-0.18,0.99);
    glVertex2f(-0.14,0.93);
	glVertex2f(-0.12,0.99);
    glVertex2f(-0.08,0.93);
	glVertex2f(-0.06,0.99);
    glVertex2f(-0.02,0.93);
	glVertex2f(-0.00,0.99);
    glVertex2f(0.04,0.93);
	glVertex2f(0.06,0.99);
    glVertex2f(0.1,0.93);
	glVertex2f(0.12,0.99);
    glVertex2f(0.16,0.93);
	glVertex2f(0.18,0.99);
    glVertex2f(0.22,0.93);
	glVertex2f(0.24,0.99);
    glVertex2f(0.28,0.93);
	glVertex2f(0.30,0.99);
    glVertex2f(0.34,0.93);
	glVertex2f(0.36,0.99);
    glVertex2f(0.40,0.93);
	glVertex2f(0.42,0.99);
    glVertex2f(0.46,0.93);
	glVertex2f(0.48,0.99);
    glVertex2f(0.52,0.93);
	glVertex2f(0.54,0.99);
    glVertex2f(0.58,0.93);
	glVertex2f(0.60,0.99);
    glVertex2f(0.64,0.93);
	glVertex2f(0.66,0.99);
    glVertex2f(0.70,0.93);
	glVertex2f(0.72,0.99);
    glVertex2f(0.76,0.93);
	glVertex2f(0.78,0.99);
    glVertex2f(0.82,0.93);
	glVertex2f(0.84,0.99);
    glVertex2f(0.88,0.93);
	glVertex2f(0.90,0.99);
    glVertex2f(0.94,0.93);
	glVertex2f(0.96,0.99);
    glVertex2f(1.0,0.93);
	glVertex2f(1.02,0.99);
    glEnd();
glTranslatef(0,-0.125,0);
    glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-0.98,0.93);
	glVertex2f(-0.96,0.99);
    glVertex2f(-0.92,0.93);
	glVertex2f(-0.90,0.99);
    glVertex2f(-0.86,0.93);
	glVertex2f(-0.84,0.99);
    glVertex2f(-0.80,0.93);
	glVertex2f(-0.78,0.99);
    glVertex2f(-0.74,0.93);
	glVertex2f(-0.72,0.99);
    glVertex2f(-0.68,0.93);
	glVertex2f(-0.66,0.99);
    glVertex2f(-0.62,0.93);
	glVertex2f(-0.60,0.99);
    glVertex2f(-0.56,0.93);
	glVertex2f(-0.54,0.99);
    glVertex2f(-0.50,0.93);
	glVertex2f(-0.48,0.99);
    glVertex2f(-0.44,0.93);
	glVertex2f(-0.42,0.99);
    glVertex2f(-0.38,0.93);
	glVertex2f(-0.36,0.99);
    glVertex2f(-0.32,0.93);
	glVertex2f(-0.30,0.99);
    glVertex2f(-0.26,0.93);
	glVertex2f(-0.24,0.99);
    glVertex2f(-0.20,0.93);
	glVertex2f(-0.18,0.99);
    glVertex2f(-0.14,0.93);
	glVertex2f(-0.12,0.99);
    glVertex2f(-0.08,0.93);
	glVertex2f(-0.06,0.99);
    glVertex2f(-0.02,0.93);
	glVertex2f(-0.00,0.99);
    glVertex2f(0.04,0.93);
	glVertex2f(0.06,0.99);
    glVertex2f(0.1,0.93);
	glVertex2f(0.12,0.99);
    glVertex2f(0.16,0.93);
	glVertex2f(0.18,0.99);
    glVertex2f(0.22,0.93);
	glVertex2f(0.24,0.99);
    glVertex2f(0.28,0.93);
	glVertex2f(0.30,0.99);
    glVertex2f(0.34,0.93);
	glVertex2f(0.36,0.99);
    glVertex2f(0.40,0.93);
	glVertex2f(0.42,0.99);
    glVertex2f(0.46,0.93);
	glVertex2f(0.48,0.99);
    glVertex2f(0.52,0.93);
	glVertex2f(0.54,0.99);
    glVertex2f(0.58,0.93);
	glVertex2f(0.60,0.99);
    glVertex2f(0.64,0.93);
	glVertex2f(0.66,0.99);
    glVertex2f(0.70,0.93);
	glVertex2f(0.72,0.99);
    glVertex2f(0.76,0.93);
	glVertex2f(0.78,0.99);
    glVertex2f(0.82,0.93);
	glVertex2f(0.84,0.99);
    glVertex2f(0.88,0.93);
	glVertex2f(0.90,0.99);
    glVertex2f(0.94,0.93);
	glVertex2f(0.96,0.99);
    glVertex2f(1.0,0.93);
	glVertex2f(1.02,0.99);
    glEnd();
glTranslatef(0,-0.125,0);
    glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-0.98,0.93);
	glVertex2f(-0.96,0.99);
    glVertex2f(-0.92,0.93);
	glVertex2f(-0.90,0.99);
    glVertex2f(-0.86,0.93);
	glVertex2f(-0.84,0.99);
    glVertex2f(-0.80,0.93);
	glVertex2f(-0.78,0.99);
    glVertex2f(-0.74,0.93);
	glVertex2f(-0.72,0.99);
    glVertex2f(-0.68,0.93);
	glVertex2f(-0.66,0.99);
    glVertex2f(-0.62,0.93);
	glVertex2f(-0.60,0.99);
    glVertex2f(-0.56,0.93);
	glVertex2f(-0.54,0.99);
    glVertex2f(-0.50,0.93);
	glVertex2f(-0.48,0.99);
    glVertex2f(-0.44,0.93);
	glVertex2f(-0.42,0.99);
    glVertex2f(-0.38,0.93);
	glVertex2f(-0.36,0.99);
    glVertex2f(-0.32,0.93);
	glVertex2f(-0.30,0.99);
    glVertex2f(-0.26,0.93);
	glVertex2f(-0.24,0.99);
    glVertex2f(-0.20,0.93);
	glVertex2f(-0.18,0.99);
    glVertex2f(-0.14,0.93);
	glVertex2f(-0.12,0.99);
    glVertex2f(-0.08,0.93);
	glVertex2f(-0.06,0.99);
    glVertex2f(-0.02,0.93);
	glVertex2f(-0.00,0.99);
    glVertex2f(0.04,0.93);
	glVertex2f(0.06,0.99);
    glVertex2f(0.1,0.93);
	glVertex2f(0.12,0.99);
    glVertex2f(0.16,0.93);
	glVertex2f(0.18,0.99);
    glVertex2f(0.22,0.93);
	glVertex2f(0.24,0.99);
    glVertex2f(0.28,0.93);
	glVertex2f(0.30,0.99);
    glVertex2f(0.34,0.93);
	glVertex2f(0.36,0.99);
    glVertex2f(0.40,0.93);
	glVertex2f(0.42,0.99);
    glVertex2f(0.46,0.93);
	glVertex2f(0.48,0.99);
    glVertex2f(0.52,0.93);
	glVertex2f(0.54,0.99);
    glVertex2f(0.58,0.93);
	glVertex2f(0.60,0.99);
    glVertex2f(0.64,0.93);
	glVertex2f(0.66,0.99);
    glVertex2f(0.70,0.93);
	glVertex2f(0.72,0.99);
    glVertex2f(0.76,0.93);
	glVertex2f(0.78,0.99);
    glVertex2f(0.82,0.93);
	glVertex2f(0.84,0.99);
    glVertex2f(0.88,0.93);
	glVertex2f(0.90,0.99);
    glVertex2f(0.94,0.93);
	glVertex2f(0.96,0.99);
    glVertex2f(1.0,0.93);
	glVertex2f(1.02,0.99);
    glEnd();
glTranslatef(0,-0.125,0);
    glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-0.98,0.93);
	glVertex2f(-0.96,0.99);
    glVertex2f(-0.92,0.93);
	glVertex2f(-0.90,0.99);
    glVertex2f(-0.86,0.93);
	glVertex2f(-0.84,0.99);
    glVertex2f(-0.80,0.93);
	glVertex2f(-0.78,0.99);
    glVertex2f(-0.74,0.93);
	glVertex2f(-0.72,0.99);
    glVertex2f(-0.68,0.93);
	glVertex2f(-0.66,0.99);
    glVertex2f(-0.62,0.93);
	glVertex2f(-0.60,0.99);
    glVertex2f(-0.56,0.93);
	glVertex2f(-0.54,0.99);
    glVertex2f(-0.50,0.93);
	glVertex2f(-0.48,0.99);
    glVertex2f(-0.44,0.93);
	glVertex2f(-0.42,0.99);
    glVertex2f(-0.38,0.93);
	glVertex2f(-0.36,0.99);
    glVertex2f(-0.32,0.93);
	glVertex2f(-0.30,0.99);
    glVertex2f(-0.26,0.93);
	glVertex2f(-0.24,0.99);
    glVertex2f(-0.20,0.93);
	glVertex2f(-0.18,0.99);
    glVertex2f(-0.14,0.93);
	glVertex2f(-0.12,0.99);
    glVertex2f(-0.08,0.93);
	glVertex2f(-0.06,0.99);
    glVertex2f(-0.02,0.93);
	glVertex2f(-0.00,0.99);
    glVertex2f(0.04,0.93);
	glVertex2f(0.06,0.99);
    glVertex2f(0.1,0.93);
	glVertex2f(0.12,0.99);
    glVertex2f(0.16,0.93);
	glVertex2f(0.18,0.99);
    glVertex2f(0.22,0.93);
	glVertex2f(0.24,0.99);
    glVertex2f(0.28,0.93);
	glVertex2f(0.30,0.99);
    glVertex2f(0.34,0.93);
	glVertex2f(0.36,0.99);
    glVertex2f(0.40,0.93);
	glVertex2f(0.42,0.99);
    glVertex2f(0.46,0.93);
	glVertex2f(0.48,0.99);
    glVertex2f(0.52,0.93);
	glVertex2f(0.54,0.99);
    glVertex2f(0.58,0.93);
	glVertex2f(0.60,0.99);
    glVertex2f(0.64,0.93);
	glVertex2f(0.66,0.99);
    glVertex2f(0.70,0.93);
	glVertex2f(0.72,0.99);
    glVertex2f(0.76,0.93);
	glVertex2f(0.78,0.99);
    glVertex2f(0.82,0.93);
	glVertex2f(0.84,0.99);
    glVertex2f(0.88,0.93);
	glVertex2f(0.90,0.99);
    glVertex2f(0.94,0.93);
	glVertex2f(0.96,0.99);
    glVertex2f(1.0,0.93);
	glVertex2f(1.02,0.99);
    glEnd();
glTranslatef(0,-0.125,0);
    glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-0.98,0.93);
	glVertex2f(-0.96,0.99);
    glVertex2f(-0.92,0.93);
	glVertex2f(-0.90,0.99);
    glVertex2f(-0.86,0.93);
	glVertex2f(-0.84,0.99);
    glVertex2f(-0.80,0.93);
	glVertex2f(-0.78,0.99);
    glVertex2f(-0.74,0.93);
	glVertex2f(-0.72,0.99);
    glVertex2f(-0.68,0.93);
	glVertex2f(-0.66,0.99);
    glVertex2f(-0.62,0.93);
	glVertex2f(-0.60,0.99);
    glVertex2f(-0.56,0.93);
	glVertex2f(-0.54,0.99);
    glVertex2f(-0.50,0.93);
	glVertex2f(-0.48,0.99);
    glVertex2f(-0.44,0.93);
	glVertex2f(-0.42,0.99);
    glVertex2f(-0.38,0.93);
	glVertex2f(-0.36,0.99);
    glVertex2f(-0.32,0.93);
	glVertex2f(-0.30,0.99);
    glVertex2f(-0.26,0.93);
	glVertex2f(-0.24,0.99);
    glVertex2f(-0.20,0.93);
	glVertex2f(-0.18,0.99);
    glVertex2f(-0.14,0.93);
	glVertex2f(-0.12,0.99);
    glVertex2f(-0.08,0.93);
	glVertex2f(-0.06,0.99);
    glVertex2f(-0.02,0.93);
	glVertex2f(-0.00,0.99);
    glVertex2f(0.04,0.93);
	glVertex2f(0.06,0.99);
    glVertex2f(0.1,0.93);
	glVertex2f(0.12,0.99);
    glVertex2f(0.16,0.93);
	glVertex2f(0.18,0.99);
    glVertex2f(0.22,0.93);
	glVertex2f(0.24,0.99);
    glVertex2f(0.28,0.93);
	glVertex2f(0.30,0.99);
    glVertex2f(0.34,0.93);
	glVertex2f(0.36,0.99);
    glVertex2f(0.40,0.93);
	glVertex2f(0.42,0.99);
    glVertex2f(0.46,0.93);
	glVertex2f(0.48,0.99);
    glVertex2f(0.52,0.93);
	glVertex2f(0.54,0.99);
    glVertex2f(0.58,0.93);
	glVertex2f(0.60,0.99);
    glVertex2f(0.64,0.93);
	glVertex2f(0.66,0.99);
    glVertex2f(0.70,0.93);
	glVertex2f(0.72,0.99);
    glVertex2f(0.76,0.93);
	glVertex2f(0.78,0.99);
    glVertex2f(0.82,0.93);
	glVertex2f(0.84,0.99);
    glVertex2f(0.88,0.93);
	glVertex2f(0.90,0.99);
    glVertex2f(0.94,0.93);
	glVertex2f(0.96,0.99);
    glVertex2f(1.0,0.93);
	glVertex2f(1.02,0.99);
    glEnd();
glTranslatef(0,-0.125,0);
    glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-0.98,0.93);
	glVertex2f(-0.96,0.99);
    glVertex2f(-0.92,0.93);
	glVertex2f(-0.90,0.99);
    glVertex2f(-0.86,0.93);
	glVertex2f(-0.84,0.99);
    glVertex2f(-0.80,0.93);
	glVertex2f(-0.78,0.99);
    glVertex2f(-0.74,0.93);
	glVertex2f(-0.72,0.99);
    glVertex2f(-0.68,0.93);
	glVertex2f(-0.66,0.99);
    glVertex2f(-0.62,0.93);
	glVertex2f(-0.60,0.99);
    glVertex2f(-0.56,0.93);
	glVertex2f(-0.54,0.99);
    glVertex2f(-0.50,0.93);
	glVertex2f(-0.48,0.99);
    glVertex2f(-0.44,0.93);
	glVertex2f(-0.42,0.99);
    glVertex2f(-0.38,0.93);
	glVertex2f(-0.36,0.99);
    glVertex2f(-0.32,0.93);
	glVertex2f(-0.30,0.99);
    glVertex2f(-0.26,0.93);
	glVertex2f(-0.24,0.99);
    glVertex2f(-0.20,0.93);
	glVertex2f(-0.18,0.99);
    glVertex2f(-0.14,0.93);
	glVertex2f(-0.12,0.99);
    glVertex2f(-0.08,0.93);
	glVertex2f(-0.06,0.99);
    glVertex2f(-0.02,0.93);
	glVertex2f(-0.00,0.99);
    glVertex2f(0.04,0.93);
	glVertex2f(0.06,0.99);
    glVertex2f(0.1,0.93);
	glVertex2f(0.12,0.99);
    glVertex2f(0.16,0.93);
	glVertex2f(0.18,0.99);
    glVertex2f(0.22,0.93);
	glVertex2f(0.24,0.99);
    glVertex2f(0.28,0.93);
	glVertex2f(0.30,0.99);
    glVertex2f(0.34,0.93);
	glVertex2f(0.36,0.99);
    glVertex2f(0.40,0.93);
	glVertex2f(0.42,0.99);
    glVertex2f(0.46,0.93);
	glVertex2f(0.48,0.99);
    glVertex2f(0.52,0.93);
	glVertex2f(0.54,0.99);
    glVertex2f(0.58,0.93);
	glVertex2f(0.60,0.99);
    glVertex2f(0.64,0.93);
	glVertex2f(0.66,0.99);
    glVertex2f(0.70,0.93);
	glVertex2f(0.72,0.99);
    glVertex2f(0.76,0.93);
	glVertex2f(0.78,0.99);
    glVertex2f(0.82,0.93);
	glVertex2f(0.84,0.99);
    glVertex2f(0.88,0.93);
	glVertex2f(0.90,0.99);
    glVertex2f(0.94,0.93);
	glVertex2f(0.96,0.99);
    glVertex2f(1.0,0.93);
	glVertex2f(1.02,0.99);
    glEnd();
glTranslatef(0,-0.125,0);
    glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-0.98,0.93);
	glVertex2f(-0.96,0.99);
    glVertex2f(-0.92,0.93);
	glVertex2f(-0.90,0.99);
    glVertex2f(-0.86,0.93);
	glVertex2f(-0.84,0.99);
    glVertex2f(-0.80,0.93);
	glVertex2f(-0.78,0.99);
    glVertex2f(-0.74,0.93);
	glVertex2f(-0.72,0.99);
    glVertex2f(-0.68,0.93);
	glVertex2f(-0.66,0.99);
    glVertex2f(-0.62,0.93);
	glVertex2f(-0.60,0.99);
    glVertex2f(-0.56,0.93);
	glVertex2f(-0.54,0.99);
    glVertex2f(-0.50,0.93);
	glVertex2f(-0.48,0.99);
    glVertex2f(-0.44,0.93);
	glVertex2f(-0.42,0.99);
    glVertex2f(-0.38,0.93);
	glVertex2f(-0.36,0.99);
    glVertex2f(-0.32,0.93);
	glVertex2f(-0.30,0.99);
    glVertex2f(-0.26,0.93);
	glVertex2f(-0.24,0.99);
    glVertex2f(-0.20,0.93);
	glVertex2f(-0.18,0.99);
    glVertex2f(-0.14,0.93);
	glVertex2f(-0.12,0.99);
    glVertex2f(-0.08,0.93);
	glVertex2f(-0.06,0.99);
    glVertex2f(-0.02,0.93);
	glVertex2f(-0.00,0.99);
    glVertex2f(0.04,0.93);
	glVertex2f(0.06,0.99);
    glVertex2f(0.1,0.93);
	glVertex2f(0.12,0.99);
    glVertex2f(0.16,0.93);
	glVertex2f(0.18,0.99);
    glVertex2f(0.22,0.93);
	glVertex2f(0.24,0.99);
    glVertex2f(0.28,0.93);
	glVertex2f(0.30,0.99);
    glVertex2f(0.34,0.93);
	glVertex2f(0.36,0.99);
    glVertex2f(0.40,0.93);
	glVertex2f(0.42,0.99);
    glVertex2f(0.46,0.93);
	glVertex2f(0.48,0.99);
    glVertex2f(0.52,0.93);
	glVertex2f(0.54,0.99);
    glVertex2f(0.58,0.93);
	glVertex2f(0.60,0.99);
    glVertex2f(0.64,0.93);
	glVertex2f(0.66,0.99);
    glVertex2f(0.70,0.93);
	glVertex2f(0.72,0.99);
    glVertex2f(0.76,0.93);
	glVertex2f(0.78,0.99);
    glVertex2f(0.82,0.93);
	glVertex2f(0.84,0.99);
    glVertex2f(0.88,0.93);
	glVertex2f(0.90,0.99);
    glVertex2f(0.94,0.93);
	glVertex2f(0.96,0.99);
    glVertex2f(1.0,0.93);
	glVertex2f(1.02,0.99);
    glEnd();
glTranslatef(0,-0.125,0);
    glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-0.98,0.93);
	glVertex2f(-0.96,0.99);
    glVertex2f(-0.92,0.93);
	glVertex2f(-0.90,0.99);
    glVertex2f(-0.86,0.93);
	glVertex2f(-0.84,0.99);
    glVertex2f(-0.80,0.93);
	glVertex2f(-0.78,0.99);
    glVertex2f(-0.74,0.93);
	glVertex2f(-0.72,0.99);
    glVertex2f(-0.68,0.93);
	glVertex2f(-0.66,0.99);
    glVertex2f(-0.62,0.93);
	glVertex2f(-0.60,0.99);
    glVertex2f(-0.56,0.93);
	glVertex2f(-0.54,0.99);
    glVertex2f(-0.50,0.93);
	glVertex2f(-0.48,0.99);
    glVertex2f(-0.44,0.93);
	glVertex2f(-0.42,0.99);
    glVertex2f(-0.38,0.93);
	glVertex2f(-0.36,0.99);
    glVertex2f(-0.32,0.93);
	glVertex2f(-0.30,0.99);
    glVertex2f(-0.26,0.93);
	glVertex2f(-0.24,0.99);
    glVertex2f(-0.20,0.93);
	glVertex2f(-0.18,0.99);
    glVertex2f(-0.14,0.93);
	glVertex2f(-0.12,0.99);
    glVertex2f(-0.08,0.93);
	glVertex2f(-0.06,0.99);
    glVertex2f(-0.02,0.93);
	glVertex2f(-0.00,0.99);
    glVertex2f(0.04,0.93);
	glVertex2f(0.06,0.99);
    glVertex2f(0.1,0.93);
	glVertex2f(0.12,0.99);
    glVertex2f(0.16,0.93);
	glVertex2f(0.18,0.99);
    glVertex2f(0.22,0.93);
	glVertex2f(0.24,0.99);
    glVertex2f(0.28,0.93);
	glVertex2f(0.30,0.99);
    glVertex2f(0.34,0.93);
	glVertex2f(0.36,0.99);
    glVertex2f(0.40,0.93);
	glVertex2f(0.42,0.99);
    glVertex2f(0.46,0.93);
	glVertex2f(0.48,0.99);
    glVertex2f(0.52,0.93);
	glVertex2f(0.54,0.99);
    glVertex2f(0.58,0.93);
	glVertex2f(0.60,0.99);
    glVertex2f(0.64,0.93);
	glVertex2f(0.66,0.99);
    glVertex2f(0.70,0.93);
	glVertex2f(0.72,0.99);
    glVertex2f(0.76,0.93);
	glVertex2f(0.78,0.99);
    glVertex2f(0.82,0.93);
	glVertex2f(0.84,0.99);
    glVertex2f(0.88,0.93);
	glVertex2f(0.90,0.99);
    glVertex2f(0.94,0.93);
	glVertex2f(0.96,0.99);
    glVertex2f(1.0,0.93);
	glVertex2f(1.02,0.99);
    glEnd();
glTranslatef(0,-0.125,0);
    glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-0.98,0.93);
	glVertex2f(-0.96,0.99);
    glVertex2f(-0.92,0.93);
	glVertex2f(-0.90,0.99);
    glVertex2f(-0.86,0.93);
	glVertex2f(-0.84,0.99);
    glVertex2f(-0.80,0.93);
	glVertex2f(-0.78,0.99);
    glVertex2f(-0.74,0.93);
	glVertex2f(-0.72,0.99);
    glVertex2f(-0.68,0.93);
	glVertex2f(-0.66,0.99);
    glVertex2f(-0.62,0.93);
	glVertex2f(-0.60,0.99);
    glVertex2f(-0.56,0.93);
	glVertex2f(-0.54,0.99);
    glVertex2f(-0.50,0.93);
	glVertex2f(-0.48,0.99);
    glVertex2f(-0.44,0.93);
	glVertex2f(-0.42,0.99);
    glVertex2f(-0.38,0.93);
	glVertex2f(-0.36,0.99);
    glVertex2f(-0.32,0.93);
	glVertex2f(-0.30,0.99);
    glVertex2f(-0.26,0.93);
	glVertex2f(-0.24,0.99);
    glVertex2f(-0.20,0.93);
	glVertex2f(-0.18,0.99);
    glVertex2f(-0.14,0.93);
	glVertex2f(-0.12,0.99);
    glVertex2f(-0.08,0.93);
	glVertex2f(-0.06,0.99);
    glVertex2f(-0.02,0.93);
	glVertex2f(-0.00,0.99);
    glVertex2f(0.04,0.93);
	glVertex2f(0.06,0.99);
    glVertex2f(0.1,0.93);
	glVertex2f(0.12,0.99);
    glVertex2f(0.16,0.93);
	glVertex2f(0.18,0.99);
    glVertex2f(0.22,0.93);
	glVertex2f(0.24,0.99);
    glVertex2f(0.28,0.93);
	glVertex2f(0.30,0.99);
    glVertex2f(0.34,0.93);
	glVertex2f(0.36,0.99);
    glVertex2f(0.40,0.93);
	glVertex2f(0.42,0.99);
    glVertex2f(0.46,0.93);
	glVertex2f(0.48,0.99);
    glVertex2f(0.52,0.93);
	glVertex2f(0.54,0.99);
    glVertex2f(0.58,0.93);
	glVertex2f(0.60,0.99);
    glVertex2f(0.64,0.93);
	glVertex2f(0.66,0.99);
    glVertex2f(0.70,0.93);
	glVertex2f(0.72,0.99);
    glVertex2f(0.76,0.93);
	glVertex2f(0.78,0.99);
    glVertex2f(0.82,0.93);
	glVertex2f(0.84,0.99);
    glVertex2f(0.88,0.93);
	glVertex2f(0.90,0.99);
    glVertex2f(0.94,0.93);
	glVertex2f(0.96,0.99);
    glVertex2f(1.0,0.93);
	glVertex2f(1.02,0.99);
    glEnd();
glTranslatef(0,-0.125,0);
    glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-0.98,0.93);
	glVertex2f(-0.96,0.99);
    glVertex2f(-0.92,0.93);
	glVertex2f(-0.90,0.99);
    glVertex2f(-0.86,0.93);
	glVertex2f(-0.84,0.99);
    glVertex2f(-0.80,0.93);
	glVertex2f(-0.78,0.99);
    glVertex2f(-0.74,0.93);
	glVertex2f(-0.72,0.99);
    glVertex2f(-0.68,0.93);
	glVertex2f(-0.66,0.99);
    glVertex2f(-0.62,0.93);
	glVertex2f(-0.60,0.99);
    glVertex2f(-0.56,0.93);
	glVertex2f(-0.54,0.99);
    glVertex2f(-0.50,0.93);
	glVertex2f(-0.48,0.99);
    glVertex2f(-0.44,0.93);
	glVertex2f(-0.42,0.99);
    glVertex2f(-0.38,0.93);
	glVertex2f(-0.36,0.99);
    glVertex2f(-0.32,0.93);
	glVertex2f(-0.30,0.99);
    glVertex2f(-0.26,0.93);
	glVertex2f(-0.24,0.99);
    glVertex2f(-0.20,0.93);
	glVertex2f(-0.18,0.99);
    glVertex2f(-0.14,0.93);
	glVertex2f(-0.12,0.99);
    glVertex2f(-0.08,0.93);
	glVertex2f(-0.06,0.99);
    glVertex2f(-0.02,0.93);
	glVertex2f(-0.00,0.99);
    glVertex2f(0.04,0.93);
	glVertex2f(0.06,0.99);
    glVertex2f(0.1,0.93);
	glVertex2f(0.12,0.99);
    glVertex2f(0.16,0.93);
	glVertex2f(0.18,0.99);
    glVertex2f(0.22,0.93);
	glVertex2f(0.24,0.99);
    glVertex2f(0.28,0.93);
	glVertex2f(0.30,0.99);
    glVertex2f(0.34,0.93);
	glVertex2f(0.36,0.99);
    glVertex2f(0.40,0.93);
	glVertex2f(0.42,0.99);
    glVertex2f(0.46,0.93);
	glVertex2f(0.48,0.99);
    glVertex2f(0.52,0.93);
	glVertex2f(0.54,0.99);
    glVertex2f(0.58,0.93);
	glVertex2f(0.60,0.99);
    glVertex2f(0.64,0.93);
	glVertex2f(0.66,0.99);
    glVertex2f(0.70,0.93);
	glVertex2f(0.72,0.99);
    glVertex2f(0.76,0.93);
	glVertex2f(0.78,0.99);
    glVertex2f(0.82,0.93);
	glVertex2f(0.84,0.99);
    glVertex2f(0.88,0.93);
	glVertex2f(0.90,0.99);
    glVertex2f(0.94,0.93);
	glVertex2f(0.96,0.99);
    glVertex2f(1.0,0.93);
	glVertex2f(1.02,0.99);
    glEnd();
glTranslatef(0,-0.125,0);
    glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-0.98,0.93);
	glVertex2f(-0.96,0.99);
    glVertex2f(-0.92,0.93);
	glVertex2f(-0.90,0.99);
    glVertex2f(-0.86,0.93);
	glVertex2f(-0.84,0.99);
    glVertex2f(-0.80,0.93);
	glVertex2f(-0.78,0.99);
    glVertex2f(-0.74,0.93);
	glVertex2f(-0.72,0.99);
    glVertex2f(-0.68,0.93);
	glVertex2f(-0.66,0.99);
    glVertex2f(-0.62,0.93);
	glVertex2f(-0.60,0.99);
    glVertex2f(-0.56,0.93);
	glVertex2f(-0.54,0.99);
    glVertex2f(-0.50,0.93);
	glVertex2f(-0.48,0.99);
    glVertex2f(-0.44,0.93);
	glVertex2f(-0.42,0.99);
    glVertex2f(-0.38,0.93);
	glVertex2f(-0.36,0.99);
    glVertex2f(-0.32,0.93);
	glVertex2f(-0.30,0.99);
    glVertex2f(-0.26,0.93);
	glVertex2f(-0.24,0.99);
    glVertex2f(-0.20,0.93);
	glVertex2f(-0.18,0.99);
    glVertex2f(-0.14,0.93);
	glVertex2f(-0.12,0.99);
    glVertex2f(-0.08,0.93);
	glVertex2f(-0.06,0.99);
    glVertex2f(-0.02,0.93);
	glVertex2f(-0.00,0.99);
    glVertex2f(0.04,0.93);
	glVertex2f(0.06,0.99);
    glVertex2f(0.1,0.93);
	glVertex2f(0.12,0.99);
    glVertex2f(0.16,0.93);
	glVertex2f(0.18,0.99);
    glVertex2f(0.22,0.93);
	glVertex2f(0.24,0.99);
    glVertex2f(0.28,0.93);
	glVertex2f(0.30,0.99);
    glVertex2f(0.34,0.93);
	glVertex2f(0.36,0.99);
    glVertex2f(0.40,0.93);
	glVertex2f(0.42,0.99);
    glVertex2f(0.46,0.93);
	glVertex2f(0.48,0.99);
    glVertex2f(0.52,0.93);
	glVertex2f(0.54,0.99);
    glVertex2f(0.58,0.93);
	glVertex2f(0.60,0.99);
    glVertex2f(0.64,0.93);
	glVertex2f(0.66,0.99);
    glVertex2f(0.70,0.93);
	glVertex2f(0.72,0.99);
    glVertex2f(0.76,0.93);
	glVertex2f(0.78,0.99);
    glVertex2f(0.82,0.93);
	glVertex2f(0.84,0.99);
    glVertex2f(0.88,0.93);
	glVertex2f(0.90,0.99);
    glVertex2f(0.94,0.93);
	glVertex2f(0.96,0.99);
    glVertex2f(1.0,0.93);
	glVertex2f(1.02,0.99);
    glEnd();
glTranslatef(0,-0.125,0);
    glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-0.98,0.93);
	glVertex2f(-0.96,0.99);
    glVertex2f(-0.92,0.93);
	glVertex2f(-0.90,0.99);
    glVertex2f(-0.86,0.93);
	glVertex2f(-0.84,0.99);
    glVertex2f(-0.80,0.93);
	glVertex2f(-0.78,0.99);
    glVertex2f(-0.74,0.93);
	glVertex2f(-0.72,0.99);
    glVertex2f(-0.68,0.93);
	glVertex2f(-0.66,0.99);
    glVertex2f(-0.62,0.93);
	glVertex2f(-0.60,0.99);
    glVertex2f(-0.56,0.93);
	glVertex2f(-0.54,0.99);
    glVertex2f(-0.50,0.93);
	glVertex2f(-0.48,0.99);
    glVertex2f(-0.44,0.93);
	glVertex2f(-0.42,0.99);
    glVertex2f(-0.38,0.93);
	glVertex2f(-0.36,0.99);
    glVertex2f(-0.32,0.93);
	glVertex2f(-0.30,0.99);
    glVertex2f(-0.26,0.93);
	glVertex2f(-0.24,0.99);
    glVertex2f(-0.20,0.93);
	glVertex2f(-0.18,0.99);
    glVertex2f(-0.14,0.93);
	glVertex2f(-0.12,0.99);
    glVertex2f(-0.08,0.93);
	glVertex2f(-0.06,0.99);
    glVertex2f(-0.02,0.93);
	glVertex2f(-0.00,0.99);
    glVertex2f(0.04,0.93);
	glVertex2f(0.06,0.99);
    glVertex2f(0.1,0.93);
	glVertex2f(0.12,0.99);
    glVertex2f(0.16,0.93);
	glVertex2f(0.18,0.99);
    glVertex2f(0.22,0.93);
	glVertex2f(0.24,0.99);
    glVertex2f(0.28,0.93);
	glVertex2f(0.30,0.99);
    glVertex2f(0.34,0.93);
	glVertex2f(0.36,0.99);
    glVertex2f(0.40,0.93);
	glVertex2f(0.42,0.99);
    glVertex2f(0.46,0.93);
	glVertex2f(0.48,0.99);
    glVertex2f(0.52,0.93);
	glVertex2f(0.54,0.99);
    glVertex2f(0.58,0.93);
	glVertex2f(0.60,0.99);
    glVertex2f(0.64,0.93);
	glVertex2f(0.66,0.99);
    glVertex2f(0.70,0.93);
	glVertex2f(0.72,0.99);
    glVertex2f(0.76,0.93);
	glVertex2f(0.78,0.99);
    glVertex2f(0.82,0.93);
	glVertex2f(0.84,0.99);
    glVertex2f(0.88,0.93);
	glVertex2f(0.90,0.99);
    glVertex2f(0.94,0.93);
	glVertex2f(0.96,0.99);
    glVertex2f(1.0,0.93);
	glVertex2f(1.02,0.99);
    glEnd();
 glTranslatef(0,-0.125,0);
    glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-0.98,0.93);
	glVertex2f(-0.96,0.99);
    glVertex2f(-0.92,0.93);
	glVertex2f(-0.90,0.99);
    glVertex2f(-0.86,0.93);
	glVertex2f(-0.84,0.99);
    glVertex2f(-0.80,0.93);
	glVertex2f(-0.78,0.99);
    glVertex2f(-0.74,0.93);
	glVertex2f(-0.72,0.99);
    glVertex2f(-0.68,0.93);
	glVertex2f(-0.66,0.99);
    glVertex2f(-0.62,0.93);
	glVertex2f(-0.60,0.99);
    glVertex2f(-0.56,0.93);
	glVertex2f(-0.54,0.99);
    glVertex2f(-0.50,0.93);
	glVertex2f(-0.48,0.99);
    glVertex2f(-0.44,0.93);
	glVertex2f(-0.42,0.99);
    glVertex2f(-0.38,0.93);
	glVertex2f(-0.36,0.99);
    glVertex2f(-0.32,0.93);
	glVertex2f(-0.30,0.99);
    glVertex2f(-0.26,0.93);
	glVertex2f(-0.24,0.99);
    glVertex2f(-0.20,0.93);
	glVertex2f(-0.18,0.99);
    glVertex2f(-0.14,0.93);
	glVertex2f(-0.12,0.99);
    glVertex2f(-0.08,0.93);
	glVertex2f(-0.06,0.99);
    glVertex2f(-0.02,0.93);
	glVertex2f(-0.00,0.99);
    glVertex2f(0.04,0.93);
	glVertex2f(0.06,0.99);
    glVertex2f(0.1,0.93);
	glVertex2f(0.12,0.99);
    glVertex2f(0.16,0.93);
	glVertex2f(0.18,0.99);
    glVertex2f(0.22,0.93);
	glVertex2f(0.24,0.99);
    glVertex2f(0.28,0.93);
	glVertex2f(0.30,0.99);
    glVertex2f(0.34,0.93);
	glVertex2f(0.36,0.99);
    glVertex2f(0.40,0.93);
	glVertex2f(0.42,0.99);
    glVertex2f(0.46,0.93);
	glVertex2f(0.48,0.99);
    glVertex2f(0.52,0.93);
	glVertex2f(0.54,0.99);
    glVertex2f(0.58,0.93);
	glVertex2f(0.60,0.99);
    glVertex2f(0.64,0.93);
	glVertex2f(0.66,0.99);
    glVertex2f(0.70,0.93);
	glVertex2f(0.72,0.99);
    glVertex2f(0.76,0.93);
	glVertex2f(0.78,0.99);
    glVertex2f(0.82,0.93);
	glVertex2f(0.84,0.99);
    glVertex2f(0.88,0.93);
	glVertex2f(0.90,0.99);
    glVertex2f(0.94,0.93);
	glVertex2f(0.96,0.99);
    glVertex2f(1.0,0.93);
	glVertex2f(1.02,0.99);
    glEnd();
glLoadIdentity();
    glPopMatrix();



glFlush();
}

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NIGHT VIEW ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void night() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2.0);

	glBegin(GL_POLYGON);//sky
	glColor3ub(0, 40, 77);
	glVertex2f(1.0,1.0);
	glVertex2f(-1.0,1.0);
	glVertex2f(-1.0,-0.2);
	glVertex2f(1.0,-0.2);
    glEnd();
//*******************************  MOON  **************************
   //glPushMatrix();
   //glTranslatef(0,sun_position,0);
   int i;
    GLfloat amount= 30;
    GLfloat twoPi=2*PI;
    GLfloat xs=0.845; GLfloat ys=0.845; GLfloat rs=0.145;
    glBegin(GL_TRIANGLE_FAN);//Moon
	glColor3ub(217, 217, 217);
		glVertex2f(xs, ys); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xs+ (rs* cos(i*twoPi / amount)),
			    ys + (rs * sin(i * twoPi / amount))
			);
		}
	glEnd();

	 GLfloat xs1=0.89; GLfloat ys1=0.85; GLfloat rs1=0.16;
    glBegin(GL_TRIANGLE_FAN);//Moon
	glColor3ub(0, 40, 77);
		glVertex2f(xs1, ys1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xs1+ (rs1* cos(i*twoPi / amount)),
			    ys1 + (rs1 * sin(i * twoPi / amount))
			);
		}
	glEnd();


	//glLoadIdentity();
	//glPopMatrix();
//###############################################  CLOUD  #########################################
glPushMatrix();
glTranslatef(cloud_position,0,0);
 GLfloat xc=-0.84; GLfloat yc=0.8; GLfloat rc=0.045;
    glBegin(GL_TRIANGLE_FAN);//Cloud 1
	glColor3ub(0, 68, 102);
		glVertex2f(xc, yc); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc+ (rc* cos(i*twoPi / amount)),
			    yc + (rc * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.05,0.03,0);
glBegin(GL_TRIANGLE_FAN);//Sun
	glColor3ub(0, 68, 102);
		glVertex2f(xc, yc); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc+ (rc* cos(i*twoPi / amount)),
			    yc + (rc * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.05,-0.05,0);
glBegin(GL_TRIANGLE_FAN);//Sun
	glColor3ub(0, 68, 102);
		glVertex2f(xc, yc); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc+ (rc* cos(i*twoPi / amount)),
			    yc + (rc * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(-0.05,-0.03,0);
glBegin(GL_TRIANGLE_FAN);//Sun
	glColor3ub(0, 68, 102);
		glVertex2f(xc, yc); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc+ (rc* cos(i*twoPi / amount)),
			    yc + (rc * sin(i * twoPi / amount))
			);
		}
	glEnd();
	//glLoadIdentity();

	GLfloat xc1=-0.6; GLfloat yc1=0.805; GLfloat rc1=0.045;
    glBegin(GL_TRIANGLE_FAN);//Cloud 2
	glColor3ub(0, 68, 102);
		glVertex2f(xc1, yc1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc1+ (rc1* cos(i*twoPi / amount)),
			    yc1 + (rc1 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.05,0.03,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 2
	glColor3ub(0, 68, 102);
		glVertex2f(xc1, yc1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc1+ (rc1* cos(i*twoPi / amount)),
			    yc1 + (rc1 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.05,-0.05,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 2
	glColor3ub(0, 68, 102);
		glVertex2f(xc1, yc1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc1+ (rc1* cos(i*twoPi / amount)),
			    yc1 + (rc1 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(-0.05,-0.03,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 2
	glColor3ub(0, 68, 102);
		glVertex2f(xc1, yc1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc1+ (rc1* cos(i*twoPi / amount)),
			    yc1 + (rc1 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	//glLoadIdentity();

	GLfloat xc2=0.0; GLfloat yc2=0.81; GLfloat rc2=0.045;
    glBegin(GL_TRIANGLE_FAN);//Cloud 3.1
	glColor3ub(0, 68, 102);
		glVertex2f(xc2, yc2); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc2+ (rc2* cos(i*twoPi / amount)),
			    yc2 + (rc2 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.05,0.03,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 3.2
	glColor3ub(0, 68, 102);
		glVertex2f(xc2, yc2); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc2+ (rc2* cos(i*twoPi / amount)),
			    yc2 + (rc2 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.05,-0.05,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 3.3
	glColor3ub(0, 68, 102);
		glVertex2f(xc2, yc2); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc2+ (rc2* cos(i*twoPi / amount)),
			    yc2 + (rc2 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(-0.05,-0.03,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 3.4
	glColor3ub(0, 68, 102);
		glVertex2f(xc2, yc2); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc2+ (rc2* cos(i*twoPi / amount)),
			    yc2 + (rc2 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	GLfloat xc3=0.55; GLfloat yc3=0.801; GLfloat rc3=0.045;
    glBegin(GL_TRIANGLE_FAN);//Cloud 4.1
	glColor3ub(0, 68, 102);
		glVertex2f(xc3, yc3); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc3+ (rc3* cos(i*twoPi / amount)),
			    yc3 + (rc3 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.05,0.03,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 4.2
	glColor3ub(0, 68, 102);
		glVertex2f(xc3, yc3); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc3+ (rc3* cos(i*twoPi / amount)),
			    yc3 + (rc3 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.05,-0.05,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 4.3
	glColor3ub(0, 68, 102);
		glVertex2f(xc3, yc3); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc3+ (rc3* cos(i*twoPi / amount)),
			    yc3 + (rc3 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(-0.05,-0.03,0);
 glBegin(GL_TRIANGLE_FAN);//Cloud 4.4
	glColor3ub(0, 68, 102);
		glVertex2f(xc3, yc3); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xc3+ (rc3* cos(i*twoPi / amount)),
			    yc3 + (rc3 * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLoadIdentity();
	glPopMatrix();

		   //******************Plane****
glPushMatrix();
glTranslatef(plane_position,0,0);


	GLfloat xp=-0.4f; GLfloat yp=0.75f; GLfloat rp =0.025f;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 77, 77);
		glVertex2f(xp, yp);
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xp + (rp * cos(i *  twoPi / amount)),
			    yp + (rp * sin(i * twoPi /amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);//body
	glColor3ub(255, 77, 77);
	glVertex2f(-0.39,0.725);
	glVertex2f(-0.6,0.725);
	glVertex2f(-0.65,0.765);
	glVertex2f(-0.65,0.8);
	glVertex2f(-0.43,0.8);
	glVertex2f(-0.39,0.775);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(255, 230, 128);
	glVertex2f(-0.375,0.75);
	glVertex2f(-0.28,0.79);
	glVertex2f(-0.28,0.71);
	glEnd();

	glBegin(GL_TRIANGLES);//wing behind
	glColor3ub(0, 60, 179);
	glVertex2f(-0.645,0.8);
	glVertex2f(-0.6,0.8);
	glVertex2f(-0.645,0.845);
	//glVertex2f();
	glEnd();

	glBegin(GL_POLYGON);//wing up
	glColor3ub(0, 60, 179);
	glVertex2f(-0.54,0.8);
	glVertex2f(-0.50,0.8);
	glVertex2f(-0.52,0.85);
	glVertex2f(-0.56,0.85);
	glEnd();

	glBegin(GL_POLYGON);//wing down
	glColor3ub(0, 60, 179);
	glVertex2f(-0.54,0.725);
	glVertex2f(-0.50,0.725);
	glVertex2f(-0.52,0.675);
	glVertex2f(-0.56,0.675);
	glEnd();

	glBegin(GL_POLYGON);//door
	glColor3ub(102, 153, 204);
	glVertex2f(-0.435,0.765);
	glVertex2f(-0.45,0.765);
	glVertex2f(-0.45,0.725);
	glVertex2f(-0.435,0.725);
	glEnd();


	glTranslatef(-0.033,0,0);
	glBegin(GL_POLYGON);//window
	glColor3ub(102, 153, 204);
	glVertex2f(-0.435,0.755);
	glVertex2f(-0.45,0.755);
	glVertex2f(-0.45,0.775);
	glVertex2f(-0.435,0.775);
	glEnd();

	glTranslatef(-0.033,0,0);
	glBegin(GL_POLYGON);//window
	glColor3ub(102, 153, 204);
	glVertex2f(-0.435,0.755);
	glVertex2f(-0.45,0.755);
	glVertex2f(-0.45,0.775);
	glVertex2f(-0.435,0.775);
	glEnd();


	glTranslatef(-0.033,0,0);
	glBegin(GL_POLYGON);//window
	glColor3ub(102, 153, 204);
	glVertex2f(-0.435,0.755);
	glVertex2f(-0.45,0.755);
	glVertex2f(-0.45,0.775);
	glVertex2f(-0.435,0.775);
	glEnd();


	glTranslatef(-0.033,0,0);
	glBegin(GL_POLYGON);//window
	glColor3ub(102, 153, 204);
	glVertex2f(-0.435,0.755);
	glVertex2f(-0.45,0.755);
	glVertex2f(-0.45,0.775);
	glVertex2f(-0.435,0.775);
	glEnd();
	glTranslatef(-0.033,0,0);
	glBegin(GL_POLYGON);//window
	glColor3ub(102, 153, 204);
	glVertex2f(-0.435,0.755);
	glVertex2f(-0.45,0.755);
	glVertex2f(-0.45,0.775);
	glVertex2f(-0.435,0.775);
	glEnd();
glLoadIdentity();
	glPopMatrix();


//****************************************************************************
glBegin(GL_POLYGON);//ground
	glColor3ub(15, 62, 15);
	glVertex2f(1.0,-1.0);
	glVertex2f(-1.0,-1.0);
	glVertex2f(-1.0,-0.2);
	glVertex2f(1.0,-0.2);
    glEnd();
    //red road
    glBegin(GL_POLYGON);//red road
	glColor3ub(26, 5, 0);
	glVertex2f(1.0,-0.2);
	glVertex2f(-1.0,-0.2);
	glVertex2f(-1.0,-0.325);
	glVertex2f(1.0,-0.325);
	glEnd();

glBegin(GL_POLYGON);//mosjid builduing tall
	glColor3ub(51, 51, 0);
	glVertex2f(0.41,-0.25);
	glVertex2f(-0.41,-0.25);
	glVertex2f(-0.41,0.9);
	glVertex2f(0.41,0.9);
    glEnd();
glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(0.41,-0.25);
glVertex2f(0.41,0.9);
glVertex2f(0.41,0.9);
glVertex2f(-0.41,0.9);
glVertex2f(-0.41,0.9);
glVertex2f(-0.41,-0.25);
glEnd();
glBegin(GL_POLYGON);//mosjid builduing longest
	glColor3ub(51, 51, 0);
	glVertex2f(0.88,-0.25);
	glVertex2f(-0.88,-0.25);
	glVertex2f(-0.88,0.1875);
	glVertex2f(0.88,0.1875);
    glEnd();
glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(0.88,0.1875);
glVertex2f(0.88,-0.25);
glVertex2f(0.88,-0.25);
glVertex2f(-0.88,-0.25);
glVertex2f(-0.88,-0.25);
glVertex2f(-0.88,0.1875);
glEnd();

    glBegin(GL_POLYGON);//mosjid builduing roof
	glColor3ub(64, 64, 64);
	glVertex2f(0.84,0.25);
	glVertex2f(-0.84,0.25);
	glVertex2f(-0.88,0.1875);
	glVertex2f(0.88,0.1875);
    glEnd();

glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(0.84,0.25);
glVertex2f(-0.84,0.25);
glVertex2f(-0.84,0.25);
glVertex2f(-0.88,0.1875);
glVertex2f(-0.88,0.1875);
glVertex2f(0.88,0.1875);
glVertex2f(0.88,0.1875);
glVertex2f(0.84,0.25);
glEnd();

glBegin(GL_POLYGON);//mosjid builduing black block 1
	glColor3ub(0,0,0);
	glVertex2f(0.41,0.65);
	glVertex2f(-0.41,0.65);
	glVertex2f(-0.41,0.675);
	glVertex2f(0.41,0.675);
    glEnd();
    glTranslatef(0,0.05,0);
    glBegin(GL_POLYGON);//mosjid builduing black block 2
	glColor3ub(0,0,0);
	glVertex2f(0.41,0.65);
	glVertex2f(-0.41,0.65);
	glVertex2f(-0.41,0.675);
	glVertex2f(0.41,0.675);
    glEnd();
    glTranslatef(0,-0.1,0);
    glBegin(GL_POLYGON);//mosjid builduing black block 3
	glColor3ub(0,0,0);
	glVertex2f(0.41,0.65);
	glVertex2f(-0.41,0.65);
	glVertex2f(-0.41,0.675);
	glVertex2f(0.41,0.675);
    glEnd();
    glLoadIdentity();
    //***********************************mosjid room block

    GLfloat x=-0.845; GLfloat y=0.135; GLfloat r=0.015;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();

    glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
    glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
    glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
    glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();

           glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
    glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();
       glTranslatef(0.06,0,0);
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x + (r* cos(i *twoPi / amount)),
			    y + (r * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.86,0.135);
	glVertex2f(-0.83,0.135);
	glVertex2f(-0.83,-0.0);
	glVertex2f(-0.86,0.0);
    glEnd();

glLoadIdentity();
////////////////////////////////////////////////////////////////////////////////////
GLfloat x1=-0.81; GLfloat y1=-0.1; GLfloat r1=0.035;
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();
glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glTranslatef(0.1,0,0);
   glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glTranslatef(0.1,0,0);

    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x1, y1); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x1+ (r1* cos(i *twoPi / amount)),
			    y1 + (r1 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.845,-0.1);
	glVertex2f(-0.775,-0.1);
	glVertex2f(-0.775,-0.23);
	glVertex2f(-0.845,-0.23);
    glEnd();
    glLoadIdentity();
//*****************************************************
    glBegin(GL_POLYGON);//mosjid builduing door
	glColor3ub(51, 51, 51);
	glVertex2f(0.167,-0.1);
	glVertex2f(-0.167,-0.1);
	glVertex2f(-0.148,0.3375);
	glVertex2f(0.148,0.3375);
    glEnd();
glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(0.167,-0.1);
glVertex2f(-0.167,-0.1);
glVertex2f(-0.167,-0.1);
glVertex2f(-0.148,0.3375);
glVertex2f(-0.148,0.3375);
glVertex2f(0.148,0.3375);
glVertex2f(0.148,0.3375);
glVertex2f(0.167,-0.1);
glEnd();

GLfloat x2=-0.105; GLfloat y2=0.15; GLfloat r2=0.035;
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x2, y2); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x2+ (r2* cos(i *twoPi / amount)),
			    y2 + (r2 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.14,0.15);
	glVertex2f(-0.07,0.15);
	glVertex2f(-0.07,-0.05);
	glVertex2f(-0.14,-0.05);
    glEnd();

    glTranslatef(0.2,0,0);
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x2, y2); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x2+ (r2* cos(i *twoPi / amount)),
			    y2 + (r2 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.14,0.15);
	glVertex2f(-0.07,0.15);
	glVertex2f(-0.07,-0.05);
	glVertex2f(-0.14,-0.05);
    glEnd();
    glLoadIdentity();

    glBegin(GL_POLYGON);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.05,0.15);
	glVertex2f(0.04,0.15);
	glVertex2f(0.04,-0.05);
	glVertex2f(-0.05,-0.05);
    glEnd();

    GLfloat x3=-0.005; GLfloat y3=0.16; GLfloat r3=0.055;
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 0);
		glVertex2f(x3, y3); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            x3+ (r3* cos(i *twoPi / amount)),
			    y3 + (r3 * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(255, 204, 0);
	glVertex2f(-0.0325,0.21);
	glVertex2f(0.0225,0.21);
	glVertex2f(-0.005,0.245);

    glEnd();


    glBegin(GL_POLYGON);//mosjid builduing door stair
	glColor3ub(38, 38, 38);
	glVertex2f(0.17,-0.1);
	glVertex2f(-0.17,-0.1);
	glVertex2f(-0.25,-0.26);
	glVertex2f(0.25,-0.26);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.17,-0.1);
	glVertex2f(-0.17,-0.1);
	glVertex2f(-0.17,-0.1);
	glVertex2f(-0.25,-0.26);
	glVertex2f(-0.25,-0.26);
	glVertex2f(0.25,-0.26);
	glVertex2f(0.25,-0.26);
	glVertex2f(0.17,-0.1);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.19,-0.14);
	glVertex2f(-0.19,-0.14);
	glVertex2f(0.21,-0.18);
	glVertex2f(-0.21,-0.18);
	glVertex2f(0.23,-0.22);
	glVertex2f(-0.23,-0.22);
	glEnd();

	//***************************Water Pool in front of mosque*********************************************
	glBegin(GL_POLYGON);//pool fringe road both side
	glColor3ub(26, 5, 0);
	glVertex2f(-0.25,-0.26);
	glVertex2f(0.25,-0.26);
	glVertex2f(0.45,-1.0);
	glVertex2f(-0.45,-1.0);
	glEnd();
	glBegin(GL_POLYGON);//pool fringe
	glColor3ub(77, 77, 77);
	glVertex2f(-0.1,-0.34);
	glVertex2f(0.1,-0.34);
	glVertex2f(0.2,-0.8);
	glVertex2f(-0.2,-0.8);
	glEnd();

	glBegin(GL_POLYGON);//shadow
	glColor3ub(38,38,38);
	glVertex2f(-0.095,-0.355);
	glVertex2f(0.095,-0.355);
	glVertex2f(0.18,-0.78);
	glVertex2f(-0.18,-0.78);
	glEnd();
	glBegin(GL_POLYGON);//water
	glColor3ub(0, 0, 77);
	glVertex2f(-0.092,-0.365);
	glVertex2f(0.092,-0.365);
	glVertex2f(0.165,-0.76);
	glVertex2f(-0.165,-0.76);
	glEnd();


	//****************************************Trees and LampPost*******************************
	glBegin(GL_POLYGON);//Tree Left1
	glColor3ub(96, 64, 32);
	glVertex2f(-0.73,-0.6);
	glVertex2f(-0.73,-0.5);
	glVertex2f(-0.70,-0.5);
	glVertex2f(-0.70,-0.6);
	glEnd();

    GLfloat xtl=-0.715; GLfloat ytl=-0.38; GLfloat rtl=0.12;
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(26,102,0);
		glVertex2f(xtl, ytl); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xtl+ (rtl* cos(i*twoPi / amount)),
			    ytl + (rtl * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(-0.125,-0.2,0);
glBegin(GL_POLYGON);//Tree Left2
	glColor3ub(96, 64, 32);
	glVertex2f(-0.73,-0.6);
	glVertex2f(-0.73,-0.5);
	glVertex2f(-0.70,-0.5);
	glVertex2f(-0.70,-0.6);
	glEnd();
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(68,102,0);
		glVertex2f(xtl, ytl); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xtl+ (rtl* cos(i*twoPi / amount)),
			    ytl + (rtl * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLoadIdentity();

	glBegin(GL_POLYGON);//Tree Right1
	glColor3ub(96, 64, 32);
	glVertex2f(0.73,-0.6);
	glVertex2f(0.73,-0.5);
	glVertex2f(0.70,-0.5);
	glVertex2f(0.70,-0.6);
	glEnd();

    GLfloat xtr=0.715; GLfloat ytr=-0.38; GLfloat rtr=0.12;
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(68,102,0);
		glVertex2f(xtr, ytr); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xtr+ (rtr* cos(i*twoPi / amount)),
			    ytr + (rtr * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.125,-0.2,0);
glBegin(GL_POLYGON);//Tree Right2
	glColor3ub(96, 64, 32);
	glVertex2f(0.73,-0.6);
	glVertex2f(0.73,-0.5);
	glVertex2f(0.70,-0.5);
	glVertex2f(0.70,-0.6);
	glEnd();
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(26,102,0);
		glVertex2f(xtr, ytr); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xtr+ (rtr* cos(i*twoPi / amount)),
			    ytr + (rtr * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLoadIdentity();

	//----------------------------- LampPost -----------------------------------
	glBegin(GL_POLYGON);//Lamp Left
	glColor3ub(89, 89, 89);
	glVertex2f(-0.33,-0.4);
	glVertex2f(-0.33,-0.25);
    glVertex2f(-0.3,-0.25);
    glVertex2f(-0.3,-0.4);
	glEnd();
	GLfloat xll=-0.315; GLfloat yll=-0.24; GLfloat rll=0.03;
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(255, 187, 51);
		glVertex2f(xll, yll); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xll+ (rll* cos(i*twoPi / amount)),
			    yll + (rll * sin(i * twoPi / amount))
			);
		}
	glEnd();

	glTranslatef(-0.65,0,0);
	glBegin(GL_POLYGON);//Lamp Left
	glColor3ub(89, 89, 89);
	glVertex2f(-0.33,-0.4);
	glVertex2f(-0.33,-0.25);
    glVertex2f(-0.3,-0.25);
    glVertex2f(-0.3,-0.4);
	glEnd();

    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(255, 187, 51);
		glVertex2f(xll, yll); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xll+ (rll* cos(i*twoPi / amount)),
			    yll + (rll * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLoadIdentity();

	glTranslatef(0.64,0,0);
	glBegin(GL_POLYGON);//Lamp Left
	glColor3ub(89, 89, 89);
	glVertex2f(-0.33,-0.4);
	glVertex2f(-0.33,-0.25);
    glVertex2f(-0.3,-0.25);
    glVertex2f(-0.3,-0.4);
	glEnd();

    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(255, 187, 51);
		glVertex2f(xll, yll); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xll+ (rll* cos(i*twoPi / amount)),
			    yll + (rll * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLoadIdentity();

	glTranslatef(1.28,0,0);
	glBegin(GL_POLYGON);//Lamp Left
	glColor3ub(89, 89, 89);
	glVertex2f(-0.33,-0.4);
	glVertex2f(-0.33,-0.25);
    glVertex2f(-0.3,-0.25);
    glVertex2f(-0.3,-0.4);
	glEnd();

    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(255, 187, 51);
		glVertex2f(xll, yll); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xll+ (rll* cos(i*twoPi / amount)),
			    yll + (rll * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLoadIdentity();

glBegin(GL_POLYGON);//Lamp Right
	glColor3ub(89, 89, 89);
	glVertex2f(-0.49,-0.95);
	glVertex2f(-0.49,-0.8);
    glVertex2f(-0.46,-0.8);
    glVertex2f(-0.46,-0.95);
	glEnd();
	GLfloat xlr=-0.475; GLfloat ylr=-0.79; GLfloat rlr=0.03;
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(255, 187, 51);
		glVertex2f(xlr, ylr); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xlr+ (rlr* cos(i*twoPi / amount)),
			    ylr + (rlr * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glTranslatef(0.935,0,0);
	glBegin(GL_POLYGON);//Lamp Right
	glColor3ub(89, 89, 89);
	glVertex2f(-0.49,-0.95);
	glVertex2f(-0.49,-0.8);
    glVertex2f(-0.46,-0.8);
    glVertex2f(-0.46,-0.95);
	glEnd();
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(255, 187, 51);
		glVertex2f(xlr, ylr); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xlr+ (rlr* cos(i*twoPi / amount)),
			    ylr + (rlr * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLoadIdentity();

	//++++++++++++++++++++++++ Man  ++++++++++++++++++++++++++++++++++++++++++++++++++
	glPushMatrix();
	glTranslatef(0.001,manr_position,0);
	glBegin(GL_POLYGON);//Man Right
	glColor3ub(92, 138, 138);
	glVertex2f(0.27,-0.35);
	glVertex2f(0.27,-0.45);
    glVertex2f(0.23,-0.45);
    glVertex2f(0.23,-0.35);
	glEnd();
	GLfloat xmr=0.25; GLfloat ymr=-0.34; GLfloat rmr=0.015;
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(0,0,0);
		glVertex2f(xmr, ymr); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xmr+ (rmr* cos(i*twoPi / amount)),
			    ymr + (rmr * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLineWidth(3.0);
	glBegin(GL_LINES);//Man Right
	glColor3ub(0,0,0);
	glVertex2f(0.27,-0.37);
	glVertex2f(0.2775,-0.37);
    glVertex2f(0.23,-0.37);
    glVertex2f(0.2225,-0.37);
	glEnd();
	glLoadIdentity();
	glPopMatrix();
glPushMatrix();
glTranslatef(0,manl_position,0);
	glBegin(GL_POLYGON);//Man Left
	glColor3ub(255, 153, 255);
	glVertex2f(-0.27,-0.7);
	glVertex2f(-0.27,-0.8);
    glVertex2f(-0.23,-0.8);
    glVertex2f(-0.23,-0.7);
	glEnd();
	GLfloat xml=-0.25; GLfloat yml=-0.69; GLfloat rml=0.015;
    glBegin(GL_TRIANGLE_FAN);//
	glColor3ub(0,0,0);
		glVertex2f(xml, yml); // center of circle
		for(i = 0; i <= amount;i++) {
			glVertex2f(
		            xml+ (rml* cos(i*twoPi / amount)),
			    yml + (rml * sin(i * twoPi / amount))
			);
		}
	glEnd();
	glLineWidth(3.0);
	glBegin(GL_LINES);//Man Left
	glColor3ub(0,0,0);
	glVertex2f(-0.27,-0.72);
	glVertex2f(-0.2775,-0.72);
    glVertex2f(-0.23,-0.72);
    glVertex2f(-0.2225,-0.72);
	glEnd();
	glLoadIdentity();
	glPopMatrix();


glFlush();
}

void sound1()
{
PlaySound("Azan.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
 }

 void sound2()
{
PlaySound("rain.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
 }

 void sound3()
{
PlaySound(NULL, NULL, SND_ASYNC|SND_FILENAME);
}

void Key(unsigned char key, int x, int y)
{
    switch(key)
    {case 'a':
    sound1();
    glutPostRedisplay();
    break;
    case 's':
sound3();
    glutPostRedisplay();
    break;
     case 'd':
    glutDisplayFunc(day);
    glutPostRedisplay();
    break;
case 'n':
   glutDisplayFunc(night);
   sound3();
    glutPostRedisplay();
    break;
glutPostRedisplay();
case 'r':
   glutDisplayFunc(rain);
   sound2();
    glutPostRedisplay();
    break;

}
}


///******************************************************************
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("BAITUL MUKARRAM MOSJID-->d=Day,n=Night,r=Rain");
	glutInitWindowSize(1280, 720);
	glutInitWindowPosition(50, 50);
    glutDisplayFunc(day);
    glutKeyboardFunc(Key);
    glutTimerFunc(100,updateCloud,0);
    glutTimerFunc(100,updateSun,0);
    glutTimerFunc(100,updatePlane,0);
    glutTimerFunc(100, updateRain, 0);
    glutTimerFunc(100, updateManL, 0);
    glutTimerFunc(100, updateManR, 0);
    glutMainLoop();
	return 0;   }

