#include <stdio.h>
#define PI 3.141593
float calarea(float radius){
    float area;
    area = PI *radius *radius;
    return area;
}
int main(){
    float radius,area;
    printf("Please input radius\n");
    scanf("%f",&radius);
    area = calarea(radius);
    printf("The area of the circle is %.f\n",area);
    return 0;
}