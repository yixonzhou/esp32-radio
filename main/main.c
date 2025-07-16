#include <stdio.h>
#include <sys/unistd.h>
#include "iic.h"

void app_main(void) {
    while (1) {
        printf("hello world\n");
        sleep(1);
    }
}
