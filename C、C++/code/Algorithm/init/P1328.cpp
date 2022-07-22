#include<iostream>
using namespace std;
int n;
int coefficient[10005];
void PolyPrint();
int main(void){
    cin>>n;
    for (int i = 1; i <=n+1 ; ++i) {
        cin>>coefficient[i];
    }
    PolyPrint();
    return 0;
}
void PolyPrint(){
    for(int i=1;i<=n+1;++i) {
        if (i == 1 && coefficient[i] != 0) {
            if (coefficient[i] != 1 && coefficient[i]!=-1) {
                cout << coefficient[i] << "x^" << n;
            } else if(coefficient[i]==1){
                cout << "x^" << n;
            }else{
                cout << "-x^" << n;
            }
        } else if (i == n + 1 && coefficient[i] != 0) {
            if (coefficient[i] > 0) {
                cout << "+" << coefficient[i];
            } else if (coefficient[i] < 0) {
                cout << coefficient[i];
            }
        } else if (i == n) {
            if(coefficient[i]>0){
                if(coefficient[i]!=1){
                    cout<<"+"<<coefficient[i]<<"x";
                }else{
                    cout<<"+"<<"x";
                }
            }else if(coefficient[i]<0){
                if(coefficient[i]!=-1){
                    cout<<coefficient[i]<<"x";
                }else {
                    cout << "-" << "x" ;
                }
            }
        }else{
            if(coefficient[i]>0){
                if(coefficient[i]!=1){
                    cout<<"+"<<coefficient[i]<<"x^"<<n-i+1;
                }else{
                    cout<<"+"<<"x^"<<n-i+1;
                }
            }else if(coefficient[i]<0){
                if(coefficient[i]!=-1){
                    cout<<coefficient[i]<<"x^"<<n-i+1;
                }else {
                    cout << "-" << "x^" << n - i + 1;
                }
            }
        }
    }
}