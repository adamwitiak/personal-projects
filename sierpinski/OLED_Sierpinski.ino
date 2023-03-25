/**
 * Adam Witiak
 * Draw Sierpinski triangle via a chaos game.
**/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ITERATIONS 600 // number of points to be drawn

Adafruit_SSD1306 display(128, 64, &Wire, -1);

int x, y;

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Can't find screen.");
    for(;;);
  }

  // Initialize random number generator
  randomSeed(analogRead(0));
    
  delay(2000);
  display.clearDisplay();
  
  display.drawPixel(64, 0, WHITE);
  display.drawPixel(64 - 37, 63, WHITE);
  display.drawPixel(64 + 37, 63, WHITE);
  
  
  // Choose starting point (not uniform, but good enough)
  x = (int) (random(64-37,64+37) + 0.5);
  if (x <= 64) {
    y = (int) (random(-1.7027*x + 108.9730,63) + 0.5);
  }
  else{
    y = (int) (random(1.7027*x - 108.9730,63) + 0.5);
  }

  display.drawPixel(x, y, WHITE);
  display.display(); 

  for(int i = 0; i < ITERATIONS; i++) {
    // Choose a random number between 1 and 3
    int r = (int) (random(0,3) + 0.5);
  
    // Based on r, move halfway to one of the vertices
    // Vertex 1: (64, 0)
    // Vertex 2: (27, 63)
    // Vertex 3: (101, 63)
  
    if (r == 1) {
      x = (int) (0.5 * x + 32);
      y = (int) (0.5 * y);
    }
    else if (r == 2) {
      x = (int) (0.5 * x + 13.5);
      y = (int) (0.5 * y + 31.5);
    }
    else {
      x = (int) (0.5 * x + 50.5);
      y = (int) (0.5 * y + 31.5);
    }
  
    // Display the new point
    display.drawPixel(x, y, WHITE);
    display.display();
  }
      
}

void loop() {
      
}
