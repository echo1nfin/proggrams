import turtle

def print_star(x, y, name):
    turtle.goto(x, y)
    turtle.dot()
    turtle.write(name)

def draw_line(star1, star2):
    turtle.goto(star1.x, star1.y)
    turtle.pendown()
    turtle.goto(star2.x, star2.y)
    turtle.penup()


class Star:

    def __init__(self, x, y) -> None:
        self.x = x
        self.y = y

turtle.penup()
# turtle.tracer(0)

STAR_1 = Star(-70, 200)
STAR_2 = Star(80, 180)
STAR_3 = Star(-40, -20)
STAR_4 = Star(0, 0)
STAR_5 = Star(40, 20)
STAR_6 = Star(-90, -180)
STAR_7 = Star(120, -140)

print_star(STAR_1.x, STAR_1.y, "star1")
print_star(STAR_2.x, STAR_2.y, "star2")
print_star(STAR_3.x, STAR_3.y, "star3")
print_star(STAR_4.x, STAR_4.y, "star4")
print_star(STAR_5.x, STAR_5.y, "star5")
print_star(STAR_6.x, STAR_6.y, "star6")
print_star(STAR_7.x, STAR_7.y, "star7")
draw_line(STAR_1, STAR_3)
draw_line(STAR_2, STAR_5)
draw_line(STAR_3, STAR_4)
draw_line(STAR_4, STAR_5)
draw_line(STAR_6, STAR_3)
draw_line(STAR_5, STAR_7)

turtle.exitonclick()