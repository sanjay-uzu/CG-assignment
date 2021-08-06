#include<GL/glut.h>
#include<stdio.h>

int moves=0; // don't rotate initially
float rotate_angle=0; // initial angle
int sh=0;
int tx=0,ty=0,posx=0,posy=0;
float translate_x=0,translate_y=0; // initial translation
int strEqu(char *a, char *b)

{
	int i = 0;
	while (1)
	{
		if (*(a + i) == 0 && *(b + i) == 0) return 1;
		else if (*(a + i) != *(b + i)) return 0;
		i++;

	}

}
void triangle(int x, int y)
{
 glColor3f(1,0,0);
 glBegin(GL_POLYGON); // drawing a Triangle
 glVertex2f(x,y);
 glVertex2f(x+400,y+300);
 glVertex2f(x+300,y+0);
 glEnd();
}
void square(int x, int y)
{
 glColor3f(1,0,0);
 glBegin(GL_POLYGON); // drawing a Triangle
 glVertex2f(x,y);
 glVertex2f(x+100,y);
 glVertex2f(x+100,y+100);
 glVertex2f(x,y+100);
 glEnd();
}
void display()
{
 int ch=0;
 char x[10];
    FILE *f;
    glClear(GL_COLOR_BUFFER_BIT);
 glLoadIdentity();
 glColor3f(1,1,1);
    char c;
    char buf[6];

    f=fopen("xyz.txt","r");
    int i=0;
    fread(buf, 1, sizeof buf, f);
    printf("\n%s",buf);
    wint_t wc;
    while((wc=fgetc(f))!=WEOF){
        x[i]=wc;
        i=i+1;
    }
    fclose(f);
 //printf("\n%s",x);
char g,h,k;
g=buf[0];
h=buf[1];

 if(strEqu(buf,"10")&&moves==0)
 {
    printf("Cell");
    ch=1;
    sh=1;
 }
  if(strEqu(buf,"01")&&moves==0)
 {
    printf("Book");
    ch=2;
    sh=2;
 }
  if(moves==1)
    ch=sh;
if(moves==1)
{
    char buf[6];

    f=fopen("op.txt","r");
    int i=0;
    fread(buf, 1, sizeof buf, f);
    fclose(f);

if(strEqu(buf,"00"))
{
    glTranslatef(posx,0,0);

}
if(strEqu(buf,"10"))
{
    glTranslatef(tx++,0,0);
    posx=tx;
}

if(strEqu(buf,"01")){
    glTranslatef(tx--,0,0);
    posx=tx;
}

}

 switch(ch)
 {
     case 1: printf("in");
             square(translate_x,translate_y);
             break;
     case 2: printf("in");
             triangle(translate_x,translate_y);
             break;

 }


  // mark origin point as white dot

  // what to rotate? – TRIANGLE boss
 glutPostRedisplay(); // call display function again and again
 glutSwapBuffers(); // show the output
}
void rotateMenu (int option)
{
 if(option==1)
 moves=1;
 if(option==2)
 moves=0;// rotate around origin
}
void init()
{
 glClearColor(0,0,0,1); //setting to black
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(-800, 800, -800, 800);
 glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{


 // getting the user's coordinates to rotate
 glutInit(&argc, argv); // initialize the graphics system
 glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB); // SINGLE also works
 glutInitWindowSize(800, 800); // 800 by 800 size..you can change it
 glutInitWindowPosition(0, 0); // where do you wanna see your window
 glutCreateWindow("Create and Rotate Triangle"); // title
 glutCreateMenu(rotateMenu);
 glutAddMenuEntry("Move",1);
 glutAddMenuEntry("Stop Moving",2);
 glutAttachMenu(GLUT_RIGHT_BUTTON);

 init(); // initialize the canvas
 glutDisplayFunc(display); // call display function
 glutMainLoop(); // run forever
}
