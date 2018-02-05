#include<cstdio>
int n,b;
int key[22];
int ans;
void init(){
    for(int i=0;i<22;i++){
        key[i]=0;
    }
}
void dfs(int sum,int idx){
    //현재 합이 b보다크면 종료(idx번째)
    if(sum>=b){
        if(ans>sum-b)
			ans=sum-b;
        return;
    }
    if(idx<=n){
        dfs(sum+key[idx],idx+1);	//idx번째 선택
        dfs(sum,idx+1);					//idx번째 선택x
    }
    return;
}
int main(){
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        init();
        scanf("%d %d",&n,&b);
        for(int i=0;i<n;i++){
            scanf("%d",&key[i]);
        }
        ans=1e9;
        dfs(0,0);
        printf("#%d %d\n",t,ans);
    }
    return 0;
}
