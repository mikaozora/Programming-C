int main()
{
    int n[5];
    int max, min;
    float avg;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &n[i]);
        avg += n[i];
    }
    avg /= 5;
    max = n[0];
    min = n[0];
    // find the largest
    for(int i = 0; i < 5; i++){
        if(n[i] > max){
            max = n[i];
        }
    }
    // find the smallest
    for(int i = 0; i < 5; i++){
        if(n[i] < min){
            min = n[i];
        }
    }
    printf("avg: %.2f\n", avg);
    printf("max: %d\n", max);
    printf("min: %d\n", min);
}