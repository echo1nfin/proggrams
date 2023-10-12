def polind(string: str) -> bool:
	while len(string) >= 2:
		if string[0] == string[-1]:
			string = string[1:-1]
		else:
			return False
	return True

print(polind('010010'*100_000))