project(my_lib
        DESCRIPTION "Utility library"
        LANGUAGES CXX
)

set(SRC_DIR src)

add_library(my_lib STATIC ${LIB_SOURCES})

target_sources(${PROJECT_NAME} PRIVATE
        ${SRC_DIR}/clock.cpp
        ${SRC_DIR}/color.cpp
        ${SRC_DIR}/random.cpp
)

target_include_directories(my_lib PRIVATE include)

target_compile_features(my_lib PRIVATE cxx_std_20)
target_compile_options(my_lib PRIVATE ${WARNING_FLAGS})
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)
