fun main()=print(readLine()!!.split(" ").mapNotNull(String::toIntOrNull).average().toInt())
