#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void * a, const void * b){
    return  *(int*)a > *(int*)b ;
}

int main(void) {
    int t; scanf("%d", &t);
    for(int tt=1;tt<=t;tt++){
        int a[25], ans[5], ind=1, sum=0;
        bool done[25]={0};


        for(int i=0;i<25;i++){
            scanf("%d", &a[i]);
            sum+=a[i];
        }
        
        qsort(a,25,sizeof(int),compare);
        
        ans[0]=a[0]/2;
        done[0]=1;
        
        int j=0;
        for(;ind<5;ind++){
            while(j<25 && done[j])
                j++;
   
            ans[ind]=a[j]-ans[0];
            
            for(int i=0;i<ind;i++){
                int cnt=0;
                for(int k=0;(k<25 && cnt<2);k++){
                    if(!done[k] && a[k]==(ans[i]+ans[ind])){
                        done[k]=1;
                        cnt++;
                    }
                }
            }
            
            for(int i=0;i<25;i++){
                if(!done[i] && a[i]==(ans[ind]*2)){
                    done[i]=1;
                    break;
                }
            }
        }
        
        printf("Case #%d: ", tt);
        for(int i=0;i<5;i++)
            printf("%d ", ans[i]);
        printf("\n");    
    }
    return 0;
}