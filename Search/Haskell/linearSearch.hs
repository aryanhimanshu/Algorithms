linearSearch :: [Int] -> Int -> Int
linearSearch [] _ = -1
linearSearch (head: tail) element
    | head == element = element
    | otherwise = linearSearch tail element
