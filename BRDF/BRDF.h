#ifndef BRDF_H
#define BRDF_H
/*
 *  BRDF.h
 *  ktRayTracer
 */

#include <iostream>
#include <math.h>

#include "vec.h"


class HitData;


using namespace std;
using namespace gutz;


class BRDF {

public:
	BRDF(void);						

	~BRDF(void);
	
	virtual void showInfo(void) const  = 0;
	
	virtual vec3f f(const HitData& hd, const vec3f& wo, const vec3f& wi) const;
	
	virtual vec3f sample_f(const HitData& hd, const vec3f& wo, vec3f& wi) const;

	virtual vec3f rho(const HitData& hd, const vec3f& wo) const;
	
};

#endif // BRDF_H