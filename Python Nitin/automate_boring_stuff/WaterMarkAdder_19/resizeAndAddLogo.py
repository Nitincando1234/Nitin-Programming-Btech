# resizeAndAddLogo.py - resizes all the images and add the logo to the bottom right corner of the image
from PIL import Image
import os

square_fit_size = 300
logo_filename = "catlogo.png"
logoIm = Image.open(logo_filename)
logoWidth, logoHeight = logoIm.size

for file in os.listdir("."):
    if not (file.endswith(".png") or (file.endswith(".jpg"))) or file == logo_filename: continue
    im = Image.open(file)
    width, height = im.size

    if width > square_fit_size and height > square_fit_size:
        if width > height:
            height = int(square_fit_size / width * height)
            width = square_fit_size
        else:
            width = int(square_fit_size / height * width)
            height = square_fit_size
        print("Resizing %s..." % file)
        im = im.resize((width, height))
    print("Adding logo to %s..." % file)
    im.paste(logoIm, (width - logoWidth, height - logoHeight), logoIm)
    im.save("withLogo" + file)

print("Done.")