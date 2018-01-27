#include<cstdio>

int n,m,r,c,l;
int map[50][50];
int cnt[50][50];
bool visit[50][50];
int pipe[8][4] = { {0,0,0,0}, {1,1,1,1},{1,1,0,0},{0,0,1,1},{1,0,0,1},{0,1,0,1},{0,1,1,0},{1,0,1,0} };	//up down left right

void init(){
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            map[i][j]=cnt[i][j]=0;
            visit[i][j]=false;
        }
    }
}

void solve(int row,int col,int time){
	if(time>l)	return;	//시간 초과시 종료
	
	
	visit[row][col]=true;	//방문여부체크
	cnt[row][col]++;		//방문횟수증가
	
	if(pipe[map[row][col]][0]==1){	//up
		//row-1, col
		int k=0;	//up
		int opp_k=1;	//down
		if(map[row][col]!=0){	//현재 파이프가 갈 수 있는가
			if(pipe[map[row][col]][0]==pipe[map[row][col]][1]){	//진행가능여부 k와 opposite k
				if(0<=row-1&&row-1<n&&0<=col&&col<m){	//safe한 범위
					if(visit[row-1][col]==false){	//방문안했다면
						solve(row-1,col,time+1);	//방문
					}
				}
			}
		}
	}
	
	if(pipe[map[row][col]][1]==1){	//down
		//row+1, col
		int k=1;
		int opp_k=0;
		if(map[row][col]!=0){
			if(pipe[map[row][col]][1]==pipe[map[row+1][col]][0]){
				if(0<=row+1&&row+1<n&&0<=col&&col<m){
					if(visit[row+1][col]==false){
						solve(row+1,col,time+1);
					}
				}
			}
		}
	}
	
	if(pipe[map[row][col]][2]==1){	//left
		//row, col-1
		int k=2;
		int opp_k=3;
		if(map[row][col-1]!=0){
			if(pipe[map[row][col]][2]==pipe[map[row][col-1]][3]){
				if(0<=row&&col<n&&0<=row-1&&col-1<m){
					if(visit[row][col-1]==false){
						solve(row,col-1,time+1);
					}
				}
			}
		}
	}
	
	if(pipe[map[row][col]][3]==1){	//right
		//row, col+1
		int k=3;
		int opp_k=2;
		if(map[row][col+1]!=0){
			if(pipe[map[row][col]][3]==pipe[map[row][col+1]][2]){
				if(0<=row&&row<n&&0<=col+1&&col+1<m){
					if(visit[row][col+1]==false){
						solve(row,col+1,time+1);
					}
				}
			}
		}
	}
	
	visit[row][col]=false;
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
