int climbStairs(int n){
    int a1 = 1, a2 = 2;
    if (n == 1)
        return 1;
    if (n == 2) 
        return 2;
    int i = 3, a;
    while (i <= n)
    {
        a = a1 + a2;
        a1 = a2;
        a2 = a;
        i++;
    }
    return a;
}