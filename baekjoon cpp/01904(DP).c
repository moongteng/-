#include <stdio.h>

//1또는 00으로 구성
int dp[1000001];
int main()
{
	int n;
	scanf("%d", &n);
	dp[1] = 1;
	dp[2] = 2;  // 11 00
	dp[3] = 3;  // 001 100 111
	dp[4] = 5;  // 0000 0011 1100 1001 1111
	//dp[4]가 5인 이유 1. dp[2]원소들에 00을 붙여준다. 2. dp[3]의 원소들에는 1만 붙일 수 있다.
	for (int i = 5; i <= 1000000; i++)
		dp[i] = ((dp[i - 1] % 15746) + (dp[i - 2] % 15746)) % 15746;
	
	printf("%d", dp[n] % 15746);
}