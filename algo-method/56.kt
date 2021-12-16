fun main() {
  val n=readLine()
  readLine()!!.split(" ").mapNotNull(String::toIntOrNull).filter{it%3==0}.forEach{println(it)}
}
