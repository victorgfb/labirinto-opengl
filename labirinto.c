//*****************************************************
// UNIVASF- Universidade Federal do Vale do São Francisco
// Disciplina: Computação Gráfica
// Docente: Jorge Cavalcanti
// Discente: Djeysi Kathleen Alves
// Semestre: 2018.2
//
// labirinto:
//fundo branco
//linhas pretas
//*****************************************************

#define nCores 3

#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#define xStep 1 //incremento no eixo x
#define yStep 1 //incremento no eixo y
#define maxY 105 //valor máximo do eixo Y
#define maxX 105 //valor máximo do eixo X

// Variáveis que guardam a translação que será aplicada 
// sobre a casinha
int Tx=0;
int Ty=0;

// Variáveis que guardam os valores mínimos de x e y da 
// casinha
GLfloat minX;
GLfloat minY;

// Variáveis que guardam a largura e altura da janela
GLfloat windowXmin, windowXmax;
GLfloat windowYmin, windowYmax;

//Variáveis que guardam os vértices do triangulo
int x1,x2,x3,x4;

int y4,y2,y3,y5;

struct cor
{
   float r;
   float g;
   float b;
};

struct objeto
{
   float x1,x2,y1,y2;
};

struct cor fundo;
struct cor paredes;
struct cor objeto;
struct cor coresParedes[nCores];
struct cor coresFundo[nCores];
struct cor coresObjeto[nCores];
struct objeto l1,l2, tri;
int i = 0;


void Inicializa (void)
{
   
   //1 mudança
   
   coresParedes[0].r = 0;
   coresParedes[0].g = 0; //parede preto.
   coresParedes[0].b = 0;

   coresFundo[0].r = 1; 
   coresFundo[0].g = 1; //fundo branco.
   coresFundo[0].b = 1;

   coresObjeto[0].r = 1;
   coresObjeto[0].g = 0;//objeto vermelho
   coresObjeto[0].b = 0;

   // 2 mudança

   coresParedes[1].r = 1;
   coresParedes[1].g = 1;//parede branca
   coresParedes[1].b = 1;

   coresFundo[1].r = 0;
   coresFundo[1].g = 0; //fundo  preto
   coresFundo[1].b = 0;

   coresObjeto[1].r = 1;
   coresObjeto[1].g = 1; //objeto amarelo
   coresObjeto[1].b = 0;

   // 3 mudança
   coresParedes[2].r = 1;
   coresParedes[2].g = 0;//parede magenta
   coresParedes[2].b = 1;

   coresFundo[2].r = 0;
   coresFundo[2].g = 1; //fundo ciano 
   coresFundo[2].b = 1;

   coresObjeto[2].r = 0.5;
   coresObjeto[2].g = 0.5; //objeto cinza
   coresObjeto[2].b = 0.5;

   paredes = coresParedes[i];
   fundo = coresFundo[i];
   objeto = coresObjeto[i];

   // Define a cor de fundo da janela de visualização como branco

   glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
   x1 = 0;
   x2 = 10;
   x3 =10;
   x4 = 0;
   y4 = 30;
   y2 = 30;
   y3 = 40;
   y5 = 40;

   glClearColor(fundo.r, fundo.g, fundo.b, 0.0f);


   // Define a janela de visualização 2D
   glMatrixMode(GL_PROJECTION);
   gluOrtho2D(0.0,maxX,0.0,maxY);
   glMatrixMode(GL_MODELVIEW); //para n manipular a matriz de projeção
}


void desenhaTriangulo(){
   
   glColor3f(objeto.r,objeto.g,objeto.b);
   
   glBegin(GL_QUADS);
   glVertex2f(x1 + Tx, y4 + Ty);
   glVertex2f(x2 + Tx, y2 + Ty);
   glVertex2f(x3 + Tx, y3 + Ty);
   glVertex2f(x4 + Tx, y5 + Ty);
   glEnd();

  
}


