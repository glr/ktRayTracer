#ifndef SPHERICAL_H
#define SPHERICAL_H
/*
 *  Spherical.h
 *  ktRayTracer
 */

#include "Mapping.h"


class Spherical : public Mapping {
	
public:
	Spherical(void);
	
	~Spherical(void);
	
	virtual void showInfo(void) const;
	
	virtual void getTexelCoords(const vec3f& hitPoint, const int wRes, const int hRes, int &x, int& y) const;
	
};

#endif // SPHERICAL_H