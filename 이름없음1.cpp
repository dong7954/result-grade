#include <stdio.h>

#include <memory.h>

#include <stdlib.h>

#include <string.h>

#include <windows.h>

#include <conio.h>

 

#define MAX_NLEN    20 //�ִ� �̸� ����

#define MAX_SUBJECT 3 //���� ��

 

struct Student {//�л� ����ü ����

    char name[MAX_NLEN+1];//�̸�

    int number; //�л� ��ȣ

    int scores[MAX_SUBJECT];//���� ���� 

    double savg;//��� 

    char* rank; //��ü ��� 

    char* s_rank[3]; // �� ���� ��� 

    

};

 

 

const char *SUB_TITLE[MAX_SUBJECT]={"����","����","����"};

 

 

Student **A; //���� �����ͷ� ����ü ���� (�Լ� ������ �ܺο� ����� �Լ��� �����ϰ� �ϱ� ����) 

int max_student=0; //�л� �� 

int count=0;

int kan=0;

 

 

void Initialize();//�ִ� �л��� �Է� ��  �л� ������ �ʱ�ȭ 

void Start();

void Exit();//�����ϱ� ���� �Ҵ��� �޸� ����

void TcLogin();

int StuLogin();

 

int Menu();//�޴� ��� �� ����

void AddStd();//�л� ������ �Է�

int RankStd(int a);//��ü ��� �����

int SubRank(int m);// ���� ��� ����� 

void RemoveStd();//�л� ������ ����

void FindStd();//�л� �˻�

void ListStd();//��� ����

void Modify();

 

void ViewStuData(Student *stu);//�л� ������ ��� 

 

int Check_Std_number(int number);//��ȿ�� ��ȣ���� �Ǻ�

int Check_Std_Score(int score);//��ȿ�� �������� �Ǻ�

 

void gotoxy(int x, int y){

   

    COORD Pos = { x-1, y-1 };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}

 

int main(void)

{    

 

   system("mode con cols=100 lines=35");

   

   int sel=1;

   

      while(count<2){

      

      

   gotoxy(24,8);

      printf("����������������������������������������������������������������������������������������������������������");

      for(int i=9;i<21;i++) {

      gotoxy(24,i);

      printf("��                                                   ��");

   }

      gotoxy(24,21);

      printf("����������������������������������������������������������������������������������������������������������");

    gotoxy(24,10);

   printf("����������������������������������������������������������������������������������������������������������");

   gotoxy(42,9);

   printf("���� ���� ���α׷�");

   gotoxy(30,11);

   printf("��������������������������������������");

   gotoxy(30,12);

   printf("��                 ��");

   gotoxy(30,13);

   printf("��������������������������������������");

   gotoxy(32,12);

   printf("1:������ �α��� ");

   gotoxy(53,11);

   printf("��������������������������������������");

   gotoxy(53,12);

   printf("��                 ��");

   gotoxy(53,13);

   printf("��������������������������������������");

   gotoxy(55,12);

   printf("2:�л��� �α��� ");

   gotoxy(70,9);

   printf("0:����");

   

   

   

   gotoxy(43,16);

   printf("����������������������������");

   gotoxy(43,17);

   printf("��            ��");

   gotoxy(43,18);

   printf("����������������������������");

   gotoxy(47,17);

   printf("�Է� :");   

   gotoxy(54,17);

   scanf("%d",&sel);

   

   system("cls");

   

   

   switch(sel) {

   case 1 :

   while(count==0){

    gotoxy(24,8);

    printf("����������������������������������������������������������������������������������������������������������");

   for(int i=9;i<21;i++) {

      gotoxy(24,i);

      printf("��                                                   ��");

   }

   gotoxy(24,21);

   printf("����������������������������������������������������������������������������������������������������������");

    

    

   gotoxy(41,9);

   printf("����������������������������������������");

   gotoxy(41,10);

   printf("��                  ��");

   gotoxy(41,11);

   printf("����������������������������������������");

   gotoxy(45,10);

   printf("������ �α���");

    TcLogin();

 }

    if(max_student==0){

    Initialize();// �ִ� �л��� �Է� ���� ������ �ʱ�ȭ 

}

    Start();//�⺻ �޴� ��� �� ���� 

    break;

   

   case 2 :

   while(1){

   gotoxy(24,8);

    printf("����������������������������������������������������������������������������������������������������������");

   for(int i=9;i<21;i++) {

      gotoxy(24,i);

      printf("��                                                   ��");

   }

   gotoxy(24,21);

   printf("����������������������������������������������������������������������������������������������������������");

 

 

   gotoxy(41,9);

   printf("����������������������������������������");

   gotoxy(41,10);

   printf("��                  ��");

   gotoxy(41,11);

   printf("����������������������������������������");

   gotoxy(45,10);

   printf("�л��� �α���");

   StuLogin();

   break;

}

   break;

   

   default :

   break;

}

 

   if(sel==0) {

   gotoxy(40,10);

    printf("���α׷� ����");

    gotoxy(40,30);

    printf("\n");

    count=2;

      return 0;

   }

 

}

    Exit();//�����ϱ� ���� �Ҵ��� �޸� ����

    return 0;

 

}

 

