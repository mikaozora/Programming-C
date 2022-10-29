#include <stdio.h>

// char map[10][10] = {};
int count = 0;
// bool visited[10][10] = {};

void pacmon(int a, int b, int x, int y, char map[][101], int visited[][101])
{
    if ((x >= 0 && x <= a) && (y >= 0 && y <= b))
    {
        if (!visited[x][y])
        {
            visited[x][y] = 1;
            if (map[x][y] == '#')
            {
                return;
            }
            else if (map[x][y] == '*' || map[x][y] == '.' || map[x][y] == 'P')
            {
                if (map[x][y] == '*')
                {
                    count++;
                }
                pacmon(a, b, x - 1, y, map, visited); // atas
                pacmon(a, b, x + 1, y, map, visited); // bawah
                pacmon(a, b, x, y - 1, map, visited); // kiri
                pacmon(a, b, x, y + 1, map, visited); // kanan
                return;
            }
            visited[x][y] = 0;
            return;
        }
        return;
    }
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int a, b, x, y;
        scanf("%d %d", &a, &b);
        getchar();
        char tempMap[101][101];
        char map[101][101] = {};
        int visited[101][101] = {};
        for (int j = 0; j < a; j++)
        {
            scanf("%s", tempMap[j]); 
            getchar();
            for (int k = 0; k < b; k++)
            {
                map[j][k] = tempMap[j][k];
                if (map[j][k] == 'P')
                {
                    x = j;
                    y = k;
                }
            }
        }
        
        pacmon(a - 1, b - 1, x, y, map, visited);
        printf("Case #%d: %d\n", i, count);
        count = 0;
    }
}