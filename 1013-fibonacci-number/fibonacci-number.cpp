class Solution {
public:
    int mem[31];

    int Fib(int n) {
        if (n == 0)
            return 0;
    if (n <= 2) 
        return 1;
    if (mem[n] != -1){
        return mem[n];
    }
    int res = Fib(n - 1) + Fib(n - 2);
    mem[n] = res;

    return res;
}

    int fib(int n) {
        memset(mem, -1, sizeof(mem));
        return Fib(n);
    }
};