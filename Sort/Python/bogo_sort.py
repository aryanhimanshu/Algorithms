from random import shuffle
def bogo_sort(obj):
    s = False
    while not (lambda a: lambda v: a(a,v)) (lambda s, x: True if (len(x)<=1 or x[0] <= x[1] and s(s,x[1:])) else False)(obj):
        shuffle(obj)
    return obj
