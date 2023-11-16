# import sympy as sym
# x = sym.Symbol('x')
# y = sym.Symbol('y')
# print(sym.solveset(2*x**4 + 3*x**3 - 3*x**2 + x + 4, x))
# solution = sym.solve((x + 5 * y - 2, -3 * x + 6 * y - 15), (x, y))
# print(solution[x], solution[y]) # результат (-3, 1) 
# sym.init_printing(use_unicode=True, wrap_line=False)
# x = sym.Symbol('x')
# y = sym.Symbol('y')
# print(sym.Rational(1, 5))
# print(sym.expand(sym.cos(x+y)**2, trig = True))
# print(sym.simplify((x+x+x+x+x)/6 + (y+1)/y))
# print(sym.limit(1/x, x, sym.oo))
# print(sym.diff(sym.cos(x+1/x), x))

# ax^2 + bx + c = 0
def sqr_resolve(text: str) -> tuple[str: int]:
	solutions = {}
	text = [i for i in text.replace('-', '+-').replace('=', '-').replace(' ', '').replace('-+-', '$').split('+') if i != '']
	text[0], text[1] = text[0].replace('x^2', ''), text[1].replace('x', '')
	text[0], text[1] = [text[0], '-1'][text[0] == '-'], [text[1], '-1'][text[1] == '-']
	a = int([1, text[0]][text[0] != ''])
	b = int([1, text[1]][text[1] != ''])
	c = sum(map(int, text[2].replace('$', ' ').replace('-', ' -').strip().split(' ')))
	import sympy as sym
	x = sym.Symbol('x')
	solution = enumerate(list(sym.solveset(a*x**2 + b*x + c, x)), 1)
	solutions = {'x' + str(x): res for x, res in solution}
	return solutions
print(sqr_resolve('-x^2 - x + 2 = 0'))