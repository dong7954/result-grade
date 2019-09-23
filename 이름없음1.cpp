#include <stdio.h>

#include <memory.h>

#include <stdlib.h>

#include <string.h>

#include <windows.h>

#include <conio.h>

 

#define MAX_NLEN    20 //최대 이름 길이

#define MAX_SUBJECT 3 //과목 수

 

struct Student {//학생 구조체 정의

    char name[MAX_NLEN+1];//이름

    int number; //학생 번호

    int scores[MAX_SUBJECT];//과목 점수 

    double savg;//평균 

    char* rank; //전체 등급 

    char* s_rank[3]; // 각 과목 등급 

    

};

 

 

const char *SUB_TITLE[MAX_SUBJECT]={"국어","영어","수학"};

 

 

Student **A; //이중 포인터로 구조체 선언 (함수 내에서 외부에 선언된 함수에 접근하게 하기 위해) 

int max_student=0; //학생 수 

int count=0;

int kan=0;

 

 

void Initialize();//최대 학생수 입력 및  학생 데이터 초기화 

void Start();

void Exit();//종료하기 전에 할당한 메모리 해제

void TcLogin();

int StuLogin();

 

int Menu();//메뉴 출력 및 선택

void AddStd();//학생 데이터 입력

int RankStd(int a);//전체 등급 만들기

int SubRank(int m);// 과목 등급 만들기 

void RemoveStd();//학생 데이터 삭제

void FindStd();//학생 검색

void ListStd();//목록 보기

void Modify();

 

void ViewStuData(Student *stu);//학생 데이터 출력 

 

int Check_Std_number(int number);//유효한 번호인지 판별

int Check_Std_Score(int score);//유효한 성적인지 판별

 

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

      printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");

      for(int i=9;i<21;i++) {

      gotoxy(24,i);

      printf("┃                                                   ┃");

   }

      gotoxy(24,21);

      printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

    gotoxy(24,10);

   printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");

   gotoxy(42,9);

   printf("성적 관리 프로그램");

   gotoxy(30,11);

   printf("┏━━━━━━━━━━━━━━━━━┓");

   gotoxy(30,12);

   printf("┃                 ┃");

   gotoxy(30,13);

   printf("┗━━━━━━━━━━━━━━━━━┛");

   gotoxy(32,12);

   printf("1:교수용 로그인 ");

   gotoxy(53,11);

   printf("┏━━━━━━━━━━━━━━━━━┓");

   gotoxy(53,12);

   printf("┃                 ┃");

   gotoxy(53,13);

   printf("┗━━━━━━━━━━━━━━━━━┛");

   gotoxy(55,12);

   printf("2:학생용 로그인 ");

   gotoxy(70,9);

   printf("0:종료");

   

   

   

   gotoxy(43,16);

   printf("┏━━━━━━━━━━━━┓");

   gotoxy(43,17);

   printf("┃            ┃");

   gotoxy(43,18);

   printf("┗━━━━━━━━━━━━┛");

   gotoxy(47,17);

   printf("입력 :");   

   gotoxy(54,17);

   scanf("%d",&sel);

   

   system("cls");

   

   

   switch(sel) {

   case 1 :

   while(count==0){

    gotoxy(24,8);

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");

   for(int i=9;i<21;i++) {

      gotoxy(24,i);

      printf("┃                                                   ┃");

   }

   gotoxy(24,21);

   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

    

    

   gotoxy(41,9);

   printf("┏━━━━━━━━━━━━━━━━━━┓");

   gotoxy(41,10);

   printf("┃                  ┃");

   gotoxy(41,11);

   printf("┗━━━━━━━━━━━━━━━━━━┛");

   gotoxy(45,10);

   printf("교수용 로그인");

    TcLogin();

 }

    if(max_student==0){

    Initialize();// 최대 학생수 입력 기존 데이터 초기화 

}

    Start();//기본 메뉴 출력 및 시작 

    break;

   

   case 2 :

   while(1){

   gotoxy(24,8);

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");

   for(int i=9;i<21;i++) {

      gotoxy(24,i);

      printf("┃                                                   ┃");

   }

   gotoxy(24,21);

   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

 

 

   gotoxy(41,9);

   printf("┏━━━━━━━━━━━━━━━━━━┓");

   gotoxy(41,10);

   printf("┃                  ┃");

   gotoxy(41,11);

   printf("┗━━━━━━━━━━━━━━━━━━┛");

   gotoxy(45,10);

   printf("학생용 로그인");

   StuLogin();

   break;

}

   break;

   

   default :

   break;

}

 

   if(sel==0) {

   gotoxy(40,10);

    printf("프로그램 종료");

    gotoxy(40,30);

    printf("\n");

    count=2;

      return 0;

   }

 

}

    Exit();//종료하기 전에 할당한 메모리 해제

    return 0;

 

}

 

