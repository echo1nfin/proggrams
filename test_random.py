import random
import re


def absolute_random(n, m):
    random_number = random.randint(1, 100)
    for i in range(random_number):
        random.seed(i + random.randint(random.randint(-10_000_000,999_999), random.randint(1_000_000, 10_000_000)))
        for _ in range(random.randint(random_number, random_number*2)):
            number = random.randint(random.randint(min(n, 0), max(n, 0)), random.randint(min(1,m), max(1,m)))
    return number

def test(flip):
    hand = ['O', 'P']
    finaly_string = ''
    for _ in range(flip):
        finaly_string += random.choice(hand)
    return finaly_string

# for _ in range(10):
#     flag = False
#     if re.search(r'O{100}', test(1000000)):
#         flag = True

#     if flag:
#         print('Luck')
#         flag = False
