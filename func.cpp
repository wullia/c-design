#include "func.h"


int judge(char *p){
    char *s="yes";
    return strcmp(p,s);
}

Lnode CreateList(){
   node *p=new node;
   p->stuIdNum=0;
   p->next=NULL;
   return p;
 }

void print(Lnode l){
	node *p=l;
	p=p->next;
    printf("学生信息:\n");
    while(p!=NULL){
        if(strcmp(p->gender,"male")==0)
        printf("学号:%d,姓名:%s,性别:%s,体重:%.2f,肺活量:%d,引体向上:%d,成绩:%.1f,成绩等级:%s\n",p->stuIdNum,p->name,p->gender,p->weight,p->vital_capacity,p->chin,p->grade,p->rank);
        else
        printf("学号:%d,姓名:%s,性别:%s,体重:%.2f,肺活量:%d,仰卧起坐:%d,成绩:%.1f,成绩等级:%s\n",p->stuIdNum,p->name,p->gender,p->weight,p->vital_capacity,p->situp,p->grade,p->rank);
        p=p->next;
    }
}
void AppendNode(Lnode &l){//insert stu after 
     node *p=l;
     char *flag;
     node *temp= new node;
     while(1){
     while(p->next!=NULL)
        p=p->next;
     temp->grade=0;
     printf("请输入学生信息:\n");
     printf("学号:"); scanf("%d",&temp->stuIdNum);
     printf("姓名:"); scanf("%s",temp->name);
     printf("性别（male/female):"); scanf("%s",temp->gender);
     
      if(strcmp(temp->gender,"male")==0)
     {   printf("体重:"); scanf("%f",&temp->weight);
           if(temp->weight>=17.9&&temp->weight<=23.9){
               temp->grade+=100*0.25;
           }
           else if(temp->weight>24&&temp->weight<=27.9||temp->weight<=17.8&&temp->weight>=0){
               temp->grade+=80*0.25;
           }
           else if(temp->weight>28){
               temp->grade+=60*0.25;
           }
           else printf("数据错误");
         printf("肺活量:"); scanf("%d",&temp->vital_capacity);
           if(temp->vital_capacity>4800){
               temp->grade+=0.35*100;
           }
           else if(temp->vital_capacity>=4181&&temp->vital_capacity<=4800){
               temp->grade+=0.35*80;
           }
            else if(temp->vital_capacity>=3101&&temp->vital_capacity<=4180){
               temp->grade+=0.35*60;
           }
           else if(temp->vital_capacity>=0&&temp->vital_capacity<=3100){
               temp->grade+=0.35*30;
           }
           else printf("数据错误");
         printf("引体向上:"); scanf("%d",&temp->chin);
         if(temp->chin>19){
             temp->grade+=100*0.4;
         }
         else if(temp->chin>=16&&temp->chin<=19){
             temp->grade+=80*0.4;
         }
         else if(temp->chin>=10&&temp->chin<=15){
             temp->grade+=60*0.4;
         }
         else if(temp->chin>=0&&temp->chin<=9){
             temp->grade+=30*0.4;
         }
         else printf("数据错误");
     }
    else if (strcmp(temp->gender,"female")==0)
     {  printf("体重:"); scanf("%f",&temp->weight);
        if(temp->weight>=17.2&&temp->weight<=23.9){
               temp->grade+=100*0.25;
           }
           else if(temp->weight>24&&temp->weight<=27.9||temp->weight<=17.1&&temp->weight>=0){
               temp->grade+=80*0.25;
           }
           else if(temp->weight>28){
               temp->grade+=60*0.25;
           }
           else printf("数据错误");
        printf("肺活量:"); scanf("%d",&temp->vital_capacity);
        if(temp->vital_capacity>3400){
               temp->grade+=0.35*100;
           }
           else if(temp->vital_capacity>=3001&&temp->vital_capacity<=3400){
               temp->grade+=0.35*80;
           }
            else if(temp->vital_capacity>=2051&&temp->vital_capacity<=3000){
               temp->grade+=0.35*60;
           }
           else if(temp->vital_capacity>=0&&temp->vital_capacity<=2050){
               temp->grade+=0.35*30;
           }
           else printf("数据错误");
        printf("仰卧起坐:"); scanf("%d",&temp->situp);
        if(temp->situp>56){
             temp->grade+=100*0.4;
         }
         else if(temp->situp>=53&&temp->situp<=56){
             temp->grade+=80*0.4;
         }
         else if(temp->situp>=25&&temp->situp<=52){
             temp->grade+=60*0.4;
         }
         else if(temp->situp>=0&&temp->situp<=16){
             temp->grade+=30*0.4;
         }
         else printf("数据错误");
     }
    if(temp->grade>95){
        temp->rank="优";
    }
    else if(temp->grade>=80&&temp->grade<=94){
        temp->rank="良";
    }
    else if(temp->grade>=60&&temp->grade<=79){
        temp->rank="中";
    } 
    else if(temp->grade>=0&&temp->grade<60){
        temp->rank="差";
    }
     temp->next=NULL;
     p->next=temp;
     l->stuIdNum++;
     printf("是否继续[yes/no]:");
     scanf("%s",flag);
     if(judge(flag)==0)
     continue;
     else break;
     } 
     printf("节点添加成功\n");
     return ;
 }
 
void DeleteNode(Lnode &l){
 	char temp[20];
 	printf("请输入要删除的姓名:\n");
 	scanf("%s",temp);
 	node *p=l;
    if(!strcmp(p->name,temp)){
    printf("数据错误");
    exit(0);
    }
 	while(strcmp(p->next->name,temp))
 		p=p->next;
	if(p->next==NULL)
	printf("姓名不存在");
	else p->next=p->next->next;
    printf("删除成功");
	return ;
 }

void FindNode(Lnode &l){
 	char temp[20];
 	printf("请输入要查询学生的姓名\n");
 	scanf("%s",temp);
 	node *p=l;
 	while(strcmp(p->name,temp)!=0&&p!=NULL)
 		{   
             p=p->next;
         }
	if(p==NULL)
	printf("姓名不存在");
	else
	if(strcmp(p->gender,"male")==0)
        printf("学号:%d,姓名:%s,性别:%s,体重:%.2f,肺活量:%d,引体向上:%d,成绩:%.1f,成绩等级:%s\n",p->stuIdNum,p->name,p->gender,p->weight,p->vital_capacity,p->chin,p->grade,p->rank);
        else
        printf("学号:%d,姓名:%s,性别:%s,体重:%.2f,肺活量:%d,仰卧起坐:%d,成绩:%.1f,成绩等级:%s\n",p->stuIdNum,p->name,p->gender,p->weight,p->vital_capacity,p->situp,p->grade,p->rank);
}


