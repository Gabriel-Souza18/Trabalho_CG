#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

#define LUMINARIA 1
#define PROJECAO 1

GLUquadricObj *q;


void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    q = gluNewQuadric();
    // Inicializa display lists
    glNewList(LUMINARIA, GL_COMPILE); // Luminaria

        glPushMatrix(); //Pe da luminaria
            glTranslated(0, -20, 0);
            glRotated(90.0, 1, 0,0);
            gluDisk(q,0,6,7,10);
        glPopMatrix();

        glPushMatrix(); //Pe da luminaria
            glTranslated(0, -20, 0);
            glRotated(90.0, 1, 0,0);
            gluCylinder(q, 6, 6, 2, 10, 3);
        glPopMatrix();

        glPushMatrix(); //Pe da luminaria
            glTranslated(0, -20.25, 0);
            glRotated(90.0, 1, 0,0);
            gluDisk(q,0,6,7,10);
        glPopMatrix();
    
        glPushMatrix(); //Corpo
            glTranslated(0, 20, 0);
            glRotated(90.0, 1, 0,0);
            gluCylinder(q, 0.5, 0.5, 40, 10, 15);
        glPopMatrix();

        glPushMatrix(); // Cabeça da luminária
            glTranslated(2, 18, 5);  // Move a cabeça da luminária para fora da haste

            glRotated(220, 1, 1, 0); // Rotaciona para que a cabeça aponte para fora
            glTranslated(0, 0, 0);
            gluCylinder(q, 6, 0.5, 5, 10, 8);
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.5, 18, 5); // Posiciona a lâmpada na extremidade da cabeça
            glutSolidSphere(2, 40, 40);

        glPopMatrix();

    glEndList();
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();
    // Chama o display list da luminaria para exibi-la
    glPushMatrix();
    glCallList(LUMINARIA);
    glPopMatrix();
    // término do posicionamento da luminária
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
    glutCreateWindow("LUMINARIA");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}