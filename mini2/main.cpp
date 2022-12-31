#include<GL/glut.h>
#include<stdio.h>


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


 glutPostRedisplay(); // call display function again and again
 glutSwapBuffers(); // show the output
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


 glutInit(&argc, argv); // initialize the graphics system
 glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB); // SINGLE also works
 glutInitWindowSize(800, 800); // 800 by 800 size..you can change it
 glutInitWindowPosition(0, 0); // where do you wanna see your window
 glutAddMenuEntry("Move",1);
 glutAddMenuEntry("Stop Moving",2);
 glutAttachMenu(GLUT_RIGHT_BUTTON);
 init(); // initialize the canvas
 glutDisplayFunc(display); // call display function
 glutMainLoop(); // run forever
}
