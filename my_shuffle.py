from random import randint

test_list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]


for i in range(len(test_list)):
    random_index_in_list = randint(0, len(test_list) - 1)
    test_list[i], test_list[random_index_in_list] = test_list[random_index_in_list], test_list[i]

print(test_list)