//
// Created by xuyou on 19-3-22.
//
int removeDuplicates(int* nums, int numsSize) {
    if(numsSize<=1)
        return numsSize;
    int cur=1,index=1;
    while(cur<numsSize){
        while(cur<numsSize&&nums[cur]==nums[cur-1])
            cur++;
        if(cur<numsSize)
            nums[index++]=nums[cur];
        cur++;
    }
    return index;
}
