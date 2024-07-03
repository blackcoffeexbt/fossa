

#include <SPI.h>
#include <TFT_eSPI.h>
#include "qrcoded.h"

TFT_eSPI tft = TFT_eSPI();

void setup()
{
  Serial.begin(115200);
  tft.init();
  tft.setRotation(1);
  tft.invertDisplay(false);

  tft.fillScreen(TFT_BLACK);

  qrShowCodeLNURL();
}

void qrShowCodeLNURL()
{
  String message = "SCAN ME OR VOUCHER. TAP SCREEN WHEN FINISHED";
  String qrData = "LNURL1DP68GURN8GHJ7MRWVFAGJ";
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(3);
  tft.setTextDatum(MC_DATUM);
  tft.drawString("Please wait while your", tft.width() / 2, tft.height() / 2 - 20);
  tft.drawString("voucher is printed", tft.width() / 2, tft.height() / 2 + 20);
  
  tft.fillScreen(TFT_WHITE);
  qrData.toUpperCase();
  const char *qrDataChar = qrData.c_str();
  QRCode qrcoded;
  uint8_t qrcodeData[qrcode_getBufferSize(20)];
  qrcode_initText(&qrcoded, qrcodeData, 11, 0, qrDataChar);

  for (uint8_t y = 0; y < qrcoded.size; y++)
  {
    for (uint8_t x = 0; x < qrcoded.size; x++)
    {
      if (qrcode_getModule(&qrcoded, x, y))
      {
        tft.fillRect(120 + 4 * x, 20 + 4 * y, 4, 4, TFT_BLACK);
      }
      else
      {
        tft.fillRect(120 + 4 * x, 20 + 4 * y, 4, 4, TFT_WHITE);
      }
    }
  }

  tft.setCursor(40, 290);
  tft.setTextSize(1);
  tft.setTextColor(TFT_BLACK, TFT_WHITE);
  tft.println(message);
}

void loop() {}