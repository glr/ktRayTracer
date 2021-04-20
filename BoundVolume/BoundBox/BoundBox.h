#ifndef BOUNDBOX_H
#define BOUNDBOX_H
/*
 *  BoundBox.h
 *  ktRayTracer
 */

#include "BoundVolume.h"
#include "vec.h"


using namespace gutz;


class BoundBox : public BoundVolume {

public:
	BoundBox(void);
	BoundBox(const vec3f& p0, const vec3f& p1);
	BoundBox(float x0, float y0, float z0, float x1, float y1, float z1);
	BoundBox(const BoundBox& b0, const BoundBox& b1);
//	BoundBox(Geometry vector goes here);
	
	~BoundBox(void);
	
	virtual void showInfo(void) const;
	
	virtual bool hit(const Ray& ray) const;
	
	void setP0(const vec3f& p0);
	void setP0(float x, float y, float z);
	vec3f getP0(void);
	
	void setP1(const vec3f& p1);
	void setP1(float x, float y, float z);
	vec3f getP1(void);
	
	vec3f getCenter(void);
	
protected:
	vec3f p0, p1, center;
	static const float kEpsilon;
	
	inline void setCenter(void) {
		center = (p0 + p1) / 2;
	}
};

#endif // BOUNDBOX_H