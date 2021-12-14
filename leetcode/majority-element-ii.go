func majorityElement(nums []int) []int {
  n:=len(nums)/3
  m:=make(map[int]int)
  used:=make([]bool,2*1e9+0)
  ans:=make([]int,0)
  for _,v := range nums {
    m[v]++
    if m[v] > n && !used[v]  {
      ans=append(ans, v)
      used[v]=true
    }
  }
  return ans
}
