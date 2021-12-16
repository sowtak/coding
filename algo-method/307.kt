fun main() {
  val n=readLine()!!.toInt()
  val a=readLine()!!.trim().split(' ').map{it.toInt()}
  val dp=IntArray(n)
  dp[0]=Math.max(0,a[0])

  for (i in 1 until n)
    dp[i]=Math.max(dp[i-1], dp[i-1]+a[i])
  
  println(dp[n-1])
}
