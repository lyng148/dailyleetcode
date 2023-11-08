bool isReachableAtTime(int sx, int sy, int fx, int fy, double t){
    int dx = abs(sx - fx) ;
    int dy = abs(sy - fy) ;
    if (dx == 0 && dy == 0) return t != 1;
    return fmax(dx, dy) <= t;
}