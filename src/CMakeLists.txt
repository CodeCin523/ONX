set(ONX_SOURCES
    onx.c
)

add_library(onx ${ONX_SOURCES})
add_library(ONX::ONX ALIAS onx)

target_include_directories(onx
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(onx
    PUBLIC
        Vulkan::Vulkan
)