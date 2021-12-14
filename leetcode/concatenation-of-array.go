func getConcatenation(nums []int) []int {
  ans:=append(nums, nums...)
  return ans
}
