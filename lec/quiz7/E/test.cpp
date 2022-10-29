#include <stdio.h>

int count = 0;
void misteri(int a, int b){
    int m;
    if(a != b){
        printf("test%d\n",count++);
        m = (a+b) / 2;
        misteri(a, m);
        misteri(m, b);
    }
    return;
}

int main(){
    misteri(0, 8);
}