#include "mgos_arduino_ssd1306.h"
#include "mongoose_logo.h"

#ifdef __cplusplus
extern "C" {
#endif

void ssd1306_splash(Adafruit_SSD1306 *ssd) {
  if (ssd == nullptr) return;
  ssd->clearDisplay();
  ssd->drawXBitmap(0, 0, (uint8_t*)mongoose_logo_bits, mongoose_logo_width, mongoose_logo_height, WHITE);
  ssd->display();
}

#ifdef __cplusplus
}
#endif
