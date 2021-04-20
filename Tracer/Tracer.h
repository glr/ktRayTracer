#ifndef TRACER_H
#define TRACER_H
/*
 *  Tracer.h
 *  ktRayTracer
 */

#include "vec.h"
#include "World.h"


using namespace gutz;


class Tracer {
	
public:
	Tracer(void);
	Tracer(World *world);
	
	~Tracer(void);
	
	virtual vec3f trace(const Ray& ray) const;
	virtual vec3f trace(const Ray ray, const int depth) const;
	virtual vec3f trace(const Ray ray, float& tmin, const int depth) const;
	
	
protected:
	World *world;
	
};

#endif // TRACER_H