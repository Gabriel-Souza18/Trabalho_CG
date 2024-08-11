#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

#define GARRAFA 1
#define PROJECAO 3

GLUquadricObj *q;
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    q = gluNewQuadric();
    // Inicializa display lists
    glNewList(GARRAFA, GL_COMPILE); // GARRAFA
        // Use aqui as primitivas e transformacoes geometricas
        // do OpenGL para modelar o GARRAFA.

        // pe da garrafa
        glPushMatrix();
            glTranslated(0, -20, 0);
            glRotated(90.0, 1, 0,0);
            gluDisk(q,0,4,7,10);
        glPopMatrix();

        // corpo da garrafa
        glPushMatrix();
            glTranslated(0, 0,0);
            glRotated(90.0, 1, 0,0);
            gluCylinder(q, 4, 4, 20, 10, 15);
        glPopMatrix();

        // curva no meio da garrafa
        glPushMatrix();
            glTranslated(0, 5, 0);
            glRotated(90.0, 1, 0,0);
            gluCylinder(q, 1, 4, 5, 10, 5);
        glPopMatrix();

        // parte mais fina da garrafa
        glPushMatrix();
            glTranslated(0, 10,0);
            glRotated(90.0, 1, 0,0);
            gluCylinder(q, 1, 1, 5, 5, 3);
        glPopMatrix();

        // boca da garrafa
        glPushMatrix();
            glTranslated(0, 10,0);
            glRotated(90.0, 1, 0,0);
            glutWireTorus(1.0, 1.1, 20, 20);
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
    glCallList(GARRAFA);
    glPopMatrix();
    // término do posicionamento da garrafa
    glutSwapBuffers();
}

void reshape(int w, int h){
     
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    if(PROJECAO == 1){
        //projeção perspectiva
        gluPerspective(60.0, (GLfloat)w/(GLfloat)h, 1.0, 100.0);
        gluLookAt(-10.0, 30.0, 50.0,0.0, -2.0, 0.0, 0.0, 1.0, 0.0);
    }else if(PROJECAO == 2){
        //projeção ortográfica - vista de cima
        glOrtho(-30.0,30.0, -30.0,30.0, 1.0,250.0);
        gluLookAt(0.0, 100.0, 30.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    }else if(PROJECAO == 3){
         //projeção ortográfica - vista frontal
        glOrtho(-30.0,30.0, -30.0,30.0, 1.0,250.0);
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
    glutCreateWindow("GARRAFA");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}