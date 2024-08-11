#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#define TACA 1
#define PROJECAO 3 // pra mudar a projecao muda esse valor (1,2,3)


void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // Inicializa display lists da TACA
    glNewList(TACA, GL_COMPILE); // TACA
    // Use aqui as primitivas e transformações geométricas do OpenGL para modelar a TACA.

    //parte de cima da taca
    glPushMatrix();
        glTranslated(0,10,0);
        glRotated(90.0,1, 0,0);
        GLUquadric* quad  = gluNewQuadric();
        gluCylinder(quad, 10, 0.5, 10, 30, 6);
    glPopMatrix();
    //haste da taca
    glPushMatrix();
        glRotated(90.0,1, 0,0);
        gluCylinder(quad, 0.5, 0.5, 15, 10, 3);
    glPopMatrix();
    // pe da taça
    glPushMatrix();
        glTranslated(0,-15,0);
        glRotated(90.0,1, 0,0);
        gluDisk(quad,0,4,7,10);
        gluCylinder(quad, 4, 4, 1, 10, 7);
    glPopMatrix();
    glEndList();
    }


void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();
    // Chama o display list da TACA para exibi-la
    glPushMatrix();
    glCallList(TACA);
    glPopMatrix();
    // término do posicionamento da TACA
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

void keyboard(unsigned char key, int x, int y){
    switch(key) {
    case GLUT_KEY_F1:
        exit(0);
        break;
    }
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("TACA");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}