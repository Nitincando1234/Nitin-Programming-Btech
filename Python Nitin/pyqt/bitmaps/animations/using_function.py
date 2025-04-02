class MyClass:

    def __init__(self):
        self._value = None
    
    def getValue(self):
        print("Getting the value", self._value)
        return self._value

    def setValue(self, value):
        print("Setting the value", value)
        self._value = value
    
    value = property(getValue, setValue)

obj = MyClass()
a = obj.value
print(a)
obj.value = "hello"
b = obj.value
print(b)