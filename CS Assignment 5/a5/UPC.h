// Name        : UPC.h
// Author      : Giovanni Parati
// Date        : 11/20/2020
// h file for UPC class

#include <string>
using namespace std;

class UPC{
private:
    long long key;
    string value;
public:
    UPC();
    UPC(long long k);
    //UPC(string v);
    UPC(long long k, string v);
    
    long long getKey();
    string getVal();

    void setKey(int k);
    void setVal(string v);
};