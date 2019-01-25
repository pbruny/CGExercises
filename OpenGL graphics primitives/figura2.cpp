#include <stdlib.h>
#include <gl/glut.h>

void Inicializa (void) {
	// Define a cor de fundo da janela de visualização como azul
	glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
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
	glColor3f(1.0,0.0,0.0);
	glLineWidth(10.0);

	glBegin(GL_LINE_STRIP);
	//linha vertical 1
	glVertex3f(5.0, 5.0, 0);
	glVertex3f(5.0, 15.0, 0);
	//linha horizontal 1
	glVertex3f(4.75, 15.0, 0);
	glVertex3f(15.2, 15.0, 0);
	//linha vertical 2
	glVertex3f(15.0, 15.0, 0);
	glVertex3f(15.0, 5.0, 0);
	//linha horizontal 2
	glVertex3f(15.2, 5.0, 0);
	glVertex3f(4.75, 5.0, 0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	//linha vertical para cima
	glVertex3f(10.0, 11.0, 0);
	glVertex3f(10.0, 20.0, 0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	//linha horizontal para direita
	glVertex3f(11.0, 10.0, 0);
	glVertex3f(20.0, 10.0, 0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	//linha horizontal para esquerda
	glVertex3f(9.0, 10.0, 0);
	glVertex3f(0.0, 10.0, 0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	//linha vertical para baixo
	glVertex3f(10.0, 9.0, 0);
	glVertex3f(10.0, 0.0, 0);
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




