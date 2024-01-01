int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    int ans = 0;
    int r1 = 0, r2 = 0;
    qsort(g, gSize, sizeof(int), cmpfunc);
    qsort(s, sSize, sizeof(int), cmpfunc);
    while (r1 < gSize && r2 < sSize)
    {
        if (g[r1] > s[r2])
        {
            r2++;
            continue;
        }
        else if (s[r2] >= g[r1])
        {
            ans++;
            r2++;
            r1++;
            continue;
        }
    }
    return ans;
}