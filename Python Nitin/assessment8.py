my_dict = {"a": 3, "b": 2, "c": 1, "d":4}
print(len(my_dict))
del my_dict["a"]
print(my_dict)
print(my_dict.get("b"))
my_dict.remove("b")