ulimit -s unlimited

export i1=pendulum1.png
export i2=pendulum2.png
export ii=pendulum.png

convert $i1 img1.png
convert $i2 img2.png

./bin/png2img -i img1.png -o img1
./bin/png2img -i img2.png -o img2

rm -f img1.png
rm -f img2.png

./bin/ngl -i1 img1 -i2 img2 -ii img

rm -f img1
rm -f img2

./bin/img2png -i img -o img.png

rm -f img

convert img.png $ii

rm -f img.png
