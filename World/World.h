#ifndef WORLD_H
#define WORLD_H
/*
 *  World.h
 *  ktRayTracer
 */

#include <vector>

#include "vec.h"
#include "Light.h"
#include "Camera.h"
#include "Geometry.h"
#include "Ray.h"
#include "Material.h"


using namespace std;
using namespace gutz;


class Tracer;

class World {
	
public:
	World(void);
	
	~World(void);
	
	void showInfo(void) const;
	
	void addLight(Light *light);
	vector<Light *> getLights(void);

	void setAmbient(Light *ambient);
	Light *getAmbient(void);
	
	void addCamera(const Camera *camera);
	
	void addGeometry(const Geometry *object);
	vector<const Geometry *> getGeometry(void);
	
	HitData hitObjects(const Ray& ray) const;
	
	Tracer *getTracer(void);
	
	void render(void);
	float render(unsigned int loops);
	
private:
	vector<const Camera *> cameras;
	vector<const Geometry *> objects;
	vector<Light *> lights;
	Light *ambient;
	Tracer *tracer;
};

#endif // WORLD_H