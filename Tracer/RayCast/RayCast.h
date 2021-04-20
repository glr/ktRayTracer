#ifndef RAYCAST_H
#define RAYCAST_H
/*
 *  RayCast.h
 *  ktRayTracer
 */

#include "Tracer.h"
#include "vec.h"


using namespace gutz;


class RayCast : public Tracer {

public:
	RayCast(void);
	RayCast(World* world);
	
	~RayCast(void);		
	
	virtual vec3f trace(const Ray& ray) const;
	virtual vec3f trace(const Ray ray, const int depth) const;
	
};

#endif // RAYCAST_H