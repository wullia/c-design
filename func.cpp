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
    printf("ѧ����Ϣ:\n");
    while(p!=NULL){
        if(strcmp(p->gender,"male")==0)
        printf("ѧ��:%d,����:%s,�Ա�:%s,����:%.2f,�λ���:%d,��������:%d,�ɼ�:%.1f,�ɼ��ȼ�:%s\n",p->stuIdNum,p->name,p->gender,p->weight,p->vital_capacity,p->chin,p->grade,p->rank);
        else
        printf("ѧ��:%d,����:%s,�Ա�:%s,����:%.2f,�λ���:%d,��������:%d,�ɼ�:%.1f,�ɼ��ȼ�:%s\n",p->stuIdNum,p->name,p->gender,p->weight,p->vital_capacity,p->situp,p->grade,p->rank);
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
     printf("������ѧ����Ϣ:\n");
     printf("ѧ��:"); scanf("%d",&temp->stuIdNum);
     printf("����:"); scanf("%s",temp->name);
     printf("�Ա�male/female):"); scanf("%s",temp->gender);
     
      if(strcmp(temp->gender,"male")==0)
     {   printf("����:"); scanf("%f",&temp->weight);
           if(temp->weight>=17.9&&temp->weight<=23.9){
               temp->grade+=100*0.25;
           }
           else if(temp->weight>24&&temp->weight<=27.9||temp->weight<=17.8&&temp->weight>=0){
               temp->grade+=80*0.25;
           }
           else if(temp->weight>28){
               temp->grade+=60*0.25;
           }
           else printf("���ݴ���");
         printf("�λ���:"); scanf("%d",&temp->vital_capacity);
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
           else printf("���ݴ���");
         printf("��������:"); scanf("%d",&temp->chin);
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
         else printf("���ݴ���");
     }
    else if (strcmp(temp->gender,"female")==0)
     {  printf("����:"); scanf("%f",&temp->weight);
        if(temp->weight>=17.2&&temp->weight<=23.9){
               temp->grade+=100*0.25;
           }
           else if(temp->weight>24&&temp->weight<=27.9||temp->weight<=17.1&&temp->weight>=0){
               temp->grade+=80*0.25;
           }
           else if(temp->weight>28){
               temp->grade+=60*0.25;
           }
           else printf("���ݴ���");
        printf("�λ���:"); scanf("%d",&temp->vital_capacity);
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
           else printf("���ݴ���");
        printf("��������:"); scanf("%d",&temp->situp);
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
         else printf("���ݴ���");
     }
    if(temp->grade>95){
        temp->rank="��";
    }
    else if(temp->grade>=80&&temp->grade<=94){
        temp->rank="��";
    }
    else if(temp->grade>=60&&temp->grade<=79){
        temp->rank="��";
    } 
    else if(temp->grade>=0&&temp->grade<60){
        temp->rank="��";
    }
     temp->next=NULL;
     p->next=temp;
     l->stuIdNum++;
     printf("�Ƿ����[yes/no]:");
     scanf("%s",flag);
     if(judge(flag)==0)
     continue;
     else break;
     } 
     printf("�ڵ���ӳɹ�\n");
     return ;
 }
 
void DeleteNode(Lnode &l){
 	char temp[20];
 	printf("������Ҫɾ��������:\n");
 	scanf("%s",temp);
 	node *p=l;
    if(!strcmp(p->name,temp)){
    printf("���ݴ���");
    exit(0);
    }
 	while(strcmp(p->next->name,temp))
 		p=p->next;
	if(p->next==NULL)
	printf("����������");
	else p->next=p->next->next;
    printf("ɾ���ɹ�");
	return ;
 }

void FindNode(Lnode &l){
 	char temp[20];
 	printf("������Ҫ��ѯѧ��������\n");
 	scanf("%s",temp);
 	node *p=l;
 	while(strcmp(p->name,temp)!=0&&p!=NULL)
 		{   
             p=p->next;
         }
	if(p==NULL)
	printf("����������");
	else
	if(strcmp(p->gender,"male")==0)
        printf("ѧ��:%d,����:%s,�Ա�:%s,����:%.2f,�λ���:%d,��������:%d,�ɼ�:%.1f,�ɼ��ȼ�:%s\n",p->stuIdNum,p->name,p->gender,p->weight,p->vital_capacity,p->chin,p->grade,p->rank);
        else
        printf("ѧ��:%d,����:%s,�Ա�:%s,����:%.2f,�λ���:%d,��������:%d,�ɼ�:%.1f,�ɼ��ȼ�:%s\n",p->stuIdNum,p->name,p->gender,p->weight,p->vital_capacity,p->situp,p->grade,p->rank);
}


