
class Square:
	def __init__(self, side):
		self.__side = side
		self.__p = None

	@property
	def side(self):
		return self.__side
	
	@side.setter
	def side(self, value):
		self.__side = value
		self.__p = None

	@property
	def p(self):
		if self.__p is None:
			self.__p = self.__side * 4
		return self.__p

	def __len__(self):
		return self.__side
	
	def __str__(self):
		return str(self.__side)