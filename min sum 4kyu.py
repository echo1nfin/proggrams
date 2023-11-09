def solution(a):
	const = len(a)
	i = 1
	n = const
	minn = float('inf')
	if const == 1:
		return a[0]
	while n != 1:
		if a[0] == 1:
			return const
		b, c = a[i], a[i-1]
		while c > 0:
			b, c = c, b%c
		if b < minn:
			minn = b
		i += 1
		n -= 1
	return minn*const
print(solution([6, 9, 21]))