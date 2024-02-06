class MyClass:
    def __init__(self):
        self.__value = 'jkbu949qe9v2'

    @property
    def get_value(self):
        return self.__value

    # @get_value.getter
    # def get_value(self):
    #     return self.__value

n = MyClass()
print(n.get_value())
