#include <sdkconfig.h>
#include <stdio.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>

#include "iic.h"

typedef unsigned short rda5807_reg_t;

i2c_master_bus_handle_t i2c_master_bus_handle;
i2c_master_dev_handle_t i2c_master_dev_handle;

constexpr int rda5807_reg_count = 6;
rda5807_reg_t regs[rda5807_reg_count];


void rda5807_init()
{
    // 初始化i2c总线
    i2c_master_bus_handle = iic_init_master_bus(I2C_NUM_1);
    // 初始化iic设备
    i2c_device_config_t device_config = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = 0x10,
        .scl_speed_hz = 200'000,
        .scl_wait_us = 0,
    };
    auto ret = i2c_master_bus_add_device(i2c_master_bus_handle, &device_config, &i2c_master_dev_handle);
    ESP_ERROR_CHECK(ret);
}

void Test_RDA5807(void)
{
    rda5807_init();
}

void app_main(void)
{
    printf("hello world\n");

    Test_RDA5807();

    while (1)
    {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
