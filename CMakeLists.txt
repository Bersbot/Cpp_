cmake_minimum_required(VERSION 3.28.3 FATAL_ERROR)

# Set project name and version
set(PROJECT_NAME Cpp_)
project(${PROJECT_NAME}.run VERSION 0.1)

# Set C++ standard
#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_EXTENSIONS OFF)
#set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Enable debug symbols by default
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug 
    CACHE STRING 
      "Choose the type of build (Debug or Release)" 
      FORCE
    )
endif()

# Find SFML shared libraries
find_package(SFML 2.5 
  COMPONENTS 
    system window graphics network audio REQUIRED
  )

# Compile executable
add_executable(${PROJECT_NAME} src/main.cpp)

# Set include directory search paths
target_include_directories(${PROJECT_NAME} 
  PRIVATE
  "${PROJECT_BINARY_DIR}"
  )

# Link executable to required SFML libraries
target_link_libraries(${PROJECT_NAME} sfml-graphics)

# Install target
install(TARGETS ${PROJECT_NAME} DESTINATION bin)

