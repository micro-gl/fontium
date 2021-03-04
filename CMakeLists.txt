cmake_minimum_required(VERSION 3.12)
project(fontium-project)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# add freetype v2
add_subdirectory(libs/freetype-2.10.0 EXCLUDE_FROM_ALL)

# fontium lib config and target
set(SOURCES_LIB
        src/Fontium.cpp
        src/utils.cpp
        src/FontRenderer.cpp
        src/AbstractLayout.cpp
        src/exporters/BMFExporter.cpp
        src/layouters/boxlayouter.cpp
        src/layouters/boxlayouteroptimized.cpp
        src/layouters/gridlayouter.cpp
        src/layouters/gridlinelayouter.cpp
        src/layouters/linelayouter.cpp
        )

add_library(fontium ${SOURCES_LIB})
target_link_libraries(fontium freetype)
target_include_directories(fontium
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include)
target_include_directories(fontium
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/libs/freetype-2.10.0/include)

# fontium cli target

set(SOURCES_CLI
        cli/utils.cpp
        cli/fontium-cli.cpp
        libs/lodepng/lodepng.cpp)

add_executable(fontium-cli ${SOURCES_CLI})
target_link_libraries(fontium-cli fontium)
target_include_directories(fontium-cli
        PRIVATE
        ${PROJECT_SOURCE_DIR}/cli/include
        ${PROJECT_SOURCE_DIR}/libs/lodepng)

add_custom_command(TARGET fontium-cli POST_BUILD COMMAND
        ${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:fontium-cli>/assets)

# install target

install(TARGETS fontium-cli  RUNTIME DESTINATION "bin")
install(TARGETS fontium  LIBRARY DESTINATION "lib"
                        ARCHIVE DESTINATION "lib")

install(DIRECTORY include/fontium DESTINATION include)
