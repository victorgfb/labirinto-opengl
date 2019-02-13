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

#include <stdlib.h>
#include <GL/glut.h>
#define xStep 5 //incremento no eixo x
#define yStep 5 //incremento no eixo y

// Variáveis que guardam a translação que será aplicada 
// sobre a casinha
GLfloat Tx;
GLfloat Ty;

// Variáveis que guardam os valores mínimos de x e y da 
// casinha
GLfloat minX, maxX;
GLfloat minY, maxY;

// Variáveis que guardam a largura e altura da janela
GLfloat windowXmin, windowXmax;
GLfloat windowYmin, windowYmax;

//Variáveis que guardam os vértices do triangulo
int x1,x2,x3;

int y4,y2,y3;


void Inicializa (void)
{
   // Define a cor de fundo da janela de visualização como branco
   glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
   x1 = 0;
   x2 = 10;
   x3 = 5;
   y4 = 30;
   y2 = 30;
   y3 = 40;
   // Define a janela de visualização 2D
   glMatrixMode(GL_PROJECTION);
   gluOrtho2D(0.0,105.0,0.0,105.0);
   glMatrixMode(GL_MODELVIEW); //para n manipular a matriz de projeção
}
   // Função callback chamada para fazer o desenho
void Desenha(void)
{
      
   // Muda para o sistema de coordenadas do modelo
   glMatrixMode(GL_MODELVIEW);
   // Inicializa a matriz de transformação corrente
   glLoadIdentity();
   
   //Limpa a janela de visualização com a cor de fundo especificada
   glClear(GL_COLOR_BUFFER_BIT);
   
   // Aplica uma translação sobre a casinha
   glTranslatef(Tx, Ty, 0.0f);
    
   // Define a cor de desenho: preto
   glColor3f(0.0,0.0,0.0);
 
   //Desenhando as linhas do labirinto na cor corrente.
   
   glLineWidth(2);
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
   
   
   
  
   
   //Desenhando um triangulo vermelho:
   
   glColor3f(1,0,0);
   glBegin(GL_TRIANGLES);
   glVertex2f(x1, y4);
   glVertex2f(x2, y2);
   glVertex2f(x3, y3);
   glEnd();

  

   glutSwapBuffers();
}


/*
// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
         if (state == GLUT_DOWN) {
               
                  
         }
    glutPostRedisplay();
}


*/

// Função callback chamada para gerenciar eventos do teclado   
// para teclas especiais, tais como F1, PgDn e Home
void TeclasEspeciais(int key)
{
    if(key == GLUT_KEY_UP) {
           Ty+= yStep;
           glMatrixMode(GL_PROJECTION);
           
    }
    if(key == GLUT_KEY_DOWN) {
           Ty -= yStep;
           glMatrixMode(GL_PROJECTION);
           
    }
    if(key == GLUT_KEY_RIGHT) {
           Tx += xStep;
           glMatrixMode(GL_PROJECTION);
           
    }
    if(key == GLUT_KEY_LEFT) {
           Tx -= xStep;
           glMatrixMode(GL_PROJECTION);
           
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
   // Registra a função callback que será chamada a cada intervalo de tempo
   glutTimerFunc(150, TeclasEspeciais, 1);
   Inicializa();
   glutMainLoop();
   
}
