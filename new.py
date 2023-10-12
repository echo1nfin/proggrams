matrix = [[1,423,2,4,2,1,0,1],[5,6,13,-1,-9,-10,1,2],[7,1,3,4,5,1,9,3],[0,0,2,3,4,5,19,4],[67,61,66,31,10,1,1,5],[1,2,3,4,4,5,6,6],[80,90,100,101,102,0,0,7],[81,93,1350,1081,1402,1,2,7]]
def det(matrix: list[list[int]]) -> int:
	if len(matrix) == 1:
		return matrix[0][0]
	if len(matrix) == 2:
		return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0])
	if len(matrix) == 3:
		return (matrix[0][0]*matrix[1][1]*matrix[2][2] + matrix[0][2]*matrix[1][0]*matrix[2][1] + matrix[2][0]*matrix[0][1]*matrix[1][2] - matrix[0][2]*matrix[1][1]*matrix[2][0] - matrix[0][0]*matrix[2][1]*matrix[1][2] - matrix[2][2]*matrix[0][1]*matrix[1][0])
	list_nums = matrix[0]
	matrix = matrix[1:]
	matrixs = []
	for j in range(len(matrix[0])):
		matr = [matrix[i][:j] + matrix[i][j+1:] for i in range(len(matrix))]
		matrixs.append(matr)
	return sum([list_nums[i] * [1, -1][i%2] * det(matrixs[i]) for i in range(len(list_nums))])
print(det(matrix))