#include  <stdio.h>  /*标准输入/输出函数库*/
#include  <stdlib.h>  /*标准函数库*/
#include  <string.h>  /*字符串函数库*/
typedef struct  //cStuInfo
{
	int ID;/*学号*/
	char name[16]; /*姓名*/
	char gender; /*性别*/
	short chinese; /*语文成绩*/
	short math; /*数学成绩*/
	short english;/*英语成绩*/
	short computer;  /*计算机成绩*/
	struct cStuInfo *nodeNext;
} cStuInfo;
cStuInfo *pFRec=NULL;
void  print_menu_main();
void  input_record()
{
	cStuInfo *pWork,*pChk;
	int NumBuf;
	char ret='N',count,keybuf;
	if(pFRec==NULL)
	{
		pFRec=(cStuInfo*)malloc(sizeof(cStuInfo));
		pFRec->nodeNext=NULL;
		pWork=pFRec;
		//RecCount++;
	}
	else //Search the last node
	{
		pChk=pFRec;
		do
		{
			pWork=pChk;
			pChk=pChk->nodeNext;
		}
		while(pChk!=NULL);
	}
	while(ret=='N'||ret=='n')
	{
		system("CLS");
		pWork->nodeNext=(cStuInfo*)malloc(sizeof(cStuInfo));
		printf("Please Insert the ID\n");
		scanf("%d",&NumBuf);
		pWork->ID=NumBuf;
		getchar();
		printf("Please Insert the name\n");
		count=0;
		do
		{
			keybuf=getchar();
			if(keybuf!=10)pWork->name[count]=keybuf;
			else pWork->name[count]=0;
			count++;
		}
		while(count<16&&keybuf!=10);
		printf("Please Insert the Gender\n1 for male,2 for female.");
		scanf("%d",&NumBuf);
		pWork->gender=NumBuf;
		printf("Please Insert the chinese grade\n");
		scanf("%d",&NumBuf);
		pWork->chinese=NumBuf;
		printf("Please Insert the math grade\n");
		scanf("%d",&NumBuf);
		pWork->math=NumBuf;
		printf("Please Insert the english grade\n");
		scanf("%d",&NumBuf);
		pWork->english=NumBuf;
		printf("Please Insert the computer grade\n");
		scanf("%d",&NumBuf);
		pWork->computer=NumBuf;
		getchar();
		printf("Node Added.Return?(Y/N)");
		ret=getchar();
		if(ret=='n'||ret=='N')pWork=pWork->nodeNext;
	}
	pWork->nodeNext=NULL;

}
void  show_record()
{
	cStuInfo *pWork,*pChk;
	char keybuf,count=0;
	int numbuf;
	system("CLS");
	if(pFRec==NULL)
	{
		printf("No Record!");
		//RecCount++;
	}
	else //Print till the last node
	{
		printf("学号\t\t姓名\t性别\t语文\t数学\t英语\t计算机 \n");
		pChk=pFRec;
		do
		{
			pWork=pChk;
			printf("%d\t",pWork->ID);
			count=0;
			do
			{
				keybuf=pWork->name[count];
				if(keybuf!=0)printf("%c",keybuf);
				count++;
			}
			while(keybuf!=0&&count<16);
			printf("\t");
			(pWork->gender==1)?(printf("Male\t")):(printf("Female\t"));
			printf("%d\t%d\t%d\t%d\n",pWork->chinese,pWork->math,pWork->english,pWork->computer);
			pChk=pChk->nodeNext;
		}
		while(pChk!=NULL);
	}

}
void  search_record()
{
	char sel,count=0,keybuf;
	int SWord,sbuf;
	cStuInfo *pWork,*pChk;
	if(pFRec==NULL)
	{
		printf("No Record!");
	}
	else //Search Till last node
	{
		pChk=pFRec;
		printf("1.Search by ID\n2.Search by name\nAny other keys for return to main menu\n");
		scanf("%d",&sel);
		getchar();
		switch(sel)
		{
			case 1:
			{
				printf("Please Insert the wanted ID:");
				scanf("%d",&SWord);
				do
				{
					pWork=pChk;
					if(SWord==pWork->ID)
					{
						printf("学号\t\t姓名\t性别\t语文\t数学\t英语\t计算机 \n");
						printf("%d\t",pWork->ID);
						do
						{
							keybuf=pWork->name[count];
							if(keybuf!=0)printf("%c",keybuf);
							count++;
						}
						while(keybuf!=0&&count<16);
						printf("\t");
						(pWork->gender==1)?(printf("Male\t")):(printf("Female\t"));
						printf("%d\t%d\t%d\t%d\n",pWork->chinese,pWork->math,pWork->english,pWork->computer);
						break;
					}
					else pChk=pChk->nodeNext;
				}
				while(pChk!=NULL);
				break;
			}
			case 2:
			{
				printf("Please Insert the wanted name:");
				for(count=0; count<4; count++)
					SWord=SWord<<8+getchar();
				do
				{
					pWork=pChk;
					for(count=0; count<4; count++)
						sbuf=sbuf<<8+pWork->name[count];
					if(SWord==sbuf)
					{
						printf("学号\t\t姓名\t性别\t语文\t数学\t英语\t计算机 \n");
						printf("%d\t",pWork->ID);
						do
						{
							keybuf=pWork->name[count];
							if(keybuf!=0)printf("%c",keybuf);
							count++;
						}
						while(keybuf!=0&&count<16);
						printf("\t");
						(pWork->gender==1)?(printf("Male\t")):(printf("Female\t"));
						printf("%d\t%d\t%d\t%d\n",pWork->chinese,pWork->math,pWork->english,pWork->computer);
						break;
					}
					else pChk=pChk->nodeNext;
				}
				while(pChk!=NULL);
				break;
			}
			default:
				printf("Invalid input!Exit Session!\n");
				break;
		}


	}
	getchar();

}
void  update_record()
{
	cStuInfo *pWork,*pChk;
	int NumBuf;
	char count,keybuf;
	if(pFRec==NULL)
	{
		pFRec=(cStuInfo*)malloc(sizeof(cStuInfo));
		pFRec->nodeNext=NULL;
		pWork=pFRec;
		//RecCount++;
	}
	else //Search the node
	{
		printf("Which ID?");
		scanf("%d",&NumBuf);
		pChk=pFRec;
		while(NumBuf!=pWork->ID)
		{
			if(pChk==NULL)
			{
				printf("Record Not Found!Exit Session!");
				return ;
			}
			pWork=pChk;
			pChk=pChk->nodeNext;
		}
		
		system("CLS");
		printf("Please Insert the ID\n");
		scanf("%d",&NumBuf);
		pWork->ID=NumBuf;
		getchar();
		printf("Please Insert the name\n");
		count=0;
		do
		{
			keybuf=getchar();
			if(keybuf!=10)pWork->name[count]=keybuf;
			else pWork->name[count]=0;
			count++;
		}
		while(count<16&&keybuf!=10);
		printf("Please Insert the Gender\n1 for male,2 for female.");
		scanf("%d",&NumBuf);
		pWork->gender=NumBuf;
		printf("Please Insert the chinese grade\n");
		scanf("%d",&NumBuf);
		pWork->chinese=NumBuf;
		printf("Please Insert the math grade\n");
		scanf("%d",&NumBuf);
		pWork->math=NumBuf;
		printf("Please Insert the english grade\n");
		scanf("%d",&NumBuf);
		pWork->english=NumBuf;
		printf("Please Insert the computer grade\n");
		scanf("%d",&NumBuf);
		pWork->computer=NumBuf;
		getchar();
		printf("Node Changed.");
	}
	getchar();

}
void  delete_record()
{
	cStuInfo *pWork,*pChk,*pPrev;
	int NumBuf;
	if(pFRec==NULL)
	{
		printf("No Record!");
		//RecCount++;
	}
	else //Print till the last node
	{
		pChk=pFRec;
		printf("Which ID?");
		scanf("%d",&NumBuf);
		while(NumBuf!=pChk->ID)
		{
			if(pChk==NULL)
			{
				printf("Record Not Found!Exit Session!");
				return ;
			}
			pWork=pChk;
			pChk=pChk->nodeNext;
		}
		pWork->nodeNext=pChk->nodeNext;
		free(pChk);
		printf("Node Delete OK!");
	}
}
void  calc_record()
{
	char sel,keybuf,count=0;
	int SWord;
	float avg1,avg2,avg3,avg4;
	cStuInfo *pWork,*pChk;
	if(pFRec==NULL)
	{
		printf("No Record!");
	}
	else //Search Till last node
	{
		pChk=pFRec;
		printf("1.Calculate Somebody's Average\n2.Calculate all Average\nAny other keys for return to main menu\n");
		scanf("%d",&sel);
		getchar();
		switch(sel)
		{
			case 1:
			{
				printf("Please Insert the wanted ID:");
				scanf("%d",&SWord);
				do
				{
					pWork=pChk;
					if(SWord==pWork->ID)
					{
						
						printf("Average:%d\n",(pWork->chinese+pWork->math+pWork->english+pWork->computer)/4);
						break;
					}
					else if(pChk->nodeNext==NULL)
					{
						printf("Record Not Found!");
						break;
					}
					pChk=pChk->nodeNext;
				}
				while(pChk!=NULL);
				break;
			}
			case 2:
			{
				do
				{
					pWork=pChk;
					avg1+=pWork->chinese;
					avg2+=pWork->math;
					avg3+=pWork->english;
					avg4+=pWork->computer;
					count++;
					pChk=pChk->nodeNext;
				}
				while(pChk!=NULL);
				avg1=avg1/count;
				avg2=avg2/count;
				avg3=avg3/count;
				avg4=avg4/count;
				printf("Average:%f,%f,%f,%f",avg1,avg2,avg3,avg4);
				break;
			}
			default:
				printf("Invalid input!Exit Session!\n");
				break;
		}


	}
	getchar();

}	

