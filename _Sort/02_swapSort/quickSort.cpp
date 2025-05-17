#include "quickSort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 双边循环快速排序
/*
1.寻找犄点pivot
1.1.向左遍历找到小于基点的元素
1.2.向右遍历找到大于等于基点的元素
1.3.交换两个元素
1.4.重复执行至两者遍历到同一位置
2.交换该位置与基点
3.对基点两侧的子表递归排序
*/
static int findPivotDouble(SortTable *table, int startIndex, int endIndex)
{
    int left = startIndex;
    int right = endIndex;
    // 选取第一个元素为基点，基点元素随机化，避免基点元素较大，尽量保证子表均分
    srand(time(NULL));
    swapElement(&table->data[startIndex],
                &table->data[rand() % (endIndex - startIndex + 1) + startIndex]);
    while (left < right)
    {
        // 向左遍历至较小元素
        while (left < right && table->data[right].key > table->data[startIndex].key)
            right--;
        // 向右遍历至较大元素
        while (left < right && table->data[left].key <= table->data[startIndex].key)
            left++;
        //PS：这里必须先向左遍历，保证循环结束时，left和right指向的元素是小于基点的
        // 两指标未重合，交换元素
        if (left < right)
            swapElement(&table->data[left], &table->data[right]);
    }
    // 循环结束，left = right，指向的位置即为基点位置
    swapElement(&table->data[startIndex], &table->data[left]);
    return left;
}
static void quickSort1(SortTable *table, int startIndex, int endIndex)
{
    if (startIndex >= endIndex)
        return;
    int pivot = findPivotDouble(table, startIndex, endIndex);
    quickSort1(table, startIndex, pivot - 1);
    quickSort1(table, pivot + 1, endIndex);
}
void quickSortV1(SortTable *table)
{
    quickSort1(table, 0, table->length - 1);
}

//单边循环快排
/*
    将startIndex作为排序基点pivot
    设定mark为排序后基点位置，初始值为startIndex
    向右遍历，若元素小于基点，则mark++，并交换mark与该元素
    最后将mark元素与pivot交换，mark处为排序后基点位置
*/
/*
解释：
    遍历到较小的元素，说明在已遍历的表中，基点位置mark应后移，即mark位置为start+较小元素数量
    这里mark相当于栈顶指针，我们实际维护的是一个小于基点元素的元素栈，最终该栈顶指针指向基点最终位置
*/
static int findPivotSingle(SortTable *table, int startIndex, int endIndex)
{
    srand(time(NULL));
    swapElement(&table->data[startIndex],
                &table->data[rand() % (endIndex - startIndex + 1) + startIndex]);
    int pivot = startIndex;
    int mark = startIndex;
    for(int i = startIndex+1;i<=endIndex;i++)
    {
        if(table->data[i].key < table->data[pivot].key)
            swapElement(&table->data[++mark],&table->data[i]);
    }
    swapElement(&table->data[pivot],&table->data[mark]);
    return mark;
}
static void quickSort2(SortTable *table, int startIndex, int endIndex){
    if (startIndex >= endIndex)
        return;
    int pivot = findPivotSingle(table, startIndex, endIndex);
    quickSort2(table, startIndex, pivot - 1);
    quickSort2(table, pivot + 1, endIndex);

}
// 单边循环快速排序
void quickSortV2(SortTable *table)
{
    quickSort2(table,0,table->length-1);
}