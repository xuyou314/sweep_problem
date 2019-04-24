//
// Created by xuyou on 19-4-21.
//
#include <iostream>
#include <vector>
using namespace std;
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int highy=D>H?H:D;
    int lowy=B>F?B:F;
    int highx=C>G?G:C;
    int lowx=A>E?A:E;
    long add=0;
    if(highy>lowy&&highx>lowx)
        add=(highy-lowy)*(highx-lowx);
    return (C-A)*(D-B)-add+(G-E)*(H-F);
}
bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    int min_max_x=rec1[2]>rec2[2]?rec2[2]:rec1[2];
    int max_min_x=rec1[0]>rec2[0]?rec1[0]:rec2[0];
    int min_max_y=rec1[3]>rec2[3]?rec2[3]:rec1[3];
    int max_min_y=rec1[1]>rec2[1]?rec1[1]:rec2[1];
    if(min_max_x>max_min_x&&min_max_y>max_min_y)
        return true;
    return false;
}
int main(){

    return 0;
}