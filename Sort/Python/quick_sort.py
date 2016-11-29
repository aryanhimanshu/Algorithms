from random import randrange
def quicksort (arr):
	less =  []
	equal = []
	more = []
	if len(arr)<=1:
		return arr
	else:
		pivot = arr[randrange(0,len(arr)-1)]
		for i in arr:
			if i<pivot:
				less.append(i)
			elif i>pivot:
				more.append(i)
			else:
				equal.append(i)
		less = quicksort(less)
		more = quicksort(more)
		return less + equal + more

a = [4, 65, 2, -31, 0, 99, 83, 782, 1]
a = quicksort (a)
print a
