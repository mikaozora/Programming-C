#include <stdio.h>

bool visited[50][50] = {};
int map[50][50] = {};
int count = 0;

void jawbreaker(int x, int y, int value, int a, int b)
{
    if((x >= 0 && x <= a) && (y >= 0 && y <= b)){
        if(!visited[x][y]){
            visited[x][y] = true;
            if(map[x][y] == value){
                count++;
                // printf("posisi: %d %d\n", x, y);
                // printf("count: %d\n", count);
                jawbreaker(x-1, y, value, a, b); //atas
                jawbreaker(x+1, y, value, a, b); //bawah
                jawbreaker(x, y+1, value, a, b); //kanan
                jawbreaker(x, y-1, value, a, b); //kiri
                return;
            }
            visited[x][y] = false;
            return;
        }
        return;
    }
    return;
}

int main()
{
    int a, b, x, y, value;
    scanf("%d %d", &a, &b);
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    scanf("%d %d", &x, &y);
    value = map[x][y];
    jawbreaker(x, y, value, a-1, b-1);
    int result = count * (count-1);
    printf("%d", result);
}