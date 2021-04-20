/*
 *  PTexture.cpp
 *  ktRayTracer
 */

#include "PTexture.h"
#include "Texture.h"
#include "World.h"

#pragma mark PTexture

PTexture::PTexture(Texture *texture) : Material(), texture(texture) {
	
}

PTexture::~PTexture(void) {
	
}


#pragma mark -
#pragma mark Info

void PTexture::showInfo(void) const {
	cout << "*** Texture Material ***" << endl;
	texture->showInfo();
}


#pragma mark -
#pragma mark Texture

void PTexture::setTexture(Texture *texture) {
	this->texture = texture;
}

Texture *PTexture::getTexture(void) {
	return texture;
}


#pragma mark -
#pragma mark Shade

vec3f PTexture::shade(HitData& hd) {
	World w = hd.getWorld();
	vec3f wo = -(hd.getRay().getDirection());
	
	vec3f L	= vec3f(0, 0, 0);
	
	vector <Light *>l = w.getLights();
	unsigned int numLights = l.size();
	
	for (unsigned int i = 0; i < numLights; i++) {
		vec3f wi = l[i]->getDirection(hd);
		float ndotwi = hd.getNormal().dot(wi);
		
		if (ndotwi > 0.0) {
			bool shadow = false;
			
			Ray sray(hd.getHitPoint(), wi);
			shadow = l[i]->shadow(sray, hd);
			
			if (!shadow) 
				L += texture->getColor(hd) * (l[i]->L(hd)) * ndotwi;
		}
	}
	
	return L;
}