module SpaceAge (Planet(..), ageOn) where

data Planet = Mercury
            | Venus
            | Earth
            | Mars
            | Jupiter
            | Saturn
            | Uranus
            | Neptune

oneYearInSeconds :: Float
oneYearInSeconds = 31557600

ageOn :: Planet -> Float -> Float
ageOn planet seconds = case planet of 
      Mercury -> seconds / oneYearInSeconds / 0.2408467
      Venus -> seconds / oneYearInSeconds / 0.61519726
      Earth -> seconds / oneYearInSeconds / 1.0
      Mars -> seconds / oneYearInSeconds / 1.8808158
      Jupiter -> seconds / oneYearInSeconds / 11.862615
      Saturn -> seconds / oneYearInSeconds / 29.447498
      Uranus -> seconds / oneYearInSeconds / 84.016846
      Neptune -> seconds / oneYearInSeconds / 164.79132

