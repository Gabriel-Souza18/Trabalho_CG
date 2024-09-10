#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

#define CADEIRA 1
#define PROJECAO 1

GLUquadricObj *q;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    // Inicializa display lists
    glNewList(CADEIRA, GL_COMPILE); // Cadeira
    
        //pe da cadeira 1
        glPushMatrix();
            glTranslated(0, 0, 0);
            glScaled(1,15,1);
            glutWireCube(1.0);
        glPopMatrix();

        //pe da cadeira 2
        glPushMatrix();
            glTranslated(10, 7.5, 0);
            glScaled(1,30,1);
            glutWireCube(1.0);
        glPopMatrix();

         //pe da cadeira 3
        glPushMatrix();
            glTranslated(10, 7.5, 10);
            glScaled(1,30,1);
            glutWireCube(1.0);
        glPopMatrix();

        //pe da cadeira 4
        glPushMatrix();
            glTranslated(0, 0, 10);
            glScaled(1,15,1);
            glutWireCube(1.0);
        glPopMatrix();

        // ligacao dos bancos na parte de cima
        glPushMatrix();
            glTranslated(10, 20, 5);
            glScaled(1,1,11);
            glutWireCube(1.0);
        glPopMatrix();

        //banco da cadeira
        glPushMatrix();
            glTranslated(5, 8, 0);
            glScaled(11,1,1);
            glutWireCube(1.0);
        glPopMatrix();

        glPushMatrix();
            glTranslated(5, 8, 10);
            glScaled(11,1,1);
            glutWireCube(1.0);
        glPopMatrix();

        glPushMatrix();
            glTranslated(0, 8, 5);
            glScaled(1,1,11);
            glutWireCube(1.0);
        glPopMatrix();

        glPushMatrix();
            glTranslated(10, 8, 5);
            glScaled(1,1,11);
            glutWireCube(1.0);
        glPopMatrix();

        // Banco
        glPushMatrix();
            glTranslated(5, 8, 5);
            glScaled(11,1,11);
            glutWireCube(1.0);
        glPopMatrix();

        // Encosto
        glPushMatrix();
            glTranslated(10, 15, 5);
            glScaled(1,11,11);
            glutWireCube(1.0);
        glPopMatrix();


    glEndList();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();
    // Chama o display list do vaso para exibi-lo
    glPushMatrix();
    glCallList(CADEIRA);
    glPopMatrix();
    // término do posicionamento da garrafa
    glutSwapBuffers();
}

void reshape(int w, int h)
{

    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (PROJECAO == 1)
    {
        // projeção perspectiva
        gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
        gluLookAt(-10.0, 30.0, 50.0, 0.0, -2.0, 0.0, 0.0, 1.0, 0.0);
    }
    else if (PROJECAO == 2)
    {
        // projeção ortográfica - vista de cima
        glOrtho(-30.0, 30.0, -30.0, 30.0, 1.0, 250.0);
        gluLookAt(0.0, 100.0, 30.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    }
    else if (PROJECAO == 3)
    {
        // projeção ortográfica - vista frontal
        glOrtho(-30.0, 30.0, -30.0, 30.0, 1.0, 250.0);
        gluLookAt(0.0, 0.0, 30.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    }
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        gluDeleteQuadric(q);
        exit(0);
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("CADEIRA");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}