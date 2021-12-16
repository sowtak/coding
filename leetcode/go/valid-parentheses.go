func isValid(s string) bool {
  stack:=make([]string,0)
  for i:=0;i<len(s);i++ {
    if s[i]=='(' || s[i]=='{' || s[i]=='[' {
      stack=append(stack, string(s[i]))
    }
    if s[i]==')' {
      if len(stack) != 0 && stack[len(stack)-1]=="(" {
        stack=stack[:len(stack)-1]
      } else {
        return false
      }
    }
    if s[i]=='}' {
      if len(stack) != 0 && stack[len(stack)-1]=="{" {
        stack=stack[:len(stack)-1]
      } else {
        return false
      }
    }
    if s[i]==']' {
      if len(stack) != 0 && stack[len(stack)-1]=="[" {
        stack=stack[:len(stack)-1]
      } else {
        return false
      }
    }
  }

  if len(stack)!=0 {
    for _,v := range stack {
      if v=="(" || v=="{" || v=="[" {
        return false
      }
    }
  }
  return true
}


