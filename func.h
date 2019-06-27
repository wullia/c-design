#pragma once

 
#ifndef func_H
 
#define func_H
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct node{
	int stuIdNum;
	char name[20];
    char gender[6];
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
void change(Lnode &l);
void change(Lnode &l);
void Sort(Lnode l);
void quickSort(Lnode l);
void quick_sort(node * start, node * end);
node * partion(node * start, node * end);
void swap(node * a, node * b);
#endif 

