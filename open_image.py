from PIL import Image
from colorit import background, init_colorit


init_colorit()

def medium_color(color_rgb1, color_rgb2):
    red = (color_rgb1[0] + color_rgb2[0])//2
    green = (color_rgb1[1] + color_rgb2[1])//2
    blue = (color_rgb1[2] + color_rgb2[2])//2
    return (red, green, blue)

image_1 = Image.open("image.jpg")
image_1 = image_1.resize((500, 500))

image_2 = Image.open("image2.jpg")
image_2 = image_2.resize((500, 500))

for y in range(image_1.size[1]):
    for x in range(image_1.size[0]):
        print(background("  ", medium_color(image_1.getpixel((x, y)), image_2.getpixel((x, y)))), end = '')
        # if (x + y) % 2 == 0:
        #     print(background("  ", image_1.getpixel((x, y))), end = '')
        # else:
        #     print(background("  ", image_2.getpixel((x, y))), end = '')

    print()