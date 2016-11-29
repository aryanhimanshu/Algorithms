class BubbleSort

   def self.sort(array)
    n = array.length
    loop do
      swapped = false

      (n-1).times do |i|
        if array[i] > array[i+1]
          array[i], array[i+1] = array[i+1], array[i]
          swapped = true
        end
      end

      break if not swapped
    end

    array
  end
end

arr = [12,15,1,2,4,5,6,25,13,78,50,4,16,13,17]
print BubbleSort.sort(arr)
