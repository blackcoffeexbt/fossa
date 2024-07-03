

#include <SPI.h>
#include <TFT_eSPI.h>


TFT_eSPI tft = TFT_eSPI();



void setup()  
{  
  Serial.begin(115200);
  tft.init();
  tft.setRotation(1);
  tft.invertDisplay(false);
  tft.fillScreen(TFT_BLACK);

tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_PURPLE);
  tft.setTextSize(3);

  tft.setCursor(40, 40);
  tft.println("Please wait while");
  tft.setCursor(40, 100);
  tft.println("your voucher is printed.");

}


void loop() {}