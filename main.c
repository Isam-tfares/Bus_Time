#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>

int CMPE(int n,char station[50][20],char bus[20][20])
{
    int p=-1;
    for(int i=0;i<20;i++)
    {
        if(strcmp(station[n-1],bus[i])==0)
           {
               p=i;
           }
    }
    return p;
}

int T(char temps[7],char tempsbus[60][6],int n,int plaque)
{
   int tempsreste,p=false;
   char temp[7];
   for (int i=0;i<n;i++)
    {
           if(strcmp(temps,tempsbus[0])<0){
             strcpy(temp,tempsbus[0]);
             p=true;
                break;
           }
            else if((strcmp(temps,tempsbus[i])>0) && (strcmp(temps,tempsbus[i+1])<0))
            {
                strcpy(temp,tempsbus[i+1]);
                p=true;
                break;
            }
            else if(strcmp(temps,tempsbus[i])==0){
                strcpy(temp,tempsbus[i]);
                p=true;
            }
    }
    if(p)
    tempsreste=((((((int)(temp[0])-48)*10)+((int)(temp[1])-48))*60)+(((int)(temp[3])-48)*10)+((int)(temp[4])-48))-((((((int)(temps[0])-48)*10)+((int)(temps[1])-48))*60)+(((int)(temps[3])-48)*10)+((int)(temps[4])-48))+plaque-1;
    else{
       char aide[]="23:59";
       tempsreste=((((((int)(aide[0])-48)*10)+((int)(aide[1])-48))*60)+(((int)(aide[3])-48)*10)+((int)(aide[4])-48))-((((((int)(temps[0])-48)*10)+((int)(temps[1])-48))*60)+(((int)(temps[3])-48)*10)+((int)(temps[4])-48))+plaque-1;
       char aided[]="00:00";
       strcpy(temp,tempsbus[0]);
        tempsreste+=((((((int)(temp[0])-48)*10)+((int)(temp[1])-48))*60)+(((int)(temp[3])-48)*10)+((int)(temp[4])-48))-((((((int)(aided[0])-48)*10)+((int)(aided[1])-48))*60)+(((int)(aided[3])-48)*10)+((int)(aided[4])-48));
    }
    return tempsreste;
}
void delay(int s)
{
    int ms=400*s;
    clock_t start_time = clock();
    while(clock()<start_time + ms);
}

