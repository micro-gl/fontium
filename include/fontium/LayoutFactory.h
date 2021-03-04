#pragma once

#include <fontium/layouters/boxlayouter.h>
#include <fontium/layouters/boxlayouteroptimized.h>
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