#include <stdio.h>

// int test(int a, int b){
//     int res = 0;
//     if(a == 1){
//         return a;
//     }else if(a % 2 == 0){
//         // a = a/2
//         if(a == b){
//             res = 1;
//         }
//         return test(a/2, b);
//     }else{
//         // a = a * 3 + 1;
//         if(a == b){
//             res = 1;
//         }
//         return test(a*3+1, b);
//     }
//     return res;
// }

// int main(){
//     int n;
//     scanf("%d", &n);
//     long long int a,b;
//     for(int i = 1; i <= n; i++){
//         int res;
//         scanf("%lld %lld", &a, &b);
//         res = test(a, b);
//         printf("Case #%d: ", i);
//         if(res){
//             printf("YES\n");
//         }else{
//             printf("NO\n");
//         }
//     }
// }

int main()
{
    int n;
    scanf("%d", &n);
    long long int a, b;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld %lld", &a, &b);
        while (a != 1 && a != b)
        {
            if (a % 2 == 0)
            {
                a = a / 2;
            }
            else
            {
                a = a * 3 + 1;
            }
        }
        printf("Case #%d: ", i);
        if (a == b)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}