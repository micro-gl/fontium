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
    struct RenderedChar {
        int32_t symbol=0;
        int offsetX=0, offsetY=0, w=0, h=0, advance=0;
        Img *img= nullptr;
        std::map<int32_t, int> kerning;

        RenderedChar()= default;
        RenderedChar(int32_t symbol, int x, int y, int w, int h, int a, Img *img) :
                symbol(symbol), offsetX(x), offsetY(y), w{w}, h{h}, advance(a), img(img) {}

        ~RenderedChar() = default;
    };

    struct RenderedMetrics {
        int ascender, descender, height;
    };

    struct FontRendererResult {
        std::map<int32_t, RenderedChar> chars;
        RenderedMetrics metrics;
        str family, style;

        void dispose() {
            for (auto & entry : chars) {
                delete entry.second.img;
            }
        }
    };
}