# OpenGL Programs psudo-code

```objectivec
int main(){
    init_window();
    init_keyboard();
    
    while(render){
        
        init_projection_matrix();
        init_view_matrix();
        
        for(model in models){
            init_model_matrix();
            render_model();
        }
    }
    
}
```

## Projection Matrix

```objectivec
glMatrixMode(GL_PROJECTION);

glLoadIdentity();

glOrtho(left, right, bottom, top, near, far);

glFrustum(left, right, bottom, top, near, far);
```

## View Matrix

```objectivec
glMatrixMode(GL_MODELVIEW);

glLoadIdentity();

glTranslatef(x, y, z);
glRotatef(x_rotate, 1, 0, 0);
glRotatef(y_rotate, 0, 1, 0);
glRotatef(z_rotate, 0, 0, 1);
```

## Model Matrix

```objectivec
glPushMatrix();

glTranslatef(x, y, z);
glRotatef(x_rotate, 1, 0, 0);
glRotatef(y_rotate, 0, 1, 0);
glRotatef(z_rotate, 0, 0, 1);

glBegin(GL_POLYGON);

...glColor*
...glVertex*

glEnd();

glPopMatrix();
```

## Model render

```objectivec
glClear(GL_COLOR_BUFFER_BIT);

glFlush();
```

## Request render

```objectivec
glutPostRedisplay();
```


## Lighting

```objectivec
glEnable(GL_LIGHTING);

GLfloat light_ambient[] = {red, green, blue, alpha};
GLfloat light_diffuse[] = {red, green, blue, alpha};
GLfloat light_specular[] = {red, green, blue, alpha};
GLfloat light_position[] = {x, y, z, r};

glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
glLightfv(GL_LIGHT0, GL_POSITION, light_position);

glEnable(GL_LIGHT0);
```