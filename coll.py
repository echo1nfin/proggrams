def lister(lst: list) -> list:
    if len(lst) > 3:
        lst = lst[-3:]
    return lst
a = [1,2,3,4,5]
print(lister(a))
