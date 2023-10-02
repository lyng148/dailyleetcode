bool winnerOfGame(char * colors){
    int a = 0, b = 0, len = strlen(colors);

    for (int i = 1; i < len - 1; i++) {
        if (colors[i] == colors[i - 1] && colors[i] == colors[i + 1]) {
            if (colors[i] == 'A') a += 1;
            else b += 1;
        }
    }
    return a > b;

}