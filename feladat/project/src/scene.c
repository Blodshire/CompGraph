#include "scene.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>
#include <math.h>
#include <game.h>

void init_scene(Scene* scene)
{
	
    scene->w=0;
    /*


    glBindTexture(GL_TEXTURE_2D, scene->texture_id);
    */
    /*
    load_model(&(scene->hare), "hare.obj");
    scene->hare_texture_id = load_texture("hare.jpg");
 */
    load_model(&(scene->raptor), "raptor.obj");
    scene->raptor_texture_id = load_texture("raptor.png");
   
    scene->material_0.ambient.red = 1.0;
    scene->material_0.ambient.green = 1.0;
    scene->material_0.ambient.blue = 1.0;

    scene->material_0.diffuse.red = 1.0;
    scene->material_0.diffuse.green = 1.0;
    scene->material_0.diffuse.blue = 1.0;

    scene->material_0.specular.red = 0.0;
    scene->material_0.specular.green = 0.0;
    scene->material_0.specular.blue = 0.0;

    scene->material_0.shininess = 0.0;
	

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
	draw_hexas(0,0);

    set_material(&(scene->material_0));
    set_lighting();

	//draw grid

	float step_y = 1.5*2;
	float step_x = sqrt(3)*2;
	draw_hexas(0.25*step_x,0.5*step_y);
	glBindTexture(GL_TEXTURE_2D, scene->raptor_texture_id);
	draw_model(&(scene->raptor));
	/*
	float i;
	float k;
	for(k = -5; k<=5;k++){
		for(i = -5; i <=5; i++){
			draw_hexas(k*step_x,i*step_y);
		}
	}
	*/

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

void draw_hexas(float x, float y){
	
	float i;
	glPushMatrix();
	glColor3f(0, 1, 0);
	glTranslatef(x,y,0);
	
	//1
	glPushMatrix();
	
	glTranslatef(sqrt(3)/2*2, 0, 0);
	
	glBegin(GL_LINES);
    
    for (i = 0; i < 6; ++i) {
        glVertex3f(sin((i-1)/6.0*2*M_PI), cos((i-1)/6.0*2*M_PI), 0);
        glVertex3f(sin(i/6.0*2*M_PI), cos(i/6.0*2*M_PI), 0);
    }
    glEnd();
	glPopMatrix();
	
	//2
	glPushMatrix();
	
	glTranslatef(sqrt(3)/2, 1.5, 0);
	
	glBegin(GL_LINES);
    for (i = 0; i < 6; ++i) {
        glVertex3f(sin((i-1)/6.0*2*M_PI), cos((i-1)/6.0*2*M_PI), 0);
        glVertex3f(sin(i/6.0*2*M_PI), cos(i/6.0*2*M_PI), 0);
    }
    glEnd();
	glPopMatrix();
	
	//3
	glPushMatrix();
	
	glTranslatef(-sqrt(3)/2, 1.5, 0);
	
	glBegin(GL_LINES);
    for (i = 0; i < 6; ++i) {
        glVertex3f(sin((i-1)/6.0*2*M_PI), cos((i-1)/6.0*2*M_PI), 0);
        glVertex3f(sin(i/6.0*2*M_PI), cos(i/6.0*2*M_PI), 0);
    }
    glEnd();
	glPopMatrix();
	
	//4
	glPushMatrix();
	
	glTranslatef(-sqrt(3)/2*2, 0, 0);
	
	glBegin(GL_LINES);
    for (i = 0; i < 6; ++i) {
        glVertex3f(sin((i-1)/6.0*2*M_PI), cos((i-1)/6.0*2*M_PI), 0);
        glVertex3f(sin(i/6.0*2*M_PI), cos(i/6.0*2*M_PI), 0);
    }
    glEnd();
	glPopMatrix();
	
	//5
	glPushMatrix();
	
	glTranslatef(-sqrt(3)/2, -1.5, 0);
	
	glBegin(GL_LINES);
    for (i = 0; i < 6; ++i) {
        glVertex3f(sin((i-1)/6.0*2*M_PI), cos((i-1)/6.0*2*M_PI), 0);
        glVertex3f(sin(i/6.0*2*M_PI), cos(i/6.0*2*M_PI), 0);
    }
    glEnd();
	glPopMatrix();
	
	glPushMatrix();
	
	glTranslatef(sqrt(3)/2, -1.5, 0);

	glBegin(GL_LINES);
    for (i = 0; i < 6; ++i) {
        glVertex3f(sin((i-1)/6.0*2*M_PI), cos((i-1)/6.0*2*M_PI), 0);
        glVertex3f(sin(i/6.0*2*M_PI), cos(i/6.0*2*M_PI), 0);
    }
    glEnd();
	glPopMatrix();
	glPopMatrix();
	
}
