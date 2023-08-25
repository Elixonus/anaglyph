mkdir -p bin
cc src/ngl.c src/img.c -o bin/ngl -std=c2x
cc src/png2.c src/img.c -o bin/png2 -std=c2x -lm
cc src/2png.c src/img.c -o bin/2png -std=c2x -lm
