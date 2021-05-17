#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    for(int i = 1; i<= 100; i++)
    {
        bool myBool = false;
        if(i %3 == 0)
        {
            cout<<"Fizz";
            myBool = true;
        }
        if(i % 5 == 0)
        {
            cout<<"Buzz";
            myBool = true;
        }
        if(!myBool)
        {
            cout<<i;
        }
        if(i < 100)
        {
            cout<<"  ";
        }
    }
    return 0;
}
