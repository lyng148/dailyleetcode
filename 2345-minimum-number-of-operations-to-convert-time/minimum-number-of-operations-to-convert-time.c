int convertTime(char * current, char * correct){
    int subtract[4] = {1, 5, 15, 60};
    int index = 3;
    int count = 0;

    char h1[3];
    char m1[3];
    char h2[3];
    char m2[3];

    h1[0] = current[0];
    h1[1] = current[1];
    h1[2] = '\0';
    m1[0] = current[3];
    m1[1] = current[4];
    m1[2] = '\0';

    h2[0] = correct[0];
    h2[1] = correct[1];
    h2[2] = '\0';
    m2[0] = correct[3];
    m2[1] = correct[4];
    m2[2] = '\0';

    int hAdded, mAdded;
    hAdded = atoi(h2) - atoi(h1) - 1;
    mAdded = atoi(m2) + 60 - atoi(m1);
    
    count += hAdded;
    while (mAdded > 0)
    {
        if (mAdded - subtract[index] >= 0)
        {
            count++;
            mAdded -= subtract[index];
        }
        else index--;
    }

    return count;
}