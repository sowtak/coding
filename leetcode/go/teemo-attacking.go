func findPoisonedDuration(timeSeries []int, duration int) int {
  cnt:=0
  for i:=0;i<len(timeSeries)-1;i++ {
    if timeSeries[i]+duration > timeSeries[i+1] {
      cnt+=timeSeries[i+1]-timeSeries[i]
    } else {
      cnt+=duration
    }
  }
  return cnt+duration
}
