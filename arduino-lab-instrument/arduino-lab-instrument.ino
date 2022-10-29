#include <math.h>
#include "timing.h"
#include "wave_gen.h"
#include "error.h"

#define PWM_PIN 6

float frequency = 50;

void setup() {
  // put your setup code here, to run once:
  pinMode(PWM_PIN, OUTPUT);
  Serial.begin(115200);
  setup_timer(frequency);
  delay(500);
}

void loop() {
  float period = 1 / frequency;
  int val;
  
  for (int i = 0; i < 100; i++) {
    val = sin( (float)i/100*TWO_PI )*127 + 127;
    Serial.println(val);
    analogWrite(PWM_PIN, val);
    delay((int)period*1000/100);
  }

}
