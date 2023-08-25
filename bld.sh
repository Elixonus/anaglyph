mkdir -p bin
cc src/ngl.c src/img.c -o bin/ngl -std=c2x
cc src/img2png.c src/img.c -o bin/img2png -std=c2x -lm
cc src/png2img.c src/img.c -o bin/png2img -std=c2x -lm
