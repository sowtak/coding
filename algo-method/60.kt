fun main() {
	val n = readLine()!!.toInt()
	println(readLine()!!.split(" ").mapNotNull(String::toIntOrNull).sum()/n)
}
