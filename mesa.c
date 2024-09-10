#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

#define MESA 1
#define PROJECAO 1 // Para mudar a projecao, altere este valor (1, 2, 3)

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glEnable(GL_DEPTH_TEST); // Habilita o teste de profundidade

    // Inicializa display lists da mesa
    glNewList(MESA, GL_COMPILE);
        // Tampo da mesa
        glPushMatrix();
            glTranslated(0, 7, 0);
            glScaled(50, 2, 50);
            glutWireCube(1.0);
        glPopMatrix();
        
        // Pé da mesa 1
        glPushMatrix();
            glTranslated(20, -8, 20);
            glScaled(2, 30, 2);
            glutWireCube(1.0);
        glPopMatrix();

        // Pé da mesa 2
        glPushMatrix();
            glTranslated(-20, -8, 20);
            glScaled(2, 30, 2);
            glutWireCube(1.0);
        glPopMatrix();

        // Pé da mesa 3
        glPushMatrix();
            glTranslated(20, -8, -20);
            glScaled(2, 30, 2);
            glutWireCube(1.0);
        glPopMatrix();

        // Pé da mesa 4
        glPushMatrix();
            glTranslated(-20, -8, -20);
            glScaled(2, 30, 2);
            glutWireCube(1.0);
        glPopMatrix();
    glEndList();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpa o buffer de cor e profundidade
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();

    // Chama o display list da mesa para exibi-la
    glPushMatrix();
    glCallList(MESA);
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (PROJECAO == 1) {
        // Projeção perspectiva
        gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
        gluLookAt(-10.0, 30.0, 50.0, 0.0, -2.0, 0.0, 0.0, 1.0, 0.0);
    } else if (PROJECAO == 2) {
        // Projeção ortográfica - vista de cima
        glOrtho(-30.0, 30.0, -30.0, 30.0, 1.0, 250.0);
        gluLookAt(0.0, 250.0, 30.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    } else if (PROJECAO == 3) {
        // Projeção ortográfica - vista frontal
        glOrtho(-30.0, 30.0, -30.0, 30.0, 1.0, 250.0);
        gluLookAt(0.0, 0.0, 30.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    }

    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 27:
        exit(0);
        break;
    }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Ativa o buffer de profundidade
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mesa");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
