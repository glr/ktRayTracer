#ifndef CHECKER_H
#define CHECKER_H
/*
 *  Checker.h
 *  ktRayTracer
 */

#include "Texture.h"


class Checker : public Texture {
	
public:
	Checker(void);
	Checker(float size, const vec3f& colorA, const vec3f& colorB);
	Checker(float size, float ra, float ga, float ba, float rb, float gb, float bb);
	
	~Checker(void);
	
	virtual void showInfo(void) const;
	
	virtual vec3f getColor(const HitData& hd) const;
	
private:
	float size;
	vec3f colorA;
	vec3f colorB;
	
};

#endif // CHECKER_H