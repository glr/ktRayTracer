#ifndef FLATMESHTRIANGLE_H
#define FLATMESHTRIANGLE_H
/*
 *  FlatMeshTriangle.h
 *  ktRayTracer
 */

#include "MeshTriangle.h"


class FlatMeshTriangle : public MeshTriangle {
	
public:
	FlatMeshTriangle(void);
	FlatMeshTriangle(GLMmodel *model, unsigned int tIndex);
	FlatMeshTriangle(Material *material);
	FlatMeshTriangle(GLMmodel *model, unsigned int tIndex, Material *material);
	
	~FlatMeshTriangle(void);
	
	virtual bool hit(const Ray& ray, float& tmin, HitData& hd) const;
	
};

#endif // FLATMESHTRIANGLE_H