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

#include <codecvt>
#include <locale>

using namespace std;

//#if _MSC_VER >= 1900
//wstring_convert<codecvt_utf8<int32_t>, int32_t> utf32conv;
//    auto utf32 = utf32conv.from_bytes("The quick brown fox jumped over the lazy dog.");
//    // use reinterpret_cast<const char32_t *>(utf32.c_str())
//#else
//std::wstring_convert<codecvt_utf8<char32_t>, char32_t> utf32conv;
//auto utf32 = utf32conv.from_bytes("The quick brown fox jumped over the lazy dog.");
//// use utf32.c_str()
//#endif

std::u32string utf_8_to_32(const std::string & val);