#ifndef BVH_H
#define BVH_H
/*
 *  BVH.h
 *  ktRayTracer
 */

#include <vector>

#include "Geometry.h"
#include "BoundBox.h"

class BVH : public Geometry {
	
public:
	BVH(void);
	BVH(const Geometry **objects, unsigned int size);
	BVH(const Geometry *left, const Geometry *right);
	BVH(const Geometry *left, const Geometry *right, const BoundBox& bb);
	
	~BVH(void);
	
	const Geometry *branch(const Geometry **objects, unsigned int size, unsigned int axis = 0);
	
	virtual void showInfo(void);
	
	virtual bool hit(const Ray& ray, float& tmin, HitData& hd) const;
	virtual bool shadowHit(const Ray& ray, float& tmin) const;
	
	BoundBox getBoundBox(void);
	
protected:
	const Geometry *left;
	const Geometry *right;
	BoundBox bb;
	
	unsigned int part(const Geometry **objects, unsigned int size, float pivot, unsigned int axis);
};

#endif // BVH_H