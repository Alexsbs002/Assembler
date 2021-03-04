// assembler lab 1 var 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int main()
{
    //(b1 * (w1 - b2) - w2 * b3) / w3 + d1 / b4
    char b1 = 100, b2 = 5, b3 = 3, b4 = 4; //1
    short int w1 = 20000, w2 = 10000, w3 = 6;//2
    int d1 = 10;//4
    int res = 0;
    _asm {
        ; 1 = (w1 - b2) = bx
        mov al, b2
        cbw
        mov bx, w1
        sub bx, ax

        ; 2 = b1 * 1 = bx
        mov al, b1
        cbw
        mul bx
        mov bx, ax

        ; 3 = w2 * b3 = ax
        mov al, b3
        cbw
        mul w2

        ; 4 = 2 - 3 = bx
        sub bx, ax

        ; 5 = 4 / w3 = ax
        mov ax, world ptr bx
        mov dx, world ptr bx+2
        div w3

        ; 6 = d1 / b4 = eax:edx
        mov eal, eax
        mov edl, edx
        mov al, b4
        cbw
        cwd
        cdq; EDX:EAX = b4


        idiv d1
       

        ; 7 = result

        mow double word ptr res, eax
        mow double word ptr res + 4, edx

    }
    
    
    
    cout << res;
    return 0;


}
