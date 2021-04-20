#ifndef SPHERE_H
#define SPHERE_H
/*
 *  Sphere.h
 *  ktRayTracer
 */

#include "Geometry.h"


class Sphere : public Geometry {
	
public:
	Sphere(void);
	Sphere(const vec3f& center, float radius);
	Sphere(float x, float y, float z, float radius);
	Sphere(Material *material);
	Sphere(const vec3f& center, float radius, Material *material);
	Sphere(float x, float y, float z, float radius, Material *material);
	
	~Sphere(void);
	
	virtual void showInfo(void) const;
	
	virtual bool hit(const Ray& ray, float& tmin, HitData& hd) const;
	virtual bool shadowHit(const Ray& ray, float& tmin) const;
	
private:
	vec3f center;
	float radius;
	
	static const float kEpsilon;
	
	void setBoundBox(void);

};

#endif // SPHERE_H