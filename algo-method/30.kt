fun main()=print(readLine()!!.split(" ").mapNotNull(String::toIntOrNull).reduce{a,b -> if ((a%10)<(b%10)) a else b})
