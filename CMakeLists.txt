cmake_minimum_required(VERSION 3.28)

# ---- Project metadata ----
project(
    ONX
    VERSION 0.0.1
    LANGUAGES C
)

message(STATUS "[START] ONX project setup")

# ---- CMake settings ----
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---- Options ----
# option(onx_handlerWindow  "Enable the window handler"  ON)
# option(onx_handlerSetting "Enable the setting handler" ON)
# option(onx_thrSafety      "Enable thread safety"       OFF)

# ---- Optional user hints (Windows-friendly) ----
# Users can pass these on the command line if needed
set(ONX_VULKAN_ROOT "" CACHE PATH "Vulkan SDK root")
# set(ONX_SDL3_ROOT   "" CACHE PATH "SDL3 root")

if(ONX_VULKAN_ROOT)
    list(PREPEND CMAKE_PREFIX_PATH "${ONX_VULKAN_ROOT}")
endif()

# if(ONX_SDL3_ROOT)
#     list(PREPEND CMAKE_PREFIX_PATH "${ONX_SDL3_ROOT}")
# endif()

# ---- Dependencies ----
find_package(Vulkan REQUIRED)
# if(onxrt_handlerWindow)
#     find_package(SDL3 REQUIRED CONFIG)
# endif()

# ---- Configure headers ----
# configure_file(
#     ${CMAKE_CURRENT_SOURCE_DIR}/src/utils_onxrt.h.in
#     ${CMAKE_CURRENT_SOURCE_DIR}/include/onxrt/utils_onxrt.h
# )

# ---- Subprojects ----
if(NOT DEFINED onxl OR onxl)
    message(STATUS "  [START] ONXLibrary setup")
    add_subdirectory(src onxl)
endif()

if(DEFINED onxe AND onxe)
    message(STATUS "  [START] ONXExamples applications setup")
    add_subdirectory(examples onxe)
endif()

if(DEFINED onxt AND onxt)
    message(STATUS "  [START] ONXTests applications setup")
    add_subdirectory(tests onxt)
endif()

message(STATUS "[END] ONX project setup")