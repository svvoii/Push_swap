/*
There are 3 classes of bitwise operators:
Unary - used as a prefix to a bit vector (like negation or a number)
	"~" one's complement / invert
Binary operators operatint on two vectors of bits:
	"&" and
	"|" or
	"^" exclusive or
Binary shift opertors whose LHS is a bit vector and RHS is integer
	"<<" shift left
	">>" shift right

Bitwise Complement Operator (Unary)
This unary complement operator flips each bit in its operand:
0 become 1 and viceversa (ex: ~[0,1,0,1] = [1,0,1,0])
	char a = Ob1100;
	char b = ~a; (Ob0011)

"&" Birwise "AND" Operator
The bitwise "and" operator takes two bit vectors, a(vecotr)&b(vector), and produce c(vector)
	-each of a(vector) and b(vector)'s plase value bits i are compared
	-when both a' and b' are 1, then c' is 1
	-otherwise, c' is 0
	ex:	|  a  |  b  |a & b|
		|  1  |  1  |  1  |
		|  1  |  0  |  0  |
		|  0  |  1  |  0  |
		|  0  |  0  |  0  |

"|" Birwise "AND" Operator
	-each of a' and b's place value bits i are compared
	-when either or both are 1, then c' is 1
	-otherwise, c' is 0
	ex:	|  a  |  b  |a & b|
		|  1  |  1  |  1  |
		|  1  |  0  |  1  |
		|  0  |  1  |  1  |
		|  0  |  0  |  0  |

"^" Birwise Exclusive "XOR" Operator
	-each of a' and b's place value bits i are compared
	-when a' is not equal b', then c' is 1
	-otherwise, c' is 0
	ex:	|  a  |  b  |a & b|
		|  1  |  1  |  0  |
		|  1  |  0  |  1  |
		|  0  |  1  |  1  |
		|  0  |  0  |  0  |

"<<" Bitwise Left Shift Operator
Takes a bit vector a' on the left-hand side
A magnitude 'm' integer on the right-hand side (produces a bit vector b')
The effect is: a'(i) = b"(i+m)
	ex:	|  a  |  m  | a<<m |
		|0101 |  1  | 1010 |
		|0101 |  2  | 0100 |
		|0101 |  3  | 1000 |
		|0101 |  4  | 0000 |
This operation can be achieved by multiplying underlying decimal by 2

">>" Bitwise Right Shift Operator
Takes a bit vector a' on the left-hand side
A magnitude 'm' integer on the right-hand side (produces a bit vector b')
The effect is: a'(i) = b"(i-m)
a'(m-1) through a'(0) are truncated 
b'(w-1) through b'(w-m) are sign-extended
	-if a'(w-1) is 0, then 0s will fill
	-if a'(w-1) is 1, then 1s will fill (this is made to make sure that the negative numbers maintain its sign)
	sign-extention with 0 high-order bit:
	ex:	|  a   |  m  | a>>m |
		| 0101 |  1  | 0010 |
		| 0101 |  2  | 0001 |
		| 0101 |  3  | 0000 |
	sign-extention with a 1 high-order bit:
	ex:	|  a   |  m  | a>>m |
		| 1010 |  1  | 1101 |
		| 1010 |  2  | 1110 |
		| 1010 |  3  | 1111 |
This can be interpreted as division by 2 (which preserves the (-)sign)

Bitwise Assignment Operators
Bitwise assign operators are for when need to perform a bitwise operation on a variable and assign result back to the variable itself
(just as with in arithmetic assignment operators: i = i + 1; same as i += 1;)
Works with all the binary bitwise operators:
	'&=' bitwise AND assignment
	'|=' OR assignment
	'^=' XOR assignment
	'<<=' left shift assignment
	'>>=' right shift assignment
ex: a >>= 2; same as: a = a >> 2;

*/
#include <unistd.h>
#include <stdio.h>

void	print_bits(unsigned char num)
{
	unsigned char	bit;
	int				i = 7;

	while (i >= 0)
	{
		bit = (num >> i & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
	write(1, "\n", 1);
}

unsigned char	reverse_bits(unsigned char num)
{
	unsigned char	bit;
	unsigned char	res = 0;
	int				i = 7;

	while (i >= 0)
	{
		res <<= 1;
		res = res | (num & 1);
		num >>= 1;
		bit = (num & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
	write(1, "\n", 1);
	return (res);
}

int	main()
{
	int	n = 10;
	int rev;
	
	print_bits(n);
	rev = reverse_bits(n);
	printf("rev:'%d'\n", rev);
	printf("rev:'%c'\n", rev);
	return (0);
}