load('api_config.js');
load('api_arduino_ssd1306.js');

Adafruit_SSD1306._spl = ffi('void ssd1306_splash(void *)');
Adafruit_SSD1306._proto.splash = function() { Adafruit_SSD1306._spl(this.ssd); };

let d = Adafruit_SSD1306.create_i2c(Cfg.get('app.ssd1306_reset_pin'), Adafruit_SSD1306.RES_128_64);
d.begin(Adafruit_SSD1306.SWITCHCAPVCC, 0x3C, true);
d.splash();
