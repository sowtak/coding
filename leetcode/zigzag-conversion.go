package main

import "fmt"

func main() {
  
}

func convert(s string, numRows int) string {
  if numRows==1 {
    return s
  }
  ans:=make([][]string, numRows)
  for i:=0;i<numRows;i++ {
    ans[i]=make([]string,0)
  }

  mod:=2*numRows-2
  mods:=make([]int,0)
  for i:=0;i<=mod;i+=2 {
    mods=append(mods, i)
  }
  for i:=0;i<len(s);i++ {
    switch

}

