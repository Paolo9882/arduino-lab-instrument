#ifndef WVG_H
#define WVG_H

#include <Arduino.h>
#include "error.h"

#define MAX_WAVES 6
#define MAX_FREQ 100000

struct pwm {
	int values[1000];	// contains values from 0 to 255
	int index;				// next index to be analogWritten
	int maxIndex;			// max index to be reached
};

struct wave {
	float frequency;	// Hz
	float period;			// seconds
	int type; 				// 1: sine, 2: square, 3: triangle
	int dutyCycle;		// 0 to 100
	pwm data;					// wave points
	bool active = false;
};


/*	analogWrites of the next value
 *	must be called by temporized function like interrupt
 */
void writePWM ();

/*	add a new wave at the list of waves
 *	if the channel is already used, modify the previous wave on that channel
 */
void addNewWave (float frequency, int type, int dutyCycle, int channel);


#endif