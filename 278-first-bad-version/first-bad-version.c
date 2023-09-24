// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int low = 1, high = n, k = 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isBadVersion(mid))
        {
            k = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return k;
}