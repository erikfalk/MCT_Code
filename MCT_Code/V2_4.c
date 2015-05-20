#include<stdio.h>
#include<conio.h>

unsigned int wert[4] = {0x00, 0x01, 0x02, 0x03};

int main(){
    
   unsigned int i;
    //setup
    outp(0x303, 0x8A) //A: Out, B: out, CL: Out, CH: In
    outp(0x302, 0x04) //Multiplexer auf Logikschaltung

    while(1){
        
        for (i=0; i<4; i++){
            outp(0x300, wert[i]);
            sleep(2000);
        }
    }

    return 0;
}

