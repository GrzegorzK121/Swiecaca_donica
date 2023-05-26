#include <FastLED.h>
#define LED_PIN 3
#define NUM_LEDS 13

CRGB leds[NUM_LEDS];

#define SensorPin A0
float sensorValue = 0;
//int startLed=0;

void setup() {
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
    FastLED.clear();
    FastLED.show();
    Serial.begin(9600);
}

void loop() {

    int ledOn = sensorValue / 5;
    static int startLed = 8;
    int ll;
    for (int i = 0; i <= NUM_LEDS; i++) {
        if (sensorValue < 1200) {
            ll = (startLed + i) % NUM_LEDS;
            leds[ll] = CRGB(sensorValue / 3, 13, 75);
            FastLED.setBrightness(100);
            FastLED.show();
            delay(50);
        }
        else {
            leds[i] = CRGB(100, 0, 0);
            FastLED.setBrightness(100);
            FastLED.show();
            delay(50);
        }
    }

    for (int i = 0; i <= NUM_LEDS; i++) {
        if (sensorValue < 1200) {
            leds[i] = CRGB(sensorValue / 20, 115, 100);
            FastLED.setBrightness(100);
            FastLED.show();
            delay(50);
        }
        else {
            leds[i] = CRGB(0, 0, 100);
            FastLED.setBrightness(100);
            FastLED.show();
            delay(50);
        }
    }
    sensorValue = analogRead(SensorPin);
    Serial.println(sensorValue);
    //Serial.println(ledOn);
    startLed = (startLed + 1) % NUM_LEDS;
    //Serial.println(startLed);
    delay(50);

}