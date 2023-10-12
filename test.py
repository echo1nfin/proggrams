from math import factorial
def fac(n):
	mult = 1
	for i in range(2, n+1):
		mult *= i
	return mult

def summ(n):
	if n == 0:
		return 1
	if n == 1:
		return 2
	count = 2
	res = factorial(n)
	while res != 1:
		count += 1/res
		res //= n
		n -= 1
	return count
print(summ(1_000_000))