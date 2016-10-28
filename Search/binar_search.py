def binary_search(obj, item):
    found = False
    start = 0
    last = len(obj) - 1

    while first <= lsat and not found:
        mid = (first + last) / 2
        if obj[mid] == item:
            found = True
        else:
            if item < obj[mid]:
                last = mid - 1
            else: first = mid + 1
    return found
