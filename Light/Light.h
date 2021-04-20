#ifndef LIGHT_H
#define LIGHT_H
/*
 *  Light.h
 *  ktRayTracer
 */

#include <iostream>

#include "vec.h"
#include "HitData.h"


using namespace std;
using namespace gutz;


class Light {
	
public:
	
	Light(void);
	
	~Light(void);
	
	virtual void showInfo(void) const = 0;
	
	virtual vec3f getDirection(HitData& hd) = 0;
	
	virtual bool shadow(const Ray& ray, const HitData& hd) const = 0;
	
	virtual vec3f L(HitData& hd) = 0;
};

#endif // LIGHT_H