#ifndef SAMPLER_H
#define SAMPLER_H
/*
 *  Sampler.h
 *  ktRayTracer
 */

#include <iostream>
#include <vector>

#include <QtGlobal>

#include "vec.h"


using namespace std;
using namespace gutz;


class Sampler {
	
public:
	Sampler(void);
	Sampler(unsigned int sampleCount, unsigned int setCount); 
	
	~Sampler(void);
	
	virtual void showInfo(void) const;
	
	void setSampleCount(unsigned int sampleCount);
	unsigned int getSampleCount(void);
	
	void setSetCount(unsigned int setCount);
	unsigned int getSetCount(void);
	
	virtual void generateSamples(void) = 0;
	
	void shuffleIndices(void);
	
	void shuffleSamples(void);
	
	vec2f nextSample(void);
	
protected:
	unsigned int sampleCount;
	unsigned int setCount;
	vector<vec2f> samples;
	vector<unsigned int> shuffledIndices;
	unsigned long count;
	int jump;
	
};

#endif SAMPLER_H