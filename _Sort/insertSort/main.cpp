#include"insertSort.h"
#include<stdio.h>
int main(){
    int n = 100000;
    SortTable* table1 = generateRandomArray(n,0,n);
    SortTable* table2 = generateLinearArray(n,1000);
    SortTable* table3 = copySortTable(table1);
    SortTable* table4 = copySortTable(table1);
    testSort("insertSort",insertSort,table1);
    testSort("insertSort2",insertSort,table2);
    testSort("insertSortSwap",insertSortSwap,table3);
    testSort("shellSort",shellSort,table4);
    releaseSortTable(table1);
    releaseSortTable(table2);
    releaseSortTable(table3);
    releaseSortTable(table4);
}