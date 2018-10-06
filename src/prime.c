#include "local_types.h"


/* 
 To check given number is prime number or not. 
 Time complexity  : O(sqrt(n))
 Space complexity : O(1)
 Input parameter : Number 'n' in 32-bit 
 Return          : Return "true" if number 'n' is a prime.
                   Return "false" if number 'n' is not a prime.  
 */                  
bool is_prime(u_int_32_t n) 
{
	if (n <= 1)
		return false;
	
	if (n <= 3) 
		return true;
	
	if (((n%2) == 0) || ((n%3) ==0))
		return false;

	
	for (u_int_32_t i = 5; i*i <= n; i=i+6){
		if (n % i == 0 || n % (i+2) == 0) {
			return false;
		}
	}
	return true;
}

