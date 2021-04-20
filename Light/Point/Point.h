#ifndef POINT_H
#define POINT_H
/*
 *  PointLight.h
 *  ktRayTracer
 */

#include "Light.h"


class Point : public Light {

public:
	Point(void);
	Point(float ls, const vec3f& location, const vec3f& color);
	Point(float ls, float x, float y, float z, const vec3f& color);
	Point(float ls, const vec3f& location, float r, float g, float b);
	Point(float ls, float x, float y, float z, float r, float g, float b);
	
	~Point(void);
	
	virtual void showInfo(void) const;
	
	void setLs(float ls);
	float getLs(void);
	
	void setLocation(const vec3f& location);
	void setLocation(float x, float y, float z);
	vec3f getLocation(void);
	
	void setColor(const vec3f& color);
	void setColor(float r, float g, float b);
	vec3f getColor(void);
	
	virtual vec3f getDirection(HitData& hd);
	
	virtual bool shadow(const Ray& ray, const HitData& hd) const;
	
	virtual vec3f L(HitData& hd);
	
private:
	float ls;
	vec3f location;
  	vec3f color;
	
};

#endif // POINT_H