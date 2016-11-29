# Obj is the object we are searching
# Item is the thing we are searching the object for
# Start is the position of the object we wish to start the search of the object on, change start for different position
def linear_search(obj, item, start=0):
    for i in range(start, len(obj)):
        if obj[i] == item:
            return True
    return False
