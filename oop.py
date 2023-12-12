class test:
	def __init__(self, value, age):
		self.value = value
		self.age = age

a = test(1000, 10)
a.age = 100
print(getattr(a, 'age'))
