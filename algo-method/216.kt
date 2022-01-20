fun main(){
    val v=readLine()!!.split(" ")[1]
    print(readLine()!!.split(" ").indexOfLast{it==v})
}
