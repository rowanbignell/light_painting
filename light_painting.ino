/*
    ADAPTED FROM 
*/
#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_DotStar.h>

#define DATAPIN  4
#define CLOCKPIN
#define Y   144  // The number of LEDs (pixels) on WS2812B
#define DELAY 250 // 250ms delay between the pause timer pixels
#define FRAME_DELAY 0 //
#define LOOPS 10
Adafruit_DotStar strip(Y, DATAPIN, CLOCKPIN, DOTSTAR_BRG);
int image_num = 0;

void setup() {
    strip.begin();
}

void loop(){
    strip.clear();  // set all pixel colors to 'off'. It only takes effect if pixels.show() is called

    // turn pixels to green one by one with delay between each pixel, as a progress bar between images
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
        strip.setPixelColor(pixel, strip.Color(0, 255, 0));  // it only takes effect if pixels.show() is called
        strip.show();

        delay(DELAY);  // pause between each pixel
    }

    int x = 0; // get x value from image being shown, how many pixels
    strip.clear();  // set all pixel colors to 'off'. It only takes effect if pixels.show() is called

    for(int k = 0; k < LOOPS; k++){
        //Each frame (x)
        for(int i = 0; i < x; i++){
            //Each pixel (y)
            for (int j = 0; j < Y*x*3; j+(x*3)){
                strip.setPixelColor(pixel, strip.Color(0, 255, 0));
            }
            strip.show();                                  
            delay(FRAME_DELAY);
        }
    }
    image_num++;
}