int main()
{
    system("color f1");
int numerod,numeroa,depart,arrivee,i,j,plaque,choixcon,add,time;
//BUS 18
char BUS18sidibouzid[70][6]={{"08:01"},{"08:06"},{"08:12"},{"08:24"},{"08:36"},{"08:48"},{"09:01"},{"09:06"},{"09:12"},{"09:24"},{"09:36"},{"09:48"},{"10:01"},{"10:06"},{"10:12"},{"10:24"},{"10:36"},{"10:48"},{"11:01"},{"11:06"},{"11:12"},{"11:24"},{"11:36"},{"11:48"},{"12:01"},{"12:06"},{"12:12"},{"12:24"},{"12:36"},{"12:48"},{"13:01"},{"13:06"},{"13:12"},{"13:24"},{"13:36"},{"13:48"},{"14:01"},{"14:06"},{"14:12"},{"14:24"},{"14:36"},{"14:48"},{"15:01"},{"15:06"},{"15:12"},{"15:24"},{"15:36"},{"15:48"},{"16:01"},{"16:06"},{"16:12"},{"16:24"},{"16:36"},{"16:48"},{"17:01"},{"17:06"},{"17:12"},{"17:24"},{"17:36"},{"17:48"},{"18:01"},{"18:06"},{"18:12"},{"18:24"},{"18:36"},{"18:48"}};
char BUS18COURSE[70][6]={{"07:30"},{"07:45"},{"08:06"},{"08:18"},{"08:25"},{"08:36"},{"08:48"},{"09:01"},{"09:12"},{"09:24"},{"09:36"},{"09:48"},{"10:01"},{"10:12"},{"10:24"},{"10:36"},{"10:48"},{"11:01"},{"11:12"},{"11:24"},{"11:36"},{"11:48"},{"12:01"},{"12:12"},{"12:24"},{"12:36"},{"12:48"},{"13:01"},{"13:12"},{"13.24"},{"13:36"},{"13:48"},{"14:01"},{"14:12"},{"14:24"},{"14:36"},{"14:48"},{"15:01"},{"15:12"},{"15:24"},{"15:36"},{"15:48"},{"16:01"},{"16:12"},{"16:24"},{"16:36"},{"16:48"},{"17:01"},{"17:12"},{"17:24"},{"17:36"},{"17:48"},{"18:01"},{"18:12"},{"18:24"},{"18:36"},{"18:48"},{"19:01"},{"19:20"},{"19:25"},{"19:30"},{"19:48"},{"20:12"}};
char BUS18ESSALAM_AZIBDARAI[60][6]={{"07:50"},{"08:10"},{"08:22"},{"08:34"},{"08:46"},{"08:58"},{"09:10"},{"09:22"},{"09:34"},{"09:46"},{"09:58"},{"10:10"},{"10:22"},{"10:34"},{"10:46"},{"10:58"},{"11:10"},{"11:22"},{"11:34"} ,{"11:46"},{"11:58"},{"12:10"},{"12:22"},{"12:34"},{"12:46"},{"12:58"},{"13:10"},{"13:22"},{"13:34"},{"13:46"},{"13:58"},{"14:10"},{"14:22"},{"14:34"},{"14:46"},{"14:58"},{"15:10"},{"15:22"},{"15:34"},{"15:46"},{"15:58"},{"16:10"},{"16:22"},{"16:34"},{"16:46"},{"16:58"},{"17:10"},{"17:22"},{"17:34"},{"17:46"},{"17:58"},{"18:10"},{"18:22"},{"18:34"},{"18:46"},{"18:58"},{"19:10"},{"19:25"},{"19:40"},{"20:05"}};
char BUS18MIFTAHKHEI_MARJAN[60][6]={{"07:43"},{"08:15"},{"08:27"},{"08:39"},{"08:51"},{"09:03"},{"09:15"},{"09:27"},{"09:39"},{"09:51"},{"10:03"},{"10:15"},{"10:27"},{"10:39"},{"10:51"},{"11:03"},{"11:15"},{"11:27"},{"11:39"},{"11:51"},{"12:03"},{"12:15"},{"12:27"},{"12:39"},{"12:51"},{"13:03"},{"13:15"},{"13:27"},{"13:39"},{"13:51"},{"14:03"},{"14:15"},{"14:27"},{"14:39"},{"14:51"},{"15:03"},{"15:15"},{"15:27"},{"15:39"},{"15:51"},{"16:03"},{"16:15"},{"16:27"},{"16:39"},{"16:51"},{"17:03"},{"17:15"},{"17:27"},{"17:39"},{"17:51"},{"18:03"},{"18:15"},{"18:27"},{"18:39"},{"18:51"},{"19:04"},{"19:15"},{"19:29"},{"19:45"},{"20:09"}};
char BUS18JRAIFAT[60][6]={{"07:38"},{"08:25"},{"08:37"},{"08:49"},{"08:59"},{"09:13"},{"09:25"},{"09:37"},{"09:49"},{"09:59"},{"10:13"},{"10:25"},{"10:37"},{"10:49"},{"10:59"},{"11:13"},{"11:25"},{"11:37"},{"11:49"},{"11:59"},{"12:13"},{"12:25"},{"12:37"},{"12:49"},{"12:59"},{"13:13"},{"13:25"},{"13:37"},{"13:49"},{"13:59"},{"14:13"},{"14:25"},{"14:37"},{"14:49"},{"14:59"},{"15:13"},{"15:25"},{"15:37"},{"15:49"},{"15:59"},{"16:13"},{"16:25"},{"16:37"},{"16:49"},{"16:59"},{"17:13"},{"17:25"},{"17:37"},{"17:49"},{"17:59"},{"18:13"},{"18:25"},{"18:37"},{"18:49"},{"18:59"},{"19:14"},{"19:25"},{"19:39"},{"19:55"},{"20:19"}};
//BUS 4
char BUS4sidibouzid[50][6]={{"07:30"},{"07:50"},{"08:08"},{"08:27"},{"08:45"},{"09:04"},{"09:24"},{"09:43"},{"10:03"},{"10:22"},{"10:42"},{"11:01"},{"11:22"},{"11:42"},{"12:02"},{"12:21"},{"12:43"},{"13:02"},{"13:10"},{"13:36"},{"14:03"},{"14:30"},{"14:56"},{"15:23"},{"15:50"},{"16:16"},{"16:43"},{"17:10"},{"17:36"},{"18:03"},{"18:32"},{"18:52"},{"19:19"},{"19:46"},{"20:12"}};
char BUS4OUADBACHAalle[50][6]={{"07:40"},{"08:00"},{"08:18"},{"08:37"},{"08:55"},{"09:14"},{"09:34"},{"09:53"},{"10:13"},{"10:32"},{"10:52"},{"11:11"},{"11:32"},{"11:52"},{"12:12"},{"12:31"},{"12:53"},{"13:12"},{"13:20"},{"13:46"},{"14:13"},{"14:40"},{"15:06"},{"15:33"},{"16:00"},{"16:26"},{"16:53"},{"17:20"},{"17:46"},{"18:13"},{"18:42"},{"19:02"},{"19:29"},{"19:56"},{"20:22"}};
char BUS4AVENUERABATalle[50][6]={{"07:50"},{"08:10"},{"08:28"},{"08:47"},{"09:05"},{"09:24"},{"09:44"},{"10:03"},{"10:23"},{"10:42"},{"11:02"},{"11:21"},{"11:42"},{"12:02"},{"12:22"},{"12:41"},{"13:03"},{"13:22"},{"13:30"},{"13:56"},{"14:23"},{"14:50"},{"15:16"},{"15:43"},{"16:10"},{"16:36"},{"17:03"},{"17:30"},{"17:56"},{"18:23"},{"18:52"},{"19:09"},{"19:35"},{"19:59"},{"20:29"}};
char BUS4CENTREVILLEalle[50][6]={{"08:00"},{"08:20"},{"08:38"},{"08:57"},{"09:15"},{"09:34"},{"09:54"},{"10:13"},{"10:33"},{"10:52"},{"11:12"},{"11:31"},{"11:52"},{"12:12"},{"12:32"},{"12:51"},{"13:13"},{"13:32"},{"13:40"},{"14:06"},{"14:33"},{"15:00"},{"15:26"},{"15:53"},{"16:20"},{"16:46"},{"17:13"},{"17:40"},{"18:06"},{"18:33"},{"19:00"},{"19:15"},{"19:39"},{"20:08"},{"20:37"}};
char BUS4COURSE[50][6]={{"07:15"},{"07:32"},{"07:50"},{"08:07"},{"08:25"},{"08:45"},{"09:05"},{"09:24"},{"09:44"},{"10:03"},{"10:23"},{"10:42"},{"11:02"},{"11:21"},{"11:42"},{"12:02"},{"12:22"},{"12:41"},{"13:03"},{"13:22"},{"13:30"},{"13:56"},{"14:23"},{"14:50"},{"15:16"},{"15:43"},{"16:10"},{"16:36"},{"17:03"},{"17:30"},{"17:56"},{"18:23"},{"18:52"},{"19:06"},{"19:32"},{"20:00"}};
char BUS4OUADBACHAretour[50][6]={{"07:45"},{"08:00"},{"08:20"},{"08:38"},{"08:57"},{"09:15"},{"09:34"},{"09:54"},{"10:13"},{"10:33"},{"10:52"},{"11:12"},{"11:31"},{"11:52"},{"12:12"},{"12:32"},{"12:51"},{"13:13"},{"13:32"},{"13:40"},{"14:06"},{"14:33"},{"15:00"},{"15:26"},{"15:53"},{"16:20"},{"16:46"},{"17:13"},{"17:40"},{"18:06"},{"18:33"},{"19:00"},{"19:12"},{"19:39"},{"20:09"}};
char BUS4AVENUERABATretour[50][6]={{"07:33"},{"08:50"},{"08:10"},{"08:28"},{"08:47"},{"09:05"},{"09:24"},{"09:44"},{"10:03"},{"10:33"},{"10:42"},{"11:02"},{"11:21"},{"11:42"},{"12:02"},{"12:22"},{"12:41"},{"13:03"},{"13:22"},{"13:30"},{"13:56"},{"14:23"},{"14:50"},{"15:16"},{"15:43"},{"16:10"},{"16:36"},{"17:03"},{"17:30"},{"17:56"},{"18:23"},{"18:50"},{"19:19"},{"19:30"},{"19:58"},{"20:25"}};
char BUS4CENTREVILLEretour[50][6]={{"07:25"},{"07:40"},{"08:00"},{"08:18"},{"08:35"},{"08:55"},{"09:14"},{"09:34"},{"09:53"},{"10:13"},{"10:32"},{"10:52"},{"11:11"},{"11:32"},{"11:52"},{"12:12"},{"12:31"},{"12:53"},{"13:12"},{"13:20"},{"13:46"},{"14:13"},{"14:40"},{"15:06"},{"15:33"},{"16:00"},{"16:26"},{"16:53"},{"17:20"},{"17:46"},{"18:13"},{"18:42"},{"19:12"},{"19:22"},{"19:47"},{"20:17"}};
char station[50][20]={{"SIDI BOUZID"},{"OAUD LBACHA"},{"MIFTAH LKHAIR"},{"AVENUS DE RABAT"},{"CENTRE VILLE"},{"MARJANE"},{"JRAIFAT"},{"COURSE"},{"AZIB DARAII"},{"HAY ESSALAM"}};
char stationBUS4[50][20]={{"SIDI BOUZID"},{"OAUD LBACHA"},{"AVENUS DE RABAT"},{"CENTRE VILLE"},{"COURSE"}};
char stationBUS18[50][20]={{"SIDI BOUZID"},{"HAY ESSALAM"},{"MIFTAH LKHAIR"},{"MARJANE"},{"AZIB DARAII"},{"JRAIFAT"},{"COURSE"}};
char temps[7];
    delay(2);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t******************************************************************************************************************************************************\n");
    delay(0.5);
    printf("\t\t******************************************************************************************************************************************************\n");
   delay(1);
    printf("\t\t**                                                                                                                                                  **\n");
   delay(1);
    printf("\t\t**      ********         *******   ****          ****     ****                                 ****      *******            ****         ****       **\n");
   delay(1);
    printf("\t\t**      *********       ********    ****        ****       ****                               ****      **** ****            ****       ****        **\n");
    delay(1);
    printf("\t\t**      ****  ****     **** ****     ****      ****         ****                             ****      ****   ****            ****     ****         **\n");
   delay(1);
    printf("\t\t**      ****   ****   ****  ****      ****    ****           ****                           ****      ****     ****            ****   ****          **\n");
    delay(1);
    printf("\t\t**      ****    **** ****   ****       ****  ****             ****          *****          ****      ****       ****            **** ****           **\n");
   delay(1);
    printf("\t\t**      ****     *******    ****        ********               ****        *******        ****      *****************            *******            **\n");
    delay(1);
    printf("\t\t**      ****      *****     ****         *****                  ****      **** ****      ****      *******************           *****              **\n");
    delay(1);
    printf("\t\t**      ****       ***      ****         ****                    ****    ****   ****    ****      ****             ****          ****               **\n");
   delay(1);
    printf("\t\t**      ****                ****        ****                      ****  ****     ****  ****      ****               ****        ****                **\n");
    delay(1);
    printf("\t\t**      ****                ****       ****                        ********       ********      ****                 ****      ****                 **\n");
    delay(1);
    printf("\t\t**      ****                ****      ****                          ******         ******      ****                   ****    ****                  **\n");
    delay(1);
    printf("\t\t**                                                                                                                                                  **\n");
    delay(1);
    printf("\t\t******************************************************************************************************************************************************\n");
     delay(1);
    printf("\t\t******************************************************************************************************************************************************\n");
    delay(1);
    delay(1);
    do{
            do{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t     --> STATION <--   \n");
    printf("\t\t\t\t\t\t\t\t\t\t\t _______________________\n");
    for (i=0;i<5;i++)
    {
        printf("\t\t\t\t\t\t\t\t\t\t\t| %d --> %s\t|\n",i+1,station[i]);
    }
    printf("\t\t\t\t\t\t\t\t\t\t\t| 6 --> MARJANE         |\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t| 7 --> JRAIFAT         |\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t| 8 --> COURSE          |\n");
    for (i=8;i<10;i++)
    {
        printf("\t\t\t\t\t\t\t\t\t\t\t| %d --> %s\t|\n",i+1,station[i]);
    }
    printf("\t\t\t\t\t\t\t\t\t\t\t|_______________________|");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t       ENTRER LE STATION DE DEPART : ");
    scanf("%d",&numerod);

            }while(numerod>10 || numerod<=0);
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t ENTRER LE TEMPS ACTUELLE (AVEC CETTE FORMAT  [][]:[][]) : ");
    scanf("%s",&temps);
    system("cls");
    do{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t     --> STATION <--   \n");
    printf("\t\t\t\t\t\t\t\t\t\t\t _______________________\n");
    for (i=0,j=1;i<5;i++)
    {
        if((i+1)!=numerod)
        printf("\t\t\t\t\t\t\t\t\t\t\t| %d --> %s\t|\n",j,station[i]);
        j++;
    }
    printf("\t\t\t\t\t\t\t\t\t\t\t| 6 --> MARJANE         |\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t| 7 --> JRAIFAT         |\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t| 8 --> COURSE          |\n");
    for (i=8,j=9;i<10;i++)
    {
        if((i+1)!=numerod)
        printf("\t\t\t\t\t\t\t\t\t\t\t| %d --> %s\t|\n",j,station[i]);
        j++;
    }
    printf("\t\t\t\t\t\t\t\t\t\t\t|_______________________|");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t       ENTRER LE STATION D'ARRIVEE : ");
    scanf("%d",&numeroa);
    system("cls");
    }while(numeroa>10 || numeroa<=0 || numeroa==numerod);
    do{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t  ENTRER LE NUMERO DU PLAQUE OU VOUS ETES : ");
    scanf("%d",&plaque);
    system("cls");
    }while(plaque<1 || plaque>10);
    //BUS 4
    depart=CMPE(numerod,station,stationBUS4);
    arrivee=CMPE(numeroa,station,stationBUS4);
    if (-1<arrivee && depart>-1)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t         ______________________\n");
        printf("\t\t\t\t\t\t\t\t\t\t        | BUS 4 EST DISPONIBLE |\n");
        printf("\t\t\t\t\t\t\t\t\t\t        |______________________|\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t  *** IL PASSE PAR ***\n");
        delay(1);
        if(depart<arrivee){
        for(i=depart+1;i<=arrivee;i++)
        {
            printf("\n\t\t\t\t\t\t\t\t\t\t\t %d --> %s \n",i-depart,stationBUS4[i]);
        }
        switch(depart)
        {
        case 0:
                printf("\n\t\t\t\t\t\t\t\t\t  ______________________________________________________");
                printf("\n\t\t\t\t\t\t\t\t\t | LE TEMPS RESTE POUR L'ARRIVATION DU BUS EST : %d min\t|\n",T(temps,BUS4sidibouzid,42,plaque));
                printf("\t\t\t\t\t\t\t\t\t |______________________________________________________|");
                break;
        case 1:
                printf("\n\t\t\t\t\t\t\t\t\t  ______________________________________________________");
                printf("\n\t\t\t\t\t\t\t\t\t | LE TEMPS RESTE POUR L'ARRIVATION DU BUS EST : %d min\t|\n",T(temps,BUS4OUADBACHAalle,42,plaque));
                printf("\t\t\t\t\t\t\t\t\t |______________________________________________________|");
                break;
        case 2:
                printf("\n\t\t\t\t\t\t\t\t\t  ______________________________________________________");
                printf("\n\t\t\t\t\t\t\t\t\t | LE TEMPS RESTE POUR L'ARRIVATION DU BUS EST : %d min\t|\n",T(temps,BUS4AVENUERABATalle,42,plaque));
                printf("\t\t\t\t\t\t\t\t\t |______________________________________________________|");
                break;
        case 3:
              printf("\n\t\t\t\t\t\t\t\t\t\t\t  ______________________________________________________");
              printf("\n\t\t\t\t\t\t\t\t\t\t\t | LE TEMPS RESTE POUR L'ARRIVATION DU BUS EST : %d min\t|\n",T(temps,BUS4CENTREVILLEalle,42,plaque));
              printf("\t\t\t\t\t\t\t\t\t\t\t |______________________________________________________|");
                break;
         }
    }
    else{
        for(i=depart-1;i>=arrivee;i--)
        {
            printf("\n\t\t\t\t\t\t\t\t\t\t\t %d --> %s \n",depart-i,stationBUS4[i]);
        }
        switch(depart)
        {
        case 1:
                printf("\n\t\t\t\t\t\t\t\t\t  ______________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t\t | LE TEMPS RESTE POUR L'ARRIVATION DU BUS EST : %d min\t|\n",T(temps,BUS4OUADBACHAretour,42,plaque));
                printf("\t\t\t\t\t\t\t\t\t |______________________________________________________|");
                break;
        case 2:
                printf("\n\t\t\t\t\t\t\t\t\t\t\t  ______________________________________________________");
                printf("\n\t\t\t\t\t\t\t\t\t | LE TEMPS RESTE POUR L'ARRIVATION DU BUS EST : %d min\t|\n",T(temps,BUS4AVENUERABATretour,42,plaque));
                printf("\t\t\t\t\t\t\t\t\t |______________________________________________________|");
                break;
        case 3:
                printf("\n\t\t\t\t\t\t\t\t\t\t\t  ______________________________________________________");
                printf("\n\t\t\t\t\t\t\t\t\t | LE TEMPS RESTE POUR L'ARRIVATION DU BUS EST : %d min\t|\n",T(temps,BUS4CENTREVILLEretour,42,plaque));
                printf("\t\t\t\t\t\t\t\t\t |______________________________________________________|");
                break;
        case 4:
                printf("\n\t\t\t\t\t\t\t\t\t  ______________________________________________________");
                printf("\n\t\t\t\t\t\t\t\t\t | LE TEMPS RESTE POUR L'ARRIVATION DU BUS EST : %d min\t|\n",T(temps,BUS4COURSE,40,plaque));
                printf("\t\t\t\t\t\t\t\t\t |______________________________________________________|");
                break;
         }
    }
    }
    else{
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t  __________________________\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t | BUS 4 EST NON DISPONIBLE |\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t |__________________________|\n");
    }
    //BUS 18
    depart=CMPE(numerod,station,stationBUS18);
    arrivee=CMPE(numeroa,station,stationBUS18);
     if (-1<arrivee && depart>-1)
    {
        printf("\n\n\n\t\t\t\t\t\t\t\t\t\t         _______________________\n");
        printf("\t\t\t\t\t\t\t\t\t\t        | BUS 18 EST DISPONIBLE |\n");
        printf("\t\t\t\t\t\t\t\t\t\t        |_______________________|\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t  *** IL PASSE PAR ***\n");
        delay(1);
        if(depart<arrivee){
        for(i=depart+1;i<=arrivee;i++)
        {
            printf("\n\t\t\t\t\t\t\t\t\t\t\t %d --> %s \n",i-depart,stationBUS18[i]);
        }
        switch(depart)
        {
        case 0:
                printf("\n\t\t\t\t\t\t\t\t\t  ______________________________________________________");
                printf("\n\t\t\t\t\t\t\t\t\t | LE TEMPS RESTE POUR L'ARRIVATION DU BUS EST : %d min\t|\n",T(temps,BUS18sidibouzid,70,plaque));
                printf("\t\t\t\t\t\t\t\t\t |______________________________________________________|");
                break;
        case 1:
                printf("\n\t\t\t\t\t\t\t\t\t  ______________________________________________________");
                printf("\n\t\t\t\t\t\t\t\t\t | LE TEMPS RESTE POUR L'ARRIVATION DU BUS EST : %d min\t|\n",T(temps,BUS18ESSALAM_AZIBDARAI,60,plaque));
                printf("\t\t\t\t\t\t\t\t\t |______________________________________________________|");
                break;
        case 2:
                printf("\n\t\t\t\t\t\t\t\t\t  ______________________________________________________");
                printf("\n\t\t\t\t\t\t\t\t\t |LE TEMPS RESTE POUR L'ARRIVATION DU BUS EST : %d min\t|\n",T(temps,BUS18MIFTAHKHEI_MARJAN,60,plaque));
                printf("\t\t\t\t\t\t\t\t\t |______________________________________________________|");
                break;
        case 3:
                printf("\n\t\t\t\t\t\t\t\t\t  ______________________________________________________");
                printf("\n\t\t\t\t\t\t\t\t\t | LE TEMPS RESTE POUR L'ARRIVATION DU BUS EST : %d min\t|\n",T(temps,BUS18JRAIFAT,60,plaque));
                printf("\t\t\t\t\t\t\t\t\t |______________________________________________________|");
                break;
         case 4:
                printf("\n\t\t\t\t\t\t\t\t\t  ______________________________________________________");
                printf("\n\t\t\t\t\t\t\t\t\t | LE TEMPS RESTE POUR L'ARRIVATION DU BUS EST : %d min\t|\n",T(temps,BUS18MIFTAHKHEI_MARJAN,60,plaque));
                printf("\t\t\t\t\t\t\t\t\t |______________________________________________________|");
                break;
        case 5:
                printf("\n\t\t\t\t\t\t\t\t\t  ______________________________________________________");
                printf("\n\t\t\t\t\t\t\t\t\t | LE TEMPS RESTE POUR L'ARRIVATION DU BUS EST : %d min\t|\n",T(temps,BUS18ESSALAM_AZIBDARAI,60,plaque));
                printf("\t\t\t\t\t\t\t\t\t |______________________________________________________|");
                break;
         }
    }
    else{
        for(i=depart-1;i>=arrivee;i--)
        {
            printf("\n\t\t\t\t\t\t\t\t\t\t\t %d --> %s \n",depart-i,stationBUS18[i]);
        }
               switch(depart)
        {
        case 1:
                printf("\n\t\t\t\t\t\t\t\t\t  ______________________________________________________");
                printf("\n\t\t\t\t\t\t\t\t\t | LE TEMPS RESTE POUR L'ARRIVATION DU BUS EST : %d min\t|\n",T(temps,BUS18ESSALAM_AZIBDARAI,60,plaque));
                printf("\t\t\t\t\t\t\t\t\t |______________________________________________________|");
                break;
        case 2:
                printf("\n\t\t\t\t\t\t\t\t\t  ______________________________________________________");
                printf("\n\t\t\t\t\t\t\t\t\t | LE TEMPS RESTE POUR L'ARRIVATION DU BUS EST : %d min\t|\n",T(temps,BUS18MIFTAHKHEI_MARJAN,60,plaque));
                printf("\t\t\t\t\t\t\t\t\t |______________________________________________________|");
                break;
        case 3:
               printf("\n\t\t\t\t\t\t\t\t\t  ______________________________________________________");
               printf("\n\t\t\t\t\t\t\t\t\t | LE TEMPS RESTE POUR L'ARRIVATION DU BUS EST : %d min\t|\n",T(temps,BUS18JRAIFAT,60,plaque));
               printf("\t\t\t\t\t\t\t\t\t |______________________________________________________|");
               break;
        case 4:
                printf("\n\t\t\t\t\t\t\t\t\t  ______________________________________________________");
                printf("\n\t\t\t\t\t\t\t\t\t | LE TEMPS RESTE POUR L'ARRIVATION DU BUS EST : %d min\t|\n",T(temps,BUS18MIFTAHKHEI_MARJAN,60,plaque));
                printf("\t\t\t\t\t\t\t\t\t |______________________________________________________|");
                break;
        case 5:
                printf("\n\t\t\t\t\t\t\t\t\t  ______________________________________________________");
                printf("\n\t\t\t\t\t\t\t\t\t | LE TEMPS RESTE POUR L'ARRIVATION DU BUS EST : %d min\t|\n",T(temps,BUS18ESSALAM_AZIBDARAI,60,plaque));
                printf("\t\t\t\t\t\t\t\t\t |______________________________________________________|");
                break;
        case 6:
                printf("\n\t\t\t\t\t\t\t\t\t  ______________________________________________________");
                printf("\n\t\t\t\t\t\t\t\t\t | LE TEMPS RESTE POUR L'ARRIVATION DU BUS EST : %d min\t|\n",T(temps,BUS18COURSE,70,plaque));
                printf("\t\t\t\t\t\t\t\t\t |______________________________________________________|");
                break;
         }
    }
    }
    else{

        printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t  ___________________________\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t | BUS 18 EST NON DISPONIBLE |\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t |___________________________|\n");
    }
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t    _________________\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t   | 1 --> CONTINUER |\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t   | 2 --> QUITTER   |\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t   |_________________|\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t         SVP ENTRER VOTRE CHOIX : ");
        scanf("%d",&choixcon);
        system("cls");
    }while(choixcon == 1);
    system("color 0f");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
     for (int i=0;i<14;i++)
 {
     printf("\t\t\t\t\t\t\t");
     for(int j=0;j<98;j++)
     {
         printf("*");
     }
     printf("\n");
 }
 delay(1);
 system("cls");
 printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t************************************************************************************************\n");
 printf("\t\t\t\t\t************************************************************************************************\n");
 printf("\t\t\t\t\t**                                                                                            **\n");
 printf("\t\t\t\t\t**      ******        *******  *************  ************  ************   ***************    **\n");
 printf("\t\t\t\t\t**      ********    *********  *************  ************  ************   **************     **\n");
 printf("\t\t\t\t\t**      ****  **** ****  ****  ****           **        **  ***                  ***          **\n");
 printf("\t\t\t\t\t**      ****   *******   ****  *************  ************  ***                  ***          **\n");
 printf("\t\t\t\t\t**      ****     ***     ****  *************  ************  ***                  ***          **\n");
 printf("\t\t\t\t\t**      ****             ****  ****           ***    ***    ***                  ***          **\n");
 printf("\t\t\t\t\t**      ****             ****  *************  ***     ***   ************   ***************    **\n");
 printf("\t\t\t\t\t**      ****             ****  *************  ***      ***  ************   ***************    **\n");
 printf("\t\t\t\t\t**                                                                                            **\n");
 printf("\t\t\t\t\t************************************************************************************************\n");
 printf("\t\t\t\t\t************************************************************************************************\n");

    return 0;
}
