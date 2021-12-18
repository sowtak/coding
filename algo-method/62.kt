fun main(){
	var (l,r)=arrayOf(0,0)
	repeat(readLine()!!.toInt()) {
		if(readLine()!! == "left") l++ else r++
	}
	print(if(l>r) "left" else if(l<r) "right" else "same")
}