void detectaColisao(struct objeto tri, struct objeto linha){
   if(((linha.x2 -1) == tri.x1) || ((linha.x1 -1) == tri.x2))
      if((tri.y1 >= (linha.y1 -1)) && (tri.y2 <= (linha.y2)-1) )
         printf("colidiu\n");
   
   if(((linha.y2 -1) == tri.y2) || ((linha.y1 -1) == tri.y1))
      if(((linha.x1 -1) <= tri.x2) && ((linha.x2 -1) >= tri.x1))
         printf("colidiu\n");


}


   // Função callback chamada para fazer o desenho
void Desenha(void)
{

      
   // Muda para o sistema de coordenadas do modelo
   glMatrixMode(GL_MODELVIEW);
   // Inicializa a matriz de transformação corrente
   glLoadIdentity();
 
   glClearColor(fundo.r, fundo.g, fundo.b, 0.0f);

   //Limpa a janela de visualização com a cor de fundo especificada
   glClear(GL_COLOR_BUFFER_BIT);
   
   
   // Define a cor de desenho: preto
   glColor3f(paredes.r,paredes.g,paredes.b);
 
   //Desenhando as linhas do labirinto na cor corrente.
   
   glLineWidth(3);
   glBegin(GL_LINES);
   glVertex2f(0, 0);
   glVertex2f(105, 0);
   glEnd();
   
   glBegin(GL_LINES);
   glVertex2f(0, 105);
   glVertex2f(105, 105);
   glEnd();
   
   glBegin(GL_LINE_STRIP);
   glVertex2f(0, 0);
   glVertex2f(0, 30);
   glVertex2f(15,30);
   glVertex2f(15,45);
   glVertex2f(30,45);
   glVertex2f(30,75);
   glVertex2f(45,75);
   glVertex2f(45,90);
   glEnd();
   
   glBegin(GL_LINES);
   glVertex2f(0, 45);
   glVertex2f(0, 105);
   glEnd();
   
   glBegin(GL_LINE_STRIP);
   glVertex2f(0, 60);
   glVertex2f(15, 60);
   glVertex2f(15, 90);
   glVertex2f(30, 90);
   glEnd();
   
   glBegin(GL_LINE_STRIP);
   glVertex2f(30, 45);
   glVertex2f(30, 15);
   glVertex2f(15, 15);
   glEnd();
   
   glBegin(GL_LINES);
   glVertex2f(75, 0);
   glVertex2f(75, 15);
   glEnd();

   l1.x1 = 75;
   l1.x2 = 75;
   l1.y1 = 0;
   l1.y2 = 15;
   
   glBegin(GL_LINES);
   glVertex2f(105, 105);
   glVertex2f(105, 60);
   glEnd();
      
   glBegin(GL_LINE_STRIP);
   glVertex2f(105, 0);
   glVertex2f(105, 45);
   glVertex2f(60, 45);
   glEnd();
   
   glBegin(GL_LINES);
   glVertex2f(90, 45);
   glVertex2f(90, 90);
   glEnd();
   
   glBegin(GL_LINES);
   glVertex2f(90, 75);
   glVertex2f(75, 75);
   glEnd();
   
   glBegin(GL_LINES);
   glVertex2f(60, 90);
   glVertex2f(75, 90);
   glEnd();
   
   glBegin(GL_LINES);
   glVertex2f(60, 60);
   glVertex2f(75, 60);
   glEnd();

   l2.x1 = 60;
   l2.x2 = 75;
   l2.y1 = 60;
   l2.y2 = 60;
   
   glBegin(GL_LINE_STRIP);
   glVertex2f(90, 15);
   glVertex2f(90, 30);
   glVertex2f(60,30);
   glVertex2f(60,15);
   glVertex2f(45,15);
   glVertex2f(45,60);
   glVertex2f(60,60);
   glVertex2f(60,105);
   glEnd();
   
   //Desenhando um triangulo vermelho de acordo com as transformações:
   
   glPushMatrix();  
   
   glTranslatef(1,1,0.0f);
  
   desenhaTriangulo();
   
   //glPopMatrix();
   
   glutSwapBuffers();
}


// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
         paredes = coresParedes[i];
         fundo = coresFundo[i];
         objeto = coresObjeto[i];
         i++;
         if(i >= nCores)
            i = 0;
    glutPostRedisplay();
}


