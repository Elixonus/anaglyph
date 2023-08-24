mkdir bin
gcc src/ngl.c src/img.c -o bin/ngl -std=c2x
gcc src/img2png.c src/img.c -o bin/img2png -std=c2x -lm
gcc src/png2img.c src/img.c -o bin/png2img -std=c2x -lm
