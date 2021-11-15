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

#include <fontium/FontConfig.h>
#include <fontium/bitmap_font.h>
#include <fontium/FontRenderer.h>
#include <fontium/LayoutConfig.h>
#include <fontium/LayoutFactory.h>
#include <fontium/ImageComposer.h>

namespace fontium {

    class Fontium {
    public:
        Fontium()= delete;
        ~Fontium()=delete;

        static
        bitmap_font create(const std::string & name,
                           bytearray & font,
                           FontConfig & font_config,
                           LayoutConfig & layout_config);
    };

}
