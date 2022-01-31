// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        3 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 4 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel matrix1 = Adafruit_NeoPixel(4, 3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel matrix2 = Adafruit_NeoPixel(4, 4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel matrix3 = Adafruit_NeoPixel(4, 5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel matrix4 = Adafruit_NeoPixel(4, 6, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  //Serial.begin(9600);

  matrix1.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  matrix2.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  matrix3.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  matrix4.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

  matrix1.setBrightness(255);
  matrix1.setPixelColor(0, matrix1.Color(255, 0, 0));
  matrix1.setPixelColor(1, matrix1.Color(255, 0, 0));
  matrix1.setPixelColor(2, matrix1.Color(255, 0, 0));
  matrix1.setPixelColor(3, matrix1.Color(255, 0, 0));
  matrix1.show();

  matrix2.setBrightness(255);
  matrix2.setPixelColor(0, matrix2.Color(0, 255, 0));
  matrix2.setPixelColor(1, matrix2.Color(0, 255, 0));
  matrix2.setPixelColor(2, matrix2.Color(0, 255, 0));
  matrix2.setPixelColor(3, matrix2.Color(0, 255, 0));
  matrix2.show();

  matrix3.setBrightness(255);
  matrix3.setPixelColor(0, matrix3.Color(0, 0, 255));
  matrix3.setPixelColor(1, matrix3.Color(0, 0, 255));
  matrix3.setPixelColor(2, matrix3.Color(0, 0, 255));
  matrix3.setPixelColor(3, matrix3.Color(0, 0, 255));
  matrix3.show();

  matrix4.setBrightness(255);
  matrix4.setPixelColor(0, matrix4.Color(255, 255, 255));
  matrix4.setPixelColor(1, matrix4.Color(255, 255, 255));
  matrix4.setPixelColor(2, matrix4.Color(255, 255, 255));
  matrix4.setPixelColor(3, matrix4.Color(255, 255, 255));
  matrix4.show();

  delay(2000);

}

int matrix_show = 0;
int matrix_show_old = 1;
int matrix_dim = 0;
int r = 0;
int g = 0;
int b = 0;
int i = 0;
int time = 0;

void loop() {
   // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  matrix_show = random(0,4);

  while (matrix_show == matrix_show_old)
  {
    matrix_show = random(0,4);
  //  Serial.print("Yo BOY");
  }
  

/*   Serial.print("Matrix Show \t");
  Serial.println(matrix_show);
  Serial.print("Matrix Show Old \t");
  Serial.println(matrix_show_old); */
  
  
  r = random(102,204);
  g = random(102,255);
  b = random(0,229);
  time = random(1000,1000);
  i = 0;
 
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    switch (matrix_show)
    {
    case 0:
    while (i<=255)
    {
      matrix1.setBrightness(i);
      matrix1.setPixelColor(0, matrix1.Color(r, g, b));
      matrix1.setPixelColor(1, matrix1.Color(r, g, b));
      matrix1.setPixelColor(2, matrix1.Color(r, g, b));
      matrix1.setPixelColor(3, matrix1.Color(r, g, b));
      matrix1.show();   // Send the updated pixel colors to the hardware.
      i++;
      delay(7);
    }      
      break;
     case 1:
    while (i<=255)
    {
      matrix2.setBrightness(i);
      matrix2.setPixelColor(0, matrix2.Color(r, g, b));
      matrix2.setPixelColor(1, matrix2.Color(r, g, b));
      matrix2.setPixelColor(2, matrix2.Color(r, g, b));
      matrix2.setPixelColor(3, matrix2.Color(r, g, b));
      matrix2.show();   // Send the updated pixel colors to the hardware.
      i++;
      delay(7);
    }
      break;
    case 2:
    while (i<=255)
    {
      matrix3.setBrightness(i);
      matrix3.setPixelColor(0, matrix3.Color(r, g, b));
      matrix3.setPixelColor(1, matrix3.Color(r, g, b));
      matrix3.setPixelColor(2, matrix3.Color(r, g, b));
      matrix3.setPixelColor(3, matrix3.Color(r, g, b));
      matrix3.show();   // Send the updated pixel colors to the hardware.
      i++;
      delay(7);
    }
      break;
    case 3:
    while (i<=255)
    {
      matrix4.setBrightness(i);
      matrix4.setPixelColor(0, matrix4.Color(r, g, b));
      matrix4.setPixelColor(1, matrix4.Color(r, g, b));
      matrix4.setPixelColor(2, matrix4.Color(r, g, b));
      matrix4.setPixelColor(3, matrix4.Color(r, g, b));
      matrix4.show();   // Send the updated pixel colors to the hardware.
      i++;
      delay(7);
    }
      break; 
    default:
      break;
    }
    
  /* for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

  switch (matrix_dim)
  {
  case 0:
    matrix1.setPixelColor(i, matrix1.Color(0, 0, 0));
    matrix1.show();   // Send the updated pixel colors to the hardware.
    break;
  case 1:
    matrix2.setPixelColor(i, matrix1.Color(0, 0, 0));
    matrix2.show();   // Send the updated pixel colors to the hardware.
    break;
  case 2:
    matrix3.setPixelColor(i, matrix1.Color(0, 0, 0));
    matrix3.show();   // Send the updated pixel colors to the hardware.
    break;
  case 3:
    matrix4.setPixelColor(i, matrix1.Color(0, 0, 0));
    matrix4.show();   // Send the updated pixel colors to the hardware.
    break;
  default:
    break;
  }
  } */
  matrix_show_old = matrix_show;
  delay(time);
}