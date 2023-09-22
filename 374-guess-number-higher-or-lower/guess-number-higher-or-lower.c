int guessNumber(int n) {
    int low = 1, high = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int result = guess(mid);

        if (result == 0) {
            return mid;
        } else if (result == -1) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}