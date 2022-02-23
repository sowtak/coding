fun main() {
  val (n,m,a)=readLine()!!.split(' ').map(String::toLong)
  println(((n-1)/a+1)*((m-1)/a+1))
}
