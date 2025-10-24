
#include <inttypes.h>

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/printk.h>

#include "BTN.h"
#include "LED.h"

#define SLEEP_MS 1

int main(void) {

  if (0 > BTN_init()) {
    return 0;
  }
  if (0 > LED_init()) {
    return 0;
  }

  while(1) {
    k_msleep(SLEEP_MS);
  }
	return 0;
}


int main(void) {
    int ret;

    if (!gpio_is_ready_dt(&button)) {
        return 0;
    }

    ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
    if (0 > ret) {
        return 0;
    }

    ret = gpio_pin_interrupt_configure_dt(&button, GPIO_INT_EDGE_TO_ACTIVE);
    if (0 > ret) {
        return 0;
    }

    gpio_init_callback(&button_isr_data, button_isr, BIT(button.pin));
    gpio_add_callback(button.port, &button_isr_data);

    while(1) {

    }

    return 0;
}