set(src_dirs
        IIC
        tea5767/src
        tea5767/interface
        tea5767/example
)

set(include_dirs
        IIC
        tea5767/example
        tea5767/src
        tea5767/interface
)

set(requires
        esp_driver_i2c
        driver
)

idf_component_register(
        SRC_DIRS ${src_dirs}
        INCLUDE_DIRS ${include_dirs}
        REQUIRES ${requires}
)

component_compile_options(-ffast-math -O3 -Wno-error=format=-Wno-format)

target_compile_options(${COMPONENT_LIB} PRIVATE -std=gnu23)