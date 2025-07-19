#include <stdio.h>
#include <freertos/FreeRTOS.h>

#include "driver_tea5767_basic.h"

void app_main(void) {
    // 初始化tea5767
    tea5767_basic_init();

    float frequency;

    tea5767_basic_get_frequency(&frequency);
    printf("current frequency: %f", frequency);

    tea5767_basic_search_up();

    tea5767_basic_get_frequency(&frequency);
    printf("current frequency: %f", frequency);


    while (1) {
        printf("hello world 1\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
