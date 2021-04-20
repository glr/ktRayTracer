#ifndef HITDATA_H
#define HITDATA_H
/*
 *  HitData.h
 *  ktRayTracer
 */

#include "vec.h"
#include "Ray.h"


class Material;
class World;


using namespace gutz;


class HitData {
	
public:
	HitData(const World& world);
	HitData(const HitData& hd);

	~HitData(void);
	
	void setHit(bool hit);
	bool getHit(void) const;
	
	void setMaterial(Material *material);
	Material *getMaterial(void) const;
	
	void setHitPoint(const vec3f& point);
	vec3f getHitPoint(void) const;

	void setTexHitPoint(const vec3f& point);
	vec3f getTexHitPoint(void) const;
	
	void setNormal(const vec3f& normal);
	vec3f getNormal(void) const;
	
	void setRay(const Ray& ray);
	Ray getRay(void) const;
	
	void setDepth(unsigned int depth);
	unsigned int getDepth(void) const;
	
	void setT(float t);
	float getT(void) const;
	
	void setWorld(const World& world);
	const World& getWorld(void) const;
	
private:
	bool hit;
	Material *material;
	vec3f hitPoint;
	vec3f texHitPoint;
	vec3f normal;
	Ray ray;
	unsigned int depth;
	float t;
	const World& world;
	
};

#endif // HITDATA_H