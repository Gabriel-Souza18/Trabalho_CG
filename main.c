
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

#define PROJECAO 1
double angle, fAspect;
float rotX, rotY, obsZ;
int luz;

void DefineIluminacao (void)
{
   //Define os parâmetros através de vetores RGBA - o último valor deve ser sempre 1.0f
       float luzAmbiente[]={0.2f, 0.2f, 0.2f, 1.0f};
       float luzDifusa[]={1.0f, 1.0f, 1.0f, 1.0f}; 
       float luzEspecular[]={1.0f, 1.0f, 1.0f, 1.0f};
       float posicaoLuz[]={0.0f, 30.0f, 0.0f, 1.0f}; // último parâmetro: 0-direcional, 1-pontual/posicional


       //Ativa o uso da luz ambiente
       glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);


       //Define os parâmetros da luz de número 0
       glLightfv(GL_LIGHT0,GL_AMBIENT, luzAmbiente);
       glLightfv(GL_LIGHT0,GL_DIFFUSE, luzDifusa );
       glLightfv(GL_LIGHT0,GL_SPECULAR, luzEspecular);
       glLightfv(GL_LIGHT0,GL_POSITION, posicaoLuz ); 
      
      
       // Brilho do material
       float especularidade[]={1.0f, 1.0f, 1.0f, 1.0f};
       int especMaterial = 60;


       // Define a reflectância do material
       glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
       // Define a concentração do brilho
       glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
}
// Função usada para especificar a posição do observador virtual
void PosicionaObservador(void)
{
   // Especifica sistema de coordenadas do modelo
   glMatrixMode(GL_MODELVIEW);
   // Inicializa sistema de coordenadas do modelo
   glLoadIdentity();
   // Especifica posição do observador e do alvo
   glTranslatef(0,0,-obsZ);
   glRotatef(rotX,1,0,0);
   glRotatef(rotY,0,1,0);
}
void EspecificaParametrosVisualizacao(void)
{
   // Especifica sistema de coordenadas de projeção
   glMatrixMode(GL_PROJECTION);
   // Inicializa sistema de coordenadas de projeção
   glLoadIdentity();
   // Especifica a projeção perspectiva(angulo,aspecto,zMin,zMax)
   gluPerspective(angle, fAspect, 0.2, 500);


   PosicionaObservador();
}


