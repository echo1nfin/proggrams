def pattern(func, n):
	'''
	main function with solution
	use for optimized proggram
	'''
	if func is None:
		return n
	match func[1]:
		case 'plus': return n + func[0]
		case 'minus': return n - func[0]
		case 'times': return n * func[0]
		case 'divided_by': return n // func[0]

def zero(func = None):
	return pattern(func, 0)
def one(func = None): 
	return pattern(func, 1)
def two(func = None):
	return pattern(func, 2)
def three(func = None): 
	return pattern(func, 3)
def four(func = None): 
	return pattern(func, 4)
def five(func = None): 
	return pattern(func, 5)
def six(func = None): 
	return pattern(func, 6)
def seven(func = None): 
	return pattern(func, 7)
def eight(func = None): 
	return pattern(func, 8)
def nine(func = None): 
	return pattern(func, 9)

def plus(func): 
	return func, 'plus'
def minus(func): 
	return func, 'minus'
def times(func): 
	return func, 'times'
def divided_by(func): 
	return func, 'divided_by' 

print(nine(divided_by(zero())))