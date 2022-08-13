module Clock (addDelta, fromHourMin, toString) where

data Clock = Clock { hours :: Int
                    ,minutes :: Int
             }
  deriving (Eq, Show)

fromHourMin :: Int -> Int -> Clock
fromHourMin hour min = Clock ((hour + (min `div` 60) ) `mod` 24) (min `mod` 60)

toString :: Clock -> String
toString (Clock hour minute) =  (hour clock) ++ ":" ++ (minute clock)

addDelta :: Int -> Int -> Clock -> Clock
addDelta hour min (Clock hour2 min2) = fromHourMin (hour + hour2) (min + min2)

main :: IO ()
main = toString $ addDelta 114 514 (Clock 19 19)

