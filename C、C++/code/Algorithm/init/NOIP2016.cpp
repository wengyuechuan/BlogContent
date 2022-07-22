#include<iostream>

using namespace std;
int main(void){
    int n=0;
    int a=0,b=0;
    int min=99999999;
    cin>>n;
    for (size_t i = 0; i < 3; i++)
    {
        int count=0;
        int sum=0;
        while (sum<n)
        {
            sum+=a;
            count++;
        }
        if(count*b<min){
            min=count*b;
        }
        
    }
    return 0;
}