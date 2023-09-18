ulimit -s unlimited

export i1=image1.png
export i2=image2.png
export ii=image.png

export dx=10
export dy=10

export r1=1
export r2=0

export g1=0
export g2=1

export b1=0
export b2=1

convert $i1 img1.png # magick convert $i1 img1.png
convert $i2 img2.png # magick convert $i2 img2.png

./bin/png2 -pg img1.png -im img1
./bin/png2 -pg img2.png -im img2

rm -f img1.png
rm -f img2.png

./bin/ngl -i1 img1 -i2 img2 -ii img -dx $dx -dy $dy -r1 $r1 -r2 $r2 -g1 $g1 -g2 $g2 -b1 $b1 -b2 $b2

rm -f img1
rm -f img2

./bin/2png -im img -pg img.png

rm -f img

convert img.png $ii # magick convert img.png $ii

rm -f img.png
