#ifndef RAY_H
#define RAY_H
/*
 *  Ray.h
 *  ktRayTracer
 */

#include "vec.h"


using namespace gutz;


class Ray {
	
public:
	Ray(void);
	Ray(const vec3f& origin, const vec3f direction);
	Ray(float x, float y, float z, vec3f direction);
	Ray(const vec3f& origin, float u, float v, float w);
	Ray(float x, float y, float z, float u, float v, float w);
	
	~Ray(void);
	
	void setOrigin(const vec3f& origin);
	void setOrigin(float x, float y, float z);
	vec3f getOrigin(void) const;
	
	void setDirection(const vec3f& direction);
	void setDirection(float u, float v, float w);
	vec3f getDirection(void) const;
	
	vec3f getPoint(float t) const;
	
private:
	vec3f origin;
	vec3f direction;
	
};

#endif RAY_H