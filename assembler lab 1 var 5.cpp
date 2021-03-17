// assembler lab 1 var 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int main()
{

	char b1 = 100, b2 = 5, b3 = 3, b4 = 4; //1
	short int w1 = 20, w2 = 10, w3 = 6;//2
	int d1 = 10;//4
	int res = 0;
	int p = (((b1 * (w1 - b2) - w2 * b3) / w3) + (d1 / b4));
	_asm {
		; 1 = (w1 - b2) = bx
		mov al, b2
		cbw
		mov bx, w1
		sub bx, ax

		; 2 = b1 * 1 = (cx:bx)
		mov al, b1
		cbw
		imul bx
		mov bx, ax
		mov cx, dx

		; 3 = w2 * b3 = (dx:ax)
		mov al, b3
		cbw
		imul w2

		; 4 = 2 - 3 = (cx:bx)
		sub bx, ax
		sbb cx, dx

		; 5 = 4 / w3 = bx
		mov dx, cx
		mov ax, bx
		
		idiv w3
		mov bx, ax


		; 6 = d1 / b4 = ax
		mov al, b4
		cbw
		mov cx, ax
		mov ax, word ptr d1
		mov dx, word ptr d1 + 2
		idiv cx

		; 7 = 5 + 6

		add bx, ax

		mov word ptr res, bx

	}
	cout << p << "\n";
	cout << res << "\n";
	return 0;
}
	
