#include<stdio.h>
#include<conio.h>

int main(){
    
    unsigned int hold = 0;
    //setup
    outp(0x303, 0x8A); //Port A: out
    

    while(1){
        
        //Taster abfragen
         
        if(inp(0x339) == 0){ //drücken feststellen
            sleep(10); //prellen abwarten
            while(1){
                if(inp(0x339) == 1){  //loslassen feststellen
                    sleep(10); //prellen abwarten
                    
                    if(hold == 1){ //LED an oder aus
                        hold = 0;
                        outp(0x300, 0x00);
                        break;  //gehe zur ersten while schleife
                    }
                    else{
                        hold = 1;
                        while(1){
                            outp(0x300, 0xff);
                            if(inp(0x339) == 0){
                                sleep(10);
                                break;
                            }
                       }
                    }
                }
            }
        }
    }
    return 0;
}
