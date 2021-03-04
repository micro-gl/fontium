# Fontium lib & Fontium-CLI

install lib and cli with **CMake**
```bash
$ cd path/to/microgl
$ mkdir cmake-build-release
$ cd cmake-build-release
$ cmake -DCMAKE_BUILD_TYPE=Release ..
$ cmake --build . --target install
```

project contains two components  
- `fontium` is a c++ library, that creates bitmap fonts with custom layout algorithms.  
it also has built-in exporters to other formats as strings so you can embed them.
- `fontium-cli` is a command line interface, that uses `fontium` to also save the  
bitmap fonts as custom export formats so you can embed/use them in your application.  
Under the hood, it uses `freetype 2`  

### supported fonts formats
`TrueType`, `CFF`, `WOFF`, `OpenType`, `SFNT`, `PCF`, `BDF`, `FNT`, `PFR`  
- note, for `BDF`, make sure that file has a new line at the end.

### supported layout formats
`box`, `line`, `box_optimal`, `grid`, `gridline`

### supported export formats for `fontium-cli`
this only applies for the `fontium-cli`  
the generated image is `png` format and the following data formats can be selected  
- **BMF** (Angel-Code's format, which is used in many frameworks)
- **C header file** with code
- many others I found from fontbuilder software and I add when I have time

#### fontium lib
you can use the lib as follows
```c++
#include <fontium/Fontium.h>

using namespace fontium;

// input data
using bytearray = std::vector<unsigned char>;
FontConfig fontConfig = FontConfig::getDefault();
LayoutConfig layoutConfig = LayoutConfig::getDefault();

// here you can load font data into the bytearray from disk or memory
bytearray font{};

// change some config
fontConfig.size= 16;
fontConfig.antialiasing= Antialiasing::Normal;
fontConfig.characters= "abcd,ABCD";
layoutConfig.layout_type=LayoutType::box;

// create the bitmap font, which contains a single channel frame buffer
// and layout data and font data of each glyph
bitmap_font bm_font = Fontium::create(
                                "bitmap font name",
                                font,
                                fontConfig,
                                layoutConfig);

```

to export your `bitmap_font` result into another format, follow
```c++
#include <fontium/Fontium.h>
#include <fontium/ExportFactory.h>

using namespace fontium;
using str = std::string;

bitmap_font bm_font= ...; // created in previous step

// export as BMF ( Angel Code's format xml)
str output_export_type = "bmf";
auto * exporter = ExportFactory::create(output_export_type);
str result = exporter->apply(bm_font);
str data_file_name= "font." + exporter->fileExtension();

// write data file
std::ofstream out(data_file_name);
out << result;
out.close();
std::cout << std::endl << "created data file :: " 
          << data_file_name << std::endl;

// free memory
delete exporter;

```

building can be done with `cmake`
```text
cd fontium
mkdir cmake_build
cd cmake_build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --target fontium
// libfontium.a file should be in your folder

```

you can also add `fontium` as a sub-directory and link it in your
cmake project
```cmake
cmake_minimum_required(VERSION 3.14)
project(your_project)
...
...
add_subdirectory(fontium)
target_link_libraries(${PROJECT_NAME} fontium)

```

#### fontium cli
run `fontium-cli -h` for help and instructions.  
build `fontium-cli` with cmake
```text
cd fontium
mkdir cmake_build
cd cmake_build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --target fontium-cli
cd ../bin
./fontium-cli -h

```

```text
usage:
  fontium <font path> [options]

description:
  fontium creates bitmap fonts with custom export formats for
  TrueType, CFF, WOFF, OpenType, SFNT, PCF, FNT, BDF, PFR fonts

options include:
* FONT options
  -font.size                  size of font in points, default 14
  -font.dpi                   dots per inch, usually { 72, 96, 100, 110, 120, 128 }, default 72
  -font.characters            (string) the characters, by default will use
                                    " !\"#$%&'()*+,-./0123456789:;<=>?@"
                                    "ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`"
                                    "abcdefghijklmnopqrstuvwxyz{|}~"
  -font.antialiasing          { None, Normal, Light, LCDH, LCDV }, default Normal
  -font.hinting               { Disable, Default, ForceFreetypeAuto, DisableFreetypeAuto }, default to Default
  -font.scale_width           percentages, scale horizontally every glyph, default is 100
  -font.scale_height          percentages, scale vertically every glyph, default is 100
  -font.char_spacing          integer, add spacing to each glyph advance in export, default 0
  -font.line_spacing          integer, add height to export's gylph metrics baseline, default 0
  -font.bold                  [0, 10] - boldness, , default 0
  -font.italic                [-20, 20] - italicness,  default 0
  -font.face_index            the face index to load,  default 0

* LAYOUT options
  -layout.type                { box, box_optimal, grid, gridline, line }, default=box
  -layout.one_pixel_offset    ( false | true) if set, adds at least one pixel separation between glyphs, default to true
  -layout.pot_image           ( false | true) if set, create power of 2 image, default false
  -layout.offset_left         integer, sets the left padding, default 0
  -layout.offset_top          integer, sets the top padding, default 0
  -layout.offset_right        integer, sets the right padding, default 0
  -layout.offset_bottom       integer, sets the bottom padding, default 0

* OUTPUT options
  -output.export              { bmf (Angel Code XML) }, default to bmf
  -output.name                name of the export files, default to <font-name>

* misc
  -h                          show help

example:
  fontium minecraft.ttf -font.size 12 -output.export bmf -output.name minecraft

Author:
  Tomer Shalev (tomer.shalev@gmail.com)
```
<img src="assets/glyph.png">
