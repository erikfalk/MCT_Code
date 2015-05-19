#include <stdio.h>
#include <conio.h>


unsigned long long int timeStamp(){
    
    unsigned long long int i64 = 0;

    //Time Stamp Counter in EAX und EDX schreiben
    _asm{
        rdtsc
        mov A, EAX
        mov D, EDX
    }
    
    i64 += D;   //0000 0000 DDDD DDDD
    i64 <<= 32; //DDDD DDDD 0000 0000
    i64 += A;   //DDDD DDDD AAAA AAAA

    return i64;
}


int main(){
    unsigned int sec;
    unsigned long long int a, b;
    
    a = timeStamp(); 
    PC_PortOut(0x70,0x00);
    b = timeStamp();

    printf("Zeit: %d sec\n",1/(b-a));


