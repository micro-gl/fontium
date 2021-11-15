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

#include <fontium/exporter/BMFExporter.h>

namespace fontium {
    class ExportFactory {
    public:
        ExportFactory() = delete;

        static
        AbstractExporter *create(const str &name) {
            AbstractExporter * exporter = nullptr;
            if (name == "bmf")
                exporter= new BMFExporter();

            if(exporter==nullptr) {
                throw std::runtime_error{"could not find exporter for :: " + name};
            }

            return exporter;
        }
    };
}