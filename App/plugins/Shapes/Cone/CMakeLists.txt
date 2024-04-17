project(raytracer_cone_shape
        DESCRIPTION "Raytracer Cone Shape plugin"
        LANGUAGES CXX
)

set(SRC_DIR src)

add_library(${PROJECT_NAME} SHARED ${SOURCE})

target_sources(${PROJECT_NAME} PRIVATE
        ${SRC_DIR}/entryPoint.cpp
        ${SRC_DIR}/coneShape.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR} include)
target_link_libraries(${PROJECT_NAME} PRIVATE raytracer_interface)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_compile_options(${PROJECT_NAME} PRIVATE ${WARNING_FLAGS})
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)