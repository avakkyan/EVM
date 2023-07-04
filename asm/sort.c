#include "sort.h"

#include <stdio.h>

void sort(int* arr, int count)
{
    __asm {
        mov ecx, dword ptr [arr]
        //int i = 0, j, tmp;
        mov dword ptr [esp], 0
        sub esp, 12
        //while (i < count) {
    loop1_start:
        mov eax, dword ptr [esp + 12]
        cmp eax, dword ptr [count]
        jge loop1_end
        //j = i + 1;
        mov eax, dword ptr [esp + 12]
        add eax, 1
        mov dword ptr [esp + 8], eax
        //while (j < count) {
    loop2_start:
        mov eax, dword ptr [esp + 8]
        cmp eax, dword ptr [count]
        jge loop2_end
        //if (arr[i] > arr[j]) {
        mov eax, dword ptr [esp + 12]
        mov edx, dword ptr [esp + 8]
        mov eax, dword ptr [ecx + eax * 4]
        cmp eax, dword ptr [ecx + edx * 4]
        jle if_end
        //tmp = arr[i];
        mov dword ptr [esp + 4], eax
        //arr[i] = arr[j];
        mov eax, dword ptr [esp + 12]
        mov edx, dword ptr [esp + 8]
        mov edx, dword ptr [ecx + edx * 4]
        mov dword ptr [ecx + eax * 4], edx
        //arr[j] = tmp;
        mov eax, dword ptr [esp + 8]
        mov edx, dword ptr [esp + 4]
        mov dword ptr [ecx + eax * 4], edx
        //}
    if_end:
        //++j;
        mov eax, dword ptr [esp + 8]
        add eax, 1
        mov dword ptr [esp + 8], eax
        //}
        jmp loop2_start
    loop2_end:
        //++i;
        mov eax, dword ptr [esp + 12]
        add eax, 1
        mov dword ptr [esp + 12], eax
        //}
        jmp loop1_start
    loop1_end:
        add esp, 12
    }
}

void findMax10(int* arr, int count, int* res) {
    __asm {
        //sort(arr, count);
        mov eax, dword ptr [count]  
        push eax  
        mov ecx ,dword ptr [arr]  
        push ecx  
        call sort  
        add esp, 8
        //int i = 0;
        mov dword ptr [esp], 0
        sub esp, 4
        //while (i < 10) {
    for_start:
        mov eax, dword ptr [esp + 4]
        cmp eax, 10
        jge for_end
        //res[i] = arr[count - i - 1];
        mov eax, dword ptr [count]
        mov ecx, dword ptr [esp + 4]
        sub eax, ecx
        sub eax, 1
        mov edx, dword ptr [arr]
        mov eax, dword ptr [edx + eax * 4]
        mov edx, dword ptr [res]
        mov dword ptr [edx + ecx * 4], eax
        //++i;
        mov eax, dword ptr [esp + 4]
        add eax, 1
        mov dword ptr [esp + 4], eax
        //}
        jmp for_start
    for_end:
        add esp, 4
    }
}