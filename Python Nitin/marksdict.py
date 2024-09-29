result={'Nitin':[100,99],'Anil':[86,96],'Nimesh':[69,87],'Jyoti':[50,87]}
final=result.copy()
total=0
for key,val in result.items():
    total=sum(val)
    final[key]=total
print(final)
high=0
topper=''
for key,val in final.items():
    if(val>high):
        high=val
        topper=key
print("The topper is : %s topper with marks: %d" %(topper,high))