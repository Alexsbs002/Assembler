// assembler lab 3 Mirko.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double a = 4, b = 1, c = 2;
	int d = -10, e = 10, q = 1;
	double resC1 = 0, resC2 = 0, resC3 = 0;
	double res1 = 0, res2 = 0, res3 = 0;

	printf(" x | res1 | res2 | res3\r\n");
	printf("---------------------------\r\n");

	for (int i = -10; i <= 10; i++)
	{
		double x = i;
		resC1 = resC2 = resC3 = 0;
		printf(" %5.1lf |", x);
		if (x == 0) {
			resC1 = x / c;
			printf(" | %7.3lf |  res1 \r\n", resC1);
		}
		else if (x > 0) {
			resC2 = (x + a) / (x + c);
			printf(" | %7.3lf |  res2\r\n", resC2);
		}
		else {
			resC3 = a * pow(x, 2) + x * pow(b, 2);
			printf(" | %7.3lf |  res3\r\n", resC3);
		}
	}

	int x = -10;
	char str[] = "    %3d |    %7.3lf   %s\r\n",
		str1[] = "res1",
		str2[] = "res2",
		str3[] = "res3";


	printf("     x  |     y\r\n");
	printf("----------------------------\r\n");
	_asm {
		finit
		met1 :
		; x / c
			cmp x, 0
			jne m2
			fild x
			fld c
			fdiv

			lea ebx, str1
			push ebx
			push dword ptr res1 + 4
			push dword ptr res1
			push x
			lea ebx, str
			push ebx
			call printf
			add esp, 20

			jmp exi

			m2 :
		; (x + a) / (x + c)
			cmp x, 0
			jle m3; jne
			finit
			fild x
			fld a
			fadd
			fild x
			fld c
			fadd
			fdiv
			fstp res2

			lea ebx, str2
			push ebx
			push dword ptr res2 + 4
			push dword ptr res2
			push x
			lea ebx, str
			push ebx
			call printf
			add esp, 20

			jmp exi

			m3 :
		; a* pow(x, 2) + x * pow(b, 2)
			; finit
			fild x
			fild x
			fmul
			fld a
			fmul
			fld b
			fld b
			fmul
			fild x
			fmul
			fadd
			fstp res3

			lea ebx, str3
			push ebx
			push dword ptr res3 + 4
			push dword ptr res3
			push x
			lea ebx, str
			push ebx
			call printf
			add esp, 20

			exi:
			mov eax, x
			add eax, 1
			mov x, eax
			cmp eax, 11
			jl met1
	}
	system("pause");
	return 0;
}









 checkB:
		cmp b, 0
			 jne checkm1
			 je checkm2

			 checkm1:
		 cmp c, 0
			 jge m3
			 jl m1

			 checkm2:
		 cmp c, 0
			 jle m3
			 jg m2
