#include "local_types.h"

//Mainitain modulo for Fabonacci perodicity
const u_int_64_t MOD=10000000000000000007ULL;

/*
 2D Matrix multiplication: operand_1 = operand_1 * operand_2 
 After multiplication, results gets stored in operand-1   
 Input Parameters:                                        
 Parameter-1     : operand_1 in 2x2 matrix.               
 Parameter-2     : operand_2 in 2x2 matrix.               
 Return          : None.                                            
*/ 
void matrix_multiply(u_int_64_t oper_1[][2], u_int_64_t oper_2[][2]) 
{
	u_int_64_t r_00, r_01, r_10, r_11;
	
	r_00 = (oper_1[0][0] * oper_2[0][0]) + (oper_1[0][1] * oper_2[1][0]);
	r_01 = (oper_1[0][0] * oper_2[0][1]) + (oper_1[0][1] * oper_2[1][1]);
	r_10 = (oper_1[1][0] * oper_2[0][0]) + (oper_1[1][1] * oper_2[1][0]);
	r_11 = (oper_1[1][0] * oper_2[1][0]) + (oper_1[1][1] * oper_2[1][1]);

	//After Matrix multuiplication, operand-1 gets result 
	oper_1[0][0] = r_00 % MOD;
	oper_1[0][1] = r_01 % MOD;
	oper_1[1][0] = r_10 % MOD;
	oper_1[1][1] = r_11 % MOD;
}

/*  
  Binary exponentiation algorithm to calculate x^y.
  Time complexity  : O(log y)  
  Space complexity : O(1). 
  Input Paramaeters:                                                       
  Parameter-1: Base value of Fibonacci is represented in 2D Matrix "fib[]".    
  Parameter-2: Initial value in 2D Matrix . Result gets stored here.                                  
  Parameter-3: Power of 'n' represented by "fib[]^n"
  Retrun     : None
 */
void binary_exponent(u_int_64_t fibo_mat[][2],u_int_64_t res_mat [][2],u_int_32_t n)
{
	while (n > 0) {
		// Check given number is odd or even.
		// If 'n' is odd, multiply fibo with result.
		if (n & 1) {
			matrix_multiply(res_mat, fibo_mat);
		}
		//multiply fibo * fibo
		matrix_multiply(fibo_mat, fibo_mat);
		n = n/2;
	}
}


/*
 	function to generate a fibonacci number of given 'n'.
 	Input Parameters:
 	Parameter-1: Number to generate fibonacci in 32-bit.
 	Return     : Fibonacci number in 64-bit.
 */
u_int_64_t fibonacci(u_int_32_t n) 
{
	u_int_64_t fib =0ULL;
	if (n > 2) {
		// Fibonacci number F(n) = F(n-1) + F(n-2). 
		// Fibo can be represented uing 2x2 matrix form
		u_int_64_t fibo_mat[2][2] = {{1, 1},{1, 0}};
		//Initial value in 2x2 matrix form
		u_int_64_t res_mat[2][2]  = {{1, 0},{0, 1}};
		//Fib[]^n
		binary_exponent(fibo_mat, res_mat, n-1);
		
		fib = fib + res_mat[0][0] % MOD ;
	} else {
		if (n > 1)
			fib = (u_int_64_t) n - 1;
		else
			fib = (u_int_64_t) n;
	}

	return fib;
}

