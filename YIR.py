from sys import set_int_max_str_digits as digits
import random

digits(100_000_000)

def fib(n):
	a, b = 0, 1
	for _ in range(n):
		a, b = b, a+b
	return a

def stringer():
	s = ''
	for _ in range(100):
		s += str(random.randint(0,1))
	return s.count('0')
print(stringer())


# codeforces.com -> зарегаться для задачек
# olymp.itas.pstu.ru -> турнир -> спорт. прогр.
# sp.urfu.ru -> квалы на 1/4 финал
# 89197090793
# hawk321@mail.ru