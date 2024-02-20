import os
import random
import keyboard


def waiter():
    keyboard.wait('space')
    return True

def check_colors(t, b):
    if t == b:
        return True
    if (b == 1 or b == 9) and (t == 1 or t == 9):
        return True
    return False

while waiter():
    text_color = random.randint(0, 9)
    bg_color = random.randint(0, 9)
    symbols = ['!', '@', '#', '$', '%', '&', '~', '{', '}', '[', ']', '|']
    while check_colors(text_color, bg_color):
        text_color = random.randint(0, 9)
    print(''.join(random.choice(symbols) for _ in range(10000)))
    os.system(f'color {str(text_color)}{str(bg_color)}')
    # os.system("cls")

# recorded_events = keyboard.record("esc")
# for i in range(len(recorded_events)):
#     if recorded_events[i].name == 'space':
#         recorded_events[i].name = ' '
# text = [recorded_events[i].name
#         for i in range(len(recorded_events)) 
#         if i%2==0 and len(recorded_events[i].name) == 1]
# for i in text:
#     print(i, end = '')
# keyboard.play(recorded_events, 10000)