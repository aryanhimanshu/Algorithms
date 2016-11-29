
@@arr = [3,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]

class BinarySearch
    def self.binary_search(left, right, x)
        mid = (left+right)/2
        mid = mid.to_i

        return -1 if left > right
        return mid if @@arr[mid] == x

        if x < @@arr[mid]
          binary_search(left, mid-1, x)
        else
          binary_search(mid+1, right,x)
        end
    end

end


result = BinarySearch.binary_search(0,@@arr.size-1,16)

if result == -1
  print "Not found"
else
  print "Found in position: ", result
end
