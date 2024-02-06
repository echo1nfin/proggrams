field = [['·' for _ in range(7)] for _ in range(7)]
field[3][4] = '*'
field[3][5] = '*'
field[4][4] = '*'
field[4][5] = '*'
for row in field:
    for j in row:
        print(f'{j:3}', end = '')
    print()
for i in range(len(field)):
    for j in range(len(field)):
        if field[i][j] == '*':
            symb = field[i][j+1] + field[i+1][j] + field[i-1][j] + field[i][j-1] + field[i+1][j+1] + field[i-1][j+1] + field[i+1][j-1] + field[i-1][j-1]
            if symb.count('*') > 1:
                pass
            else:
                pass
