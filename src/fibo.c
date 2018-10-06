#include<stdio.h>

#include "local_types.h"
#include "fibonacci.h"
#include "prime.h"

#define MOD_3(n) (n%3)
#define MOD_5(n) (n%5)

#define BUZZ        0x01
#define FIZZ        0x02
#define FIZZBUZZ    0x03
#define BUZZFIZZ    0x04
#define FABO        0x08

/*
 Function to identify a status of given number 'n'.
 Input Parameter:
 Parameter: Positive integer 'n' is 32-bit 
 Return   : status of give number 'n'
 */
u_int_8_t status_n(u_int_32_t n) 
{
	u_int_8_t stat =0;
	if (0 == n) {
		return FABO;
	}
	
	//For inital value, assign "prime"
	if ((3 == n) || (5 == n))
		return BUZZFIZZ;
	
	//Check MOD 3
	if (0 == MOD_3(n)) {
		stat |= BUZZ;
	}

	//Check MOD 5
	if (0 == MOD_5(n)) {
		stat |= FIZZ;
	}
	
	//Call prime algorithm only when number 'n 
	//is not divisible by '3' or '5'.
	//Time complexity of prime algo is O(sqrt(n)).
	if (stat == 0 && true == is_prime(n)) {
		stat |= BUZZFIZZ;
	} 

	if (stat == 0) {
		stat = FABO;
	}
	
	return stat;
}

/*
 Function to print a FuzzBuzz or fabonacci sequence number
 Input Parmeter:
 Parameter-1: Status of number 'n'.
 Parameter-2: Fabonacci Sequence of number 'n'in 64-bit
 Parameter-3: Positive integer 'n' is 32-bit or F(n)
 Return     : None
 */
void print_result(u_int_8_t stat, u_int_64_t fab_no, u_int_32_t n)
{
	printf("f(%d)   : ",n); 
	if (stat & FABO){
		printf("%llu\n", fab_no);
	} else if (stat & BUZZFIZZ) {
		printf("BuzzFizz\n");
	} else if (FIZZBUZZ == (stat & FIZZBUZZ)) {
		printf("FizzBuzz\n");
	} else if (stat & FIZZ) {
		printf("Fizz\n");
	} else {
		printf("Buzz\n");
	}
}



int main()
{
	u_int_32_t n;
	u_int_64_t fab_no;
	u_int_8_t  ret_status;
	
	printf("Enter a number: ");
	scanf("%u",&n);

	//Generate a FIZZBUZZ and Fabonacci sequence number.
	for (u_int_32_t i = 0; i <= n; i++) {
			//First check a status of 'n'		   
			ret_status =  status_n(i);
			fab_no     = 0ULL;
			//Call Fabonacci algo, only when 'n'
			//is not divisble by 3 or 5 or not a prime number.
			if (ret_status == FABO) {
				//Time complexity is O(log n).
				fab_no = fibonacci(i);
			} 
			//Print a result.
			print_result(ret_status, fab_no, i);
	}	
	
	return 0;
}

