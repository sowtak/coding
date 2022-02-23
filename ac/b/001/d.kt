fun main() {
  val st=mutableSetOf<Pair<Int, Int>>()
  repeat(readLine()!!.toInt()) {
    val (s,e)=readLine()!!.split('-').map{it.toInt())}
    st.add(s-s%5 to
