#pragma once

 
#ifndef func_H
 
#define func_H
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct node{
	int stuIdNum;
	char name[20];
    char gender[4];
    float weight;
    int vital_capacity;
    int chin;
    int situp;
    node *next;
    float grade;
    char *rank;
};
typedef node* Lnode;

int judge(char *p);
Lnode CreateList();
void print(Lnode );
void AppendNode(Lnode &l);
void DeleteNode(Lnode &l);
void FindNode(Lnode &l);
  
#endif 

