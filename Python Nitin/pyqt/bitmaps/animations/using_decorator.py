class MyClass:

    def __init__(self):
        self._value = None
    
    @property
    def value(self):
        print("Getting the value: ", self._value)
        return self._value

    @value.setter
    def value(self, value):
        print("Setting the value: ", self._value)
        self._value = value

obj = MyClass()
a = obj.value
print(a)
obj.value = "hello"
b = obj.value
print(b)