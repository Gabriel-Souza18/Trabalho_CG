
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#define CHAO 1
#define PROJECAO 1 // pra mudar a projecao muda esse valor (1,2,3)


void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // Inicializa display lists da CHAO
    glNewList(CHAO, GL_COMPILE); // CHAO
    // Use aqui as primitivas e transformações geométricas do OpenGL para modelar a CHAO.
    int tamanho = 10;
    float passo = 2.0;
    glBegin(GL_TRIANGLES);
    for (int x = -tamanho; x < tamanho; x++) {
        for (int z = -tamanho; z < tamanho; z++) {
            // Primeiro triângulo
            glVertex3f(x * passo, 0, z * passo);
            glVertex3f((x + 1) * passo, 0, z * passo);
            glVertex3f(x * passo, 0, (z + 1) * passo);

            // Segundo triângulo
            glVertex3f((x + 1) * passo, 0, z * passo);
            glVertex3f((x + 1) * passo, 0, (z + 1) * passo);
            glVertex3f(x * passo, 0, (z + 1) * passo);
        }
    }
    glEnd();
    glEndList();
}


void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();
    // Chama o display list da CHAO para exibi-la
    glPushMatrix();
    glCallList(CHAO);
    glPopMatrix();
    // término do posicionamento da CHAO
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
    glutCreateWindow("CHAO");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}