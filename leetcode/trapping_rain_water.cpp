//
// Created by xuyou on 19-3-21.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int trap(vector<int>& height) {
    int start=0,length=height.size();
    while (start<length-1&&height[start+1]>=height[start])
        start++;
    int sum=0;
    while (start<length-2) {
        int low=start+1;
        while (low < length - 1 && height[low + 1] <= height[low]) {
            low++;
        }
        if(low+1>=length)
            break;
        int high = low + 1;
        int highindex=low+1;
        while (high < length - 1 && (height[high] < height[start]||height[high+1]>=height[high])) {
            if(height[highindex]<height[high])
                highindex=high;
            high++;
        }
        if(high==length-1)
            if(height[high]>height[highindex])
                highindex=high;
        if(high<length&&height[high]>=height[start]) {
            int minheigh = height[start] > height[high] ? height[high] : height[start];
            int vol = 0;
            for (int i = start; i <= high; i++) {
                if (height[i] < minheigh) {
                    vol = vol + minheigh - height[i];
                }
            }
            sum += vol;
            start = high;
        } else{
            int vol=0;
            for(int i=start;i<=highindex;i++){
                if(height[i]<height[highindex])
                    vol=vol+height[highindex]-height[i];
            }
            sum+=vol;
            start=highindex;
        }
    }
    return sum;
}
int main(){
    vector<int>h={5,2,1,2,1,5};//14
    vector<int>h2={0,1,0,2,1,0,1,3,2,1,2,1};//6
    vector<int>h3={4,4,4,7,1,0};//0
    vector<int>h4={0,7,1,4,6}; //7
    int res=trap(h3);
    return 0;
}