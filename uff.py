def syst(num: int, system: int) -> list[int]:
	system_num = []
	if 1 < system < 11:
		while num > 0:
			system_num = [str(num % system)] + system_num
			num //= system
		return int(''.join(system_num))
	elif system > 10:
		while num > 0:
			system_num = [num % system] + system_num
			num //= system
		return system_num
def mult_num_system(num_1: int, num_2: int, sys_num1: int = 10, sys_num2: int = 10, finaly_sys: int = 10) -> int | list[int]:
	finaly_num = int(str(num_1), sys_num1) * int(str(num_2), sys_num2)
	return syst(finaly_num, finaly_sys)

print(mult_num_system(1001, 111))