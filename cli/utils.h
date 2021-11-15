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

#include <fstream>
#include <vector>

std::vector<unsigned char> * loadFileAsByteArray(const std::string &file_name);

template <typename I>
std::string intToHexString(I w, size_t hex_len = sizeof(I)<<1) {
    static const char* digits = "0123456789ABCDEF";
    std::string rc(hex_len,'0');
    for (size_t i=0, j=(hex_len-1)*4 ; i<hex_len; ++i,j-=4)
        rc[i] = digits[(w>>j) & 0x0f];
    return "0x"+rc;
}

std::vector<std::string> split(std::string s, std::string delimiter);
void split(std::string s, const std::string& delimiter, std::vector<std::string> & list);
std::string filename(const std::string & path);

template <class T,class U> U* Int2Hex(T lnumber, U* buffer)
{
    const char* ref = "0123456789ABCDEF";
    T hNibbles = (lnumber >> 4);

    unsigned char* b_lNibbles = (unsigned char*)&lnumber;
    unsigned char* b_hNibbles = (unsigned char*)&hNibbles;

    U* pointer = buffer + (sizeof(lnumber) << 1);

    *pointer = 0;
    do {
        *--pointer = ref[(*b_lNibbles++) & 0xF];
        *--pointer = ref[(*b_hNibbles++) & 0xF];
    } while (pointer > buffer);

    return buffer;
}