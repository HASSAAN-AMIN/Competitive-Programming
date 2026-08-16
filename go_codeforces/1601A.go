package main

import "fmt"

func gcd( a int , b int)int{
	if b== 0 {
		return a
	}
	return gcd( b ,  a%b)
}
func main(){

    
	var t int

	fmt.Scan(&t)

	// fmt.Println(&t)  this prints the adress 
	//fmt.Println(t)

	for t > 0{
		
		var n int
		fmt.Scan(&n)


		var arr [30]int

		for i := 0 ; i < n ; i++{
			var x int
			fmt.Scan(&x) 

			for b := 0 ; b < 30 ; b++{
				if x&(1<< b) != 0 {
					arr[b]++
				}
			}
		}

		var g int

		for b := 0 ;b < 30 ; b++{
			g = gcd( g ,arr[b])
		}

		for k := 1 ; k<= n ; k++{
			if g%k == 0 {
				fmt.Print( k ) 
				fmt.Print(" ")
			}
		}
		fmt.Println()



		t--
	}


}