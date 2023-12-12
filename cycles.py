from time import time

start = time()
for i in range(10_000_000):
    pass
print(time() - start)

n = 0
start = time()
while n < 10_000_000:
    n += 1
print(time() - start)
