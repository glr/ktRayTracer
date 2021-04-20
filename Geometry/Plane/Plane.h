#ifndef PLANE_H
#define PLANE_H
/*
 *  Plane.h
 *  ktRayTracer
 */

#include "Geometry.h"


class Plane : public Geometry {
	
public:
	Plane(void);
	Plane(const vec3f& point, const vec3f& normal);
	Plane(float x, float y, float z, const vec3f& normal);
	Plane(const vec3f& point, float u, float v, float w);
	Plane(float x, float y, float z, float u, float v, float w);
	Plane(Material *material);
	Plane(const vec3f& point, const vec3f& normal, Material *material);
	Plane(float x, float y, float z, const vec3f& normal, Material *material);
	Plane(const vec3f& point, float u, float v, float w, Material *material);
	Plane(float x, float y, float z, float u, float v, float w, Material *material);
	
	~Plane(void);
	
	virtual void showInfo(void) const;
	
	virtual bool hit(const Ray& ray, float& tmin, HitData& hd) const;
	virtual bool shadowHit(const Ray& ray, float& tmin) const;
	
private:
	vec3f point;
	vec3f normal;
	
	static const float kEpsilon;
	
};

#endif PLANE_H