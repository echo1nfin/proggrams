import numpy as np
def add_array():
	# a = np.arange(9).reshape(3,3)
	# print(a)
	# a.shape = a.size
	# print(a)
	b = np.arange(8).reshape(2, 4)
	c =  np.arange(13,21).reshape(2,4)
	m = np.hstack([b, c])
	r = np.vstack([b, c])
	print(m, r, sep = '\n')
	n = np.concatenate([b, c], axis = -1)
	# print(n)
	# a = np.r_[b, c]
	# print(a)

def split_array():
	a = np.arange(10)
	# print(np.hsplit(a, 5))
	b = np.arange(20).reshape(5, 4)
	# print(np.hsplit(b, 2))
	c = np.arange(125).reshape(5,5,5)
	print(c)

split_array()