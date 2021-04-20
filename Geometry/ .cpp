/*
 *  Geometry.cpp
 *  ktRayTracer
 *
 *  Created by Gabriel on 2/27/10.
 *  Copyright 2010 krahSTek, LLC. All rights reserved.
 *
 */

#include "Geometry.h"


#pragma mark Geometry

Geometry::Geometry(void) : material(NULL), bb(BoundBox()) {
	
}

Geometry::Geometry(Material *material) : material(material), bb(BoundBox()) {
	
}

Geometry::~Geometry(void) {
	if (material) {
		delete material;
		material = NULL;
	}
}


#pragma mark -
#pragma mark Info

void Geometry::showInfo(void) const {
	if (material) {
		material->showInfo();
	}
}


#pragma mark -
#pragma mark Material

void Geometry::setMaterial(Material *material) {
	this->material = material;
}

Material *Geometry::getMaterial(void) const {
	return material;
}


#pragma mark -
#pragma mark Bounding Box

void Geometry::setBoundBox(BoundBox bb) {
	this->bb = bb;
}

BoundBox Geometry::getBoundBox(void) const {
	return bb;
}
