#include<stdio.h>

int g_X;
char g_Y;

int main(){
    
    char l_a;
    static int l_b; //Aufgabe 3
    char l_c;
    int* ptr; //Zeiger für direkte Zuweisung

    //Aufgabe 1
    g_X = 255;
    printf("Adresse von g_X: %0x\n", &g_X);
    
    g_Y = 16;
    printf("Adresse von g_Y: %x\n", &g_Y);

    l_a = 100;
    printf("Adresse von l_a: %x\n", &l_a);

    l_b = 19;
    printf("Adresse von l_b: %x\n", &l_b);

    l_c = 234;
    printf("Adresse von l_c: %x\n", &l_c);
    
    //Aufgabe 2
    ptr = &g_X; //dirket mit Speicheradresse adressieren 
    printf("Inhalt von g_X:  %d\n",*ptr);

    return 0;
}


