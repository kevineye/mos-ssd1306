#include "mgos.h"
#include "mgos_arduino_ssd1306.h"

#include "mongoose_logo.h"

Adafruit_SSD1306* display;

enum mgos_app_init_result mgos_app_init(void) {
  display = mgos_ssd1306_create_i2c(mgos_sys_config_get_app_ssd1306_reset_pin(), Adafruit_SSD1306::RES_128_64);
  mgos_ssd1306_begin(display, SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS, true);

  display->clearDisplay();
  display->drawXBitmap(0, 0, (uint8_t*)mongoose_logo_bits, mongoose_logo_width, mongoose_logo_height, WHITE);
  mgos_ssd1306_display(display);

  return MGOS_APP_INIT_SUCCESS;
}
