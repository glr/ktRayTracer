#ifndef MATERIAL_H
#define MATERIAL_H
/*
 *  Material.h
 *  ktRayTracer
 */

#include <iostream>

#include "vec.h"


using namespace std;
using namespace gutz;


class HitData;


class Material {
	
public:
	Material(void);
	
	virtual void showInfo(void) const = 0;
	
	virtual vec3f shade(HitData& hd);
	
};

#endif // MATERIAL_H