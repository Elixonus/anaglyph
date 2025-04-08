#!/bin/bash
shopt -s expand_aliases
alias gcc="gcc-14"
mkdir -p bin
gcc -c src/image.c -o bin/image.o -std=c23
gcc src/anaglyph.c -o bin/anaglyph bin/image.o -std=c23