int StuLogin() {

   

   int number;   

   

   gotoxy(35,14);

   printf("����������������������������������������������������������������");

   gotoxy(35,15);

   printf("��                              ��");

   gotoxy(35,16);

   printf("����������������������������������������������������������������");

   gotoxy(38,15);

   printf("�й� �Է� : ");

   scanf("%d",&number);

   

   if(Check_Std_number(number-18021000)==0)//��ȿ�� ��ȣ�� �ƴ� ��

    {

       system("cls"); 

       gotoxy(35,10);

        printf("�й��� �ùٸ��� �ʽ��ϴ�.\n");

        

        Sleep(1000);   //ȭ�� ��� ���� 

        system("cls");   //ȭ�� �����

        

        return 0; 

    }

    

    system("cls");

    printf("��ȣ\t�̸�\t����\t����\t����\t���\t���\n");

    printf("================================================================================================\n");

    

    ViewStuData(A[number-18021001]);

    printf("================================================================================================\n");

    printf("\n");

    

    system("pause");

   system("cls");

    return 0;

 

   

   

}

void TcLogin()

{

   

   char iid[20]={"\0"};

    char pass[20]={"\0"};

    int key;

    int cnt;

    char ID[20]={"admin"};

    char PW[20]={"1234"};    

    

    gotoxy(38,14);

   printf("����������������������������������������������������");

   gotoxy(38,15);

   printf("��                        ��");

   gotoxy(38,16);

   printf("����������������������������������������������������");

    gotoxy(42,15);

    printf("ID : ");

    scanf("%s",iid);

    gotoxy(38,17);

   printf("����������������������������������������������������");

   gotoxy(38,18);

   printf("��                        ��");

   gotoxy(38,19);

   printf("����������������������������������������������������");

    gotoxy(42,18);

    printf("Password : ");

     while(1){

          key = getch();

          if(key == 13){ // ���ͽ� ���� 

             key = 0;

             break;

         }

         else if(key == '\b'){// �齺���̽� ���� 

            printf("\b \b"); 

               cnt--;     

               pass[cnt] = '\0';

         }

         else if(key != '\0'){

            putchar('*');

            pass[cnt] = (char)key;

            cnt++;

         }

      }

  

    system("cls");

    

    if(strcmp(ID,iid)==0 && strcmp(PW,pass)==0) {

       gotoxy(40,10);

       printf("�α��� ����!");

      

      Sleep(1000);   //ȭ�� ��� ���� 

        system("cls");   //ȭ�� �����

        count=1;

   }

   else {

      gotoxy(40,10);

      printf("�α��� ����!");  

      cnt=0;

      Sleep(1000);   //ȭ�� ��� ���� 

        system("cls");   //ȭ�� ����� 

       

   }

 }

 

void Initialize()

{

    

    gotoxy(40,10);

    printf("�ִ� �л� ��: ");

    scanf("%d",&max_student);

 

    system("cls");   //ȭ�� ����� 

 

    A = (Student **)malloc(max_student*sizeof(Student *));//���� �迭 �޸� �Ҵ�   malloc = ���ڷ� ���޵� ũ���� ����Ʈ �� ��ŭ �޸� ������ ����

    memset(A,0,max_student*sizeof(Student *));//�޸� �ʱ�ȭ(A �迭�� �����ּҺ��� max_student*sizeof(Student *)����Ʈ ũ�⸸ŭ 1����Ʈ ������ 0���� ����)

}

 