void  save_record()
{

	FILE  *fp;
	cStuInfo   *pshow,*pCheck;

	if((fp=fopen("student.txt","w"))==NULL)
	{
		printf("Can not  open  this  file!\n");
		exit(0);
	}
	else if(pFRec==NULL)
	{
		printf("No Record!");
		//RecCount++;
	}
	else
	{
		pCheck=pFRec;
		fprintf(fp,"+----------+----------+----------+--------+--------+--------+--------+\n");
		fprintf(fp,"+   学号   +  姓名    +  性别    +   语文 +   数学 +  英语  +  计算机+\n");
		fprintf(fp,"+----------+----------+----------+--------+--------+--------+--------+\n");
		do
		{
			pshow=pCheck;
			fprintf(fp,"|%10s|%10s|%d|%8d|%8d|%8d|%8d|\n",
			        pshow->ID,pshow->name,pshow->gender,pshow->chinese,pshow->math,
			        pshow->english,pshow->computer);
			fprintf(fp,"+----------+----------+----------+--------+--------+--------+--------+\n");
			pCheck=pCheck->nodeNext;
		}
		while(pCheck!=NULL);
	}
	fclose(fp);
}

void  print_menu_main()
{
	char sel;
	while(1)
	{
		system("CLS");
		printf("* * * * * * * * * * * * * * * * * * *\n");
		printf("*           Main Menu               *\n");
		printf("* 1. Input Record                   *\n");
		printf("* 2. Modify                         *\n");
		printf("* 3. Delete                         *\n");
		printf("* 4. Calculate                      *\n");
		printf("* 5. Show Record                    *\n");
		printf("* 6. Query                          *\n");
		printf("* 7. Save to file                   *\n");
		printf("* 0. Exit                           *\n");
		printf("* * * * * * * * * * * * * * * * * * *\n");
		printf("Please enter your choice:");
		scanf("%d",&sel);
		getchar();
		switch(sel)
		{
			case 1:
				input_record();
				break;
			case 2:
				update_record();
				break;
			case 3:
				show_record();
				delete_record();
				break;
			case 4:
				calc_record();
				break;
			case 5:
				show_record();
				break;
			case 6:
				search_record();
				break;
			case 7:
				save_record();
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("Invalid Input!\n");
				break;
		}

		printf("Press Any key to continue....");
		getchar();
	}

}
main()
{
	print_menu_main();
}
