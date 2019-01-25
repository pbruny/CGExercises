#include <stdlib.h>
#include <gl/glut.h>

void Inicializa (void) {
	// Define a cor de fundo da janela de visualização como azul
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,20.0,0.0,20.0);
}
// Função callback chamada para fazer o desenho
void Desenha(void) {
	//Limpa a janela de visualização com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);
	//Executa os comandos OpenGL para renderização.	
	// Define a cor de desenho: vermelho
	glColor3f(1.0,0.0,0.0);
	glLineWidth(2.0);

	glBegin(GL_LINE_LOOP);
	//Primeiro segmento diagonal do ponto (8,10) até o ponto (4, 3)
	glColor3f(1.0, 0.0, 0.0);
    glVertex2f(8.0, 10.0);
    glVertex2f(4.0, 3.0);
    
    //Segundo segmento diagonal do ponto (10, 7) até o ponto (16, 3)
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(10.0, 7.0);
    glVertex2f(16.0, 3.0);
    
    //Terceiro segmento diagonal que fecha o loop do ponto (12, 10) até (10, 17)
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(12.0, 10.0);
    glVertex2f(10.0, 17.0);  
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
	glutInitWindowSize(400,400);
	glutCreateWindow("Primeiro Programa");
	glutDisplayFunc(Desenha);
	Inicializa();
	glutKeyboardFunc(Teclado);
	glutMainLoop();
}




