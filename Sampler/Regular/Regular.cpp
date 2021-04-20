/*
 *  Regular.cpp
 *  ktRayTracer
 */

#include "Regular.h"


#pragma mark Regular

Regular::Regular(void) : Sampler() {
	generateSamples();
}

Regular::Regular(unsigned int sampleCount) : Sampler(sampleCount, 1) {
	generateSamples();
}

Regular::~Regular(void) {
	
}


#pragma mark -
#pragma mark Info

void Regular::showInfo(void) {
	cout << "*** Regular Sampler ***" << endl;
	cout << "Number of Samples:  " << sampleCount << endl;
}


#pragma mark -
#pragma mark Samples

void Regular::generateSamples(void) {
	unsigned int n = (unsigned int)sqrt(sampleCount);
	
	for (unsigned int i = 0; i < setCount; i++) {
		for (unsigned int j = 0; j < n; j++) {
			for (unsigned int k = 0; k < n; k++) {
				vec2f sample ((k * 0.5) / n, (j * 0.5) / n);
				samples.push_back(sample);
			}
		}
	}
}