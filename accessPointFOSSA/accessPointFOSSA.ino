

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
  String qrData = "LNURL1DP68GURN8GHJ7MRWVFAGJ";
  
  tft.fillScreen(TFT_WHITE);
  qrData.toUpperCase();
  const char *qrDataChar = qrData.c_str();
  QRCode qrcoded;
  uint8_t qrcodeData[qrcode_getBufferSize(20)];
  qrcode_initText(&qrcoded, qrcodeData, 11, 0, qrDataChar);

  // calculate start position on screen to get center, use tft.width() and qrcoded.size
  int startX = (tft.width() - qrcoded.size * 3) / 2;
  for (uint8_t y = 0; y < qrcoded.size; y++)
  {
    for (uint8_t x = 0; x < qrcoded.size; x++)
    {
      if (qrcode_getModule(&qrcoded, x, y))
      {
        tft.fillRect(startX + 3 * x, 30 + 3 * y, 4, 4, TFT_BLACK);
      }
      else
      {
        tft.fillRect(startX + 3 * x, 30 + 3 * y, 4, 4, TFT_WHITE);
      }
    }
  }

  tft.setTextSize(2);
  tft.setTextColor(TFT_BLACK, TFT_WHITE);
  tft.drawString("Scan me or your printed voucher", tft.width() / 2, 235);
  tft.drawString("with a Bitcoin Lightning wallet", tft.width() / 2, 260);
  tft.drawString("Tap the screen when finished", tft.width() / 2, 295);
}

void loop() {}