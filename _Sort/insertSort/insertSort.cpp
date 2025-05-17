#include"insertSort.h"
#include<stdio.h>
//直接插入排序
void insertSort(SortTable*table){
    //取无序表的首元素
    for(int i = 1;i<table->length;i++)
    {
        //取元素待插入位置
        int j = i;
        Element tmp = table->data[j];
        //将待插元素不断与前一元素比较，若逆序，则将前一元素后移，直至比较结果为顺序，找到插入位置
        while(j>0 && table->data[j-1].key > tmp.key)
        {
            table->data[j] = table->data[j-1];
            j--;
        }
        table->data[j] = tmp; 
    }
}
//直接插入排序，插入采用交换策略
void insertSortSwap(SortTable*table){
    //取无序表的首元素
    for(int i = 1;i<table->length;i++)
    {
        //首元素的待插入位置
        int j;
        Element tmp = table->data[i];
        for(j = i;j>0 && table->data[j-1].key > tmp.key;j--){
            table->data[j] = table->data[j-1];
        }
    }
}
void shellSort(SortTable*table){
    //生成增量序列
    for(int gap = table->length/2;gap>0;gap/=2)
    {
        //取无序表的首元素
        for(int i = gap;i<table->length;i++)    //这里是依次对每个分组进行插排操作，即A->B->C->...->A->...
        {
            //取待插入位置
            int j;
            Element tmp = table->data[i];
            for(j = i;j>=gap && table->data[j-gap].key > tmp.key;j-=gap)
                table->data[j] = table->data[j-gap];
            table->data[j] =   tmp;
        }
    }
}