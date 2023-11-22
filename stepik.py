import re

n = int(input())
strings = [input() for _ in range(n)]

for i in range(len(strings)):
    if re.findall(r'.*a.*n.*t.*o.*n', strings[i]):
        print(i+1, end = ' ')