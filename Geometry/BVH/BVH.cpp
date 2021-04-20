/*
 *  BVH.cpp
 *  ktRayTracer
 */

#include "BVH.h"


#pragma mark BVH

BVH::BVH(void) : Geometry() {
	
}

BVH::BVH(const Geometry **objects, unsigned int size) {
	
	//  make sure there are no null leaves
	if (size == 1) *this = BVH(objects[0], objects[0]);
	if (size == 2) *this = BVH(objects[0], objects[1]);
	
	// find the midpoint of the bounding box to use as a qsplit pivot
	bb = objects[0]->getBoundBox();
	for (unsigned int i = 1; i < size; i++)
		bb = BoundBox(bb, objects[i]->getBoundBox());
	
	vec3f pivot = bb.getCenter();
	
	// partitions routine
	unsigned int midPoint = part(objects, size, pivot[0], 0);
	
	// create a new boundingVolume
	left = branch(objects, midPoint, 1);
	right = branch(&objects[midPoint], size - midPoint, 1);
}

BVH::BVH(const Geometry *left, const Geometry *right) : left(left), right(right), bb(BoundBox(left->getBoundBox(), right->getBoundBox())) {

}

BVH::BVH(const Geometry *left, const Geometry *right, const BoundBox& bb) : left(left), right(right), bb(bb) {
	
}

BVH::~BVH(void) {
	
}

const Geometry *BVH::branch(const Geometry **objects, unsigned int size, unsigned int axis) {
	
	if (size == 1) return objects[0];
	if (size == 2) return new BVH(objects[0], objects[1]);
	
	// find the midpoint of the bounding box to use as pivot
	BoundBox box = objects[0]->getBoundBox();
	for (unsigned int i = 1; i < size; i++)
		box = BoundBox(box, objects[i]->getBoundBox());
	
	vec3f pivot = box.getCenter();
	
	// now split according to correct axis
	unsigned int midPoint = part(objects, size, pivot[axis], axis);
	
	// create a new boundingVolume
	const Geometry* left  = branch(objects, midPoint, (axis + 1) % 3);
	const Geometry* right = branch(&objects[midPoint], size - midPoint, (axis + 1) % 3);

	return new BVH(left, right, box);
	
}


#pragma mark -
#pragma mark Info

void BVH::showInfo(void) {
	
}


#pragma mark -
#pragma mark Hit

bool BVH::hit(const Ray& ray, float& tmin, HitData& hd) const {
	if (!bb.hit(ray))
		return false;
	
	bool hitLeft = left->hit(ray, tmin, hd);
	bool hitRight = right->hit(ray, tmin, hd);
	
	return (hitLeft || hitRight);
}

bool BVH::shadowHit(const Ray& ray, float& tmin) const {
	if (!bb.hit(ray))
		return false;
	
	return (left->shadowHit(ray, tmin) || right->shadowHit(ray, tmin));
}


#pragma mark -
#pragma mark Bounding Volume

BoundBox BVH::getBoundBox(void) {
	return bb;
}


#pragma mark -
#pragma mark Partitioning

unsigned int BVH::part(const Geometry **objects, unsigned int size, float pivot, unsigned int axis) {

	BoundBox box;
	float centroid;
	unsigned int retval = 0;
	
	for (unsigned int i = 0; i < size; i++)
	{
		box = objects[i]->getBoundBox();
		centroid = ((box.getP0())[axis] + (box.getP1())[axis]) / 2.0;
		if (centroid < pivot)
		{
			const Geometry* temp = objects[i];
			objects[i] = objects[retval];
			objects[retval] = temp;
			retval++;
		}
	}
	if (retval == 0 || retval == size) retval = size / 2;
	
	return retval;
	
}
