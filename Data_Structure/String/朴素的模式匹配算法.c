 #include<stdio.h>
 #include<string.h>
 #define MAXSIZE 100 /* 存储空间初始分配量 */
 typedef char String[MAXSIZE+1];


 int Index(String S, String T, int pos) 
{
	int i = pos;	/* i用于主串S中当前位置下标值，若pos不为1，则从pos位置开始匹配 */
	int j = 0;				/* j用于子串T中当前位置下标值 */
    printf("%lu %lu\n",strlen(S),strlen(T));
	while (i <= strlen(S) && j <= strlen(T)) /* 若i小于S的长度并且j小于T的长度时，循环继续 */
	{
		if (S[i] == T[j]) 	/* 两字母相等则继续 */
      	{
			++i;
         	++j; 
      	} 
      	else 				/* 指针后退重新开始匹配 */
      	{  
         	i = i-j+1;		/* i退回到上次匹配首位的下一位 */
         	j = 0; 			/* j退回到子串T的首位 */
      	}      
	}
	if (j > strlen(T)) 
		return i-strlen(T);
	else 
		return 0;
}



int main()
{
    char S[]="goodgoogle";
    char T[]="google";
    int result=Index(S,T,0);
    printf("%d\n",result);
}