fun main()=print(if(0==readLine()!!.split(" ").mapNotNull(String::toIntOrNull).reduce{a,b->a%b}) "Yes" else "No")
