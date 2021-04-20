#ifndef PHONG_H
#define PHONG_H
/*
 *  Phong.h
 *  ktRayTracer
 */

#include "Material.h"
#include "Lambert.h"
#include "Glossy.h"


class Phong : public Material {
	
public:
	Phong(void);
	Phong(float ka, float kd, const vec3f& cd, float ks, const vec3f& cs, float ps);
	Phong(float ka, float kd, float rd, float gd, float bd, float ks, float rs, float gs, float bs, float ps);
	
	~Phong(void);
	
	virtual void showInfo(void) const;
	
	void setKa(float ka);
	float getKa(void);
	
	void setKd(float kd);
	float getKd(void);
	
	void setCd(const vec3f& cd);
	void setCd(float r, float g, float b);
	vec3f getCd(void);
	
	void setKs(float ks);
	float getKs(void);
	
	void setPs(float ps);
	float getPs(void);
	
	void setCs(const vec3f& cs);
	void setCs(float r, float g, float b);
	vec3f getCs(void);
	
	virtual vec3f shade(HitData& hd);
	
protected:
	Lambert *ambient;
	Lambert *diffuse;
	Glossy *specular;	
};

#endif // PHONG_H