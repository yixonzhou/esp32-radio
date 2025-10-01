idf_component_register(
        SRC_DIRS "."
        INCLUDE_DIRS "."
        REQUIRES driver iic
)
target_compile_options(${COMPONENT_LIB} PRIVATE -std=gnu23)