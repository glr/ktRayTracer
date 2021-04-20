/*
 *  Matte.h
 *  ktRayTracer
 */

#include "Material.h"
#include "Lambert.h"


class Matte : public Material {
	
public:
	Matte(void);
	Matte(float ka, float kd, const vec3f& cd);
	Matte(float ka, float kd, float r, float g, float b);
	
	~Matte(void);
	
	void showInfo(void) const;
	
	void setKa(float ka);
	float getKa(void);
	
	void setKd(float kd);
	float getKd(void);
	
	void setCd(const vec3f& cd);
	void setCd(float r, float g, float b);
	vec3f getCd(void);
	
	virtual vec3f shade(HitData& hd);
	
private:
	Lambert *ambient;
	Lambert *diffuse;
	
};