void Start()

{

    int select = 0;

    while((select = Menu())!=0)//������ �޴��� 0�� �ƴϸ� �ݺ�

    {

        switch(select)//������ Ű�� ���� ��� ����

        {

        case 1: AddStd(); break;

        case 2: Modify(); break; 

        case 3: RemoveStd(); break;

        case 4: FindStd(); break;

        case 5: ListStd(); break;

        default:

        gotoxy(38,15);

      printf("�߸� �����Ͽ����ϴ�.\n"); Sleep(1000); system("cls"); break;

        }        

    }

    gotoxy(35,8);

    printf("�α��� ȭ������ �̵��մϴ�.");

    gotoxy(40,30);

    printf("\n");

    Sleep(500);

    system("cls");

}

 

int Menu()

{    

 

    int select=0;

    

    gotoxy(24,8);

    printf("����������������������������������������������������������������������������������������������������������");

    for(int i=9;i<27;i++) {

      gotoxy(24,i);

      printf("��                                                   ��");

    }

    gotoxy(24,27);

    printf("����������������������������������������������������������������������������������������������������������");

    gotoxy(24,10);

   printf("����������������������������������������������������������������������������������������������������������");

    gotoxy(42,9);

    printf("���� ���� ���α׷� ");

    gotoxy(67,9);

    printf("�α���:0");

    

    gotoxy(26,11);

   printf("����������������������������������������������");

   gotoxy(26,12);

   printf("��                     ��");

   gotoxy(26,13);

   printf("����������������������������������������������");  

    gotoxy(29,12);

    printf("�л� ������ �Է�:1");

 

gotoxy(52,11); 

   printf("����������������������������������������������");

   gotoxy(52,12);

   printf("��                     ��");

   gotoxy(52,13);

   printf("����������������������������������������������");

   gotoxy(55,12);

    printf("�л� ������ ����:2");

    

   gotoxy(26,14);

   printf("����������������������������������������������");

   gotoxy(26,15);

   printf("��                     ��");

   gotoxy(26,16);

   printf("����������������������������������������������");

    gotoxy(29,15);

    printf("�л� ������ ����:3");

    

    gotoxy(52,14);

   printf("����������������������������������������������");

   gotoxy(52,15);

   printf("��                     ��");

   gotoxy(52,16);

   printf("����������������������������������������������");

    gotoxy(59,15);

    printf("�л� �˻�:4 ");

    

    gotoxy(26,17);

   printf("����������������������������������������������");

   gotoxy(26,18);

   printf("��                     ��");

   gotoxy(26,19);

   printf("����������������������������������������������");

    gotoxy(30,18);

    printf("��ü ���� Ȯ��:5");

    

    gotoxy(43,23);

   printf("������������������������������");

   gotoxy(43,24);

   printf("��             ��");

   gotoxy(43,25);

   printf("������������������������������");

    gotoxy(47,24);

    printf("�Է� : ");

    scanf("%d",&select);

    system("cls");   //ȭ�� ����� 

    

    

    return select;

}

 

void AddStd()

