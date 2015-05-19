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
    
    PC_PortOut(0x70,0x00);
    sec = PC_PortIn(0x71);
    
    a = timeStamp();

    while(1){
        if (sec != PC_PortIn(0x71)){
            b = timeStamp();
            break;
        }
    
    printf("Frequenz: %d GHz\n", (b-a)/1000000);

    return 0;
}
