def quicksort(array):
    if(len(array)<=1):
        return array
    else:
        pivot=array[len(array)//2]
        left=[x for x in array if x<pivot]
        middle=[x for x in array if x==pivot]
        right=[x for x in array if x>pivot]
        return quicksort(left)+middle+quicksort(right)
x=int(input("Enter the size of the array: "))
print("Enter the elements of the array: ")
array=[]
for i in range(x):
    array.append(int(input()))
print(quicksort(array))
