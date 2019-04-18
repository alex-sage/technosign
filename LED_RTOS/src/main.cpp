#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <PololuLedStrip.h>

// define all the tasks
void TaskAnalogRead(void *pvParameters);
void TaskUpdateLEDs(void *pvParameters);

// global variables and constants
#define LED_COUNT 30
PololuLedStrip<12> ledStrip;
rgb_color colors[LED_COUNT];
int analogValue;

void setup() {
  // init global variables
  analogValue = 0;
  
  // Now set up two tasks to run independently.
  xTaskCreate(
    TaskUpdateLEDs
    ,  (const portCHAR *) "UpdateLEDs"   // A name just for humans
    ,  128  // This stack size can be checked and adjusted by reading the Stack Highwater
    ,  NULL
    ,  3  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  NULL );
 
  xTaskCreate(
    TaskAnalogRead
    ,  (const portCHAR *) "AnalogRead"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  NULL );
}

// Converts a color from HSV to RGB.
// h is hue, as a number between 0 and 360.
// s is the saturation, as a number between 0 and 255.
// v is the value, as a number between 0 and 255.
rgb_color hsvToRgb(uint16_t h, uint8_t s, uint8_t v)
{
    uint8_t f = (h % 60) * 255 / 60;
    uint8_t p = (255 - s) * (uint16_t)v / 255;
    uint8_t q = (255 - f * (uint16_t)s / 255) * (uint16_t)v / 255;
    uint8_t t = (255 - (255 - f) * (uint16_t)s / 255) * (uint16_t)v / 255;
    uint8_t r = 0, g = 0, b = 0;
    switch((h / 60) % 6){
        case 0: r = v; g = t; b = p; break;
        case 1: r = q; g = v; b = p; break;
        case 2: r = p; g = v; b = t; break;
        case 3: r = p; g = q; b = v; break;
        case 4: r = t; g = p; b = v; break;
        case 5: r = v; g = p; b = q; break;
    }
    return rgb_color(r, g, b);
}

void loop() {
  // Empty. Things are done in Tasks
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/

void TaskUpdateLEDs(void *pvParameters)  // This is a task.
{
  (void) pvParameters;

  for (;;)
  {
    // Update the colors.
    for(uint16_t i = 0; i < LED_COUNT; i++)
    {
      colors[i] = rgb_color(255, 255, 255); //hsvToRgb((uint32_t)analogValue * 359 / 1023, 255, 255);
    }
  
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    vTaskDelay(10);
  }
}

void TaskAnalogRead(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
 
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
 
  for (;;)
  {
    // read the input on analog pin 0:
    analogValue = analogRead(A0);
    // print out the value you read:
    Serial.println(analogValue);
    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability
  }
}