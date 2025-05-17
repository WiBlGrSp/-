#include<stdio.h>
#include"bubbleSort.h"
#include<stdlib.h>
void bubbleSortV1(SortTable*table)
{
    for(int i = 0;i<table->length-1;i++)    //n-1轮，每轮将最大值移动至一端
        for(int j = 0;j<table->length-1-i;j++)  //第i轮，只需对[0,n-1-i)处理
            if(table->data[j].key>table->data[j+1].key) 
                swapElement(&table->data[j],&table->data[j+1]);
}
void bubbleSortV2(SortTable*table)
{
    //冒泡至某一轮，表已经有序，不发生交换，结束排序
     for(int i = 0;i<table->length-1;i++)    
     {
        int isSorted = 1;
        for(int j = 0;j<table->length-1-i;j++)  
            if(table->data[j].key>table->data[j+1].key) 
            {
                isSorted = 0;
                swapElement(&table->data[j],&table->data[j+1]);
            }
        if(isSorted)
            break;
     }
}
//外层循环轮次不固定，内层循环时记录最后一次交换的位置
//内层循环的右边界由最后一次交换位置决定
void bubbleSortV3(SortTable*table)
{
    int n = table->length;  //无序表长度
    int newLength;  //更新的无序表长度
    do
    {
        newLength = 0;
        for(int i = 0;i<n-1;i++)
        {
            if(table->data[i].key >table->data[i+1].key)
            {
                newLength = i+1;
                swapElement(&table->data[i],&table->data[i+1]);
            }
        }
        n = newLength;
    } while(newLength>0);
}
//用两个栈实现冒泡排序？？？
void bubbleSortV4(SortTable*table)
{
    //申请两个栈
    Element*s1 = (Element*)malloc(sizeof(Element)*table->length);
    Element*s2 = (Element*)malloc(sizeof(Element)*table->length);
    int top1 =-1;
    int top2 = -1;
    //将table填入s1
    for(int i = 0;i<table->length;i++)
    {
        s1[++top1] = table->data[i];
    }
    //循环n次，每次找到最大值，填入表相应位置
    Element tmp;
    for(int i =0;i<table->length;i++)
    {
        /* 若s2空，则将s1元素压入s2，此过程保证s2栈顶元素最大，最后将栈顶元素填入[i]*/
        if(top2 == -1)
        {
            s2[++top2] = s1[top1--];
            while(top1!=-1)
            {
                if(s1[top1].key >s2[top2].key)
                    s2[++top2] = s1[top1--];
                else
                {
                    tmp = s2[top2--];
                    s2[++top2] = s1[top1--];
                    s2[++top2] = tmp;
                }
            }
            table->data[table->length-1-i] = s2[top2--];
        }
        /* 若s1空，与将s2元素压入s1，此过程保证s1栈顶元素最大*/
        else if(top1 == -1)
        {
            s1[++top1] = s2[top2--];
            while(top2!=-1)
            {
                if(s2[top2].key > s1[top1].key)
                    s1[++top1] = s2[top2--];
                else 
                {
                    tmp = s1[top1--];
                    s1[++top1]  = s2[top2--];
                    s1[++top1] = tmp;
                }
            }
            table->data[table->length-1-i] = s1[top1--];
        }
    }
    free(s1);
    free(s2);
}
