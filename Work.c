#include <stdio.h>
#include <stdlib.h>
#include <time.h>		//為了寫出Random
#include <string.h>

typedef struct {		//定義
	int enter_num[7];	//宣告變數
}Lotto;


int main(int argc, char *argv[])
{				//主函式
 	char lotto1[49];	//宣告樂透號碼範圍
 	int n=0,a=0,b=0,i,j;	//宣告變數

 Lotto *ptr=NULL;		//指標
 ptr=(Lotto*)malloc(sizeof(Lotto));
 memset(ptr,0,sizeof(Lotto)); 	//動態配置記憶體
 while(scanf("%d",&ptr->enter_num[a]))//迴圈輸入變數
 {
  	a++;			//變數增加
  	if(getchar()=='\n'){
    break;			//如果遇到下一行就停止
 }
 }

 srand(time(NULL)); 		//RANDOM值
 printf("樂透號碼開獎中.....\n");

 for (i=0;i<49;i++)
 {
  	lotto1[i]=i+1;}     	// 用迴圈使陣列中數字增加
 for (i=0;i<=6;i++)
 {   				// 為做出樂透號碼1~6號
  int tmp;
  j=(rand()%49);		//從範圍1~49數字中隨機取出一位數字
  tmp=lotto1[i];
  lotto1[i]=lotto1[j];		//一維陣列
  lotto1[j]=tmp;
 }

 printf("中獎號碼如下:\n");
 for (i=0;i<6;i++)		//顯示1~6號
  printf("%d ",lotto1[i]);
 printf("特別號: %d\n", lotto1[6]);
  printf("中獎號碼:");
 for(i=0;i<7;i++) 		//找出輸入值(i)
 {
	for(j=0;j<7;j++)	//隨機跑出的7位數(j)
  {
   if(ptr->enter_num[i] == 0)
    break;
   else if(ptr->enter_num[i] == lotto1[j])
   {				//如輸入號碼與隨機號碼相符
    n++;
    printf("%d ",ptr->enter_num[i]); //用指標結構顯示出中獎號碼
   }
  }
 }

 if(n == 0) 			//n = 中獎號碼
 {
  printf("什麼都沒中");
 }

 return 0;
}
