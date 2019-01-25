#include <stdlib.h>
#include <gl/glut.h>

void Inicializa (void) {
	// Define a cor de fundo da janela de visualização como azul
	glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,20.0,0.0,20.0);
	glutInitWindowSize(400,400);
}
// Função callback chamada para fazer o desenho
void Desenha(void) {
	//Limpa a janela de visualização com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);
	//Executa os comandos OpenGL para renderização.
	
	// Define a cor de desenho: vermelho
	glColor3f(0.0,0.0,1.0);
	
	// Desenha um triângulo no centro da janela
	glBegin(GL_QUADS);
	glVertex3f(7.5, 14.0, 0);
	glVertex3f(10.0, 16.5, 0);
	glVertex3f(12.5, 14.0, 0);
	glVertex3f(10.0, 11.5, 0);
	glEnd();
	
	// Define a cor de desenho: vermelho
	glColor3f(1.0,1.0,0.0);
	
	// Desenha um triângulo no centro da janela
	glBegin(GL_QUADS);
	glVertex3f(3.5, 10.0, 0);
	glVertex3f(6.0, 12.5, 0);
	glVertex3f(8.5, 10.0, 0);
	glVertex3f(6.0, 7.5, 0);
	glEnd();
	
	// Define a cor de desenho: vermelho
	glColor3f(1.0,0.0,0.0);
	
	// Desenha um triângulo no centro da janela
	glBegin(GL_QUADS);
	glVertex3f(11.5, 10.0, 0);
	glVertex3f(14.0, 12.5, 0);
	glVertex3f(16.5, 10.0, 0);
	glVertex3f(14.0, 7.5, 0);
	glEnd();
	
	// Define a cor de desenho: vermelho
	glColor3f(0.0,0.0,0.0);
	
	// Desenha um triângulo no centro da janela
	glBegin(GL_QUADS);
	glVertex3f(7.5, 6.0, 0);
	glVertex3f(10.0, 8.5, 0);
	glVertex3f(12.5, 6.0, 0);
	glVertex3f(10.0, 3.5, 0);
	glEnd();
	
	glFlush();
}

void Teclado (unsigned char key, int x, int y) {
	if (key == 27){
		exit(0);
	}
}

int main(void) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Primeiro Programa");
	Inicializa();
	glutDisplayFunc(Desenha);
	glutKeyboardFunc(Teclado);
	glutMainLoop();
}




