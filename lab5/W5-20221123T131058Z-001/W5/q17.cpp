int foldShift(long long key, int addressSize)
{
    // Fold shift method in hashing
    // TODO
    int result = 0;
    int shift = 0;
    while (key > 0)
    {
        result ^= (key & 0xFFFF) << shift;
        key >>= 16;
        shift = (shift + 16) % addressSize;
    }
    return result;
}

int rotation(long long key, int addressSize)
{
}