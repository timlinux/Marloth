#!/bin/bash

#/usr/local/opt/gdal2/bin/gdal_translate -projwin 440019.76266582345 6245274.60981234 456389.2577118958 6236462.772180573 -ot Float32 -of AAIGrid /Users/timlinux/Sync/maps.kartoza.com/Swellendam/csg_20m_contour.tiff /Users/timlinux/Downloads/piotr/dem.asc
wine piotr.exe -l 15 -d piotr_out dem.asc
