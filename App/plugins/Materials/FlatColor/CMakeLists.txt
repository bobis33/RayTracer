project(material_color
        DESCRIPTION "Raytracer Color Material plugin"
        LANGUAGES CXX
)

set(SRC_DIR src)

add_library(${PROJECT_NAME} SHARED ${SOURCE})

target_sources(${PROJECT_NAME} PRIVATE
        ${SRC_DIR}/entryPoint.cpp
        ${SRC_DIR}/flatColor.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR} include)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_compile_options(${PROJECT_NAME} PRIVATE ${WARNING_FLAGS})
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)