{

   kan=0;

    int number=0;

    Student *stu=0;

    int s=0;

    

    gotoxy(24,8);

    printf("����������������������������������������������������������������������������������������������������������");

    for(int i=9;i<21;i++) {

      gotoxy(24,i);

      printf("��                                                   ��");

    }

    gotoxy(24,21);

    printf("����������������������������������������������������������������������������������������������������������");

    gotoxy(24,10);

   printf("����������������������������������������������������������������������������������������������������������");

   

    gotoxy(42,9);

   printf("���� ���� ���α׷�");

    gotoxy(38,13);

    printf("�߰��� �л� ��ȣ(1~%d): ",max_student);

    scanf("%d",&number);

    

    system("cls");   //ȭ�� ����� 

    

    if(Check_Std_number(number)==0)//��ȿ�� ��ȣ�� �ƴ� ��

    {

       gotoxy(35,10);

        printf("������ ��� �л� ��ȣ�Դϴ�.\n");

        gotoxy(38,11);

        printf("���� �޴��� �Ѿ�ϴ�.\n");

        

        Sleep(2000);   //ȭ�� ��� ���� 

        system("cls");   //ȭ�� ����� 

        return;

    }

 

    if(A[number-1])//�л� �����Ͱ� �ִٸ�

    {

       gotoxy(35,10);

        printf("�̹� �߰��Ͽ����ϴ�\n");

        gotoxy(35,11);

        printf("���� �޴��� �Ѿ�ϴ�.\n");

        

        Sleep(2000);   //ȭ�� ��� ���� 

        system("cls");   //ȭ�� ����� 

        return;

    }

 

    

    stu = (Student *)malloc(sizeof(Student));//�л� ����ü ���� �޸� �Ҵ�

    A[number-1] = stu;//�Ҵ��� �޸� �ּҸ� �迭�� ����    

    stu->number = number;

    

    gotoxy(24,8);

    printf("����������������������������������������������������������������������������������������������������������");

    for(int i=9;i<21;i++) {

      gotoxy(24,i);

      printf("��                                                   ��");

    }

    gotoxy(24,21);

    printf("����������������������������������������������������������������������������������������������������������");

    gotoxy(24,10);

   printf("����������������������������������������������������������������������������������������������������������");

   

    gotoxy(42,9);

   printf("���� ���� ���α׷�");

   

    gotoxy(43,12);

    printf("�̸� :     ");

    scanf("%s",stu->name,sizeof(stu->name));

 

    for(s=0;s<MAX_SUBJECT;s++)

    {

       gotoxy(43,13+s);

        printf("%s ����:    ",SUB_TITLE[s]);

        scanf("%d",stu->scores+s);

       

        if(Check_Std_Score(stu->scores[s])==0)//��ȿ�� ������ �ƴ� ��

        {

            stu->scores[s]=0;

            gotoxy(20,1+s);

            printf("�Է��� ������ ��ȿ���� �ʾƼ� %s ������ 0ó�� �Ͽ����ϴ�.\n",SUB_TITLE[s]);

        }

    }

    Sleep(500);

    system("cls"); //ȭ�� ����� 

    

        gotoxy(38,10);

        printf("�Է��� �Ϸ��߽��ϴ�.\n");

        gotoxy(37,12);

        printf("���� �޴��� �Ѿ�ϴ�.\n");

        

        Sleep(1000);   //ȭ�� ��� ���� 

        system("cls");   //ȭ�� ����� 

      

   RankStd(number-1);

   SubRank(number-1);

}

 

void Modify()

