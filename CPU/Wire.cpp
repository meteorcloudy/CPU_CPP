#include <iostream>
#include <string>
#include <stdio.h>
#include "Wire.h"
using namespace std;

Wire::Wire()
{
    size = 0;
    name = "";
    val = 0;
    change = 1;
}

void Wire::set(string _name,int _size)
{
    Wire();
    name = string(_name);
    size = _size;
}

void Wire::setVal(int _val)
{
    if (val==_val) return;
    val = _val;
    addChange();
}

void Wire::setVal(int pos,int _val)
{
    int tmp = val;
    if (_val!=0&&_val!=1) return;
    val -= val&(1<<pos);
    val += _val<<pos;
    if (val != tmp)
        addChange();
}

int Wire::getVal(int l,int r){
    long long res = val;
    if (l<r) return 0;
    res &= ((long long)1<<(l+1))-1;
    res >>= r;
    return (int) res;
}

int Wire::getVal(int pos){
    return (val>>pos)&1;
}

int countDigit(int x)
{
    if (x==0) return 1;
    if (x==-1) return 32;
    int res = 0;
    while (x)
    {
        x/=16;
        res++;
    }
    return res;
}

void Wire::print()
{
    string width;
    int l = (size/4)+(size%4!=0);
    printf("\"%s\" : \"",name.c_str());

    if (name.find("inst")!=name.find("bad"))
    {
        int d = countDigit(val);
        for (int i=0;i<l-d;i++)
            printf("0");
        printf("%x\",\n",val);
    } else
    {
        printf("%d\",\n",val);
    }


}













