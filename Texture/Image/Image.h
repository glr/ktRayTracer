#ifndef IMAGE_H
#define IMAGE_H
/*
 *  Image.h
 *  ktRayTracer
 */

#include <QImage>

#include "Texture.h"


class Mapping;


class Image : public Texture {

public:
	Image(void);
	Image(QImage *image);
	Image(const char *filename, const char *format = 0);
	Image(Mapping *mapping);
	Image(Mapping *mapping, QImage *image);
	Image(Mapping *mapping, const char *filename, const char *format = 0);
	
	~Image(void);
	
	virtual void showInfo(void) const;
	
	void setImage(QImage *image);
	void setImage(const char *filename, const char *format = 0);
	QImage *getImage(void);
	
	void setMapping(Mapping *mapping);
	Mapping *getMapping(void);
	
	virtual vec3f getColor(const HitData& hd) const;
	
private:
	QImage *image;
	Mapping *mapping;
	
};

#endif IMAGE_H