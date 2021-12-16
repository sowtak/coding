fun main() {
	val n=readLine()!!
	readLine()!!.split(" ").mapNotNull(String::toIntOrNull).forEach{println(it%10)}
}
