#ifndef MAPPING_H
#define MAPPING_H
/*
 *  Mapping.h
 *  ktRayTracer
 */

#include <iostream>

#include "vec.h"


using namespace std;
using namespace gutz;


class Mapping {

public:
	Mapping(void);
	
	~Mapping(void);
	
	virtual void showInfo(void) const = 0;
	
	virtual void getTexelCoords(const vec3f& hitPoint, const int wRes, const int hRes, int& x, int& y) const = 0;
	
};

#endif // MAPPING_H