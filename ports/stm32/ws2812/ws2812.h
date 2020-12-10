#ifndef MICROPY_INCLUDED_STM32_WS2812_H
#define MICROPY_INCLUDED_STM32_WS2812_H

void ws2812_init(int count);
void ws2812_destroy();

void ws2812_set_led(int led, int r, int g, int b);

void ws2812_display();

#endif
