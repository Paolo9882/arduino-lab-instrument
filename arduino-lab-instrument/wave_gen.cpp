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

	waves[channel].frequency = frequency;
	waves[channel].period = 1 / frequency;
	waves[channel].dutyCycle = dutyCycle;
	waves[channel].type = type;
	waves[channel].active = true;

}