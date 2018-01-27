#include<cstdio>

int n,m,r,c,l;
int map[50][50];
int cnt[50][50];
bool visit[50][50];
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int pipe[8][4] = { {0,0,0,0}, {1,1,1,1},{1,1,0,0},{0,0,1,1},{1,0,0,1},{0,1,0,1},{0,1,1,0},{1,0,1,0} };	//up down left right

void init(){
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            map[i][j]=cnt[i][j]=0;
            visit[i][j]=false;
        }
    }
}

void solve(int r,int c,int hour){
	if(hour>l)	return;
	
	visit[r][c]=true;
	cnt[r][c]++;
	
	for(int k=0;k<4;k++){
		int opp_k;
		if(k==0)	opp_k=1;
		else if(k==1)	opp_k=0;
		else if(k==2)	opp_k=3;
		else if(k==3)	opp_k=2;
		
		int nr=r+dr[k];	//next row
		int nc=c+dc[k];	//next col
		
		if(pipe[map[r][c]][k]==1){
			if(map[nr][nc]!=0){
				if(pipe[map[r][c]][k]==pipe[map[nr][nc]][opp_k]){
					if(0<=nr&&nr<n&&0<=nc&&nc<m){
						if(visit[nr][nc]==false){
							solve(nr,nc,hour+1);
						}
					}
				}
			}
		}
	}
	
	
	visit[r][c]=false;
}

int main(){
	int tc;
	int ans;
	scanf("%d",&tc);
	for(int t=1;t<=tc;t++){
        init();
		ans=0;
		scanf("%d %d %d %d %d",&n,&m,&r,&c,&l);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&map[i][j]);
			}
		}
		solve(r,c,1);
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(cnt[i][j]>0)	ans++;
			}
		}
		printf("#%d %d\n",t,ans);
	}
	return 0;
}
