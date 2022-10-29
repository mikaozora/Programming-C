#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    long long int siswa;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &siswa);
        long long int score[1001] = {};
        // int index[1001] = {};
        int max = 0;
        for(int y = 0; y < siswa; y++){
            scanf("%lld", &score[y]);
            if(max < score[y]){
                max = score[y];
            }
        }
        int count = 0;
        for(int y = 0; y < siswa; y++){
            if(max == score[y]){
                count++;
            }
        }
        
        printf("Case #%d: %d\n", i, count);
    }
}