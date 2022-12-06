#include <stdio.h>

int fungsi (int A, int B, int K, int x)
{
	if (K==1)
	{
		if ((A*x + B) > 0) return A*x + B;
		else return -(A*x + B);
	}
	if ((A*fungsi(A, B, K-1, x)+B) > 0) return A*fungsi(A, B, K-1, x)+B;
	else return -(A*fungsi(A, B, K-1, x)+B);
}

int main ()
{
	int A, B, K, x;
	scanf ("%d %d %d %d", &A, &B, &K, &x);
	printf ("%d", fungsi (A, B, K, x));
	return 0;
}
