#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, const char* argv[]) {
    int n = 0;
    //fTable[n]记录n个人都拿错（全不获奖）的情况种数，allTable[n]记录所有可能的组合情况n的阶乘
    long long fTable[21] = { 0, 0, 1 }, allTable[21] = { 0, 1, 2 };
    for (int i = 3; i < 21; ++i) {
        //递推计算i个人全部拿错
        fTable[i] = (i - 1) * (fTable[i - 1] + fTable[i - 2]);
        //递推计算i的阶乘
        allTable[i] = i * allTable[i - 1];
    }
    while (scanf("%d", &n) != -1) {
        printf("%4.2lf%%\n", 100 * double(fTable[n]) / allTable[n]);
    }
    return 0;
}