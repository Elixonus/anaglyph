#!/bin/bash
read -rep "left eye image filename: " image1
read -rep "right eye image filename: " image2
read -rep "output anaglyph image filename: " image
read -rep "left eye filter, red multiplier: " red1
read -rep "left eye filter, green multiplier: " green1
read -rep "left eye filter, blue multiplier: " blue1
read -rep "right eye filter, red multiplier: " red2
read -rep "right eye filter, green multiplier: " green2
read -rep "right eye filter, blue multiplier: " blue2
mkdir -p tmp
convert "$image1" tmp/image1.png
convert "$image2" tmp/image2.png
./bin/png2image tmp/image1.png tmp/image1
./bin/png2image tmp/image2.png tmp/image2
./bin/anaglyph tmp/anaglyph image1=tmp/image1 image2=tmp/image2 "filter1=<$red1 $green1 $blue1>" "filter2=<$red2 $green2 $blue2>"
./bin/image2png tmp/anaglyph tmp/anaglyph.png
convert tmp/anaglyph.png "$image"
