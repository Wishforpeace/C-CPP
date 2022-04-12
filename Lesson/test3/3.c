#include<stdio.h>
void byteswap(){
    int a=0x12345678,b,c;
    // (a>>24)&0x0000000ff 清0操作
    b= (a<<24)+(a>>24&0x0000000ff);
    c = (a >>8 &0x0000ff00)+(a<<8 &0x00ff0000);
    printf("%#x\n",b+c);
    printf("%#x\n",b|c);
    printf("%#x",b^c);

}
int main(){
   byteswap();
}