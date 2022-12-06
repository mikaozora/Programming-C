#include<stdio.h>

int arr[400050];
int n;
long long int m;
long long int calc[400050];

long long int func()
{
	long long int max = 0, sum = 0;
	int i = n, j = n, k = 0;
	while(i >= 0)
	{
		if(sum == m)
		{
			return sum;
		}
		else if(sum < m)
		{
			i--;
			k++;
			sum += (arr[i]*k);
		}
		else
		{
			k--;
			sum -= (calc[i]-calc[j]);
			j--;
		}

		if(sum > max && sum <= m)
		{
			max = sum;
		}
	}
	return max;
}

int main()
{
	scanf("%d", &n);
	
	for(int i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	long long int sum = 0;
	for(int i = n-1; i >= 0; i--)
	{
		sum += arr[i];
		calc[i] = sum;
	}
	
	scanf("%lld", &m);
	long long int hasil = func();
	
	printf("%lld\n", hasil);
	
	return 0;
}
