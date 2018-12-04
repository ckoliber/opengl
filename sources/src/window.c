#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>

void window(int argc, char** argv);
void keyboard(unsigned char key, int x, int y);
void render();

// global variables
int projection_type;
void (*render_all)(void);
float view[] = {
        0.0f,   // x-pos
        0.0f,   // y-pos
        0.0f,   // z-pos
        0.0f,   // x-rotate
        0.0f,   // y-rotate
        0.0f    // z-rotate
};
float projection[] = {
        -1.0f,  // left
        1.0f,   // right
        -1.0f,  // bottom
        1.0f,   // top
        1.0f,   // near
        500.0f  // far
};

// glut init window
void window(int argc, char** argv){
    // init glut window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Example 1");

    // set keyboard onKey handler
    glutKeyboardFunc(keyboard);

    // start render loop
    glutDisplayFunc(render);
    glutMainLoop();
}

// glut keyboard onKey handler
void keyboard(unsigned char key, int x, int y){
    switch (key){
        case 'w':
            view[1] -= 0.1;
            break;
        case 'd':
            view[0] -= 0.1;
            break;
        case 's':
            view[1] += 0.1;
            break;
        case 'a':
            view[0] += 0.1;
            break;
        case 'e':
            view[2] -= 0.1;
            break;
        case 'q':
            view[2] += 0.1;
            break;
        default:break;
    }

    // request render
    glutPostRedisplay();
}

// glut render function
void render(){
    glClear(GL_COLOR_BUFFER_BIT);

    // projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(projection_type == 0){
        glOrtho(projection[0], projection[1], projection[2], projection[3], projection[4], projection[5]);
    }else{
        glFrustum(projection[0], projection[1], projection[2], projection[3], projection[4], projection[5]);
    }

    // view matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(view[0], view[1], view[2]);
    glRotatef(view[3], 1, 0, 0);
    glRotatef(view[4], 0, 1, 0);
    glRotatef(view[5], 0, 0, 1);

    // model render
    render_all();

    glFlush();
    glutPostRedisplay();
}

void start(int argc, char** argv, void (*internal_render)(void), int projection){
    projection_type = projection;
    render_all = internal_render;
    window(argc, argv);
}