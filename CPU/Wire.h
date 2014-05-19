#ifndef WIRE_H_INCLUDED
#define WIRE_H_INCLUDED
#include <string>
using namespace std;

class Wire
{
    public :

	int size;
	string name;
	int val;
	int change;

	Wire();
	void set(string name,int size);
    void setVal(int val);
    void setVal(int pos,int val);
	void addChange() {change+=2; if (change>2) change=2;};
    void subChange() {change--; if (change<0) change=0;};
    bool isChange() { return change!=0;}
    int getVal(int l,int r);
    int getVal(int pos);
    Wire getWire(int l,int r);
	void print();
};

typedef Wire Reg;

#endif // WIRE_H_INCLUDED
