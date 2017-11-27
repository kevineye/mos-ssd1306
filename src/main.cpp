#include "mgos.h"

#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(16);

static void led_timer_cb(void *arg) {
  bool val = mgos_gpio_toggle(2);
  LOG(LL_INFO, ("%s uptime: %.2lf, RAM: %lu, %lu free", val ? "Tick" : "Tock",
                mgos_uptime(), (unsigned long) mgos_get_heap_size(),
                (unsigned long) mgos_get_free_heap_size()));
  (void) arg;
}

enum mgos_app_init_result mgos_app_init(void) {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.display();

  mgos_gpio_set_mode(2, MGOS_GPIO_MODE_OUTPUT);
  mgos_set_timer(1000, MGOS_TIMER_REPEAT, led_timer_cb, NULL);
  
  return MGOS_APP_INIT_SUCCESS;
}