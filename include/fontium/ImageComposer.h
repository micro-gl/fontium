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
#include <fontium/FontRendererResult.h>
#include <fontium/LayoutResult.h>
#include <fontium/LayoutConfig.h>

namespace fontium {
    class ImageComposer {
    public:
        ImageComposer() = delete;

        static
        Img *compose(const LayoutResult &data,
                     const LayoutConfig &config,
                     FontRendererResult &rendered) {

            Img *final = new Img(data.width, data.height, 1);
            for (auto &lc : data.placed) {
                const auto symbol = lc.symbol;
                bool contains = rendered.chars.find(symbol) != rendered.chars.end();
                if (!contains) continue;

                const RenderedChar &ren = rendered.chars[symbol];
                int x = lc.x + config.offset_left;
                int y = lc.y + config.offset_top;
                final->copy(*ren.img, x, y);
            }
            return final;
        }

    };
}