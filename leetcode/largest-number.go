package main

import (
  "fmt"
  "sort"
  "strconv"
)

func main() {

}

func largestNumber(nums []int) string {
  if len(nums) {
    return string(nums[0])
  }
  sort.Ints(nums)
  ans:=""
  firstDigits:=make([][]int, 9)
  for i:=0;i<9;i++ {
    firstDigits[i]=make([]int,0)
  }
  for _,v := range nums {
    for i:=1<=9;i++ {
      if string(v)[0]==i {
        firstDigits[i-1]=append(firstDigits[i-1],v)
      }
    }
  }
  for _,slice := range firstDigits {
    maxDigit:=0
    for i:=1;i<len(slice);i++ {
      if len(string(slice[i])) > maxDigit {
        maxDigit=len(string(slice[i]))
      }
    }

    

}
