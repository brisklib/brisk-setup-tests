# Minimum supported CMake version is 3.22
cmake_minimum_required(VERSION 3.22)

project(HelloWorldApp)

# Locate Brisk libraries and headers
find_package(Brisk CONFIG REQUIRED)

# Define application metadata
brisk_metadata(
    VENDOR "Brisk"                     # Vendor or company name
    NAME "HelloWorldApp"               # Application name
    DESCRIPTION "Brisk Hello World"    # Short application description
    VERSION "0.1.0"                    # Version number
    COPYRIGHT "© 2025 Brisk"           # Copyright information
    ICON ${CMAKE_SOURCE_DIR}/icon.png  # Path to the icon (PNG)
    APPLE_BUNDLE_ID com.brisklib.helloworld # Apple bundle identifier
)

# Create an executable target 'main' from main.cpp
add_executable(main main.cpp)

# Link necessary Brisk libraries to 'main'
target_link_libraries(main PRIVATE Brisk::Widgets Brisk::Executable)

# Set up the executable 'main' with Brisk icons, metadata, and startup/shutdown code
brisk_setup_executable(main)