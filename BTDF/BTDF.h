#ifndef BTDF_H
#define BTDF_H
/*
 *  BTDF.h
 *  ktRayTracer
 */

#include <iostream>
#include <math.h>

#include "vec.h"


class HitData;


using namespace std;
using namespace gutz;


class BTDF {
	
public:
	BTDF(void);						
	
	~BTDF(void);
	
	virtual void showInfo(void) const = 0;
	
	virtual vec3f f(const HitData& hd, const vec3f& wo, const vec3f& wt) const;
	
	virtual vec3f sample_f(const HitData& hd, const vec3f& wo, vec3f& wt) const;
	
	virtual vec3f rho(const HitData& hd, const vec3f& wo) const;
	
	virtual bool tir(const HitData& hd) const = 0;

};

#endif // BTDF_H