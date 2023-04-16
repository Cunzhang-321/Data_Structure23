#include <iostream>
#include<cstdio>
using namespace std;
int main (){
    int a[10000];
    char c;
    int i=0;
    int m,num=0;
    scanf("%c",&c);//输入以‘@’结尾的字符串 ，一个字符一个字符的读入
    while(c!='@'){
        switch(c)
        {
            case '.':
                a[i]=num;  //当输入为‘.’时将num值存入 一维数组中
                num=0;     //更新num的值
                i++;
                break;
            case '+':
                m=a[i-2]+a[i-1];
                i=i-2;
                a[i]=m;
                i++;
                break;
            case '-':
                m=a[i-2]-a[i-1];
                i=i-2;
                a[i]=m;
                i++;
                break;
            case '*':
                m=a[i-2]*a[i-1];
                i=i-2;
                a[i]=m;
                i++;
                break;
            case '/':
                m=a[i-2]/a[i-1];
                i=i-2;
                a[i]=m;
                i++;
                break;
            default:                //可认为当输入为数字时
                num=num*10+(c-'0');
        }
        scanf("%c",&c);
    }
    cout<<a[i-1];
    return 0;
}