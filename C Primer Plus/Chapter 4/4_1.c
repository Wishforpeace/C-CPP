// talkback.c --  演示与用户交互
#include <stdio.h>
#include <string.h>
#define DENSITY 62.4
int main(){
    float weigth,volume;
    int size,letters;
    char name[40];

    printf("Hi! What's your first name?\n");
    scanf("%s",name);
    printf("%s,what's your weight in pounds?\n",name);
    scanf("%f",&weigth);
    size = sizeof(name);
    letters = strlen(name);
    volume = weigth/DENSITY;
    printf("Well, %s , your volume is %2.2f cubic feet.\n",
        name,volume);
    printf("Also,your first name has %d letters,\n",
    letters);
    printf("and we have %d bytes to store it.\n",size);
    return 0;
}