{   

 

    int number=0;

    int sel; 

    int jum;

    

    gotoxy(24,8);

    printf("����������������������������������������������������������������������������������������������������������");

    for(int i=9;i<21;i++) {

      gotoxy(24,i);

      printf("��                                                   ��");

    }

    gotoxy(24,21);

    printf("����������������������������������������������������������������������������������������������������������");

    gotoxy(24,10);

   printf("����������������������������������������������������������������������������������������������������������");

   

    gotoxy(42,9);

   printf("���� ���� ���α׷�");

    gotoxy(38,13);

    printf("������ �л� ��ȣ(1~%d): ",max_student);

    scanf("%d",&number);

 

    system("cls"); //ȭ�� ����� 

  

    if(Check_Std_number(number)==0)//��ȿ�� ��ȣ�� �ƴ� ��

    {

        gotoxy(35,10);

        printf("������ ��� �л� ��ȣ�Դϴ�.\n");

        gotoxy(38,11);

        printf("���� �޴��� �Ѿ�ϴ�.\n");

        

        Sleep(1000);   //ȭ�� ��� ���� 

        system("cls");   //ȭ�� �����

        

        return;

    }

 

    if(A[number-1]==0)//�л� �����Ͱ� ���� ��

    {

        gotoxy(38,10);

        printf("�����Ͱ� �����ϴ�.\n");

        gotoxy(35,11);

        printf("���� �޴��� �Ѿ�ϴ�.\n");

        

        Sleep(1000);   //ȭ�� ��� ���� 

        system("cls");   //ȭ�� �����

        

        return;

    }

    

    gotoxy(42,9);

    printf("���� ���� ���α׷�");

    

    gotoxy(24,8);

    printf("����������������������������������������������������������������������������������������������������������");

    for(int i=9;i<21;i++) {

      gotoxy(24,i);

      printf("��                                                   ��");

    }

    gotoxy(24,21);

    printf("����������������������������������������������������������������������������������������������������������");

    gotoxy(24,10);

   printf("����������������������������������������������������������������������������������������������������������");

   

   

   gotoxy(37,11);

   printf("��������������������������������������������������������");

   gotoxy(37,12);

   printf("��                          ��");

   gotoxy(37,13);

   printf("��������������������������������������������������������");

   gotoxy(39,12);

      printf("����: 1 ���� : 2 ���� : 3\n");

   

   gotoxy(43,16);

   printf("������������������������������");

   gotoxy(43,17);

   printf("��             ��");

   gotoxy(43,18);

   printf("������������������������������");

   

   gotoxy(47,17);

    printf("�Է� : "); 

   scanf("%d",&sel);

    

    system("cls");

    

    gotoxy(42,9);

    printf("���� ���� ���α׷�");

    

    gotoxy(24,8);

    printf("����������������������������������������������������������������������������������������������������������");

    for(int i=9;i<21;i++) {

      gotoxy(24,i);

      printf("��                                                   ��");

    }

    gotoxy(24,21);

    printf("����������������������������������������������������������������������������������������������������������");

    gotoxy(24,10);

   printf("����������������������������������������������������������������������������������������������������������");

   

   

   gotoxy(37,11);

   printf("��������������������������������������������������������");

   gotoxy(37,12);

   printf("��                          ��");

   gotoxy(37,13);

   printf("��������������������������������������������������������");

   gotoxy(39,12);

      printf("����: 1 ���� : 2 ���� : 3\n");

   

   gotoxy(43,16);

   printf("������������������������������");

   gotoxy(43,17);

   printf("��             ��");

   gotoxy(43,18);

   printf("������������������������������");

    

      gotoxy(47,17);

      printf("���� : ");

      scanf("%d",&jum);

      

    A[number-1]->scores[sel-1] = jum;

    RankStd(number-1);

    SubRank(number-1);

 

    system("cls");

    

    gotoxy(38,10);

    printf("�����Ͽ����ϴ�.\n");

    gotoxy(35,11);

    printf("���� �޴��� �Ѿ�ϴ�.\n");

    

    Sleep(1000);   //ȭ�� ��� ���� 

    system("cls");   //ȭ�� �����

}

 

int RankStd(int b) {

      

      int sum=0;

      double avg=0;

      

      for(int i=0;i<MAX_SUBJECT;i++) {

         sum=sum+A[b]->scores[i];

       }

       avg=(double)sum/(double)MAX_SUBJECT;

       

      A[b]->savg=(double)avg;

       

       if(avg >= 95) {

         A[b]->rank = "A+";

      }

      else if(avg >= 90) {

         A[b]->rank = "A";

      }

      else if(avg >= 85) {

         A[b]->rank = "B+";

      }

      else if(avg >= 80) {

         A[b]->rank = "B";

      }

      else if(avg >= 75) {

         A[b]->rank = "B+";

      }

      else if(avg >= 70) {

         A[b]->rank = "C";

      }

      else if(avg >= 65) {

         A[b]->rank = "D+";

      }

      else if(avg >= 60) {

         A[b]->rank = "D";

      }

      else {

         A[b]->rank = "F";

      }

 

   

}

 

int SubRank(int m)

{

   

   for(int i=0; i<MAX_SUBJECT;i++){

   if(A[m]->scores[i]>=95) {

      A[m]->s_rank[i]="A+";

   }

   else if(A[m]->scores[i]>=90) {

      A[m]->s_rank[i]="A";

   }

   else if(A[m]->scores[i]>=85) {

      A[m]->s_rank[i]="B+";

   }

   else if(A[m]->scores[i]>=80) {

      A[m]->s_rank[i]="B";

   }

   else if(A[m]->scores[i]>=75) {

      A[m]->s_rank[i]="C+";

   }

   else if(A[m]->scores[i]>=70) {

      A[m]->s_rank[i]="C";

   }

   else if(A[m]->scores[i]>=65) {

      A[m]->s_rank[i]="D+";

   }

   else if(A[m]->scores[i]>=60) {

      A[m]->s_rank[i]="D";

   }

   else {

      A[m]->s_rank[i]="F";

   }

}

}

 

int Check_Std_number(int number)

{

    return (number>=1)&&(number<=max_student);

}

int Check_Std_Score(int score)

{

    return (score>=0)&&(score<=100);

}

 

void RemoveStd()

