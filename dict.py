test_dict = {
    'a': 1,
    'b': 2,
    'c': 3,
    'd': 4
}

if not test_dict.get('a') is None:
    test_dict['a'] = test_dict.get('a') + 1



print(test_dict)