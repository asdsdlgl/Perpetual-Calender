#include<stdio.h>
#include<stdlib.h>
int monthname(int month){
        switch(month){			//將呼叫的月份名稱印出
                case 1:
                        printf(" January");
                        break;
                case 2:
                        printf(" February");
                        break;
                case 3:
                        printf(" March");
                        break;
                case 4:
                        printf(" April");
                        break;
                case 5:
                        printf(" May");
                        break;
                case 6:
                        printf(" June");
                        break;
                case 7:
                        printf(" July");
                        break;
                case 8:
                        printf(" August");
                        break;
                case 9:
                        printf(" September");
                        break;
                case 10:
                        printf(" October");
                        break;
                case 11:
                        printf(" November");
                        break;
                case 12:
                        printf(" December");
                        break;
        }
        printf("\n\n");
}
int main(int argc,char* argv[]){
     	int i,j,startyear=1900,
		year,month,day,monthday,totalday=0;
	int maxday[13] = 				{0,31,0,31,30,31,30,31,31,30,31,30,31};	//寫每月的最//大天數寫入陣列 且陣列0為0陣列2可能為 28或29
        int spaceday[13]={0};	//空白天預設為0
        year = atoi(argv[1]);
        if((year%400==0)||(year%100!=0)&&(year%4==0))
                maxday[2] = 29;	//閏年二月29天
        else
                maxday[2] = 28;	//非閏年28天
        for(i=startyear;i<year;i++){//從1900年開始跑
                                                                                                                                                   
                 for(month=1;month<=12;month++)//每個月
                        switch(month){//用一個totalday
	//算從1900年1月1號到目標年的前一年的12月31號的天數
                                case 1: case 3: case 5: case 7: case 8: case 10:                                                                                                           case 12:
                                        totalday += 31;
                                        break;
                                case 4: case 6: case 9: case 11:
                                        totalday += 30;
                                        break;
                                case 2:
                                        if((i%400==0)||(i%100!=0)&&(i%4==0))
                                                totalday += 29;
                                        else
                                                totalday += 28;
                                        break;
                                default :
                                        totalday += 0;
                                        break;
                }
        }
        spaceday[1] = (totalday+1)%7;//計算出目標年的空白天

        for(i=1;i<12;i++)	//1900年1月1號為周一所以加一
                spaceday[i+1] = (spaceday[i]+maxday[i])%7;
		//目標年的那年每月的空白天

        if(argc==2){	//如果只有輸入年沒月

        for(monthday=1;monthday<=12;monthday++){
                monthname(monthday);
                printf(" Sun Mon Tue Wed Thu Fri Sat\n");
                for(i=1;i<=spaceday[monthday];i++)
                        printf("    ");	//空白天印出
                for(i=1;i<=maxday[monthday];i++){
                        printf("%4d",i);	//數字1到最大天數印出
                        if(spaceday[monthday]==0&&i%7==0){
                                printf("\n");//判斷是否換行
                        }
                        else if(i%7==(7-(spaceday[monthday]%7)))	//判斷是否換行
                                        printf("\n");
                }
                printf("\n\n");
        }
        }else if(argc==3){//如果年月都有輸入
                                monthday = atoi(argv[2]);
                                monthname(monthday);
                                printf(" Sun Mon Tue Wed Thu Fri Sat\n");
                                for(i=1;i<=spaceday[monthday];i++)
                                        printf("    ");
                                for(i=1;i<=maxday[monthday];i++){
                                        printf("%4d",i);
                                        if(spaceday[monthday]==0&&i%7==0){
                                                printf("\n");
                                        }
                                        else if(i%7==(7-(spaceday[monthday]%7)))
                                                        printf("\n");
                                }
                                printf("\n\n");
        }
        printf("\n\n");
}

