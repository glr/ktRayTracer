#ifndef TRIANGLE_H
#define TRIANGLE_H
/*
 *  Triangle.h
 *  ktRayTracer
 */

#include "Geometry.h"
#include "BoundVolume.h"


class Triangle : public Geometry {

public:
	Triangle(void);
	Triangle(const vec3f& p0, const vec3f& p1, const vec3f& p2);
	Triangle(float x0, float y0, float z0, float x1, float y1, float z1, float x2, float y2, float z2);
	Triangle(Material *material);
	Triangle(const vec3f& p0, const vec3f& p1, const vec3f& p2, Material *material);
	Triangle(float x0, float y0, float z0, float x1, float y1, float z1, float x2, float y2, float z2, Material *material);
	
	~Triangle(void);
	
	virtual void showInfo(void) const;
	
	virtual bool hit(const Ray& ray, float& tmin, HitData& hd) const;
	virtual bool shadowHit(const Ray& ray, float& tmin) const;
	
private:
	vec3f p0, p1, p2;
	vec3f normal;
	
	static const float kEpsilon;

	BoundVolume *bv;
};

#endif // TRIANGLE_H