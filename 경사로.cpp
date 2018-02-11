#include<cstdio>
#include<vector>
using namespace std;
int arr[101][101];
bool visit[101][101];
int N,L;
int ans;

void dfs(int row,int col, vector<vector<int> > &map,int k){
    visit[row][col]=true;
    if(col==N-1){
        ans++;
        return;
    }
    if(col+L<N){
        if(visit[row][col+L]==false&&map[row][col]+1==map[row][col+L]&&k!=1){
            bool ok=true;
            for(int i=col;i<col+L;i++){
                if(map[row][i]!=map[row][col]){
                    ok=false;
                    break;
                }
            }
            if(ok){
                dfs(row,col+L,map,0);
            }
        }
        else if(visit[row][col+L]==false&&map[row][col]-1==map[row][col+L]){
            bool ok=true;
            for(int i=col+1;i<=col+L;i++){
                if(map[row][i]!=map[row][col+L]){
                    ok=false;
                    break;
                }
            }
            if(ok){
                dfs(row,col+L,map,1);
            }
        }
    }
    if(visit[row][col+1]==false&&map[row][col]==map[row][col+1]){
        dfs(row,col+1,map,0);
    }
}

void init(){
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            visit[i][j]=false;
        }
    }
}

int main(){
    scanf("%d %d",&N,&L);
    vector<vector<int> > map(N,vector<int> (N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&map[i][j]);
        }
    }
    ans=0;
    vector<vector<int> > reverseMap(N,vector<int> (N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            reverseMap[j][i]=map[i][j];
        }
    }
    init();
    for(int i=0;i<N;i++){
        dfs(i,0,map,0);
    }
    init();
    for(int i=0;i<N;i++){
        dfs(i,0,reverseMap,0);
    }
    printf("%d\n",ans);
    return 0;
}
