idf_component_register(
        SRCS "iic.c"
        INCLUDE_DIRS "./"
        REQUIRES driver 
)
target_compile_options(${COMPONENT_LIB} PRIVATE -std=gnu23)