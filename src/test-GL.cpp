#include <iostream>
#include <windows.h>
#include <gl/GL.h>
#include "GL/glut.h"
#include <math.h>

#define PI 3.1415926535898

using namespace std; 

void init();
void display();
void reshape(int, int);
void drawPikachuBody();
void drawPikachuPoints();
void drawShape(int centerX, int centerY, int radius, int numOfPoints, float angle_rotate, GLenum mode);
void Timer(int);

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Pikachu face");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    Timer(0);

    glutMainLoop();

    return 0;
}

void drawShape(int centerX, int centerY, int radius, int numOfPoints, float angle_rotate, GLenum mode = GL_LINE_LOOP) {
    glBegin(mode);

    float angle_radian;
    for(int i = 0; i < numOfPoints; i++) {
        angle_radian = (2 * PI * i / numOfPoints);
        glVertex2f(centerX + radius * cos(angle_radian + angle_rotate), centerY + radius * sin(angle_radian + angle_rotate));
    }
    glEnd();
}

float rotation = 0;
float bodyRotation = 0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // clear frame buffer to redraw
    glColor3f(0.0f, 0.0f, 0.0f); // clear color buffer

    // EYES
    glLineWidth(3);
    drawShape(-10, 50, 7,  100000, 0);
    drawShape(-60, 50, 8, 100000, 0);

    // NOSE
    glLineWidth(1);
    drawShape(-50, 25, 3, 3, - PI / 2, GL_TRIANGLES);

    // MOUTH
    glBegin(GL_POLYGON);
    glVertex2f(-49, 20);
    glVertex2f(-32, 10);
    glVertex2f(-66, 10);
    glEnd();

    drawPikachuBody();
    glFlush(); // show on screen
}

void drawPikachuBody() {
    glBegin(GL_LINE_STRIP);

    glVertex2f(-50, -110);

    glVertex2f(10, -110);
    glVertex2f(0, -120);
    glVertex2f(10, -120);
    glVertex2f(30, -110);

    glVertex2f(40, -90);
    glVertex2f(40, -80);
    glVertex2f(40, -70);
    glVertex2f(40, -40);

    glVertex2f(30, 10);
    glVertex2f(30, 30);
    glVertex2f(20, 60);

    glVertex2f(50, 70);
    glVertex2f(70, 80);
    glVertex2f(90, 100);
    glVertex2f(70, 100);
    glVertex2f(30, 90);

    glVertex2f(0, 70);

    glVertex2f(-10, 80);
    glVertex2f(-40, 80);

    glVertex2f(-60, 70);
    glVertex2f(-70, 90);

    glVertex2f(-100, 110);
    glVertex2f(-130, 120);
    glVertex2f(-120, 100);

    glVertex2f(-90, 70);
    glVertex2f(-70, 60);

    glVertex2f(-80, 50);
    glVertex2f(-80, 30);

    glVertex2f(-90, 20);
    glVertex2f(-90, 10);

    glVertex2f(-70, -10);
    glVertex2f(-60, -20);

    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(-70, -60);
    glVertex2f(-80, -80);

    glVertex2f(-80, -90);
    glVertex2f(-70, -100);

    glVertex2f(-80, -120);
    glVertex2f(-70, -120);

    glVertex2f(-50, -110);

    glEnd();

    // tail
    glBegin(GL_LINE_STRIP);
    
    glVertex2f(40, -70);

    glVertex2f(60, -60);
    glVertex2f(50, -40);
    glVertex2f(70, -30);
    glVertex2f(60, -10);
    glVertex2f(80, 0);
    glVertex2f(50, 40);
    glVertex2f(120, 80);
    glVertex2f(140, 30);
    glVertex2f(90, 10);
    glVertex2f(100, -10);
    glVertex2f(80, -20);
    glVertex2f(90, -40);
    glVertex2f(70, -50);
    glVertex2f(80, -60);

    glVertex2f(40, -80);
    
    glEnd();

    // right hand
    glBegin(GL_LINE_STRIP);
    glVertex2f(-10, -20);
    glVertex2f(-20, -40);
    glVertex2f(-20, -60);
    glVertex2f(-10, -70);
    glVertex2f(10, -60);
    glVertex2f(20, -40);
    glEnd();

    // left hand
    glBegin(GL_LINE_STRIP);
    glVertex2f(-70, -10);
    glVertex2f(-80, -20);
    glVertex2f(-80, -50);

    glVertex2f(-70, -60);
    glVertex2f(-60, -70);
    glVertex2f(-50, -60);
    glVertex2f(-50, -40);
    glVertex2f(-60, -30);
    glEnd();
}

