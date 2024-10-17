cmake_minimum_required(VERSION 3.15)
project(App)

set(CMAKE_CXX_STANDARD 17)

# GLOB all source files in the src directory
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp" "${CMAKE_SOURCE_DIR}/src/*.h")

# Add your source files
add_executable(${PROJECT_NAME} ${SOURCES})

# Path to GLFW headers (from the pre-compiled binaries folder)
include_directories(thirdparty/glfw/include)

# Manually link the pre-compiled binary
# For example, if you are using a static library:
if (WIN32)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/thirdparty/glfw/lib/glfw3.lib)
elseif(APPLE)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/thirdparty/glfw/lib/libglfw3.a)
elseif(UNIX)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/thirdparty/glfw/lib/libglfw3.a)
endif()

# Add platform-specific dependencies
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa" "-framework OpenGL" "-framework IOKit" "-framework CoreVideo")
elseif (UNIX)
    target_link_libraries(${PROJECT_NAME} X11 Xrandr Xi Xxf86vm Xinerama Xcursor GL pthread dl)
elseif (WIN32)
    target_link_libraries(${PROJECT_NAME} opengl32)
endif()