mkdir -p bin
gcc src/ngl.c src/img.c -o bin/ngl -std=c2x
gcc src/png2.c src/img.c -o bin/png2 -lm -std=c2x
gcc src/2png.c src/img.c -o bin/2png -lm -std=c2x
