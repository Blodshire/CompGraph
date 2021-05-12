#include "scene.h"

#include <GL/glut.h>
#define M_PI acos(-1.0)


void init_scene(Scene* scene)
{
    scene->teapot_rotation = 0.0;
}
void update_scene(Scene* scene, double time)
{
    scene->teapot_rotation += 10 * time;
    if ( scene->teapot_rotation > 360.0) {
        scene->teapot_rotation-=360;
    }
}

void draw_scene(const Scene* scene)
{
    int i, k;
    draw_origin();

    /*glPushMatrix();
    for (k=0;k<8;++k) {
        glPushMatrix();
        for (i=0; i < 6; ++i) {


            glBegin(GL_TRIANGLES);
            glColor3f(1, 0, 0);
            glVertex3f(1, 0, 0);

            glColor3f(0, 1, 0);
            glVertex3f(0, 1, 0);

            glColor3f(0, 0, 1);
            glVertex3f(0, 0, 1);
            glEnd();

            glTranslatef(0,0,0.2);
        }
        glPopMatrix();
        glTranslatef(1,1,0);
    }
    glPopMatrix();

    glPushMatrix();
    glRotatef(scene->teapot_rotation, 1, 0 , 0);
    glColor3f(cos(scene->teapot_rotation /60), sin(scene->teapot_rotation / 120), 1);
    glutSolidTeapot(scene->teapot_rotation/360);
    glPopMatrix();
    */

    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 1);
    glEnd();

    /*glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glTranslatef(0.5, 0.5, 0.5);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();*/

    glPushMatrix();
    glRotatef(scene->teapot_rotation, 1, 0 , 0);
    glTranslatef(0.5, 0.5, 0.5);
    glColor3f(0.5, 0.5, 0.5);
    glutSolidSphere(0.4,10,10);
    glPopMatrix();

    //instructions unclear on google maps
    glBegin(GL_LINES);
    float nm;
    for (nm = 0.2; nm <= 1; nm+=0.2) {

        glColor3f(0.5, 0.5, 0.5);
        glVertex3f (0, nm,0);
        glVertex3f (1, nm,0);
        glVertex3f (nm, 0,0);
        glVertex3f (nm, 1,0);
    }
    glEnd();
	glPushMatrix();
	glTranslatef(3, 0, 0);
	float resolution = 1;
	float height = 2;
	float radius = M_PI/4;
    /* top triangle */
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, height, 0);  /* center */
    for (i = 0; i <= 2 * M_PI; i += resolution)
        glVertex3f(radius * cos(i), height, radius * sin(i));
    glEnd();

    /* bottom triangle: note: for is in reverse order */
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, 0, 0);  /* center */
    for (i = 2 * M_PI; i >= 0; i -= resolution)
        glVertex3f(radius * cos(i), 0, radius * sin(i));
    /* close the loop back to 0 degrees */
    glVertex3f(radius, height, 0);
    glEnd();

    /* middle tube */
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i <= 2 * M_PI; i += resolution)
    {
        glVertex3f(radius * cos(i), 0, radius * sin(i));
        glVertex3f(radius * cos(i), height, radius * sin(i));
    }
    /* close the loop back to zero degrees */
    glVertex3f(radius, 0, 0);
    glVertex3f(radius, height, 0);
    glEnd();
	glPopMatrix();


}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}
