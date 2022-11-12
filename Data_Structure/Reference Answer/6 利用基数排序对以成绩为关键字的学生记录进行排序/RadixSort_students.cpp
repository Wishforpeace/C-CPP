#include "SqListFunc_students.cpp"

#define RADIX 10

int bitsnum = 3;    //�ؼ��ֵ�λ��

void RadixPass(RcdType A[],RcdType B[],int n, int i)
{
	int j,k;
	int count[RADIX];

    for(j=0; j<RADIX; ++j) count[j]=0;
    for(k=0; k<n; ++k) count[A[k].keys[i]]++;
    for(j=1; j<RADIX; ++j)count[j]=count[j-1]+count[j];

	for(k=n-1; k>=0; --k)
	{
        j=A[k].keys[i];
        B[count[j]-1]=A[k];
        count[j]--;
    }//for

}//RsdixPass

void RadixSort(SqList &L)
{
    int j, i;

	RcdType * C = new RcdType[L.length];
	i = bitsnum - 1;
    
	while(i>=0){
        RadixPass(L.elem, C, L.length, i);
        i--;
        if(i>=0){
            RadixPass(C, L.elem, L.length, i);
            i--;
        }//if
        else
            for(j=0; j<L.length; ++j) L.elem[j]=C[j];
    }//while
}//RadixSort

void InputStudents(SqList &L)   //����ѧ����Ϣ�����Ա�L��
{
	int i, num;
	ElemType e;
	
	cout<<"������ѧ������:";
	cin>>num;
	cout<<endl;
	for(i = 1; i <= num; i++)
	{
		cout<<"�������"<<i<<"��ѧ����ѧ��:";
		cin>>e.no;
		cout<<"�������"<<i<<"��ѧ��������:";
		cin>>e.name;
		cout<<"�������"<<i<<"��ѧ���ĳɼ�:";
		cin>>e.grade;
		
		//��ѧ���ĳɼ������ͣ�ת��Ϊ�ؼ��֣����飩
		e.keys[0] = e.grade/100;                    
        e.keys[1] = e.grade/10 - e.keys[0]*10;
		e.keys[2] = e.grade%10;
		cout<<endl;

		ListInsert_Sq(L, i, e); 
	}
}

void OutputStudents_gradedown(SqList L)    //��������ѧ����Ϣ�������������
{
	int i;
	cout<<"����     ѧ��          ����     �ɼ�"<<endl;
    for(i=L.length-1; i>=0; i--)
       printf(" %-2d      %-10s    %-4s     %-3d\n", L.length-i, L.elem[i].no, L.elem[i].name, L.elem[i].grade);
}

void OutputStudents_gradeup(SqList L)    //��������ѧ����Ϣ�������������
{
	int i;
	cout<<"����     ѧ��          ����     �ɼ�"<<endl;
    for(i=0; i<=L.length-1; i++)
       printf(" %-2d      %-10s    %-4s     %-3d\n", L.length-i, L.elem[i].no, L.elem[i].name, L.elem[i].grade);
}

void main()
{
    SqList L;
	InitList_Sq(L);

	InputStudents(L);      //����ѧ����Ϣ

    RadixSort(L);         //����
   
	ListTraverse_Sq(L, OutputStudents_gradedown);

	//ListTraverse_Sq(L, OutputStudents_gradeup);
}