int StuLogin() {

   

   int number;   

   

   gotoxy(35,14);

   printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");

   gotoxy(35,15);

   printf("┃                              ┃");

   gotoxy(35,16);

   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

   gotoxy(38,15);

   printf("학번 입력 : ");

   scanf("%d",&number);

   

   if(Check_Std_number(number-18021000)==0)//유효한 번호가 아닐 때

    {

       system("cls"); 

       gotoxy(35,10);

        printf("학번이 올바르지 않습니다.\n");

        

        Sleep(1000);   //화면 잠시 정지 

        system("cls");   //화면 지우기

        

        return 0; 

    }

    

    system("cls");

    printf("번호\t이름\t국어\t영어\t수학\t평균\t등급\n");

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

   printf("┏━━━━━━━━━━━━━━━━━━━━━━━━┓");

   gotoxy(38,15);

   printf("┃                        ┃");

   gotoxy(38,16);

   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━┛");

    gotoxy(42,15);

    printf("ID : ");

    scanf("%s",iid);

    gotoxy(38,17);

   printf("┏━━━━━━━━━━━━━━━━━━━━━━━━┓");

   gotoxy(38,18);

   printf("┃                        ┃");

   gotoxy(38,19);

   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━┛");

    gotoxy(42,18);

    printf("Password : ");

     while(1){

          key = getch();

          if(key == 13){ // 엔터시 종료 

             key = 0;

             break;

         }

         else if(key == '\b'){// 백스페이스 설정 

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

       printf("로그인 성공!");

      

      Sleep(1000);   //화면 잠시 정지 

        system("cls");   //화면 지우기

        count=1;

   }

   else {

      gotoxy(40,10);

      printf("로그인 실패!");  

      cnt=0;

      Sleep(1000);   //화면 잠시 정지 

        system("cls");   //화면 지우기 

       

   }

 }

 

void Initialize()

{

    

    gotoxy(40,10);

    printf("최대 학생 수: ");

    scanf("%d",&max_student);

 

    system("cls");   //화면 지우기 

 

    A = (Student **)malloc(max_student*sizeof(Student *));//동적 배열 메모리 할당   malloc = 인자로 전달된 크기의 바이트 수 만큼 메모리 공간을 만듬

    memset(A,0,max_student*sizeof(Student *));//메모리 초기화(A 배열에 시작주소부터 max_student*sizeof(Student *)바이트 크기만큼 1바이트 단위로 0으로 설정)

}

 

void Start()

{

    int select = 0;

    while((select = Menu())!=0)//선택한 메뉴가 0이 아니면 반복

    {

        switch(select)//선택한 키에 따라 기능 수행

        {

        case 1: AddStd(); break;

        case 2: Modify(); break; 

        case 3: RemoveStd(); break;

        case 4: FindStd(); break;

        case 5: ListStd(); break;

        default:

        gotoxy(38,15);

      printf("잘못 선택하였습니다.\n"); Sleep(1000); system("cls"); break;

        }        

    }

    gotoxy(35,8);

    printf("로그인 화면으로 이동합니다.");

    gotoxy(40,30);

    printf("\n");

    Sleep(500);

    system("cls");

}

 

int Menu()

{    

 

    int select=0;

    

    gotoxy(24,8);

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");

    for(int i=9;i<27;i++) {

      gotoxy(24,i);

      printf("┃                                                   ┃");

    }

    gotoxy(24,27);

    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

    gotoxy(24,10);

   printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");

    gotoxy(42,9);

    printf("성적 관리 프로그램 ");

    gotoxy(67,9);

    printf("로그인:0");

    

    gotoxy(26,11);

   printf("┏━━━━━━━━━━━━━━━━━━━━━┓");

   gotoxy(26,12);

   printf("┃                     ┃");

   gotoxy(26,13);

   printf("┗━━━━━━━━━━━━━━━━━━━━━┛");  

    gotoxy(29,12);

    printf("학생 데이터 입력:1");

 

gotoxy(52,11); 

   printf("┏━━━━━━━━━━━━━━━━━━━━━┓");

   gotoxy(52,12);

   printf("┃                     ┃");

   gotoxy(52,13);

   printf("┗━━━━━━━━━━━━━━━━━━━━━┛");

   gotoxy(55,12);

    printf("학생 데이터 수정:2");

    

   gotoxy(26,14);

   printf("┏━━━━━━━━━━━━━━━━━━━━━┓");

   gotoxy(26,15);

   printf("┃                     ┃");

   gotoxy(26,16);

   printf("┗━━━━━━━━━━━━━━━━━━━━━┛");

    gotoxy(29,15);

    printf("학생 데이터 삭제:3");

    

    gotoxy(52,14);

   printf("┏━━━━━━━━━━━━━━━━━━━━━┓");

   gotoxy(52,15);

   printf("┃                     ┃");

   gotoxy(52,16);

   printf("┗━━━━━━━━━━━━━━━━━━━━━┛");

    gotoxy(59,15);

    printf("학생 검색:4 ");

    

    gotoxy(26,17);

   printf("┏━━━━━━━━━━━━━━━━━━━━━┓");

   gotoxy(26,18);

   printf("┃                     ┃");

   gotoxy(26,19);

   printf("┗━━━━━━━━━━━━━━━━━━━━━┛");

    gotoxy(30,18);

    printf("전체 성적 확인:5");

    

    gotoxy(43,23);

   printf("┏━━━━━━━━━━━━━┓");

   gotoxy(43,24);

   printf("┃             ┃");

   gotoxy(43,25);

   printf("┗━━━━━━━━━━━━━┛");

    gotoxy(47,24);

    printf("입력 : ");

    scanf("%d",&select);

    system("cls");   //화면 지우기 

    

    

    return select;

}

 

void AddStd()

{

   kan=0;

    int number=0;

    Student *stu=0;

    int s=0;

    

    gotoxy(24,8);

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");

    for(int i=9;i<21;i++) {

      gotoxy(24,i);

      printf("┃                                                   ┃");

    }

    gotoxy(24,21);

    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

    gotoxy(24,10);

   printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");

   

    gotoxy(42,9);

   printf("성적 관리 프로그램");

    gotoxy(38,13);

    printf("추가할 학생 번호(1~%d): ",max_student);

    scanf("%d",&number);

    

    system("cls");   //화면 지우기 

    

    if(Check_Std_number(number)==0)//유효한 번호가 아닐 때

    {

       gotoxy(35,10);

        printf("범위를 벗어난 학생 번호입니다.\n");

        gotoxy(38,11);

        printf("선택 메뉴로 넘어갑니다.\n");

        

        Sleep(2000);   //화면 잠시 정지 

        system("cls");   //화면 지우기 

        return;

    }

 

    if(A[number-1])//학생 데이터가 있다면

    {

       gotoxy(35,10);

        printf("이미 추가하였습니다\n");

        gotoxy(35,11);

        printf("선택 메뉴로 넘어갑니다.\n");

        

        Sleep(2000);   //화면 잠시 정지 

        system("cls");   //화면 지우기 

        return;

    }

 

    

    stu = (Student *)malloc(sizeof(Student));//학생 구조체 동적 메모리 할당

    A[number-1] = stu;//할당한 메모리 주소를 배열에 설정    

    stu->number = number;

    

    gotoxy(24,8);

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");

    for(int i=9;i<21;i++) {

      gotoxy(24,i);

      printf("┃                                                   ┃");

    }

    gotoxy(24,21);

    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

    gotoxy(24,10);

   printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");

   

    gotoxy(42,9);

   printf("성적 관리 프로그램");

   

    gotoxy(43,12);

    printf("이름 :     ");

    scanf("%s",stu->name,sizeof(stu->name));

 

    for(s=0;s<MAX_SUBJECT;s++)

    {

       gotoxy(43,13+s);

        printf("%s 성적:    ",SUB_TITLE[s]);

        scanf("%d",stu->scores+s);

       

        if(Check_Std_Score(stu->scores[s])==0)//유효한 성적이 아닐 때

        {

            stu->scores[s]=0;

            gotoxy(20,1+s);

            printf("입력한 성적이 유효하지 않아서 %s 성적은 0처리 하였습니다.\n",SUB_TITLE[s]);

        }

    }

    Sleep(500);

    system("cls"); //화면 지우기 

    

        gotoxy(38,10);

        printf("입력을 완료했습니다.\n");

        gotoxy(37,12);

        printf("선택 메뉴로 넘어갑니다.\n");

        

        Sleep(1000);   //화면 잠시 정지 

        system("cls");   //화면 지우기 

      

   RankStd(number-1);

   SubRank(number-1);

}

 

void Modify()

{   

 

    int number=0;

    int sel; 

    int jum;

    

    gotoxy(24,8);

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");

    for(int i=9;i<21;i++) {

      gotoxy(24,i);

      printf("┃                                                   ┃");

    }

    gotoxy(24,21);

    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

    gotoxy(24,10);

   printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");

   

    gotoxy(42,9);

   printf("성적 관리 프로그램");

    gotoxy(38,13);

    printf("수정할 학생 번호(1~%d): ",max_student);

    scanf("%d",&number);

 

    system("cls"); //화면 지우기 

  

    if(Check_Std_number(number)==0)//유효한 번호가 아닐 때

    {

        gotoxy(35,10);

        printf("범위를 벗어난 학생 번호입니다.\n");

        gotoxy(38,11);

        printf("선택 메뉴로 넘어갑니다.\n");

        

        Sleep(1000);   //화면 잠시 정지 

        system("cls");   //화면 지우기

        

        return;

    }

 

    if(A[number-1]==0)//학생 데이터가 없을 때

    {

        gotoxy(38,10);

        printf("데이터가 없습니다.\n");

        gotoxy(35,11);

        printf("선택 메뉴로 넘어갑니다.\n");

        

        Sleep(1000);   //화면 잠시 정지 

        system("cls");   //화면 지우기

        

        return;

    }

    

    gotoxy(42,9);

    printf("성적 관리 프로그램");

    

    gotoxy(24,8);

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");

    for(int i=9;i<21;i++) {

      gotoxy(24,i);

      printf("┃                                                   ┃");

    }

    gotoxy(24,21);

    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

    gotoxy(24,10);

   printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");

   

   

   gotoxy(37,11);

   printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓");

   gotoxy(37,12);

   printf("┃                          ┃");

   gotoxy(37,13);

   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

   gotoxy(39,12);

      printf("국어: 1 영어 : 2 수학 : 3\n");

   

   gotoxy(43,16);

   printf("┏━━━━━━━━━━━━━┓");

   gotoxy(43,17);

   printf("┃             ┃");

   gotoxy(43,18);

   printf("┗━━━━━━━━━━━━━┛");

   

   gotoxy(47,17);

    printf("입력 : "); 

   scanf("%d",&sel);

    

    system("cls");

    

    gotoxy(42,9);

    printf("성적 관리 프로그램");

    

    gotoxy(24,8);

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");

    for(int i=9;i<21;i++) {

      gotoxy(24,i);

      printf("┃                                                   ┃");

    }

    gotoxy(24,21);

    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

    gotoxy(24,10);

   printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");

   

   

   gotoxy(37,11);

   printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓");

   gotoxy(37,12);

   printf("┃                          ┃");

   gotoxy(37,13);

   printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

   gotoxy(39,12);

      printf("국어: 1 영어 : 2 수학 : 3\n");

   

   gotoxy(43,16);

   printf("┏━━━━━━━━━━━━━┓");

   gotoxy(43,17);

   printf("┃             ┃");

   gotoxy(43,18);

   printf("┗━━━━━━━━━━━━━┛");

    

      gotoxy(47,17);

      printf("점수 : ");

      scanf("%d",&jum);

      

    A[number-1]->scores[sel-1] = jum;

    RankStd(number-1);

    SubRank(number-1);

 

    system("cls");

    

    gotoxy(38,10);

    printf("수정하였습니다.\n");

    gotoxy(35,11);

    printf("선택 메뉴로 넘어갑니다.\n");

    

    Sleep(1000);   //화면 잠시 정지 

    system("cls");   //화면 지우기

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

    printf("삭제할 학생 번호(1~%d): ",max_student);

    scanf("%d",&number);

 

    system("cls"); //화면 지우기 

  

    if(Check_Std_number(number)==0)//유효한 번호가 아닐 때

    {

       gotoxy(35,10);

        printf("범위를 벗어난 학생 번호입니다.\n");

        gotoxy(38,11);

        printf("선택 메뉴로 넘어갑니다.\n");

        

        Sleep(1000);   //화면 잠시 정지 

        system("cls");   //화면 지우기

        

        return;

    }

 

    if(A[number-1]==0)//학생 데이터가 없을 때

    {

       gotoxy(38,10);

        printf("데이터가 없습니다.\n");

        gotoxy(35,11);

        printf("선택 메뉴로 넘어갑니다.\n");

        

        Sleep(1000);   //화면 잠시 정지 

        system("cls");   //화면 지우기

        

        return;

    }

 

    free(A[number-1]);//메모리 해제

    A[number-1] = 0;

 

    gotoxy(38,10);

    printf("삭제하였습니다.\n");

    gotoxy(35,11);

    printf("선택 메뉴로 넘어갑니다.\n");

    

    Sleep(1000);   //화면 잠시 정지 

    system("cls");   //화면 지우기

}

 

void FindStd()

{

   

    int number=0;    

    

    gotoxy(24,8);

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");

    for(int i=9;i<27;i++) {

      gotoxy(24,i);

      printf("┃                                                   ┃");

    }

    gotoxy(24,27);

    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

    gotoxy(24,10);

   printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");

   

    gotoxy(40,12);

    printf("검색할 학생 번호(1~%d): ",max_student);

    scanf("%d",&number);

 

   system("cls"); //화면 지우기 

 

    if(Check_Std_number(number)==0)//유효한 번호가 아닐 때

    {

       gotoxy(35,10);

        printf("범위를 벗어난 학생 번호입니다.\n");

        gotoxy(38,11);

        printf("선택 메뉴로 넘어갑니다.\n");

        

        Sleep(1000);   //화면 잠시 정지 

        system("cls");   //화면 지우기

        

        return;

    }

 

    if(A[number-1]==0)//학생 데이터가 없을 때

    {

       gotoxy(38,10);

        printf("데이터가 없습니다.\n");

        gotoxy(35,11);

        printf("선택 메뉴로 넘어갑니다.\n");

        

        Sleep(1000);   //화면 잠시 정지 

        system("cls");   //화면 지우기

        

        return;

    }

    

    printf("번호\t이름\t국어\t영어\t수학\t평균\t등급\n");

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

    

 

    printf("번호\t이름\t국어\t영어\t수학\t평균\t등급\n");

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

            free(A[i]);//메모리 해제

        }

    }

    free(A);//메모리 해제

}
