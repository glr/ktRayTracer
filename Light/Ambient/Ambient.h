#ifndef AMBIENT_H
#define AMBIENT_H
/*
 *  Ambient.h
 *  ktRayTracer
 */

#include "Light.h"

class Ambient: public Light {
	
public:
	Ambient(void);
	Ambient(float ls, const vec3f&color);
	Ambient(float ls, float r, float g, float b);
	
	~Ambient(void);
	
	virtual void showInfo(void) const;
	
	void setColor(const vec3f& color);
	void setColor(const float r, const float g, const float b);
	vec3f getColor(void);
	
	virtual vec3f getDirection(HitData& hd);
	
	virtual bool shadow(const Ray& ray, const HitData& hd) const;

	void setLs(const float ls);
	float getLs(void) const;
		
	virtual vec3f L(HitData& hd);
	
private:
	float ls;
	vec3f color;
	
};

#endif // AMBIENT_H