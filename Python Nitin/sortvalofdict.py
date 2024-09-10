dict={'Ravi':[1,2,4,0],'Nita':[2,4,1,6,2]}
sort=dict
print(sort)
for u in dict:
    sort[u]=sorted(dict[u])
print('After Sorting:')
print(sort)