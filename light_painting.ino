/*
    ADAPTED FROM https://arduinogetstarted.com/tutorials/arduino-ws2812b-led-strip
*/

#include <Adafruit_NeoPixel.h>
#include "image_data.h"

#define PIN_WS2812B  4   // Arduino pin that connects to WS2812B
#define Y   144  // The number of LEDs (pixels) on WS2812B
#define DELAY 250 // 250ms delay between the pause timer pixels
#define FRAME_DELAY 0 //
#define LOOPS 10
Adafruit_NeoPixel WS2812B(NUM_PIXELS, PIN_WS2812B, NEO_GRB + NEO_KHZ800);
int image_num = 0;

void setup() {
    WS2812B.begin(); // INITIALIZE WS2812B strip object (REQUIRED)
}

void loop(){
    WS2812B.clear();  // set all pixel colors to 'off'. It only takes effect if pixels.show() is called

    // turn pixels to green one by one with delay between each pixel, as a progress bar between images
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
        WS2812B.setPixelColor(pixel, WS2812B.Color(0, 255, 0));  // it only takes effect if pixels.show() is called
        WS2812B.show();                                           // send the updated pixel colors to the WS2812B hardware.

        delay(DELAY);  // pause between each pixel
    }

    int x = 0; // get x value from image being shown, how many pixels
    WS2812B.clear();  // set all pixel colors to 'off'. It only takes effect if pixels.show() is called

    for(int k = 0; k < LOOPS; k++){
        //Each frame (x)
        for(int i = 0; i < x; i++){
            //Each pixel (y)
            for (int j = 0; j < Y; j++){
                WS2812B.setPixelColor(pixel, WS2812B.Color(0, 255, 0));
            }
            WS2812B.show();                                           // send the updated pixel colors to the WS2812B hardware.
            delay(FRAME_DELAY);
        }
    }

    image_num++;

}