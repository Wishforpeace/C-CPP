#include<stdio.h>

int main(){
    int coord[7][2]={{1,1},{3,1},{5,4},{1,3},{2,2},{2,3},{2,6}};
    int i ;
    int j ;
    int result[7][2];
    int num = 0;
    for (i=0;i<6;i++){
       for(j=i+1;j<7;j++){
           int a = coord[j][1]-coord[i][1];
           printf("a:%d\n",a);
           int b = coord[i][0]-coord[j][0];
           printf("b:%d\n",b);
           int c = coord[i][0]*coord[j][1]-coord[i][1]*coord[j][0];
           printf("c:%d\n",c);
           int m;
           int index[5];
           for (m = 0 ; m<7; m++){
                printf("i:%d\n",i);
                printf("j:%d\n",j);
                printf("m:%d\n",m);
                int count=0;
                if (m == i||m==j){
                    continue;
                }else if(m !=i&&m!=j) {
                    index[count]= a*coord[m][0]+b*coord[m][1];
                    printf("count:%d\n",count);
                    count++;
                    printf("%d\n",index[count]);
                }
            }
        
            int k;
            int flag = 0;
            if (index[0]>c){
                for(k=1;k<5;k++){
                    
                    if(index[k]<c){
                        flag = 1;
                        break;
                    } 
                }
            }else if (index[0]<c){
                for ( k = 1; k < 5; k++)
                {
                    if(index[k]>c){
                        flag = 1;
                        break;
                    }
                }   
            }
            if(flag==0){
                result[num][0]=i;
                result[num][1]=j;
                num ++;
            }
        }
        
           
    
    }
    int count =0;
    for (count =0 ;count<7;count++){
        printf("%d---%d",result[count][0],result[count][1]);
    }   
    return 0 ;
}