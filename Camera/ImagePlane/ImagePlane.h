#ifndef IMAGEPLANE_H
#define IMAGEPLANE_H
/*
 *  ImagePlane.h
 *  ktRayTracer
 */

#include "vec.h"


using namespace gutz;


class ImagePlane {

public:
	ImagePlane(void);
	ImagePlane(const vec3f& location, float width, float height, const vec3f& w, const vec3f& h, float wRes, float hRes);
	
	~ImagePlane(void);
	
	void showInfo(void) const;
	
	void setLocation(const vec3f& location);
	void setLocation(float x, float y, float z);
	vec3f getLocation(void) const;
	
	void setWidth(float width);
	float getWidth(void) const;
	void setHeight(float height);
	float getHeight(void) const;
	
	void setW(const vec3f& x_dir);
	void setW(float x, float y, float z);
	vec3f getW(void) const;
	void setH(const vec3f& y_dir);
	void setH(float x, float y, float z);
	vec3f getH(void) const;
	
	void setWRes(float x_pix);
	unsigned int getWRes(void) const;
	void setHRes(float y_pix);
	unsigned int getHRes(void) const;
	
	vec3f *getPixelBuffer(void) const;
	void setPixelColor(int x, int y, const vec3f& color);
	vec3f getPixelColor(int x, int y) const;
	
	inline vec3f getPixelLocation(int x, int y) const {
		return origin + ((x * pixW * w)) + ((y * pixH * h));
	};
	
	inline float getPixelHeight(void) const {
		return pixH;
	}
	inline float getPixelWidth(void) const {
		return pixH;
	}
	
	void generateTestImage(void);
	
private:
	vec3f location;			// center location in world coord
	vec3f origin;			// origin location in world coord
	
	float width;			// unit width
	float height;			// unit height
	
	vec3f w;				// w direction
	vec3f h;				// h direction
	
	unsigned int wRes;		// pixels in w
	unsigned int hRes;		// pixels in h
	
	float pixW;				// pixel width
	float pixH;				// pixel height
	
	void initPixelBuffer(void);
	vec3f *pixelBuffer;	
};

#endif // IMAGEPLANE_H