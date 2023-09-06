

#ifndef TCTi_SPI_HELPER_ESP32_H__
#define TCTi_SPI_HELPER_ESP32_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include <driver/spi_master.h>
#include <esp_timer.h>
#include <esp_rom_gpio.h>

#include "tss2_tcti_spi_helper.h"


//TSS2_TCTI_SPI_HELPER_PLATFORM create_tcti_spi_helper_platform(spi_device_handle_t spi, gpio_num_t cs_pin);
TSS2_TCTI_CONTEXT* create_tcti_ctx();

#endif
