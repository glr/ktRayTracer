#ifndef MESHTRIANGLE_H
#define MESHTRIANGLE_H
/*
 *  MeshTriangle.h
 *  ktRayTracer
 */

#include "Geometry.h"
#include "glm.h"

class MeshTriangle : public Geometry {

public:
	MeshTriangle(void);
	MeshTriangle(GLMmodel *model, unsigned int tIndex);
	MeshTriangle(Material *material);
	MeshTriangle(GLMmodel *model, unsigned int tIndex, Material *material);
	
	~MeshTriangle(void);
	
	virtual void showInfo(void) const;
	
	virtual bool hit(const Ray& ray, float& tmin, HitData& hd) const = 0;
	virtual bool shadowHit(const Ray& ray, float& tmin) const;
	
	void setModel(GLMmodel *model);
	GLMmodel *getModel(void) const;
	
	void setTIndex(unsigned int tIndex);
	unsigned int getTIndex(void) const;
	
protected:
	GLMmodel *model;
	unsigned int tIndex;
	
	static const float kEpsilon;
	
	void setBoundBox(void);
	
};
#endif // MESHTRIANGLE_H