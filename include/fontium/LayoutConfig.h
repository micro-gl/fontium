/*========================================================================================
 Copyright (2021), Tomer Shalev (tomer.shalev@gmail.com, https://github.com/HendrixString).
 All Rights Reserved.
 License is a custom open source semi-permissive license with the following guidelines:
 1. unless otherwise stated, derivative work and usage of this file is permitted and
    should be credited to the project and the author of this project.
 2. Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
========================================================================================*/
#pragma once

#include <fontium/common_types.h>

namespace fontium {

    enum LayoutType {
        box, box_optimal, grid, gridline, line
    };

    struct LayoutConfig {
        static LayoutConfig getDefault() {
            LayoutConfig config;
            config.layout_type=LayoutType::box;
            config.one_pixel_offset=true;
            config.pot_image=false;
            config.size_increment=0;
            config.offset_left=0;
            config.offset_top=0;
            config.offset_right=0;
            config.offset_bottom=0;
            return config;
        }

        static
        LayoutType stringToLayoutTypeEnum(const str & val) {
            if(val=="box")
                return LayoutType::box;
            if(val=="box_optimal")
                return LayoutType::box_optimal;
            if(val=="grid")
                return LayoutType::grid;
            if(val=="gridline")
                return LayoutType::gridline;
            if(val=="line")
                return LayoutType::line;
            return LayoutType::box;
        }

        LayoutType layout_type=LayoutType::box;
        bool one_pixel_offset=true;
        bool pot_image=false;
        int size_increment=0;
        int offset_left=0;
        int offset_top=0;
        int offset_right=0;
        int offset_bottom=0;
    };
}