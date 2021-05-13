#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
    Model raptor;
	Model hare;
    Material material;
    GLuint hare_texture_id;
	GLuint raptor_texture_id;
	double w;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting();

/**
 *Update the scene
 */
void update_scene(Scene* scene, double time);

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);


/**
 * Draw hexas around x, y
 */
void draw_hexas(float x, float y);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

#endif /* SCENE_H */
