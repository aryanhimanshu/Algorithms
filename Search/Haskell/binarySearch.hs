binarySearch :: [Int] -> Int -> Int
binarySearch list element = 
    binarySearch' list 0 (size - 1) element
    where size = length list

binarySearch' :: [Int] -> Int -> Int -> Int -> Int
binarySearch' list left right element
    | right < left = -1
    | (list !! middle) == element = middle
    | (list !! middle) < element = binarySearch' list (middle + 1) right element
    | otherwise = binarySearch' list left (middle - 1) element
    where middle = (left + right) `div` 2