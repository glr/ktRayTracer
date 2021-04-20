/*
 *  Sampler.cpp
 *  ktRayTracer
 */

#include "Sampler.h"


#pragma mark Sampler

Sampler::Sampler(void) : sampleCount(1), setCount(1) {
	
}

Sampler::Sampler(unsigned int sampleCount, unsigned int setCount) : sampleCount(sampleCount), setCount(setCount) {
	
}

Sampler::~Sampler(void) {
	
}


#pragma mark -
#pragma mark Info

void Sampler::showInfo(void) const {
	cout << "*** Sampler ***" << endl;
	cout << "Number of Samples:  " << sampleCount << endl;
	cout << "Number of Sample Sets:  " << setCount << endl;
}


#pragma mark -
#pragma mark Samples

void Sampler::setSampleCount(unsigned int sampleCount) {
	this->sampleCount = sampleCount;
}

unsigned int Sampler::getSampleCount(void) {
	return sampleCount;
}

void Sampler::setSetCount(unsigned int setCount) {
	this->setCount = setCount;
}

unsigned int Sampler::getSetCount(void) {
	return setCount;
}


void Sampler::shuffleIndices(void) {
	
}

void Sampler::shuffleSamples(void) {
	
}

vec2f Sampler::nextSample(void) {

//	return samples[count ++ % (sampleCount * setCount)];
	
	qsrand(time(NULL));
	if (count % sampleCount == 0) {
		jump = (qrand() % setCount) * sampleCount;
	}
	return samples[jump + count++ % sampleCount];
}