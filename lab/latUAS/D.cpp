#include <stdio.h>
#include <string.h>

int count = 0;

void pacmon(int a, int b, int x, int y, char map[][100], bool visited[][100], char king)
{
    if ((x >= 0 && x <= a) && (y >= 0 && y <= b))
    {
        if (!visited[x][y])
        {
            visited[x][y] = true;
            if (map[x][y] == '#')
            {
                return;
            }
            else if (map[x][y] == '.' || map[x][y] == king)
            {
                count++;
                pacmon(a, b, x - 1, y, map, visited, king);
                pacmon(a, b, x + 1, y, map, visited, king);
                pacmon(a, b, x, y - 1, map, visited, king);
                pacmon(a, b, x, y + 1, map, visited, king);
            }
        }
    }
}

int main()
{
    int n, alpha, x, y;
    scanf("%d %d", &n, &alpha);
    char tempMap[100][100] = {};
    char map[100][100] = {};
    bool visited[100][100] = {};
    int locX[alpha] = {};
    int locY[alpha] = {};
    for (int j = 0; j < n; j++)
    {
        scanf("%s", tempMap[j]);
        getchar();
        for (int k = 0; k < n; k++)
        {
            map[j][k] = tempMap[j][k];
            for (int l = 0; l < alpha; l++)
            {
                if (map[j][k] == 97 + l)
                {
                    locX[l] = j;
                    locY[l] = k;
                    break;
                }
            }
        }
    }
    // printf("%d %d", locX[1], locY[1]);
    for (int i = 0; i < alpha; i++)
    {
        pacmon(n - 1, n - 1, locX[i], locY[i], map, visited, 97 + i);
        printf("%c %d\n", 97+i, count);
        count = 0;
    }
}