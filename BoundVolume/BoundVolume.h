#ifndef BOUNDVOLUME_H
#define BOUNDVOLUME_H
/*
 *  BoundVolume.h
 *  ktRayTracer
 */

#include <iostream>


using namespace std;


class Ray;


class BoundVolume {
	
public:
	BoundVolume(void);
	
	virtual void showInfo(void) const;
	
	virtual bool hit(const Ray& ray) const = 0;
	
};

#endif // BOUNDVOLUME_H
