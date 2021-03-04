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
