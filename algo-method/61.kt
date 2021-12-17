fun main() {
  val n=readLine()
	println(readLine()!!.split(" ").mapNotNull(String::toIntOrNull).minOrNull())
}
