#ifndef TEXTURE_H
#define TEXTURE_H
/*
 *  Texture.h
 *  ktRayTracer
 */

#include <iostream>

#include "vec.h"
#include "HitData.h"


using namespace std;
using namespace gutz;


class Texture {
	
public:
	Texture(void);
	
	~Texture(void);
	
	virtual void showInfo(void) const = 0;
	
	virtual vec3f getColor(const HitData& hd) const = 0;
	
};

#endif TEXTURE_H