ulimit -s unlimited

read -p "input image1: " i1
read -p "input image2: " i2
read -p "output image: " ii
read -p "displacement x: " dx
read -p "displacement y: " dy
read -p "coefficient r1: " r1
read -p "coefficient r2: " r2
read -p "coefficient g1: " g1
read -p "coefficient g2: " g2
read -p "coefficient b1: " b1
read -p "coefficient b2: " b2

convert $i1 img1.png
convert $i2 img2.png

./bin/png2img -i img1.png -o img1
./bin/png2img -i img2.png -o img2

rm -f img1.png
rm -f img2.png

./bin/ngl -i1 img1 -i2 img2 -ii img -dx $dx -dy $dy -r1 $r1 -r2 $r2 -g1 $g1 -g2 $g2 -b1 $b1 -b2 $b2

rm -f img1
rm -f img2

./bin/img2png -i img -o img.png

rm -f img

convert img.png $ii

rm -f img.png
