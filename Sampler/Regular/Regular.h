#ifndef REGULAR_H
#define REGULAR_H
/*
 *  Regular.h
 *  ktRayTracer
 */

#include "Sampler.h"


class Regular : public Sampler {
	
public:
	Regular(void);
	Regular(unsigned int sampleCount);
	
	~Regular(void);
	
	virtual void showInfo(void);
	
private:
	virtual void generateSamples(void);
	
};

#endif // REGULAR_H