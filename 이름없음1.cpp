#include <stdio.h>

#include <memory.h>

#include <stdlib.h>

#include <string.h>

#include <windows.h>

#include <conio.h>

 

#define MAX_NLEN    20 //譆渠 檜葷 望檜

#define MAX_SUBJECT 3 //婁跡 熱

 

struct Student {//з儅 掘褻羹 薑曖

    char name[MAX_NLEN+1];//檜葷

    int number; //з儅 廓��

    int scores[MAX_SUBJECT];//婁跡 薄熱 

    double savg;//ゎ敕 

    char* rank; //瞪羹 蛔晝 

    char* s_rank[3]; // 陝 婁跡 蛔晝 

    

};

 

 

const char *SUB_TITLE[MAX_SUBJECT]={"措橫","艙橫","熱з"};

 

 

Student **A; //檜醞 ん檣攪煎 掘褻羹 摹樹 (л熱 頂縑憮 諼睡縑 摹樹脹 л熱縑 蕾斬ж啪 ж晦 嬪п) 

int max_student=0; //з儅 熱 

int count=0;

int kan=0;

 

 

void Initialize();//譆渠 з儅熱 殮溘 塽  з儅 等檜攪 蟾晦�� 

void Start();

void Exit();//謙猿ж晦 瞪縑 й渡и 詭賅葬 п薯

void TcLogin();

int StuLogin();

 

int Menu();//詭景 轎溘 塽 摹鷗

void AddStd();//з儅 等檜攪 殮溘

int RankStd(int a);//瞪羹 蛔晝 虜菟晦

int SubRank(int m);// 婁跡 蛔晝 虜菟晦 

void RemoveStd();//з儅 等檜攪 餉薯

void FindStd();//з儅 匐儀

void ListStd();//跡煙 爾晦

void Modify();

 

void ViewStuData(Student *stu);//з儅 等檜攪 轎溘 

 

int Check_Std_number(int number);//嶸�褲� 廓��檣雖 っ滌

int Check_Std_Score(int score);//嶸�褲� 撩瞳檣雖 っ滌

 

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

      printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");

      for(int i=9;i<21;i++) {

      gotoxy(24,i);

      printf("早                                                   早");

   }

      gotoxy(24,21);

      printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

    gotoxy(24,10);

   printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽");

   gotoxy(42,9);

   printf("撩瞳 婦葬 Щ煎斜極");

   gotoxy(30,11);

   printf("旨收收收收收收收收收收收收收收收收收旬");

   gotoxy(30,12);

   printf("早                 早");

   gotoxy(30,13);

   printf("曲收收收收收收收收收收收收收收收收收旭");

   gotoxy(32,12);

   printf("1:掖熱辨 煎斜檣 ");

   gotoxy(53,11);

   printf("旨收收收收收收收收收收收收收收收收收旬");

   gotoxy(53,12);

   printf("早                 早");

   gotoxy(53,13);

   printf("曲收收收收收收收收收收收收收收收收收旭");

   gotoxy(55,12);

   printf("2:з儅辨 煎斜檣 ");

   gotoxy(70,9);

   printf("0:謙猿");

   

   

   

   gotoxy(43,16);

   printf("旨收收收收收收收收收收收收旬");

   gotoxy(43,17);

   printf("早            早");

   gotoxy(43,18);

   printf("曲收收收收收收收收收收收收旭");

   gotoxy(47,17);

   printf("殮溘 :");   

   gotoxy(54,17);

   scanf("%d",&sel);

   

   system("cls");

   

   

   switch(sel) {

   case 1 :

   while(count==0){

    gotoxy(24,8);

    printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");

   for(int i=9;i<21;i++) {

      gotoxy(24,i);

      printf("早                                                   早");

   }

   gotoxy(24,21);

   printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

    

    

   gotoxy(41,9);

   printf("旨收收收收收收收收收收收收收收收收收收旬");

   gotoxy(41,10);

   printf("早                  早");

   gotoxy(41,11);

   printf("曲收收收收收收收收收收收收收收收收收收旭");

   gotoxy(45,10);

   printf("掖熱辨 煎斜檣");

    TcLogin();

 }

    if(max_student==0){

    Initialize();// 譆渠 з儅熱 殮溘 晦襄 等檜攪 蟾晦�� 

}

    Start();//晦獄 詭景 轎溘 塽 衛濛 

    break;

   

   case 2 :

   while(1){

   gotoxy(24,8);

    printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");

   for(int i=9;i<21;i++) {

      gotoxy(24,i);

      printf("早                                                   早");

   }

   gotoxy(24,21);

   printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

 

 

   gotoxy(41,9);

   printf("旨收收收收收收收收收收收收收收收收收收旬");

   gotoxy(41,10);

   printf("早                  早");

   gotoxy(41,11);

   printf("曲收收收收收收收收收收收收收收收收收收旭");

   gotoxy(45,10);

   printf("з儅辨 煎斜檣");

   StuLogin();

   break;

}

   break;

   

   default :

   break;

}

 

   if(sel==0) {

   gotoxy(40,10);

    printf("Щ煎斜極 謙猿");

    gotoxy(40,30);

    printf("\n");

    count=2;

      return 0;

   }

 

}

    Exit();//謙猿ж晦 瞪縑 й渡и 詭賅葬 п薯

    return 0;

 

}

 

