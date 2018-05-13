#!/bin/bash

/usr/local/opt/gdal2/bin/gdal_translate -projwin 440019.76266582345 6245274.60981234 456389.2577118958 6236462.772180573 -ot Float32 -of AAIGrid /Users/timlinux/Sync/maps.kartoza.com/Swellendam/csg_20m_contour.tiff dem.asc
# Also convert to PNG so we can get the world file and apply it to the output product
/usr/local/opt/gdal2/bin/gdal_translate -projwin 440019.76266582345 6245274.60981234 456389.2577118958 6236462.772180573 -ot Float32 -of PNG /Users/timlinux/Sync/maps.kartoza.com/Swellendam/csg_20m_contour.tiff dem.png
#docker run -ti -v /Users/timlinux/Downloads/PiotrApp2-2/:/piotr -w /piotr frolvlad/alpine-glibc:latest ./run-linux.sh
# Copy the world file to the output product and copy them to the source dir
cp piotr_out/*_rock_hachures.png /Users/timlinux/Sync/maps.kartoza.com/Swellendam/rock_hachures.png
cp dem.png.aux.xml /Users/timlinux/Sync/maps.kartoza.com/Swellendam/rock_hachures.png.aux.xml
/usr/local/opt/gdal2/bin/gdal_translate -ot Float32 -of GTIFF /Users/timlinux/Sync/maps.kartoza.com/Swellendam/rock_hachures.png /Users/timlinux/Sync/maps.kartoza.com/Swellendam/rock_hachures.tif
tar cfz dem.asc.tar.gz dem.asc
