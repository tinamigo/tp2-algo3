from PIL import Image
from PIL import ImageFilter
import numpy as np
import sys

foto = sys.argv[1]

img = Image.open("ImagenesSrc/"+foto+'.jpg')
width, height = img.size


# Convierte a greyscale
img_grey = img.convert('L')
img_grey = img_grey.filter(ImageFilter.GaussianBlur(0.5))
img_grey.save("ImagenesGrey/"+foto+'_grey.png')


# Guardo a txt greyscale values
file = open("ImagenesTxtGray/"+foto+'.txt', "w+")

dims = np.array([width, height])
values = np.asarray(img_grey.getdata(), dtype=np.int).reshape((img_grey.size[1], img_grey.size[0]))

dims.tofile(file, sep=" ")
file.write('\n')
for v in values:
	v.tofile(file, sep=" ")
	file.write('\n')

file.close()
