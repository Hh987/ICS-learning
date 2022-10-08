/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
#include "bits.h"

//P1
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(4, 5) = -6, bitNor(-1,-2) = 0
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
	return ~x & ~y;
}

//P2
/* 
 * tmax - return maximum two's complement integer (0x7fffffff)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
	return ~(1 << 31);
}

//P3
/*
 * isTmin - returns 1 if x is the minimum two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +   1000   -->  0000  1001  0111
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {
	return !(x ^ ~(x + (~1 + 1))) & !!(x);
}

//P4
/*
 * minusOne - return a value of -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void){
	return ~0;
}

//P5
/*
 * absVal - return the absolute value of x
 *   Examples: absVal(-10) = 10
 *			   absVal(5) = 5
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int absVal(int x){
  int sign = x >> 31;
  return (x & ~sign) | ((~x + 1) & sign);
}

//P6 
/*
 * leastBitPos - return a mask that marks the position of the least significant 1 bit.
 *   Examples: leastBitPos(12) = 4  1100
 *			       leastBitPos(-2) = 2  
 *             leastBitPos(0)  = 0  0000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 * 
 * 
 *  
 */
int leastBitPos(int x){
	return  (x & (x + ~1 + 1)) ^ x;
}

//P7
/*
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12 34 56 78, 1, 3) = 0x56 34 12 78
 *            byteSwap(0xDE AD BE EF, 0, 2) = 0xDE EF BE AD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 20
 *  Rating: 2
 */
int byteSwap(int x, int n, int m){
  int a = x >> (n << 3) & 0xff; 
	int b = x >> (m << 3) & 0xff;
  x &= ~(0xff << (n << 3)); 
	x |= b << (n << 3); 
	x &= ~(0xff << (m << 3));
	x |= a << (m << 3);
  return x;
}

//P8
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3      1001  0100  0001
 */
int logicalShift(int x, int n) {
  int temp = x >> 31;
  int sign = temp & 1;
  return ((x + (sign << 31)) >> n) + (sign << (31 + (~n) + 1));
}

//P9
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int fx = x >> 31 & 1;
  int fy = y >> 31 & 1;
  int a = y + (~x + 1);
  int flag = (a >> 31) & 1;
  int b = !flag;
  int c = (!fy) & fx;
  return ((b & !(fx ^ fy)) | c);
}

//P10 
/* 
 * multFiveEighths - return floor(x*5/8), for 0 <= x, x is an integer 
 *   Example: multFiveEighths(10) = 6
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multFiveEighths(int x) {
  int l1 = x & 1;
  int l3 = (x & 4) >> 2;
  int of = ((l3 + l1) & 2) >> 1;
  x = (x >> 3) + (x >> 1) + of;
  return x;
}

//P11
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x){
  int temp, res, t1, t2, t3, t4, t5;
  temp = 0x55 | (0x55 << 8);  
  t1 = temp | (temp << 16); 
  temp = 0x33 | (0x33 << 8);  
  t2 = temp | (temp << 16);  
  temp = 0x0f | (0x0f << 8);  
	t3 = temp | (temp << 16);  
	t4 = 0xff | (0xff << 16);  
	t5 = 0xff | (0xff << 8);  
	res = (x & t1) + ((x >> 1) & t1);  
	res = (res & t2) + ((res >> 2) & t2);  
	res = (res & t3) + ((res >> 4) & t3);  
	res = (res + (res >> 8)) & t4;  
  res = (res + (res >> 16)) & t5;
  return res;  
}

//P12
/*
 * greatestBitPos - return a mask that marks the position of the greatest significant 1 bit.
 *   Example: greatestBitPos(12) = 8
 *            greatestBitPos(-2) = -2147483648
 *            greatestBitPos(0)  = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 60
 *   Rating: 4
 */ 
int greatestBitPos(int x) {
  x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
  x = ((~x >> 1) | (1 << 31)) & x;
	return x;
}

//P13
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 * x | (~x + 1) if x is 0, the sign position is 0, the other is 1
 * the anwser >> 31 will become 0 or 1
 */
int bang(int x) {
  return ~((x | (~x + 1)) >> 31) & 1;
}

//P14
/*
 * bitReverse - Reverse bits in an 32-bit integer
 *   Examples: bitReverse(0x80000004) = 0x20000001
 *             bitReverse(0x7FFFFFFF) = 0xFFFFFFFE
 *   Max ops: 40
 *   Rating: 4
 */ 
int bitReverse(int x){
  int temp, t1, t2, t3, t4, t5;
  temp = 0x55 | (0x55 << 8);  
  t1 = temp | (temp << 16); 
  temp = 0x33 | (0x33 << 8);  
  t2 = temp | (temp << 16);  
  temp = 0x0f | (0x0f << 8);  
	t3 = temp | (temp << 16);  
	t4 = 0xff | (0xff << 16);  
	t5 = 0xff | (0xff << 8);  
  x = ((x >> 1) & t1) | ((x & t1) << 1);
  x = ((x >> 2) & t2) | ((x & t2) << 2);
  x = ((x >> 4) & t3) | ((x & t3) << 4);
  x = ((x >> 8) & t4) | ((x & t4) << 8);
  x = ((x >> 16) & t5) | ((x & t5) << 16);
  return x;
}

//P15
/*
 * mod3 - calculate x mod 3 without using %.
 *   Example: mod3(100) = 1
 *            mod3(-100) = -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int mod3(int x){
  int sign = x & (1 << 31);
  int y = x ^ sign;
  int t1 = (y >> 16) + (y & ((0xFF << 8) + 0xFF));
  int t2 = (t1 >> 8) + (t1 & 0xFF);
  int t3 = (t2 >> 4) + (t2 & 0xF);
  int t4 = (t3 >> 2) + (t3 & 3);
  int t5 = (t4 >> 2) + (t4 & 3);
  int t6 = (t5 >> 2) + (t5 & 3);
  int mod = (!(t6 ^ 3) + 7) & t6;
  return mod + (sign >> 30);
}

//P16
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  if ((((uf & 0x7fffffff) >> 23) == 255) && (uf & 0x7fffff))
    return uf;
  else return uf + (1 << 31);
}

//P17
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  int count = 0;  
  unsigned temp, flag;  
  unsigned a;
  unsigned abs = x;   
  int sign = 0;  
  if (x == 0) return 0;  
  if (x < 0)  
  {  
  sign = 0x80000000;  
  abs = -x;  
  }  
  a = abs;  
  while (1)  
  {  
  temp = a;  
  a <<= 1;  
  count++;  
  if (temp & 0x80000000) break;  
  }  
  if ((a & 0x01ff) > 0x0100)  
    flag = 1;  
  else if ((a & 0x03ff) == 0x0300)  
    flag = 1;  
  else  
    flag = 0;  
  return sign + (a >> 9) + ((159 - count) << 23) + flag;
}

//P18
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  if ((uf & 0x7f800000) == 0) return ((uf & 0x007FFFFF) << 1) | (uf & 0x80000000); // e = 00000000
  if ((uf & 0x7f800000) != 0x7f800000) return uf + 0x00800000;  //e != 11111111
  return uf; //e = 11111111
}
