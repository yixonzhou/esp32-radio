/**
  ******************************************************************************
  * @encoding  utf-8
  * @file      iic.h
  * @author    ZYX
  * @brief     ref: https://docs.espressif.com/projects/esp-idf/zh_CN/v5.4.2/esp32s3/api-reference/peripherals/i2c.html
  ******************************************************************************
  */

#ifndef IIC_H
#define IIC_H

#include <soc/gpio_num.h>
#include <driver/i2c_master.h>

i2c_master_bus_handle_t iic_init_master_bus(i2c_port_t iic_port);

#endif //IIC_H
