fun main() {
  val m=readLine()!!.toInt()
  val VV=when{
    m<100->"00"
    m<=5000-> if(m<1000) "0" +m/100 else m/100
    m<=30000-> m/1000+50
    m<=70000-> (m/1000-30)/5+80
    else -> "89"
  }
  println(VV)
}
