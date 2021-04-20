#ifndef WHITTED_H
#define WHITTED_H
/*
 *  Whitted.h
 *  ktRayTracer
 */

#include "Tracer.h"
#include "vec.h"


using namespace gutz;


class Whitted : public Tracer {

public: 
	Whitted(void);
	Whitted(World* world);
	
	~Whitted(void);
	
	virtual vec3f trace(const Ray& ray) const;
	virtual vec3f trace(const Ray ray, const int depth) const;
	virtual vec3f trace(const Ray ray, float& tmin, const int depth) const;
	
};

#endif // WHITTED_H