#include<cstdio>
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int N,K;
int map[10][10];
bool visit[10][10];
int result;
int max;

void init(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            visit[i][j]=false;
        }
    }
}

void dfs(int x,int y,int n){
    visit[x][y]=true;
    if(result<n)
        result=n;
    for(int k=0;k<4;k++){
        int nx=x+dx[k];
        int ny=y+dy[k];
        if(nx<0||nx>=N||ny<0||ny>=N)	continue;
        if(map[nx][ny]>=map[x][y]||visit[nx][ny]==true)	continue;
        dfs(nx,ny,n+1);
    }
    visit[x][y]=false;
    return;
}
int main(){
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        scanf("%d %d",&N,&K);
        max=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                scanf("%d",&map[i][j]);
                if(max<map[i][j])
                    max=map[i][j];
            }
        }
        result=0;
        for(int k=0;k<=K;k++){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    map[i][j]-=k;
                    for(int a=0;a<N;a++){
                        for(int b=0;b<N;b++){
                            if(map[a][b]==max){
                                init();
                                dfs(a,b,1);
                            }
                        }
                    }
                    map[i][j]+=k;
                }
            }
        }
        printf("#%d %d\n",t,result);
    }
    return 0;
}
