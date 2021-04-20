#ifndef JITTERED_H
#define JITTERED_H
/*
 *  Jittered.h
 *  ktRayTracer
 */

#include "Sampler.h"


class Jittered : public Sampler {

public:
	Jittered(void);
	Jittered(unsigned int sampleCount);
	
	~Jittered(void);
	
	virtual void showInfo(void);
	
private:
	virtual void generateSamples(void);
	
};

#endif // JITTERED_H