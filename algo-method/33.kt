fun main() {
  var s=readLine()!!.toCharArray()
  val (n,m)=readLine()!!.split(" ").mapNotNull(String::toIntOrNull)
  with(s[n-1]) {
    s[n-1]=s[m-1]
    s[m-1]=this
  }
  print(s)
}
