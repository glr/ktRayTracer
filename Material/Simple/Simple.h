#ifndef SIMPLE_H
#define SIMPLE_H
/*
 *  Simple.h
 *  ktRayTracer
 */

#include "Material.h"


class Simple : public Material {
	
public:
	Simple(void);
	Simple(const vec3f& color);
	Simple(float r, float g, float b);

	~Simple(void);
	
	virtual void showInfo(void) const;
	
	void setColor(const vec3f& color);
	void setColor(float r, float g, float b);
	vec3f getColor(void);
	
	virtual vec3f shade(HitData& hd);
	
private:
	vec3f color;
	
};

#endif // SIMPLE_H