#ifndef GEOMETRY_H
#define GEOMETRY_H
/*
 *  Geometry.h
 *  ktRayTracer
 */

#include <iostream>

#include "vec.h"
#include "Ray.h"
#include "HitData.h"
#include "Material.h"
#include "BoundBox.h"


using namespace std;
using namespace gutz;


class Geometry {

public:
	Geometry(void);
	Geometry(Material *material);

	~Geometry(void);
	
	virtual void showInfo(void) const;
	
	virtual bool hit(const Ray& ray, float& tmin, HitData& hd) const = 0;
	virtual bool shadowHit(const Ray& ray, float& tmin) const = 0;
	
	void setMaterial(Material *material);
	Material *getMaterial(void) const;
	
	void setBoundBox(BoundBox bb);
	BoundBox getBoundBox(void) const;
	
protected:
	mutable Material *material;
	BoundBox bb;
};

#endif // GEOMETRY_H