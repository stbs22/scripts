import numpy as np

arr1 = np.array([x for x in range(10)])

arr2 = np.array([9 for x in range(10)])

print("1 -->",arr1)

np.append(arr1,20)

print("2 -->",arr1)