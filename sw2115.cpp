#include <cstdio>

int N, M, C, cost, max;
int map[10][10];
bool visit[10][10];

//꿀통 선택 후, 최대 수익 구하기
void dfs(int x, int y, int m, int cnt, int co){
	//m은 M , cnt는 C, co는 수익
	if (cnt > C) return;	//capacity초과시 종료

	//if (co < cost) return; 

	if (co > cost) cost = co;	//cost업데이트

	if (m == M) return;	//M 범위 종료

	dfs(x, y + 1, m + 1, cnt + map[x][y], co + (map[x][y] * map[x][y]));	//선택하기
	dfs(x, y + 1, m + 1, cnt, co);	//넘어가기
	return;
}

int go(int x, int y)
{
	int cost1 = 0, cost2 = 0;	//cost1 첫번째 일꾼 cost

	for (int j = 0; j < M; j++)//첫번째 일꾼 선택
		visit[x][y + j] = true;

	cost = 0;
	dfs(x, y, 0, 0, 0);
	cost1 = cost;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= N - M; j++) {
			if (visit[i][j])	continue;
			cost = 0;
			dfs(i, j, 0, 0, 0);
			if (cost > cost2)	cost2 = cost;
		}
	}
	return cost1 + cost2;
}

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++)
	{
		scanf("%d %d %d", &N, &M, &C);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				visit[i][j] = false;
			}
		}
		
		max = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= N - M; j++) {
				int ans = go(i, j);
				if (max < ans)	max = ans;
			}
		}


		printf("#%d %d\n", t, max);
	}
	return 0;
}