{   

   kan=0;

    int number=0;

    

    gotoxy(35,12);

    printf("������ �л� ��ȣ(1~%d): ",max_student);

    scanf("%d",&number);

 

    system("cls"); //ȭ�� ����� 

  

    if(Check_Std_number(number)==0)//��ȿ�� ��ȣ�� �ƴ� ��

    {

       gotoxy(35,10);

        printf("������ ��� �л� ��ȣ�Դϴ�.\n");

        gotoxy(38,11);

        printf("���� �޴��� �Ѿ�ϴ�.\n");

        

        Sleep(1000);   //ȭ�� ��� ���� 

        system("cls");   //ȭ�� �����

        

        return;

    }

 

    if(A[number-1]==0)//�л� �����Ͱ� ���� ��

    {

       gotoxy(38,10);

        printf("�����Ͱ� �����ϴ�.\n");

        gotoxy(35,11);

        printf("���� �޴��� �Ѿ�ϴ�.\n");

        

        Sleep(1000);   //ȭ�� ��� ���� 

        system("cls");   //ȭ�� �����

        

        return;

    }

 

    free(A[number-1]);//�޸� ����

    A[number-1] = 0;

 

    gotoxy(38,10);

    printf("�����Ͽ����ϴ�.\n");

    gotoxy(35,11);

    printf("���� �޴��� �Ѿ�ϴ�.\n");

    

    Sleep(1000);   //ȭ�� ��� ���� 

    system("cls");   //ȭ�� �����

}

 

void FindStd()

{

   

    int number=0;    

    

    gotoxy(24,8);

    printf("����������������������������������������������������������������������������������������������������������");

    for(int i=9;i<27;i++) {

      gotoxy(24,i);

      printf("��                                                   ��");

    }

    gotoxy(24,27);

    printf("����������������������������������������������������������������������������������������������������������");

    gotoxy(24,10);

   printf("����������������������������������������������������������������������������������������������������������");

   

    gotoxy(40,12);

    printf("�˻��� �л� ��ȣ(1~%d): ",max_student);

    scanf("%d",&number);

 

   system("cls"); //ȭ�� ����� 

 

    if(Check_Std_number(number)==0)//��ȿ�� ��ȣ�� �ƴ� ��

    {

       gotoxy(35,10);

        printf("������ ��� �л� ��ȣ�Դϴ�.\n");

        gotoxy(38,11);

        printf("���� �޴��� �Ѿ�ϴ�.\n");

        

        Sleep(1000);   //ȭ�� ��� ���� 

        system("cls");   //ȭ�� �����

        

        return;

    }

 

    if(A[number-1]==0)//�л� �����Ͱ� ���� ��

    {

       gotoxy(38,10);

        printf("�����Ͱ� �����ϴ�.\n");

        gotoxy(35,11);

        printf("���� �޴��� �Ѿ�ϴ�.\n");

        

        Sleep(1000);   //ȭ�� ��� ���� 

        system("cls");   //ȭ�� �����

        

        return;

    }

    

    printf("��ȣ\t�̸�\t����\t����\t����\t���\t���\n");

    printf("================================================================================================\n");

    

    ViewStuData(A[number-1]);

    printf("================================================================================================\n");

    printf("\n");

    system("pause");

    system("cls");

}

 

void ViewStuData(Student *stu)

{

    int s = 0;

 

    printf("  %d\t%s",stu->number,stu->name);

    for(s=0;s<MAX_SUBJECT;s++)

    {

        printf("\t%d %s",stu->scores[s],stu->s_rank[s]);

        

    }

    printf("\t%.1f",stu->savg);

    printf("\t%s",stu->rank);

    printf("\n");

    

}

 

void ListStd()

{

    int i = 0;       

    

 

    printf("��ȣ\t�̸�\t����\t����\t����\t���\t���\n");

    printf("================================================================================================\n");

    for(i=0;i<max_student;i++)

    {

        if(A[i])

        {

            ViewStuData(A[i]);                 

        }

    }

    printf("================================================================================================\n");

    printf("\n"); 

    system("pause");

    system("cls");

    

}

 

void Exit()

{

    int i = 0;        

    

    for(i=0;i<max_student;i++)

    {

        if(A[i])

        {

            free(A[i]);//�޸� ����

        }

    }

    free(A);//�޸� ����

}
