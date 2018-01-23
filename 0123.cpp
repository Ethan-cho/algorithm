#include<iostream>
using namespace std;
int N,M,R,C,L;
int map[55][55];
bool chk[55][55];
int queue[55*55][3];
int dr[]={-1,1,0,0};
int dc[]={-0,0,-1,1};
int direction[8][4]={{0,0,0,0},{1,1,1,1},{1,1,0,0},{0,0,1,1},{1,0,0,1},{0,1,0,1},{0,1,1,0},{1,0,1,0}};
int main(){
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++){
        for(int i=0;i<55;i++){
            for(int j=0;j<55;j++){
                chk[i][j]=false;
            }
        }
        
        cin>>N>>M>>R>>C>>L;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>map[i][j];
            }
        }
        
        int sp=0,ep=0;
        queue[ep][0]=R;
        queue[ep][1]=C;
        queue[ep++][2]=1;
        chk[R][C]=true;
        int ans=1;
        
        while(sp<ep){
            int r=queue[sp][0];
            int c=queue[sp][1];
            int t=queue[sp++][2];
            
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                int nt=t+1;
                
                int opp_k;
                if(k==0){opp_k=1;}
                else if(k==1){opp_k=0;}
                else if(k==2){opp_k=3;}
                else if(k==3){opp_k=2;}
                
                if(0<=nr&&nr<N&&0<=nc&&nc<M&&chk[nr][nc]==false&&nt<=L){
                    //cout<<nr<<' '<<nc<<' '<<map[r][c]<<' '<<map[nr][nc]<<' '<<"dir "<<k<<' '<<opp_k<<' '<<direction[map[r][c]][k]<<direction[map[r][c]][opp_k]<<'\n';
                    if(direction[map[r][c]][k]==1&&direction[map[nr][nc]][opp_k]==1){
                        ans++;
                        chk[nr][nc]=true;
                        queue[ep][0]=nr;
                        queue[ep][1]=nc;
                        queue[ep++][2]=nt;
                    }
                }
            }
            
            //cout<<r<<' '<<c<<'\n';
            /*for(int k=0;k<4;k++){
                int nr=r+dx[k];
 				int nc=c+dy[k];
				//cout<<nr<<' '<<nc<<'\n';
                if(0<=nr&&nr<N&&0<=nc&&nc<M&&nt<L&&chk[nr][nc]==false){
                    if(direction[map[r][c]][0]==1){
                        queue[ep][0]=nr;
                        queue[ep][1]=nc;
                        queue[ep++][2]=nt;direction[map[r][c]][0]<<
                        ans++;
                        chk[nr][nc]=true;
                    }
                    if(direction[map[r][c]][1]==1){
                        queue[ep][0]=nr;
                        queue[ep][1]=nc;
                        queue[ep++][2]=nt;
                        ans++;
                        chk[nr][nc]=true;
                    }
                    if(direction[map[r][c]][2]==1){
                        queue[ep][0]=nr;
                        queue[ep][1]=nc;
                        queue[ep++][2]=nt;
                        ans++;
                        chk[nr][nc]=true;
                    }
                    if(direction[map[r][c]][3]==1){
                        queue[ep][0]=nr;
                        queue[ep][1]=nc;
                        queue[ep++][2]=nt;
                        ans++;
                        chk[nr][nc]=true;
                    }
                }
            }*/
        }
        cout<<'#'<<t<<' '<<ans<<'\n';
        
    }
    return 0;
}
