#include "mgos.h"

#include <mgos_arduino_ssd1306.h>

Adafruit_SSD1306* display = mgos_ssd1306_create_i2c(16, Adafruit_SSD1306::RES_128_64);

enum mgos_app_init_result mgos_app_init(void) {
  mgos_ssd1306_begin(display, SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS, true);
  mgos_ssd1306_display(display);

  return MGOS_APP_INIT_SUCCESS;
}
