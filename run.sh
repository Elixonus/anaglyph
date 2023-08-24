ulimit -s unlimited

export i1=pendulum1.png
export i2=pendulum2.png
export ii=pendulum.png

convert $i1 image1.png
convert $i2 image2.png

./bin/png2img -i image1.png -o image1
./bin/png2img -i image2.png -o image2

./bin/ngl -i1 image1 -i2 image2 -ii image -dx -200 -dy 200 -r1 1 -r2 0 -g1 0 -g2 1 -b1 0 -b2 1

./bin/img2png -i image -o image.png

convert image.png $ii
