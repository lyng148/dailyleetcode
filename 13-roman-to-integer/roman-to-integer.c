int romanToInt(char * s){
    int a[15] = {0};
    int b[15] = {0};
    int n = strlen(s);
    for( int i = 0; i < n; i++){
        if( s[i] == 'I') a[i] = 1;
        if( s[i] == 'V') a[i] = 5;
        if( s[i] == 'X') a[i] = 10;
        if( s[i] == 'L') a[i] = 50;
        if( s[i] == 'C') a[i] = 100;
        if( s[i] == 'D') a[i] = 500;
        if( s[i] == 'M') a[i] = 1000;
    }
    int sum = 0;
    for( int i = 0; i < n - 1; i++){
        if( ( a[i] < a[i + 1] ) && ( b[i] == 0) && ( b[i + 1] == 0) ){
            sum = sum + a[i + 1] - a[i];
            b[i + 1] = 1;
            b[i] = 1;
        }
        else if ( ( a[i] > a[i + 1] && b[i] == 0 && b[i+1] == 0 ) || (a[i] == a[i + 1] && b[i] == 0 && b[i+1] == 0)){
            sum = sum +  a[i];
            b[i] = 1;
        }
    }
    if ( b[n-1] == 0 ) sum += a[n-1];
    return sum;
}