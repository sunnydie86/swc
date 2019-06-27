// sample.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<malloc.h>
using namespace std;
void find_min(bool** visited,int** dist,int N,int M,int* i, int* j) {

	int min = 5000;
	for (int p = 0;p < N;p++) {
		for (int q = 0;q < M;q++) {
			if ((min > dist[p][q]) && (!visited[p][q]) ) {
				min = dist[p][q];
				*i = p;
				*j = q;
			}
		} 
	}
	return;
}

int main()
{
	int test_case;
	int t;
	FILE* f = freopen("C:\\Users\\Vishal Reddy\\source\\repos\\input.txt","r",stdin);
	
	int N,M, R, C, L,a = 0,b = 0, p = 0,count = 0;

	cin >> t;

	int** pipe = (int**)malloc(50 * sizeof(int*));
	for (int i = 0;i < 50;i++) {
		pipe[i] = (int*)malloc(50 * sizeof(int));
	}

	int**  dist = (int**)malloc(50 * sizeof(int*));
	for (int i = 0;i < 50;i++) {
		dist[i] = (int*)malloc(50 * sizeof(int));
	}

	bool** visited = (bool**)malloc(50 * sizeof(bool*));
	for (int i = 0;i < 50;i++) {
		visited[i] = (bool*)malloc(50 * sizeof(bool));
	}
	
	for (test_case = 0;test_case < t;test_case++) {
		cin >>N>>M>>R>>C>>L;

		for (int i = 0;i < N; i++) {
			for (int j = 0;j < M;j++) {
				//cin >> p;
				pipe[i][j] = 1;
				dist[i][j] = 3000;
				visited[i][j] = false;
			}

		}
		
		dist[R][C] = 0;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				find_min(visited, dist,N,M, &a,&b);
				switch (pipe[a][b])
				{
				case(0):
					break;
				case(1):
					if ((a + 1<N) && ((pipe[a + 1][b] == 1) || (pipe[a + 1][b] == 2) || (pipe[a + 1][b] == 4) || (pipe[a + 1][b] == 7))) {
						if (dist[a + 1][b] > dist[a][b]) dist[a + 1][b] = dist[a][b] + 1;
					}
					if ((b + 1<M) && ((pipe[a][b + 1] == 1) || (pipe[a][b + 1] == 3) || (pipe[a][b + 1] == 6) || (pipe[a][b + 1] == 7))) {
						if (dist[a][b+1] > dist[a][b]) dist[a][b+1] = dist[a][b] + 1;
					}
					if ((a - 1 >= 0) && ((pipe[a - 1][b] == 1) || (pipe[a - 1][b] == 2) || (pipe[a - 1][b] == 5) || (pipe[a - 1][b] == 6))) {
						if (dist[a-1][b] > dist[a][b]) dist[a-1][b] = dist[a][b] + 1;
					}
					if ((b - 1 >= 0) && ((pipe[a][b - 1] == 1) || (pipe[a][b - 1] == 3) || (pipe[a][b - 1] == 4) || (pipe[a][b - 1] == 5))) {
						if (dist[a][b-1] > dist[a][b]) dist[a][b-1] = dist[a][b] + 1;
						//cout << "changed to" << dist[a][b - 1] << endl;
					}
					break;
				case(2):
					if ((a + 1<N) && ((pipe[a + 1][b] == 1) || (pipe[a + 1][b] == 2) || (pipe[a + 1][b] == 4) || (pipe[a + 1][b] == 7))) {
						if (dist[a + 1][b] > dist[a][b]) dist[a + 1][b] = dist[a][b] + 1;
					}
					if ((a - 1 >= 0) && ((pipe[a - 1][b] == 1) || (pipe[a - 1][b] == 2) || (pipe[a - 1][b] == 5) || (pipe[a - 1][b] == 6))) {
						//if ((i == 1) && (j == 4)) cout << "check " << dist[1][4]<< endl;
						if (dist[a - 1][b] > dist[a][b]) dist[a - 1][b] = dist[a][b] + 1;
					}
					break;
				case(3):
					if ((b + 1<M) && ((pipe[a][b + 1] == 1) || (pipe[a][b + 1] == 3) || (pipe[a][b + 1] == 6) || (pipe[a][b + 1] == 7))) {
						if (dist[a][b + 1] > dist[a][b]) dist[a][b + 1] = dist[a][b] + 1;
					}
					if ((b - 1 >= 0) && ((pipe[a][b - 1] == 1) || (pipe[a][b - 1] == 3) || (pipe[a][b - 1] == 4) || (pipe[a][b - 1] == 5))) {
						if (dist[a][b - 1] > dist[a][b]) dist[a][b - 1] = dist[a][b] + 1;
					}
					break;
				case(4):
					if ((b + 1<M) && ((pipe[a][b + 1] == 1) || (pipe[a][b + 1] == 3) || (pipe[a][b + 1] == 6) || (pipe[a][b + 1] == 7))) {
						if (dist[a][b + 1] > dist[a][b]) dist[a][b + 1] = dist[a][b] + 1;
					}
					if ((a - 1 >= 0) && ((pipe[a - 1][b] == 1) || (pipe[a - 1][b] == 2) || (pipe[a - 1][b] == 5) || (pipe[a - 1][b] == 6))) {
						if (dist[a - 1][b] > dist[a][b]) dist[a - 1][b] = dist[a][b] + 1;
					}
					break;
				case(5):
					if ((b + 1<M) && ((pipe[a][b + 1] == 1) || (pipe[a][b + 1] == 3) || (pipe[a][b + 1] == 6) || (pipe[a][b + 1] == 7))) {
						if (dist[a][b+1] > dist[a][b]) dist[a][b+1] = dist[a][b] + 1;
					}
					if ((a + 1<N) && ((pipe[a + 1][b] == 1) || (pipe[a + 1][b] == 2) || (pipe[a + 1][b] == 4) || (pipe[a + 1][b] == 7))) {
						if (dist[a+1][b] > dist[a][b]) dist[a+1][b] = dist[a][b] + 1;
					}
					break;
				case(6):
					if ((a + 1<N) && ((pipe[a + 1][b] == 1) || (pipe[a + 1][b] == 2) || (pipe[a + 1][b] == 4) || (pipe[a + 1][b] == 7))) {
						if (dist[a + 1][b] > dist[a][b]) dist[a + 1][b] = dist[a][b] + 1;
					}
					if ((b - 1 >= 0) && ((pipe[a][b - 1] == 1) || (pipe[a][b - 1] == 3) || (pipe[a][b - 1] == 4) || (pipe[a][b - 1] == 5))) {
						if (dist[a][b - 1] > dist[a][b]) dist[a][b - 1] = dist[a][b] + 1;
					}
					break;
				case(7):
					if ((b - 1 >= 0) && ((pipe[a][b - 1] == 1) || (pipe[a][b - 1] == 3) || (pipe[a][b - 1] == 4) || (pipe[a][b - 1] == 5))) {
						if (dist[a][b - 1] > dist[a][b]) dist[a][b - 1] = dist[a][b] + 1;
					}
					if ((a - 1 >= 0) && ((pipe[a - 1][b] == 1) || (pipe[a - 1][b] == 2) || (pipe[a - 1][b] == 5) || (pipe[a - 1][b] == 6))) {
						if (dist[a - 1][b] > dist[a][b]) dist[a - 1][b] = dist[a][b] + 1;
					}
					break;
				default:
					cout << pipe[a][b] << " error\n";
					break;
				}
				visited[a][b] = true;
			}
		}
		count = 0;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				if (dist[i][j] < L) count++;
				//cout << dist[i][j] << " ";
			}
			//cout << endl;
		}
		cout <<"#"<<test_case<<" "<<count<< endl;
	}
	
	
	
    return 0;
}

