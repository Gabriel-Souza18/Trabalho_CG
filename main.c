
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#define MESA 1
#define CADEIRA 2
#define CHAO 3
#define TACA 4
#define GARRAFA 5
#define LUMINARIA 6
GLUquadricObj *qGarrafa;

#define PROJECAO 3

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
// Inicializa as display lists
    glNewList(CHAO, GL_COMPILE); // Chao
{// modelando mesa
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
}
    glEndList();


    glNewList(MESA, GL_COMPILE); // Mesa
{ // Modelando mesa
        //Tampo da mesa
        glPushMatrix();
            glTranslated(0,7,0);
            glScaled(50,2,50);
            glutWireCube(1.0);
        glPopMatrix();
        
        //pe da mesa 1
        glPushMatrix();
            glTranslated(20,-8,20);
            glScaled(2,30,2);
            glutWireCube(1.0);
        glPopMatrix();

        //pe da mesa 2
        glPushMatrix();
            glTranslated(-20,-8,20);
            glScaled(2,30,2);
            glutWireCube(1.0);
        glPopMatrix();

         //pe da mesa 3
        glPushMatrix();
            glTranslated(20,-8,-20);
            glScaled(2,30,2);
            glutWireCube(1.0);
        glPopMatrix();

        //pe da mesa 4
        glPushMatrix();
            glTranslated(-20,-8,-20);
            glScaled(2,30,2);
            glutWireCube(1.0);
        glPopMatrix();
}
    glEndList();


    glNewList(CADEIRA, GL_COMPILE); // Cadeira
{ // Modelando cadeira
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

        glTranslated(5, 8, 5); // Centralize a posição do banco

        glBegin(GL_TRIANGLE_STRIP); // Desenhando linhas no banco
            // Especifica os quatro vértices do retângulo que forma o banco
            glVertex3f(-5.0, 0.0, -5.0); // Vértice inferior esquerdo
            glVertex3f( 5.0, 0.0, -5.0); // Vértice inferior direito

            glVertex3f( 0.0, 0.0, 0.0);

            glVertex3f(-5.0, 0.0,  5.0); // Vértice superior esquerdo
            glVertex3f( 5.0, 0.0,  5.0); // Vértice superior direito
        glEnd();

        glTranslated(5, 2, 0); // Ajuste a posição conforme necessário
        glRotatef(-90.0, 0.0, 1.0, 0.0);
        glBegin(GL_TRIANGLE_STRIP);
            glVertex3f(-5.0,  0.0, 0.0);  // Vértice inferior esquerdo
            glVertex3f( 5.0,  0.0, 0.0);  // Vértice inferior direito

            glVertex3f( 0.0, 5.0, 0.0);

            glVertex3f(-5.0, 10.0, 0.0);  // Vértice superior esquerdo
            glVertex3f( 5.0, 10.0, 0.0);  // Vértice superior direito
        glEnd();
}
    glEndList();


    glNewList(TACA, GL_COMPILE); // Taca
{// Modelando Taca
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
}
    glEndList();


    glNewList(GARRAFA, GL_COMPILE); // GARRAFA
{// Modelando garrafa
        // pe da garrafa
        glPushMatrix();
        GLUquadric* q  = gluNewQuadric();
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

    glNewList(LUMINARIA, GL_COMPILE); // Luminaria
{
        GLUquadric* q  = gluNewQuadric();
        glPushMatrix(); //Pe da luminaria
            glTranslated(0, -20, 0);
            glRotated(90.0, 1, 0,0);
            gluDisk(q,0,6,7,6);
        glPopMatrix();

        glPushMatrix(); //Pe da luminaria
            glTranslated(0, -20, 0);
            glRotated(90.0, 1, 0,0);
            gluCylinder(q, 6, 6, 2, 6, 1);
        glPopMatrix();

        glPushMatrix(); //Pe da luminaria
            glTranslated(0, -20.25, 0);
            glRotated(90.0, 1, 0,0);
            gluDisk(q,0,6,7,6);
        glPopMatrix();
    
        glPushMatrix(); //Corpo
            glTranslated(0, 20, 0);
            glRotated(90.0, 1, 0,0);
            gluCylinder(q, 0.5, 0.5, 40, 3, 5);
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
    glEndList();
}
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();
 // Chama o display list do chao para exibi-lo
    
    glPushMatrix();
        glScaled(1.5,1,1.5);
        glTranslated(0,-16,0);
        glCallList(CHAO);
    glPopMatrix();

 // término do posicionamento do chão
 // Chama o display list da mesa para exibi-la
    glPushMatrix();
        glScaled(0.6,0.7,0.6);
        glCallList(MESA);
    glPopMatrix();
 // término do posicionamento da mesa
 // Chama o display list da cadeira 1 para exibi-lo
    glPushMatrix();
        glRotated(20,0,1,0);
        glTranslated(15,-9,0);
        glCallList(CADEIRA);
    glPopMatrix();
 // término do posicionamento da cadeira 1

  // Chama o display list da cadeira 2 para exibi-lo
    glPushMatrix();
        
        glTranslated(-10,-9,5);
        glRotated(180,0,1,0);
        glCallList(CADEIRA);
    glPopMatrix();
 // término do posicionamento da cadeira 2

 // Chama o display list da TACA  para exibi-lo
    glPushMatrix();
        glTranslated(7,9,6);
        glScaled(0.2,0.2,0.2);
        
        glCallList(TACA);
    glPopMatrix();
 // término do posicionamento da TACA 

 // Chama o display list da GARRAFA  para exibi-lo
    glPushMatrix();
        glTranslated(0,12,0);
        glScaled(0.3,0.3,0.3);
        glCallList(GARRAFA);
    glPopMatrix();
 // término do posicionamento da GARRAFA 

 // Chama o display list da LUMINARIA  para exibi-lo
    glPushMatrix();
        glTranslated(-25, 0.25,-25);
        glScaled(1,0.75,1);
        glCallList(LUMINARIA);
    glPopMatrix();
 // término do posicionamento da LUMINARIA 

    glutSwapBuffers();
}
void reshape(int w, int h){
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
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
        case 27:
        gluDeleteQuadric(qGarrafa);
        exit(0);
        break;
    }
}
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("cena");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}