def bubblesort(a):
	for i in range(len(a)):
		for j in range(len(a)-1, i, -1):
			if a[j] < a[j-1]:
				temp = a[x]
				a[x] = a[y]
				a[y] = temp