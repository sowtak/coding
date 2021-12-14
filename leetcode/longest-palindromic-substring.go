package main

import "fmt"

func main() {
  var s string
  fmt.Scan(&s)
  fmt.Println(longestPalindrome(s))
}

func longestPalindrome(s string) string {
  ans:=""
  if len(s)==1 {
    return s
  } else {
    maxLen:=0
    for i:=0;i<len(s);i++ {
      for j:=i+1;j<len(s);j++ {
        ok := true
        for l,r := i,j;l<r;l,r=l+1,r-1 {
          if s[l]!=s[r] {
            ok=false
            break
          } else {
            continue
          }
        }
        if ok {
          if maxLen < len(s[i:j+1]) {
            maxLen=len(s[i:j+1])
            ans=s[i:j+1]
          }
        } else {
          if ans == "" {
            ans = s[i:i+1]
          }
        }
      }
    }
  }
  return ans
}


