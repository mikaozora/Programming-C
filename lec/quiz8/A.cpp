#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int hours = 0, minute = 0;
        char day[10] = {};
        scanf("%d:%d %s", &hours, &minute, day);
        if(strcmp(day, "am") == 0){
            if(hours >= 12){
                hours -= 12;
            }
        }else if(strcmp(day, "pm") == 0){
            if(hours < 12){
                hours += 12;
            }
        }
        printf("Case #%d: %02d:%02d\n", i, hours, minute);
    }
}