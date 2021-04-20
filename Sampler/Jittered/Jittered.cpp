/*
 *  Jittered.cpp
 *  ktRayTracer
 */

#include "Jittered.h"


#pragma mark Jittered

Jittered::Jittered(void) : Sampler() {
	generateSamples();
}

Jittered::Jittered(unsigned int sampleCount) : Sampler(sampleCount, 1) {
	generateSamples();
}

Jittered::~Jittered(void) {
	
}


#pragma mark -
#pragma mark Info

void Jittered::showInfo(void) {
	cout << "*** Jittered Sampler ***" << endl;
	cout << "Number of Samples:  " << sampleCount << endl;
}


#pragma mark -
#pragma mark Samples

void Jittered::generateSamples(void) {
	unsigned int n = (unsigned int)sqrt(sampleCount);
	
	for (unsigned int i = 0; i < setCount; i++) {
		for (unsigned int j = 0; j < n; j++) {
			for (unsigned int k = 0; k < n; k++) {
				vec2f sample ((k + ((float)qrand() / (float)RAND_MAX)) / n, (j + ((float)qrand() / (float)RAND_MAX)) / n);
				samples.push_back(sample);
			}
		}
	}
}