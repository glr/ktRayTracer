#ifndef REFLECTIVE_H
#define REFLECTIVE_H
/*
 *  Reflective.h
 *  ktRayTracer
 */

#include "Phong.h"
#include "PerfectSpecular.h"

class Reflective : public Phong {

public:
	Reflective(void);
	Reflective(float ka, float kd, const vec3f& cd, float ks, const vec3f& cs, float ps, float kr, const vec3f& cr);
	Reflective(float ka, float kd, float rd, float gd, float bd, float ks, float rs, float gs, float bs, float ps, 
			   float kr, float rr, float gr, float br);
	
	~Reflective(void);
	
	virtual void showInfo(void) const;
	
	void setKr(float kr);
	float getKr(void);
	
	void setCr(const vec3f& cr);
	void setCr(float r, float g, float b);
	vec3f getCr(void);
	
	virtual vec3f shade(HitData& hd);
	
private:
	PerfectSpecular *reflection;
	
};

#endif // REFLECTIVE_H