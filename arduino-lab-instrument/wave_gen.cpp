#include "wave_gen.h"

#define PWM_PIN 6

wave waves[MAX_WAVES];

int addNewWave (float frequency, int type, int dutyCycle, int channel) {

	if (channel > MAX_WAVES || channel < 1) 
		return ERR_WRONGCHANNELNUMBER;

	if (frequency > MAX_FREQ) 
		return ERR_HIGHFREQ;

	if (dutyCycle < 0 || dutyCycle > 100) 
		return ERR_DUTYCYCLE;

	if (type < 1 || type > MAX_TYPE)
		return ERR_WAVETYPE;

	waves[channel].frequency = frequency;
	waves[channel].period = 1 / frequency;
	waves[channel].dutyCycle = dutyCycle;
	waves[channel].type = type;
	waves[channel].active = true;

	computeValuesPWM(channel);
	return 0;
}

void computeValuesPWM (int ch) {
	int val;

	// set the number of points that represents a period of the wave
	wave[ch].data.maxIndex = MAX_SAMPLING_FREQUENCY / wave[ch].frequency;

	if (wave[ch].data.maxIndex > MAX_VALUESPERIOD) 
		wave[ch].data.maxIndex = MAX_VALUESPERIOD;

	for (int i = 0; i < wave[ch].data.maxIndex; i++) {

		if (wave[ch].type == TYPE_SINE) {
			val = sin( (float)i/wave[ch].data.maxIndex*TWO_PI )*127 + 127;
		}
		else if (wave[ch].type == TYPE_SQUARE) {
			if (i < wave[ch].dutyCycle*wave[ch].data.maxIndex/100)
				val = 255;
			else
				val = 0;
		}
		/*
		else if (wave[ch].type == TYPE_TRIANGLE) {
			
		}
		*/
		wave[ch].data.values[i] = val;
  }
}

void writePWM () {
	
}