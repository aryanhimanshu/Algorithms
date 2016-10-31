def bubble_sort(obj):
    for i in range(len(obj)):
        for k in range(len(obj)-1, i, -1):
            if obj[k] < obj[k-1]:
                swap(obj, k, k-1)

def swap(obj, x, y):
    obj[x],obj[y]=obj[y],obj[x]
