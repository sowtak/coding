func romanToInt(s string) int {
  m:=map[byte]int{'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
  stack:=make([]byte,0)
  stack=append(stack,s[0])

  for i:=1;i<len(s);i++ {
    if i<len(s)-1 {
      if m[s[i]] > m[s[i-1]] {
        ans+=m[s[i]]-m[s[i-1]]*len(stack)
        stack=stack[0:1]
      } else if m[s[i]]==m[s[i-1]] {
        stack=append(
      
    } else {
      if s[i]
    

