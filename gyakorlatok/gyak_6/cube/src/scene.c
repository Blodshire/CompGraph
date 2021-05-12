#include "scene.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
    scene->rotation =0.0;

    load_model(&(scene->cube), "cat.obj");
    scene->texture_id = load_texture("cube.png");

    glBindTexture(GL_TEXTURE_2D, scene->texture_id);

   //black
    scene->material.ambient.red = 0.02f;
    scene->material.ambient.green = 0.02f;
    scene->material.ambient.blue = 0.02f;

    scene->material.diffuse.red = 0.01f;
    scene->material.diffuse.green = 0.01f;
    scene->material.diffuse.blue = 0.01f;

    scene->material.specular.red = 0.4f;
    scene->material.specular.green = 0.4;
    scene->material.specular.blue = 0.4;

    scene->material.shininess = 10.0;
	
	//plastic
	scene->plastic_material.ambient.red = 0.00f;
    scene->plastic_material.ambient.green = 0.00f;
    scene->plastic_material.ambient.blue = 0.00f;

    scene->plastic_material.diffuse.red = 0.05f;
    scene->plastic_material.diffuse.green = 0.00f;
    scene->plastic_material.diffuse.blue = 0.00f;

    scene->plastic_material.specular.red = 0.7f;
    scene->plastic_material.specular.green = 0.6;
    scene->plastic_material.specular.blue = 0.6;

    scene->plastic_material.shininess = 32;
}

void set_lighting()
{
    float ambient_light[] = { 0.1f, 0.1f, 0.1f, 0.1f };
    float diffuse_light[] = { 1.0f, 1.0f, 1.0, 1.0f };
    float specular_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
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

void update_scene(Scene* scene, float time) {

    scene->rotation+=100*time;
}

void draw_scene(const Scene* scene)
{
    
    set_lighting();
    draw_origin();
	
	
	
	set_material(&(scene->material));
	
	
    glPushMatrix();
    glRotatef(scene->rotation, 1,0,0); 
	
    draw_model(&(scene->cube));
	
	set_material(&(scene->plastic_material));
    glTranslatef(1,0,0);
    draw_model(&(scene->cube));
    glPopMatrix();
	
	
	glPushMatrix();
	glTranslatef(-1, 0,0);
	glutSolidTeapot(0.2);
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
