int strStr(char * haystack, char * needle){
    int len1 = strlen(haystack);
    int len2 = strlen(needle);
    int stt = -1;
    for( int i = 0; i < len1 - len2 + 1; i++){
        if(haystack[i] == needle[0]){
            stt = i;
            for (int j = i + 1; j < i + len2; j++){
                if( haystack[j] != needle[ j - i]){
                    stt = -1;
                    break;        
                }
            
            }
            if ( stt != -1) return stt;
        }
    }
    return stt;
}