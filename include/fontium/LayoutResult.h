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

namespace fontium {
    struct LayoutChar {
        int32_t symbol;
        int x, y, w, h;

        LayoutChar(int32_t s, int x, int y, int w, int h) :
                symbol(s), x(x), y(y), w(w), h(h) {}

        LayoutChar(int32_t s, int w, int h) :
                symbol(s), x(0), y(0), w(w), h(h) {}

        LayoutChar() : symbol(0), x(0), y(0), w(0), h(0) {}
    };

    struct LayoutResult {
        int width = 0, height = 0;
        std::vector<LayoutChar> placed{};
    };
}