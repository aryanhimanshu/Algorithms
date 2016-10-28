def insertion_sort(obj):
    for index in range(1, len(obj)):
        temp = obj[index]
        position = index
        while position > 0 and temp < obj[position - 1]:
            obj[position] = obj[position-1]
            position -= 1
        obj[position] = temp
