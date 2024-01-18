int climbStairs(int n) {
    int stair[46];
    stair[0] = 1;
    stair[1] = 1;
    stair[2] = 2;
    if (n < 3) return stair[n];
    for (int i = 3; i <= n; i++)
    {
        stair[i] = stair[i - 1] + stair[i - 2];
    }
    return stair[n];
}