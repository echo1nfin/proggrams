import turtle
import random

turtle.screensize(10000, 10000)
turtle.bgcolor("black")
turtle.pencolor("red")
turtle.speed(0)
turtle.tracer(0)

colors = ["white", "pink", "red", "blue", "green", "purple", "yellow", "orange"]
values = [True, False]
colors = ["blue", "red"]

turtle.hideturtle()

degree = 60

step = 1.2

# for i in range(180):

#     for j in range(3):

#         turtle.forward(step)
#         turtle.left(degree)


#     turtle.pencolor(random.choice(colors))
#     turtle.left(1)
#     step += 1

for i in range(100_000):

    f = random.choice(values)
    turtle.pencolor(colors[f])

    if f:
        turtle.right(45)
        turtle.forward(step)
    else:
        turtle.left(45)
        turtle.forward(step)


    # turtle.left(1)
    # step += 1

turtle.exitonclick()