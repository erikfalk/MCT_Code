#include <conio.h>
#include <stdio.h>

int main(){

    unsigned int sec;

    PC_PortOut(0x70,0x00); //Output auf Sekunden einstellen 
    sec = PC_PortIn(0x71); //Sekunden speichern

    while(1){
        if(sec != PC_PortIn(0x71)){
            sec = PC_PortIn(0x71);
            printf("Sekunde: %d\n",sec);
        }
    }

    return 0;
}
