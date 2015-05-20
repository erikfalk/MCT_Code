#include <stdio.h>
int *c; //globale Variable vom Typ int Zeiger
int * add(int fa[], int fb[]); //Definition der Funktion add

int main(){
    
    int a[3], b[3]; //Deklaration der Arrays a und b 
    int i; //Deklaration von i
    
    for (i=0; i<3;i++)  a[i]=i;   //füllen von Array a mit den Werten 0,1,2 
    for (i=0; i<3;i++) b[i]=i+1; //füllen von Array b mit den Werten 1,2,3
    
    c = add(a,b); //Array a und b an Funktion add übergeben und Rückgabewert an c zugewiesen
    
    for (i=0; i<3; i++) printf("%i + %i = %i\n",a[i], b[i], *(c+i));//Ausgabe der Werte von a und b an der Stelle i und Ausgabe des Inhalts an der
                                                                    //an der Speicheradresse c+i

    //Ausgabe der Adressen
    printf("Adresse Funktion add %x\n", &add);
    printf("Adresse Array a: %x, b: %x\n", a, b);
    printf("Adresse Pointer *c %x\n", c);
    
    return 0;
}


   
int * add(int fa[], int fb[]) {
    int i; //Variablendeklaration
    static int x[3]; // Arraydeklaration
        
    for (i=0; i<3; i++) x[i] = fa[i] + fb[i]; //addieren der Werte von fa und fb an der Stelle von i
    for (i=0; i<3; i++) printf("%i + %i = %i\n",fa[i], fb[i], x[i]); //Ausgabe der Werte von fa, fb und x an der Stelle i
    
    printf("Adresse Rückgabewert x %x\n",x);

    return x; //Rückgabe der Speicheradresse von x
}
