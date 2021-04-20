/*
 *  Image.cpp
 *  ktRayTracer
 */

#include "Image.h"
#include "Spherical.h"

#pragma mark Image

Image::Image(void) : Texture(), image(new QImage(":/Resources/earth.png", "PNG")), mapping(new Spherical()) {
	
}

Image::Image(QImage *image) : Texture(), image(image), mapping(new Spherical()) {
	
}

Image::Image(const char *filename, const char *format) : Texture(), image(new QImage(filename, format)), mapping(new Spherical()) {
	
}

Image::Image(Mapping *mapping) : Texture(), image(new QImage(":/Resources/earth.png", "PNG")), mapping(mapping) {
	
}

Image::Image(Mapping *mapping, QImage *image) : Texture(), image(image), mapping(mapping) {
	
}

Image::Image(Mapping *mapping, const char *filename, const char *format)
: Texture(), image(new QImage(filename, format)), mapping(mapping) {
	
}

Image::~Image(void) {
	
}


#pragma mark -
#pragma mark Info

void Image::showInfo(void) const {
	cout << "*** Image Texture ***" << endl;
	cout << "Size:  " << image->width() << "x" << image->height() << endl;
}


#pragma mark -
#pragma mark Image

void Image::setImage(QImage *image) {
	this->image = image;
}

void Image::setImage(const char *filename, const char *format) {
	image = new QImage(filename, format);
}

QImage *Image::getImage(void) {
	return image;
}


#pragma mark -
#pragma mark Mapping

void Image::setMapping(Mapping *mapping) {
	this->mapping = mapping;
}

Mapping *Image::getMapping(void) {
	return mapping;
}


#pragma mark -
#pragma mark Color

vec3f Image::getColor(const HitData& hd) const {
	
	int x, y;
	
	if (mapping) {
		mapping->getTexelCoords(hd.getNormal(), image->width(), image->height(), x, y);
	} else {
		x = (int)(hd.getTexHitPoint()[0] * (image->width() - 1));
		y = (int)(hd.getTexHitPoint()[1] * (image->height() -1));	
	}
	
	QRgb c = image->pixel(x, image->height() - y);
	
	return vec3f((float)(qRed(c)/255.0), (float)(qGreen(c)/255.0), (float)(qBlue(c)/255.0));
}