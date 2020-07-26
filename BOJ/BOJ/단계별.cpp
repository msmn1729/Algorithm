#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
//    int sum=0,x[5]={},i;
//    for(i=0; i<5 ;i++){
//        cin >> x[i];
//        if(x[i]<40)x[i]=40;
//        sum += x[i];
//    }
//    cout << sum/5;
    
    //2523
    int n, i, j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            cout<<'*';
        }
        cout<<endl;
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            cout<<'*';
        }
        cout<<endl;
    }
    
    return 0;
}
