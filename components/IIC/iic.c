/**
  ******************************************************************************
  * @encoding  utf-8
  * @file      iic.c
  * @author    ZYX
  * @brief     None
  ******************************************************************************
  */

#include "iic.h"

typedef struct IicGpioPort {
    int sda;
    int scl;
} IicGpioPort;

const IicGpioPort IIC_GPIO_PORT[] = {
    {
        GPIO_NUM_41,
        GPIO_NUM_42,
    },
    {
        GPIO_NUM_5,
        GPIO_NUM_4,
    },
};

i2c_master_bus_handle_t i2c_master_bus_handles[I2C_NUM_MAX];

i2c_master_bus_handle_t iic_init_master_bus(i2c_port_t iic_port) {
    // todo 防止重复初始化
    // 初始化总线
    i2c_master_bus_config_t bus_config = {
        .i2c_port = iic_port,
        .sda_io_num = IIC_GPIO_PORT[iic_port].sda,
        .scl_io_num = IIC_GPIO_PORT[iic_port].scl,
        .clk_source = I2C_CLK_SRC_XTAL,
        .glitch_ignore_cnt = 7, // 通常为7
        .intr_priority = 3,
        .trans_queue_depth = 0,
        .flags.enable_internal_pullup = true,
        .flags.allow_pd = false,
    };

    auto ret = i2c_new_master_bus(&bus_config, &i2c_master_bus_handles[iic_port]);
    ESP_ERROR_CHECK(ret);
    return i2c_master_bus_handles[iic_port];
}