void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST); // Habilita o teste de profundidade
    glEnable(GL_LIGHTING); // Habilita a iluminação
    glEnable(GL_LIGHT0); // Habilita a luz 0
    glEnable(GL_COLOR_MATERIAL);



   // Especifica o ângulo da projeção perspectiva 
    angle=50;  
       // Inicializa o valor para correção de aspecto  
    fAspect = 1;

    rotX = 0;
    rotY = 0;
    obsZ = 50;
    luz =1;
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
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
    glColor3d(0.5,0.5,0);
        //Tampo da mesa
        glPushMatrix();
            glTranslated(0,7,0);
            glScaled(50,2,50);
            glutSolidCube(1.0);
        glPopMatrix();
        
        //pe da mesa 1
        glPushMatrix();
            glTranslated(20,-8,20);
            glScaled(2,30,2);
            glutSolidCube(1.0);
        glPopMatrix();

        //pe da mesa 2
        glPushMatrix();
            glTranslated(-20,-8,20);
            glScaled(2,30,2);
            glutSolidCube(1.0);
        glPopMatrix();

         //pe da mesa 3
        glPushMatrix();
            glTranslated(20,-8,-20);
            glScaled(2,30,2);
            glutSolidCube(1.0);
        glPopMatrix();

        //pe da mesa 4
        glPushMatrix();
            glTranslated(-20,-8,-20);
            glScaled(2,30,2);
            glutSolidCube(1.0);
        glPopMatrix();
}
    glEndList();


    glNewList(CADEIRA, GL_COMPILE); // Cadeira
    glColor3d(0,0.2,0.7);
{ // Modelando cadeira
        //pe da cadeira 1
        glPushMatrix();
            glTranslated(0, 0, 0);
            glScaled(1,15,1);
            glutSolidCube(1.0);
        glPopMatrix();

        //pe da cadeira 2
        glPushMatrix();
            glTranslated(10, 7.5, 0);
            glScaled(1,30,1);
            glutSolidCube(1.0);
        glPopMatrix();

         //pe da cadeira 3
        glPushMatrix();
            glTranslated(10, 7.5, 10);
            glScaled(1,30,1);
            glutSolidCube(1.0);
        glPopMatrix();

        //pe da cadeira 4
        glPushMatrix();
            glTranslated(0, 0, 10);
            glScaled(1,15,1);
            glutSolidCube(1.0);
        glPopMatrix();

        // ligacao dos bancos na parte de cima
        glPushMatrix();
            glTranslated(10, 20, 5);
            glScaled(1,1,11);
            glutSolidCube(1.0);
        glPopMatrix();

        //banco da cadeira
        glPushMatrix();
            glTranslated(5, 8, 0);
            glScaled(11,1,1);
            glutSolidCube(1.0);
        glPopMatrix();

        glPushMatrix();
            glTranslated(5, 8, 10);
            glScaled(11,1,1);
            glutSolidCube(1.0);
        glPopMatrix();

        glPushMatrix();
            glTranslated(0, 8, 5);
            glScaled(1,1,11);
            glutSolidCube(1.0);
        glPopMatrix();

        glPushMatrix();
            glTranslated(10, 8, 5);
            glScaled(1,1,11);
            glutSolidCube(1.0);
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
    glColor3d(0.3,0.0,0.2);
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
    glColor3d(1,0,0);
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
            glutSolidTorus(1.0, 1.1, 20, 20);
        glPopMatrix();

    glEndList();
}

    glNewList(LUMINARIA, GL_COMPILE); // Luminaria
    glColor3d(0.1,0.1,0.1);
{//modelando luminaria
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

    EspecificaParametrosVisualizacao();
    DefineIluminacao();
 // Chama o display list do chao para exibi-lo
    
    glPushMatrix();
        glScaled(1.5,1,1.5);
        glTranslated(0,-16,0);
        glCallList(CHAO);
    glPopMatrix();
EspecificaParametrosVisualizacao();
    glPushMatrix();
        glScaled(0.6,0.7,0.7);
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
void GerenciaMouse(int button, int state, int x, int y)
{
   if (button == GLUT_LEFT_BUTTON)
       if (state == GLUT_DOWN) {  // Zoom-in
           if (angle >= 40) angle -= 4;
       }
   if (button == GLUT_RIGHT_BUTTON)
       if (state == GLUT_DOWN) {  // Zoom-out
           if (angle <= 72) angle += 4;
       }
   EspecificaParametrosVisualizacao();
   glutPostRedisplay();
}


void TeclasEspeciais(int key, int x, int y)
{
   switch (key)
   {
       case GLUT_KEY_LEFT:rotY--;
               break;
       case GLUT_KEY_RIGHT:rotY++;
               break;
       case GLUT_KEY_UP:rotX++;
               break;
       case GLUT_KEY_DOWN:rotX--;
               break;
       case GLUT_KEY_HOME:obsZ++;
               break;
       case GLUT_KEY_END:obsZ--;
               break;
       case GLUT_KEY_F1: if (luz) luz = 0;
       else luz = 1;
       break;     
       case GLUT_KEY_F10:// "camera reset"
               rotX=0;
               rotY=0;
               obsZ=200;
               angle=50;
               EspecificaParametrosVisualizacao();
               break;
   }
   PosicionaObservador();
   glutPostRedisplay();
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
    glutMouseFunc(GerenciaMouse);
    glutSpecialFunc(TeclasEspeciais);
    glutMainLoop();
    return 0;
}