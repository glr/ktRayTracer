#ifndef PTEXTURE_H
#define PTEXTURE_H
/*
 *  PTexture.h
 *  ktRayTracer
 */

#include "Material.h"


class Texture;


class PTexture : public Material {
	
public:
	PTexture(Texture *texture);
	
	~PTexture(void);
	
	virtual void showInfo(void) const;
	
	void setTexture(Texture *texture);
	Texture *getTexture(void);
	
	virtual vec3f shade(HitData& hd);
	
private:
	Texture *texture;
	
};

#endif // PTEXTURE_H