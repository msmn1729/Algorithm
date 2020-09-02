#include <iostream>

using namespace std;

int N;
int vis[15][3];
int result = 0;

void N_Queen(int i)
{
    if(i == N)
    {
        result++;
        return;
    }
    for(int j=0; j<N; j++)
    {
        if(vis[j][0] || vis[j+i][1] || vis[i-j+N][2]) continue;
        vis[j][0] = vis[j+i][1] = vis[i-j+N][2] = 1;
        N_Queen(i+1);
        //vis[j][0] = vis[j+i][1] = vis[i-j+N][2] = 0;
    }
}

int main()
{
    cin>>N;
    N_Queen(0);
    cout<<result<<endl;

    return 0;
}
