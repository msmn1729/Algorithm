#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int ar[3][2]={},i, j,ans_x=0,ans_y=0;
    
    for(i=0;i<3;i++)
    {
        for(j=0;j<2;j++)
        {
            cin >> ar[i][j];
        }
    }
    if(ar[0][0] == ar[1][0]) ans_x = ar[2][0];
    else if(ar[1][0] == ar[2][0]) ans_x = ar[0][0];
    else if(ar[2][0] == ar[0][0]) ans_x = ar[1][0];
    
    if(ar[0][1] == ar[1][1]) ans_y = ar[2][1];
    else if(ar[1][1] == ar[2][1]) ans_y = ar[0][1];
    else if(ar[2][1] == ar[0][1]) ans_y = ar[1][1];
    printf("%d %d",ans_x,ans_y);

    return 0;
}
