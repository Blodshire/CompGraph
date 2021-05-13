#include "scene.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>
#include <math.h>

void init_scene(Scene* scene)
{
    scene->w=0;
    /*


    glBindTexture(GL_TEXTURE_2D, scene->texture_id);
    */
    /*
    load_model(&(scene->hare), "hare.obj");
    scene->hare_texture_id = load_texture("hare.jpg");

    load_model(&(scene->raptor), "raptor.obj");
    scene->raptor_texture_id = load_texture("raptor.png");
    */
    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 0.0;
    scene->material.specular.green = 0.0;
    scene->material.specular.blue = 0.0;

    scene->material.shininess = 0.0;

}

void update_scene(Scene* scene, double time) {
    scene->w +=time;
}

void set_lighting()
{

    float ambient_light[] = { 1.0f, 1.0f,1.0f, 1.0f };
    float diffuse_light[] = { 0.0f, 0.0f, 0.0, 0.0f };
    float specular_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}


void draw_scene(const Scene* scene)
{


    //draw_origin();


    //set_material(&(scene->material));
    set_lighting();
    //draw_model(&(scene->cube));
    /*
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->hare_texture_id);
    glTranslatef(2,0,0);
    glScalef(0.2,0.2,0.2);
    draw_model(&(scene->hare));
    glPopMatrix();

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->raptor_texture_id);
    draw_model(&(scene->raptor));
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_QUADS);
    glTranslatef(0,-2,0);

    glTexCoord2f(0,0);
    glVertex3f(0, 0, 0);

    glTexCoord2f(fabs(sin(scene->w)),0);
    glVertex3f(1, 0, 0);

    glTexCoord2f(1, fabs(sin(scene->w)));
    glVertex3f(1, 1, 0);

    glTexCoord2f(0,1);
    glVertex3f(0, 1, 0);


    glEnd();
    glPopMatrix();
    */
    float i;
    float p;
    float s;
/*
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3, 0.3);
    for (i = 0; i < 6; ++i) {
        glVertex2d(sin(i/6.0*2*M_PI),
                   cos(i/6.0*2*M_PI));
        // printf("%lf - %lf\n",sin(i/6.0*2*M_PI),cos(i/6.0*2*M_PI));

    }
    //printf("\n");
    glEnd();
	*/
    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    for (i = 0; i < 6; ++i) {
        glVertex3f(sin((i-1)/6.0*2*M_PI), cos((i-1)/6.0*2*M_PI), 0);
        glVertex3f(sin(i/6.0*2*M_PI), cos(i/6.0*2*M_PI), 0);
    }
    glEnd();
	
	glPushMatrix();
	glTranslatef(sqrt(3)/2*2, 0, 0);
	glBegin(GL_LINES);
    glColor3f(0, 1, 0);
    for (i = 0; i < 6; ++i) {
        glVertex3f(sin((i-1)/6.0*2*M_PI), cos((i-1)/6.0*2*M_PI), 0);
        glVertex3f(sin(i/6.0*2*M_PI), cos(i/6.0*2*M_PI), 0);
    }
    glEnd();
	
	
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-sqrt(3)/2*2, 0, 0);
	glBegin(GL_LINES);
    glColor3f(0, 0, 1);
    for (i = 0; i < 6; ++i) {
        glVertex3f(sin((i-1)/6.0*2*M_PI), cos((i-1)/6.0*2*M_PI), 0);
        glVertex3f(sin(i/6.0*2*M_PI), cos(i/6.0*2*M_PI), 0);
    }
    glEnd();
	glPopMatrix();
	
	
	
	glPushMatrix();
	glTranslatef(sqrt(3)/2, 1.5, 0);
	glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    for (i = 0; i < 6; ++i) {
        glVertex3f(sin((i-1)/6.0*2*M_PI), cos((i-1)/6.0*2*M_PI), 0);
        glVertex3f(sin(i/6.0*2*M_PI), cos(i/6.0*2*M_PI), 0);
    }
    glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(sqrt(3)/2, -1.5, 0);
	glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    for (i = 0; i < 6; ++i) {
        glVertex3f(sin((i-1)/6.0*2*M_PI), cos((i-1)/6.0*2*M_PI), 0);
        glVertex3f(sin(i/6.0*2*M_PI), cos(i/6.0*2*M_PI), 0);
    }
    glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-sqrt(3)/2, -1.5, 0);
	glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    for (i = 0; i < 6; ++i) {
        glVertex3f(sin((i-1)/6.0*2*M_PI), cos((i-1)/6.0*2*M_PI), 0);
        glVertex3f(sin(i/6.0*2*M_PI), cos(i/6.0*2*M_PI), 0);
    }
    glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-sqrt(3)/2, 1.5, 0);
	glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    for (i = 0; i < 6; ++i) {
        glVertex3f(sin((i-1)/6.0*2*M_PI), cos((i-1)/6.0*2*M_PI), 0);
        glVertex3f(sin(i/6.0*2*M_PI), cos(i/6.0*2*M_PI), 0);
    }
    glEnd();
	glPopMatrix();
	
    //glBegin(GL_LINES);
    // glColor3f(0, 0, 0);
    //glVertex3f(0, 0, 0);
    //glVertex3f(sin(1/6.0*2*M_PI), cos(1/6.0*2*M_PI), 0);
    //glEnd();
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
