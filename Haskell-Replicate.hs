repli :: [a] -> Int -> [a]
repli xs n = foldl (\acc e -> acc ++ repli' e n) [] xs
    where
      repli' _ 0 = []
      repli' x n = x : repli' x (n-1)