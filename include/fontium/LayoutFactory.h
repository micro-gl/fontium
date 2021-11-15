#pragma once

#include <fontium/layouters/boxlayouter.h>
#include <fontium/layouters/boxlayouteroptimized.h>
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
#include <fontium/layouters/gridlayouter.h>
#include <fontium/layouters/gridlinelayouter.h>
#include <fontium/layouters/linelayouter.h>

namespace fontium {
    class LayoutFactory {
    public:
        LayoutFactory() = delete;

        static
        AbstractLayout *create(const LayoutConfig &config) {
            switch (config.layout_type) {
                case LayoutType::box:
                    return new BoxLayouter(&config);
                case LayoutType::box_optimal:
                    return new BoxLayouterOptimized(&config);
                case LayoutType::grid:
                    return new GridLayouter(&config);
                case LayoutType::gridline:
                    return new GridLineLayouter(&config);
                case LayoutType::line:
                    return new LineLayouter(&config);
                default:
                    return new BoxLayouter(&config);
            }
        }

    };

}