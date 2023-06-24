def selectionSort(array, size):
	
	for ind in range(size):
		min_index = ind

		for j in range(ind + 1, size):
			# select the minimum element in every iteration
			if array[j] < array[min_index]:
				min_index = j
		# swapping the elements to sort the array
		array[ind], array[min_index]= array[min_index], array[ind]

n=int(input())
arr=[]
arr=list(map(int,input().split()))
# for i in range(0,n):
#      x=int(input())
#      arr.append(x)
# print(arr)

size = len(arr)
selectionSort(arr, size)
print('The array after sorting in Ascending Order by selection sort is:')
print(arr)
