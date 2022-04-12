/*练习整型数（短、中、长）、浮点型、字符型变量的定义
和输出、以及基本运算符（+、-、*、\）的使用*/
#include <stdio.h>
int main(){
    int a =65537;
    char ch ='A';
    short int b ;
    b=a;
    long int c;
    c=b;
    printf("the short value of %d is %d\n",a,b);
    printf("the long value of %d is %ld\n",a,c);
    printf("The ACII code of \'%c\'is %d\n",ch,ch);

}