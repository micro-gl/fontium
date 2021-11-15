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
#include <fontium/LayoutResult.h>

namespace fontium {
    struct LayoutConfig;

    class AbstractLayout {
    private:
        const LayoutConfig *m_config=nullptr;
        LayoutResult m_result{};
        int m_compact_w=0;
        int m_compact_h=0;

        virtual void processing_hook(QVector<LayoutChar> &chars);

    public:
        explicit AbstractLayout(const LayoutConfig *$config);
        virtual ~AbstractLayout()= default;

        LayoutResult &layout(const vector<LayoutChar> &input); //DoPlace

    protected:
        void resize(int w, int h);

        int width() const;

        int height() const;

        void place(const LayoutChar &);

        virtual void internal_layout(const QVector<LayoutChar> &input) = 0;
    };

}