int StuLogin() {

   

   int number;   

   

   gotoxy(35,14);

   printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");

   gotoxy(35,15);

   printf("早                              早");

   gotoxy(35,16);

   printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

   gotoxy(38,15);

   printf("з廓 殮溘 : ");

   scanf("%d",&number);

   

   if(Check_Std_number(number-18021000)==0)//嶸�褲� 廓�ㄟ� 嬴棍 陽

    {

       system("cls"); 

       gotoxy(35,10);

        printf("з廓檜 螢夥腦雖 彊蝗棲棻.\n");

        

        Sleep(1000);   //�飛� 濡衛 薑雖 

        system("cls");   //�飛� 雖辦晦

        

        return 0; 

    }

    

    system("cls");

    printf("廓�αt檜葷\t措橫\t艙橫\t熱з\tゎ敕\t蛔晝\n");

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

   printf("旨收收收收收收收收收收收收收收收收收收收收收收收收旬");

   gotoxy(38,15);

   printf("早                        早");

   gotoxy(38,16);

   printf("曲收收收收收收收收收收收收收收收收收收收收收收收收旭");

    gotoxy(42,15);

    printf("ID : ");

    scanf("%s",iid);

    gotoxy(38,17);

   printf("旨收收收收收收收收收收收收收收收收收收收收收收收收旬");

   gotoxy(38,18);

   printf("早                        早");

   gotoxy(38,19);

   printf("曲收收收收收收收收收收收收收收收收收收收收收收收收旭");

    gotoxy(42,18);

    printf("Password : ");

     while(1){

          key = getch();

          if(key == 13){ // 縛攪衛 謙猿 

             key = 0;

             break;

         }

         else if(key == '\b'){// 寥蝶む檜蝶 撲薑 

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

       printf("煎斜檣 撩奢!");

      

      Sleep(1000);   //�飛� 濡衛 薑雖 

        system("cls");   //�飛� 雖辦晦

        count=1;

   }

   else {

      gotoxy(40,10);

      printf("煎斜檣 褒ぬ!");  

      cnt=0;

      Sleep(1000);   //�飛� 濡衛 薑雖 

        system("cls");   //�飛� 雖辦晦 

       

   }

 }

 

void Initialize()

{

    

    gotoxy(40,10);

    printf("譆渠 з儅 熱: ");

    scanf("%d",&max_student);

 

    system("cls");   //�飛� 雖辦晦 

 

    A = (Student **)malloc(max_student*sizeof(Student *));//翕瞳 寡翮 詭賅葬 й渡   malloc = 檣濠煎 瞪殖脹 觼晦曖 夥檜お 熱 虜躑 詭賅葬 奢除擊 虜蛟

    memset(A,0,max_student*sizeof(Student *));//詭賅葬 蟾晦��(A 寡翮縑 衛濛輿模睡攪 max_student*sizeof(Student *)夥檜お 觼晦虜躑 1夥檜お 欽嬪煎 0戲煎 撲薑)

}

 

void Start()

{

    int select = 0;

    while((select = Menu())!=0)//摹鷗и 詭景陛 0檜 嬴棲賊 奩犒

    {

        switch(select)//摹鷗и 酈縑 評塭 晦棟 熱ч

        {

        case 1: AddStd(); break;

        case 2: Modify(); break; 

        case 3: RemoveStd(); break;

        case 4: FindStd(); break;

        case 5: ListStd(); break;

        default:

        gotoxy(38,15);

      printf("澀跤 摹鷗ж艘蝗棲棻.\n"); Sleep(1000); system("cls"); break;

        }        

    }

    gotoxy(35,8);

    printf("煎斜檣 �飛橉虞� 檜翕м棲棻.");

    gotoxy(40,30);

    printf("\n");

    Sleep(500);

    system("cls");

}

 

int Menu()

{    

 

    int select=0;

    

    gotoxy(24,8);

    printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");

    for(int i=9;i<27;i++) {

      gotoxy(24,i);

      printf("早                                                   早");

    }

    gotoxy(24,27);

    printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

    gotoxy(24,10);

   printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽");

    gotoxy(42,9);

    printf("撩瞳 婦葬 Щ煎斜極 ");

    gotoxy(67,9);

    printf("煎斜檣:0");

    

    gotoxy(26,11);

   printf("旨收收收收收收收收收收收收收收收收收收收收收旬");

   gotoxy(26,12);

   printf("早                     早");

   gotoxy(26,13);

   printf("曲收收收收收收收收收收收收收收收收收收收收收旭");  

    gotoxy(29,12);

    printf("з儅 等檜攪 殮溘:1");

 

gotoxy(52,11); 

   printf("旨收收收收收收收收收收收收收收收收收收收收收旬");

   gotoxy(52,12);

   printf("早                     早");

   gotoxy(52,13);

   printf("曲收收收收收收收收收收收收收收收收收收收收收旭");

   gotoxy(55,12);

    printf("з儅 等檜攪 熱薑:2");

    

   gotoxy(26,14);

   printf("旨收收收收收收收收收收收收收收收收收收收收收旬");

   gotoxy(26,15);

   printf("早                     早");

   gotoxy(26,16);

   printf("曲收收收收收收收收收收收收收收收收收收收收收旭");

    gotoxy(29,15);

    printf("з儅 等檜攪 餉薯:3");

    

    gotoxy(52,14);

   printf("旨收收收收收收收收收收收收收收收收收收收收收旬");

   gotoxy(52,15);

   printf("早                     早");

   gotoxy(52,16);

   printf("曲收收收收收收收收收收收收收收收收收收收收收旭");

    gotoxy(59,15);

    printf("з儅 匐儀:4 ");

    

    gotoxy(26,17);

   printf("旨收收收收收收收收收收收收收收收收收收收收收旬");

   gotoxy(26,18);

   printf("早                     早");

   gotoxy(26,19);

   printf("曲收收收收收收收收收收收收收收收收收收收收收旭");

    gotoxy(30,18);

    printf("瞪羹 撩瞳 �挫�:5");

    

    gotoxy(43,23);

   printf("旨收收收收收收收收收收收收收旬");

   gotoxy(43,24);

   printf("早             早");

   gotoxy(43,25);

   printf("曲收收收收收收收收收收收收收旭");

    gotoxy(47,24);

    printf("殮溘 : ");

    scanf("%d",&select);

    system("cls");   //�飛� 雖辦晦 

    

    

    return select;

}

 

void AddStd()

{

   kan=0;

    int number=0;

    Student *stu=0;

    int s=0;

    

    gotoxy(24,8);

    printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");

    for(int i=9;i<21;i++) {

      gotoxy(24,i);

      printf("早                                                   早");

    }

    gotoxy(24,21);

    printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

    gotoxy(24,10);

   printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽");

   

    gotoxy(42,9);

   printf("撩瞳 婦葬 Щ煎斜極");

    gotoxy(38,13);

    printf("蹺陛й з儅 廓��(1~%d): ",max_student);

    scanf("%d",&number);

    

    system("cls");   //�飛� 雖辦晦 

    

    if(Check_Std_number(number)==0)//嶸�褲� 廓�ㄟ� 嬴棍 陽

    {

       gotoxy(35,10);

        printf("彰嬪蒂 慇橫陪 з儅 廓��殮棲棻.\n");

        gotoxy(38,11);

        printf("摹鷗 詭景煎 剩橫骨棲棻.\n");

        

        Sleep(2000);   //�飛� 濡衛 薑雖 

        system("cls");   //�飛� 雖辦晦 

        return;

    }

 

    if(A[number-1])//з儅 等檜攪陛 氈棻賊

    {

       gotoxy(35,10);

        printf("檜嘐 蹺陛ж艘蝗棲棻\n");

        gotoxy(35,11);

        printf("摹鷗 詭景煎 剩橫骨棲棻.\n");

        

        Sleep(2000);   //�飛� 濡衛 薑雖 

        system("cls");   //�飛� 雖辦晦 

        return;

    }

 

    

    stu = (Student *)malloc(sizeof(Student));//з儅 掘褻羹 翕瞳 詭賅葬 й渡

    A[number-1] = stu;//й渡и 詭賅葬 輿模蒂 寡翮縑 撲薑    

    stu->number = number;

    

    gotoxy(24,8);

    printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");

    for(int i=9;i<21;i++) {

      gotoxy(24,i);

      printf("早                                                   早");

    }

    gotoxy(24,21);

    printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

    gotoxy(24,10);

   printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽");

   

    gotoxy(42,9);

   printf("撩瞳 婦葬 Щ煎斜極");

   

    gotoxy(43,12);

    printf("檜葷 :     ");

    scanf("%s",stu->name,sizeof(stu->name));

 

    for(s=0;s<MAX_SUBJECT;s++)

    {

       gotoxy(43,13+s);

        printf("%s 撩瞳:    ",SUB_TITLE[s]);

        scanf("%d",stu->scores+s);

       

        if(Check_Std_Score(stu->scores[s])==0)//嶸�褲� 撩瞳檜 嬴棍 陽

        {

            stu->scores[s]=0;

            gotoxy(20,1+s);

            printf("殮溘и 撩瞳檜 嶸�褲狫� 彊嬴憮 %s 撩瞳擎 0籀葬 ж艘蝗棲棻.\n",SUB_TITLE[s]);

        }

    }

    Sleep(500);

    system("cls"); //�飛� 雖辦晦 

    

        gotoxy(38,10);

        printf("殮溘擊 諫猿ц蝗棲棻.\n");

        gotoxy(37,12);

        printf("摹鷗 詭景煎 剩橫骨棲棻.\n");

        

        Sleep(1000);   //�飛� 濡衛 薑雖 

        system("cls");   //�飛� 雖辦晦 

      

   RankStd(number-1);

   SubRank(number-1);

}

 

void Modify()

{   

 

    int number=0;

    int sel; 

    int jum;

    

    gotoxy(24,8);

    printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");

    for(int i=9;i<21;i++) {

      gotoxy(24,i);

      printf("早                                                   早");

    }

    gotoxy(24,21);

    printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

    gotoxy(24,10);

   printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽");

   

    gotoxy(42,9);

   printf("撩瞳 婦葬 Щ煎斜極");

    gotoxy(38,13);

    printf("熱薑й з儅 廓��(1~%d): ",max_student);

    scanf("%d",&number);

 

    system("cls"); //�飛� 雖辦晦 

  

    if(Check_Std_number(number)==0)//嶸�褲� 廓�ㄟ� 嬴棍 陽

    {

        gotoxy(35,10);

        printf("彰嬪蒂 慇橫陪 з儅 廓��殮棲棻.\n");

        gotoxy(38,11);

        printf("摹鷗 詭景煎 剩橫骨棲棻.\n");

        

        Sleep(1000);   //�飛� 濡衛 薑雖 

        system("cls");   //�飛� 雖辦晦

        

        return;

    }

 

    if(A[number-1]==0)//з儅 等檜攪陛 橈擊 陽

    {

        gotoxy(38,10);

        printf("等檜攪陛 橈蝗棲棻.\n");

        gotoxy(35,11);

        printf("摹鷗 詭景煎 剩橫骨棲棻.\n");

        

        Sleep(1000);   //�飛� 濡衛 薑雖 

        system("cls");   //�飛� 雖辦晦

        

        return;

    }

    

    gotoxy(42,9);

    printf("撩瞳 婦葬 Щ煎斜極");

    

    gotoxy(24,8);

    printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");

    for(int i=9;i<21;i++) {

      gotoxy(24,i);

      printf("早                                                   早");

    }

    gotoxy(24,21);

    printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

    gotoxy(24,10);

   printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽");

   

   

   gotoxy(37,11);

   printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收旬");

   gotoxy(37,12);

   printf("早                          早");

   gotoxy(37,13);

   printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

   gotoxy(39,12);

      printf("措橫: 1 艙橫 : 2 熱з : 3\n");

   

   gotoxy(43,16);

   printf("旨收收收收收收收收收收收收收旬");

   gotoxy(43,17);

   printf("早             早");

   gotoxy(43,18);

   printf("曲收收收收收收收收收收收收收旭");

   

   gotoxy(47,17);

    printf("殮溘 : "); 

   scanf("%d",&sel);

    

    system("cls");

    

    gotoxy(42,9);

    printf("撩瞳 婦葬 Щ煎斜極");

    

    gotoxy(24,8);

    printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");

    for(int i=9;i<21;i++) {

      gotoxy(24,i);

      printf("早                                                   早");

    }

    gotoxy(24,21);

    printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

    gotoxy(24,10);

   printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽");

   

   

   gotoxy(37,11);

   printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收旬");

   gotoxy(37,12);

   printf("早                          早");

   gotoxy(37,13);

   printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

   gotoxy(39,12);

      printf("措橫: 1 艙橫 : 2 熱з : 3\n");

   

   gotoxy(43,16);

   printf("旨收收收收收收收收收收收收收旬");

   gotoxy(43,17);

   printf("早             早");

   gotoxy(43,18);

   printf("曲收收收收收收收收收收收收收旭");

    

      gotoxy(47,17);

      printf("薄熱 : ");

      scanf("%d",&jum);

      

    A[number-1]->scores[sel-1] = jum;

    RankStd(number-1);

    SubRank(number-1);

 

    system("cls");

    

    gotoxy(38,10);

    printf("熱薑ж艘蝗棲棻.\n");

    gotoxy(35,11);

    printf("摹鷗 詭景煎 剩橫骨棲棻.\n");

    

    Sleep(1000);   //�飛� 濡衛 薑雖 

    system("cls");   //�飛� 雖辦晦

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

    printf("餉薯й з儅 廓��(1~%d): ",max_student);

    scanf("%d",&number);

 

    system("cls"); //�飛� 雖辦晦 

  

    if(Check_Std_number(number)==0)//嶸�褲� 廓�ㄟ� 嬴棍 陽

    {

       gotoxy(35,10);

        printf("彰嬪蒂 慇橫陪 з儅 廓��殮棲棻.\n");

        gotoxy(38,11);

        printf("摹鷗 詭景煎 剩橫骨棲棻.\n");

        

        Sleep(1000);   //�飛� 濡衛 薑雖 

        system("cls");   //�飛� 雖辦晦

        

        return;

    }

 

    if(A[number-1]==0)//з儅 等檜攪陛 橈擊 陽

    {

       gotoxy(38,10);

        printf("等檜攪陛 橈蝗棲棻.\n");

        gotoxy(35,11);

        printf("摹鷗 詭景煎 剩橫骨棲棻.\n");

        

        Sleep(1000);   //�飛� 濡衛 薑雖 

        system("cls");   //�飛� 雖辦晦

        

        return;

    }

 

    free(A[number-1]);//詭賅葬 п薯

    A[number-1] = 0;

 

    gotoxy(38,10);

    printf("餉薯ж艘蝗棲棻.\n");

    gotoxy(35,11);

    printf("摹鷗 詭景煎 剩橫骨棲棻.\n");

    

    Sleep(1000);   //�飛� 濡衛 薑雖 

    system("cls");   //�飛� 雖辦晦

}

 

void FindStd()

{

   

    int number=0;    

    

    gotoxy(24,8);

    printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");

    for(int i=9;i<27;i++) {

      gotoxy(24,i);

      printf("早                                                   早");

    }

    gotoxy(24,27);

    printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

    gotoxy(24,10);

   printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽");

   

    gotoxy(40,12);

    printf("匐儀й з儅 廓��(1~%d): ",max_student);

    scanf("%d",&number);

 

   system("cls"); //�飛� 雖辦晦 

 

    if(Check_Std_number(number)==0)//嶸�褲� 廓�ㄟ� 嬴棍 陽

    {

       gotoxy(35,10);

        printf("彰嬪蒂 慇橫陪 з儅 廓��殮棲棻.\n");

        gotoxy(38,11);

        printf("摹鷗 詭景煎 剩橫骨棲棻.\n");

        

        Sleep(1000);   //�飛� 濡衛 薑雖 

        system("cls");   //�飛� 雖辦晦

        

        return;

    }

 

    if(A[number-1]==0)//з儅 等檜攪陛 橈擊 陽

    {

       gotoxy(38,10);

        printf("等檜攪陛 橈蝗棲棻.\n");

        gotoxy(35,11);

        printf("摹鷗 詭景煎 剩橫骨棲棻.\n");

        

        Sleep(1000);   //�飛� 濡衛 薑雖 

        system("cls");   //�飛� 雖辦晦

        

        return;

    }

    

    printf("廓�αt檜葷\t措橫\t艙橫\t熱з\tゎ敕\t蛔晝\n");

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

    

 

    printf("廓�αt檜葷\t措橫\t艙橫\t熱з\tゎ敕\t蛔晝\n");

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

            free(A[i]);//詭賅葬 п薯

        }

    }

    free(A);//詭賅葬 п薯

}
