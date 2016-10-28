def selection_sort(obj):
    for i in range(0, len(obj)):
        smallest = i
        for k in range(i+1, len(obj)):
            if obj[k] < obj[smallest]:
                smallest = k
        swap(obj, smallest, i)

def swap(obj, smallest, i):
    tmp = obj[smallest]
    obj[smallest] = obj[i]
    obj[i] = tmp
