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

#include <ft2build.h>
#include FT_FREETYPE_H

#include <fontium/common_types.h>
#include <fontium/FontRendererResult.h>
#include <fontium/utils.h>

namespace fontium {
    struct FontConfig;

    class FontRenderer {
    public:
        FontRenderer(const bytearray &font, int faceIndex=0);
        ~FontRenderer();

        FontRendererResult render(const FontConfig &config, float scale=1.0f);
        FT_Face face() const { return m_ft_face; }

    private:
        FT_Library m_ft_library;
        FT_Face m_ft_face;

        RenderedChar copy_current_glyph(uint symbol);
        void append_kerning_to_char(RenderedChar &rendered_char, const int32_t *other, int amount);
        void throw_exception(const std::string & what, int code);
    };

}