// Função callback chamada para gerenciar eventos do teclado   
// para teclas especiais, tais como F1, PgDn e Home
void TeclasEspeciais(int key, int x, int y)
{
   
   printf("TX=%d, TY=%d\n", Tx,Ty);
   if(key == GLUT_KEY_UP) {
      Ty+= yStep;
      printf("Ty= %d  \n", Ty);
      if(( y3 + Ty) > 103){
         Ty = 0;
         Tx = 0;
      }
   }
    
   if(key == GLUT_KEY_DOWN) {
      Ty -= yStep;
      printf("y4= %d Ty= %d  \n",y4, Ty);
      if(( y4 + Ty) < 0){
         Ty = 0;
         Tx = 0;
      }
   }
    
   if(key == GLUT_KEY_RIGHT) {
      Tx += xStep;
      if(( x2 + Tx) > 103){
         Ty = 0;
         Tx = 0;
      }
   }
   
   if(key == GLUT_KEY_LEFT) {
      Tx -= xStep;
      if(( x1 + Tx) < 0){
         Ty = 0;
         Tx = 0;
      }
   }
   
   //encapsulando o objeto com uma lógica bizarra oriental:
   
   
   tri.y1 = y3 + Ty;
   tri.x1 =  x1 + Tx;
   tri.x2 = x2 + Tx;
   tri.y2 = y4 + Ty;
   
   printf("x1 (reta de cima) = %f, x2 (reta de baixo) = %f", tri.x1, tri.x2);
   
   detectaColisao(tri,l1);
   detectaColisao(tri,l2);
   
    glutPostRedisplay();
  //  Desenha();
     //  glutTimerFunc(150, TeclasEspeciais, 1);
}
   
void GerenciaTeclado(unsigned char key, int x, int y)
{
    switch (key) {
            case 'R': 
            case 'r':// muda a cor corrente para vermelho
                     glColor3f(1.0f, 0.0f, 0.0f);
                     break;
            case 'G':
            case 'g':// muda a cor corrente para verde
                     glColor3f(0.0f, 1.0f, 0.0f);
                     break;
            case 'B':
            case 'b':// muda a cor corrente para azul
                     glColor3f(0.0f, 0.0f, 1.0f);
                     break;
    }
    glutPostRedisplay();
}   

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	GLsizei largura, altura;

	// Evita a divisao por zero
	if(h == 0) h = 1;

	// Atualiza as variáveis
	largura = w;
	altura = h;

	// Especifica as dimensões da Viewport
	glViewport(0, 0, largura, altura);

	// Inicializa o sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de seleção (esquerda, direita, inferior, 
	// superior) mantendo a proporção com a janela de visualização
	if (largura <= altura) 
	{
		gluOrtho2D (0.0f, 105.0f, 0.0f*altura/largura, 105.0f*altura/largura);
		windowXmin = 0.0f;
		windowXmax =  105.0f;
		windowYmin = 0.0f*altura/largura;
		windowYmax = 105.0f*altura/largura;
	}
	else
	{ 
		gluOrtho2D (0.0f*largura/altura, 105.0f*largura/altura, 0.0f, 105.0f);
		windowXmin = 0.0f*largura/altura;
		windowXmax =  105.0f*largura/altura;
		windowYmin = 0.0f;
		windowYmax =  105.0f;
	}
}

void Teclado (unsigned char key, int x, int y)
{
   if (key == 27)
   exit(0);
}


// Programa Principal
int main(int argc, char** argv)
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowPosition(5,5); // Especifica a posição inicial da janela GLUT
   glutInitWindowSize(400,400); // Especifica o tamanho inicial em pixels da janela GLUT
   glutCreateWindow("labirinto Impossível");
   glutDisplayFunc(Desenha);
   glutReshapeFunc(AlteraTamanhoJanela); // Registra a função callback de redimensionamento da janela de visualização
   glutKeyboardFunc (Teclado);
   glutSpecialFunc(TeclasEspeciais);

   // Registra a função callback que será chamada a cada intervalo de tempo
   // glutTimerFunc(150, TeclasEspeciais, 1);
   
   glutMouseFunc (GerenciaMouse);
   Inicializa();
   glutMainLoop();
   
}
