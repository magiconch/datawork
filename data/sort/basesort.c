#include<stdio.h>
//从前往后冒
void BubbleSortEx(int arr[],uint64_t size,Compare cmp)
{
    if(arr == NULL || size <= 1)
    {
        return;
    }

    //此时，[0,bound]为带排序区间,(bound,size)为已排序区间
    int bound = size - 1;
    for(;bound > 0;bound--)
    {
        int cur = 0;
        for(;cur < bound;cur++)
        {
            if(cmp(arr[cur],arr[cur + 1]) == 1)
            {
                Swap(&arr[cur],&arr[cur + 1]);
            }
        }
    }                                                                                                           
    return;
}
int main(){
  return 0;
}
