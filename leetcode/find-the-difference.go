//package main
//
//import "fmt"
//
func findTheDifference(s string, t string) byte {
  m:=make(map[byte]int)
  for i:=0;i<len(s);i++ {
    m[s[i]]--
    m[t[i]]++
  }
  m[t[len(t)-1]]++
    var ans byte
  for k,v := range m {
    if v==1 {
      ans=k
    }
  }
    return ans
}

//func main() {
//  fmt.Println(findTheDifference("abcd","abcde"))
//}

