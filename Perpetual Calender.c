#include<stdio.h>
#include<stdlib.h>
int monthname(int month){
        switch(month){			//�N�I�s������W�٦L�X
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
	int maxday[13] = 				{0,31,0,31,30,31,30,31,31,30,31,30,31};	//�g�C�몺��//�j�ѼƼg�J�}�C �B�}�C0��0�}�C2�i�ର 28��29
        int spaceday[13]={0};	//�ťդѹw�]��0
        year = atoi(argv[1]);
        if((year%400==0)||(year%100!=0)&&(year%4==0))
                maxday[2] = 29;	//�|�~�G��29��
        else
                maxday[2] = 28;	//�D�|�~28��
        for(i=startyear;i<year;i++){//�q1900�~�}�l�]
                                                                                                                                                   
                 for(month=1;month<=12;month++)//�C�Ӥ�
                        switch(month){//�Τ@��totalday
	//��q1900�~1��1����ؼЦ~���e�@�~��12��31�����Ѽ�
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
        spaceday[1] = (totalday+1)%7;//�p��X�ؼЦ~���ťդ�

        for(i=1;i<12;i++)	//1900�~1��1�����P�@�ҥH�[�@
                spaceday[i+1] = (spaceday[i]+maxday[i])%7;
		//�ؼЦ~�����~�C�몺�ťդ�

        if(argc==2){	//�p�G�u����J�~�S��

        for(monthday=1;monthday<=12;monthday++){
                monthname(monthday);
                printf(" Sun Mon Tue Wed Thu Fri Sat\n");
                for(i=1;i<=spaceday[monthday];i++)
                        printf("    ");	//�ťդѦL�X
                for(i=1;i<=maxday[monthday];i++){
                        printf("%4d",i);	//�Ʀr1��̤j�ѼƦL�X
                        if(spaceday[monthday]==0&&i%7==0){
                                printf("\n");//�P�_�O�_����
                        }
                        else if(i%7==(7-(spaceday[monthday]%7)))	//�P�_�O�_����
                                        printf("\n");
                }
                printf("\n\n");
        }
        }else if(argc==3){//�p�G�~�볣����J
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

