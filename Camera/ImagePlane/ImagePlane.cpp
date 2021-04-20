/*
 *  ImagePlane.cpp
 *  ktRayTracer
 */

#include <iostream>

#include "ImagePlane.h"


using namespace std;


#pragma mark ImagePlane

ImagePlane::ImagePlane(void)
: location(vec3f(0, 1, 0)), width(2), height(2), w(vec3f(1, 0, 0)), h(vec3f(0, 0, 1)), wRes(512), hRes(512) {
	this->w.normalize();
	this->h.normalize();
	
	pixW = width / wRes;
	pixH = height / hRes;
	
	origin = (location - (width / 2) * w - (height / 2) * h);
	initPixelBuffer();
}

ImagePlane::ImagePlane(const vec3f& location, float width, float height, const vec3f& w, const vec3f& h, float wRes, float hRes) 
: location(location), width(width), height(height), w(w), h(h), wRes(wRes), hRes(hRes) {
	this->w.normalize();
	this->h.normalize();
	
	pixW = width / wRes;
	pixH = height / hRes;
	
	origin = (location - (width / 2) * w - (height / 2) * h);
	initPixelBuffer();
}

ImagePlane::~ImagePlane(void) {
	delete [] this->pixelBuffer;
}


#pragma mark -
#pragma mark Info

void ImagePlane::showInfo(void) const {
	cout << "*** Image Plane Info ***" << endl;
	cout << "Centered at:" << location << endl;
	cout << "Origin at:  " << origin << endl;
	cout << "Size:  " << width << " x " << height << endl;
	cout << "Width Direction:  " << w << endl;
	cout << "Height Direction:  " << h << endl;
	cout << "Resolution:  " << wRes << " x " << hRes << endl;
	cout << "Pixel Size:  " << pixW << " x " << pixH << endl;
	cout << endl;
}


#pragma mark -
#pragma mark Location

void ImagePlane::setLocation(const vec3f& location) {
	this->location = location;
}

void ImagePlane::setLocation(float x, float y, float z) {
	this->location = vec3f(x, y, z);
}

vec3f ImagePlane::getLocation(void) const{
	return location;
}


#pragma mark -
#pragma mark Dimensions

void ImagePlane::setWidth(float width) {
	this->width = width;
}


float ImagePlane::getWidth(void) const{
	return width;
}


void ImagePlane::setHeight(float height) {
	this->height = height;
}


float ImagePlane::getHeight(void) const{
 	return height;
}


#pragma mark -
#pragma mark Directions

void ImagePlane::setW(const vec3f& w) {
	this->w = w;
	this->w.normalize();
}

void ImagePlane::setW(float x, float y, float z) {
	w= vec3f(x, y, z);
	w.normalize();
}

vec3f ImagePlane::getW(void) const{
	return w;
}

void ImagePlane::setH(const vec3f& h) {
	this->h = h;
	this->h.normalize();
}

void ImagePlane::setH(float x, float y, float z) {
	h = vec3f(x, y, z);
	h.normalize();
}

vec3f ImagePlane::getH(void) const {
	return h;
}


#pragma mark -
#pragma mark Resolutions

void ImagePlane::setWRes(float wRes) {
	this->wRes = wRes;
}


unsigned int ImagePlane::getWRes(void) const {
	return wRes;
}


void ImagePlane::setHRes(float hRes) {
	this->hRes = hRes;
}


unsigned int ImagePlane::getHRes(void) const {
 	return hRes;
}


#pragma mark -
#pragma mark Pixel Buffer

void ImagePlane::initPixelBuffer(void) {
	unsigned int bufsize = wRes * hRes;
	pixelBuffer = new vec3f[bufsize];
	for (unsigned int i = 0; i < bufsize; i++) {
		pixelBuffer[i] = vec3f(0, 0, 0);
	}
}

vec3f *ImagePlane::getPixelBuffer(void) const {
	return pixelBuffer;
}

void ImagePlane::setPixelColor(int x, int y, const vec3f& color) {
	pixelBuffer[(y * hRes) + x] = color;
}

vec3f ImagePlane::getPixelColor(int x, int y) const {
	return pixelBuffer[(y * hRes) + x];
}


#pragma mark -
#pragma mark Test Image

void ImagePlane::generateTestImage(void) {
	for (unsigned int i = 0; i < wRes; i++) {
		for (unsigned int j = 0; j < hRes; j++) {
			vec3f col(0, 0, 0);
			
			// draw a gray square
			unsigned int border = 0.1 * min(wRes, hRes);
			if (i >= border && i <= wRes - border && j >= border && j <= hRes - border) {
				col += vec3f(0.5, 0.5, 0.5);
			}
			
			// draw red circle centered in the window
			int r = min(wRes, hRes) / 2;
			int h = wRes / 2;
			int k = hRes / 2;
			if (sqrt(((i - h) * (i - h)) + ((j - k) * (j - k))) <= r) {
				col += vec3f(0.78, 0, 0);
			}
			
			// draw smaller green circle
			int r1 = min(wRes, hRes) / 4;
			int h1 = wRes / 4;
			int k1 = hRes / 4;
			if (sqrt(((i - h1) * (i - h1)) + ((j - k1) * (j - k1))) <= r1) {
				col += vec3f(0, 0.39, 0);
			}
			
			setPixelColor(i, j, col);
		}
	}
}