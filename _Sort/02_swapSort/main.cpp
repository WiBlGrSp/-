#include<stdio.h>
#include"bubbleSort.h"
#include"quickSort.h"
void test01(){
    int n = 10000;
    SortTable*table1 = generateRandomArray(n,0,n);
    SortTable*table2 = copySortTable(table1);
    SortTable*table3 = copySortTable(table1);
    SortTable*table4 = copySortTable(table1);
    testSort("BubbleSortV1",bubbleSortV1,table1);
    testSort("BubbleSortV2",bubbleSortV2,table2);
    testSort("BubbleSortV3",bubbleSortV3,table3);
    testSort("BubbleSortV4",bubbleSortV4,table4);
    releaseSortTable(table1);
    releaseSortTable(table2);
    releaseSortTable(table3);
    releaseSortTable(table4);
}
void test02()
{
    int n = 1000000;
    SortTable*table1 = generateRandomArray(n,0,n);
    SortTable*table2 = copySortTable(table1);
    testSort("quickSortV1",quickSortV1,table1);
    testSort("quickSortV2",quickSortV2,table2);
    releaseSortTable(table1);
    releaseSortTable(table2);
}
int main(){
    test02();
}