#include <GL/gl.h>
#include <window.h>

void model_render(){
    // cube
    glBegin(GL_QUADS);

    glColor3f(0, 0, 0); glVertex3f(-1, -1, -1);
    glColor3f(0, 0, 1); glVertex3f(-1, -1,  1);
    glColor3f(0, 1, 1); glVertex3f(-1,  1,  1);
    glColor3f(0, 1, 0); glVertex3f(-1,  1, -1);

    glColor3f(1, 0, 0); glVertex3f( 1, -1, -1);
    glColor3f(1, 0, 1); glVertex3f( 1, -1,  1);
    glColor3f(1, 1, 1); glVertex3f( 1,  1,  1);
    glColor3f(1, 1, 0); glVertex3f( 1,  1, -1);

    glColor3f(0, 0, 0); glVertex3f(-1, -1, -1);
    glColor3f(0, 0, 1); glVertex3f(-1, -1,  1);
    glColor3f(1, 0, 1); glVertex3f( 1, -1,  1);
    glColor3f(1, 0, 0); glVertex3f( 1, -1, -1);

    glColor3f(0, 1, 0); glVertex3f(-1,  1, -1);
    glColor3f(0, 1, 1); glVertex3f(-1,  1,  1);
    glColor3f(1, 1, 1); glVertex3f( 1,  1,  1);
    glColor3f(1, 1, 0); glVertex3f( 1,  1, -1);

    glColor3f(0, 0, 0); glVertex3f(-1, -1, -1);
    glColor3f(0, 1, 0); glVertex3f(-1,  1, -1);
    glColor3f(1, 1, 0); glVertex3f( 1,  1, -1);
    glColor3f(1, 0, 0); glVertex3f( 1, -1, -1);

    glColor3f(0, 0, 1); glVertex3f(-1, -1,  1);
    glColor3f(0, 1, 1); glVertex3f(-1,  1,  1);
    glColor3f(1, 1, 1); glVertex3f( 1,  1,  1);
    glColor3f(1, 0, 1); glVertex3f( 1, -1,  1);

    glEnd();
}

int main(int argc, char** argv){
    start(argc, argv, model_render, 1);
}