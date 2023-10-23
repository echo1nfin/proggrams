from sys import set_int_max_str_digits as digits
from sympy import fibonacci
import random

from time import time

digits(100_000_000)

def fib(n):
	a, b = 0, 1
	for _ in range(n):
		a, b = b, a+b
	return a

start = time()
fibonacci(100_000)
end = time()
print((end - start)*1000)




# к след занятию придумать тему и спланировать работу

# разработать тему реферата

# хакеры как феномен информационного пространства
# компьютерные игры за и против(minecraft)
# Сравнение компиляторов python

# codeforces.com -> зарегаться для задачек
# olymp.itas.pstu.ru -> турнир -> спорт. прогр.
# sp.urfu.ru -> квалы на 1/4 финал
# 89197090793
# hawk321@mail.ru