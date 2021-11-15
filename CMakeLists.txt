cmake_minimum_required(VERSION 3.12)
project("fontium"
        VERSION
        1.0.0
        DESCRIPTION
        "creates bitmap fonts with custom layout algorithms"
        HOMEPAGE_URL
        "https://micro-gl.github.io/docs")
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

message("===============\n${PROJECT_NAME} v${PROJECT_VERSION} project \n===============")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# add freetype v2
add_subdirectory(libs/freetype-2.10.0)

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

add_library(${PROJECT_NAME} STATIC ${SOURCES_LIB})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} freetype)
target_include_directories(
        ${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}_Targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

write_basic_package_version_file("${PROJECT_NAME}ConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion)

configure_package_config_file(
        "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
        "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
        INSTALL_DESTINATION
        ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)
# install cmake config files for targets of this lib, so they can be found more easily
# without a custom find script, but with find_package(fontium CONFIG) command
install(EXPORT ${PROJECT_NAME}_Targets
        FILE ${PROJECT_NAME}Targets.cmake
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

install(FILES
        "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
        "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)
# install include files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# fontium cli target
set(SOURCES_CLI
        cli/utils.cpp
        cli/fontium-cli.cpp
        libs/lodepng/lodepng.cpp)

add_executable(fontium-cli ${SOURCES_CLI})
target_link_libraries(fontium-cli ${PROJECT_NAME})
target_include_directories(fontium-cli
        PRIVATE
        ${PROJECT_SOURCE_DIR}/cli/include
        ${PROJECT_SOURCE_DIR}/libs/lodepng)
set_target_properties(fontium-cli PROPERTIES OUTPUT_NAME "fontium")
add_custom_command(TARGET fontium-cli POST_BUILD COMMAND
        ${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:fontium-cli>/assets)
install(TARGETS fontium-cli RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
