#========================================================================================
# Copyright (2021), Tomer Shalev (tomer.shalev@gmail.com, https://github.com/HendrixString).
# All Rights Reserved.
#
# this should help find the fontium headers-only package and define the fontium target that was
# installed on your system and does not include CMakeLists.txt file, so you can easily link to it.
# If successful, the following will happen:
# 1. fontium_FOUND will be defined
# 1. fontium_INCLUDE_DIR will be defined
# 1. fontium_LIBRARY will be defined
# 2. fontium::fontium target will be defined so you can link to it using target_link_libraries(..)
#========================================================================================
include(GNUInstallDirs)
include(FindPackageHandleStandardArgs)

find_path(fontium_INCLUDE_DIR
        NAMES fontium
        HINTS ${CMAKE_INSTALL_INCLUDEDIR}
        PATH_SUFFIXES fontium.h)
find_library(fontium_LIBRARY
        NAMES fontium
        HINTS ${CMAKE_INSTALL_LIBDIR})

find_package_handle_standard_args(fontium DEFAULT_MSG
        fontium_LIBRARY fontium_INCLUDE_DIR)

if(fontium_FOUND)
    message("fontium was found !!!")
else(fontium_FOUND)
    message("fontium was NOT found !!!")
endif(fontium_FOUND)

if(fontium_FOUND AND NOT TARGET fontium::fontium)
    # build the target
    add_library(fontium::fontium STATIC IMPORTED)
    set_target_properties(
            fontium::fontium
            PROPERTIES
            INTERFACE_INCLUDE_DIRECTORIES "${fontium_INCLUDE_DIR}"
            IMPORTED_LOCATION ${fontium_LIBRARY})
endif()