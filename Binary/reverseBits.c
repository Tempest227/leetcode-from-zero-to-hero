uint32_t reverseBits(uint32_t n) {
    uint32_t t = 0;
    int i = 0;
    for(i=0;i<32;i++)
    {
        t=t|(((n>>i)&1)<<(32-1-i));
    }
    return t;
}