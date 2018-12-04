#include <GL/gl.h>
#include <window.h>

void model_render(){
    // triangle
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 1.0);  /* blue */
    glVertex3f(0, 5, -7);
    glColor3f(0.0, 1.0, 0.0);  /* green */
    glVertex3f(-5, 0, -7);
    glColor3f(1.0, 0.0, 0.0);  /* red */
    glVertex3f(5, 0, -7);
    glEnd();
    glPopMatrix();
}

int main(int argc, char** argv){
    start(argc, argv, model_render, 1);
}