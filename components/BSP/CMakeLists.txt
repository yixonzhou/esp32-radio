set(src_dirs
        IIC
        tea5767/src
        tea5767/interface
        tea5767/example
)

set(include_dirs
        IIC
        tea5767/example
)

set(private_include_dirs
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
        PRIV_INCLUDE_DIRS  ${private_include_dirs}
        REQUIRES ${requires}
)

component_compile_options(-ffast-math -O3 -Wno-error=format=-Wno-format)