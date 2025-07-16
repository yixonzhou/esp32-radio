/**
  ******************************************************************************
  * @encoding  utf-8
  * @file      iic.c
  * @author    ZYX
  * @brief     None
  ******************************************************************************
  */

#include "iic.h"

#include <soc/gpio_num.h>
#include <driver/i2c_types.h>
#include <driver/i2c_master.h>

typedef struct IicGpioPort
{
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

i2c_master_bus_handle_t iic_init_master(i2c_port_t iic_port)
{
    i2c_master_bus_config_t bus_config = {
        .i2c_port = iic_port,
        .sda_io_num = IIC_GPIO_PORT[iic_port].sda,
        .scl_io_num = IIC_GPIO_PORT[iic_port].scl,
        .clk_source = I2C_CLK_SRC_XTAL,
        .glitch_ignore_cnt = 7, // 通常为7
        .intr_priority = 3,
        .trans_queue_depth = 0,
        .flags = {
            0,
            0,
        },
    };

    i2c_device_config_t dev_config = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
    };
}