void drawPikachuPoints() {
    glPointSize(4.0); // Set the size of the points
    glEnable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);

    glVertex2f(-50, -110);
    glVertex2f(10, -110);
    glVertex2f(0, -120);
    glVertex2f(10, -120);
    glVertex2f(30, -110);
    glVertex2f(40, -90);
    glVertex2f(40, -80);
    glVertex2f(40, -70);
    glVertex2f(40, -40);
    glVertex2f(30, 10);
    glVertex2f(30, 30);
    glVertex2f(20, 60);
    glVertex2f(50, 70);
    glVertex2f(70, 80);
    glVertex2f(90, 100);
    glVertex2f(70, 100);
    glVertex2f(30, 90);
    glVertex2f(0, 70);
    glVertex2f(-10, 80);
    glVertex2f(-40, 80);
    glVertex2f(-60, 70);
    glVertex2f(-70, 90);
    glVertex2f(-100, 110);
    glVertex2f(-130, 120);
    glVertex2f(-120, 100);
    glVertex2f(-90, 70);
    glVertex2f(-70, 60);
    glVertex2f(-80, 50);
    glVertex2f(-80, 30);
    glVertex2f(-90, 20);
    glVertex2f(-90, 10);
    glVertex2f(-70, -10);
    glVertex2f(-60, -20);
    glVertex2f(-70, -60);
    glVertex2f(-80, -80);
    glVertex2f(-80, -90);
    glVertex2f(-70, -100);
    glVertex2f(-80, -120);
    glVertex2f(-70, -120);

    glVertex2f(40, -70);
    glVertex2f(60, -60);
    glVertex2f(50, -40);
    glVertex2f(70, -30);
    glVertex2f(60, -10);
    glVertex2f(80, 0);
    glVertex2f(50, 40);
    glVertex2f(120, 80);
    glVertex2f(140, 30);
    glVertex2f(90, 10);
    glVertex2f(100, -10);
    glVertex2f(80, -20);
    glVertex2f(90, -40);
    glVertex2f(70, -50);
    glVertex2f(80, -60);
    glVertex2f(40, -80);

    glVertex2f(-10, -20);
    glVertex2f(-20, -40);
    glVertex2f(-20, -60);
    glVertex2f(-10, -70);
    glVertex2f(10, -60);
    glVertex2f(20, -40);

    glVertex2f(-70, -10);
    glVertex2f(-80, -20);
    glVertex2f(-80, -50);
    glVertex2f(-70, -60);
    glVertex2f(-60, -70);
    glVertex2f(-50, -60);
    glVertex2f(-50, -40);
    glVertex2f(-60, -30);

    glDisable(GL_POINT_SMOOTH);
    glEnd();
}


void Timer(int value) {
    glutTimerFunc(1, Timer, 0);
    glutPostRedisplay();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);

    GLfloat aspect = (GLfloat) w / (GLfloat) h;

    glLoadIdentity();

    if(w >= h) {
        gluOrtho2D(-150 * aspect, 150 * aspect, -150, 150);
    } else {
        gluOrtho2D(-150, 150, -150.0 / aspect, 150.0 / aspect);
    }
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0); // clear background color
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-150, 150, -150, 150);
}