double findMedianSortedArrays(int nums1, int nums1Size, int nums2, int nums2Size){
    int totalSize = nums1Size + nums2Size;
    int arr = (int)malloc(sizeof(int)(totalSize));
    int n1 = 0;
    int n2 = 0;
    int i = 0;

    while(n1<nums1Size && n2<nums2Size)
    {
        if(nums1[n1]>nums2[n2])
        {
            arr[i] = nums2[n2];
            n2++;
        }
        else
        {
            arr[i] = nums1[n1];
            n1++;
        }
        i++;
    }
    
    while(n1<nums1Size)
    {
        arr[i] = nums1[n1];
        i++;
        n1++;
    }
    while(n2<nums2Size)
    {
        arr[i] = nums2[n2];
        i++;
        n2++;
    }
    for(int i=0;i<totalSize;i++)
    {
        printf(%d ,arr[i]);
    }
    if(totalSize % 2 == 0)
    {
        return (double)(arr[totalSize2]+arr[totalSize2-1])  2;
    }
    else
    {
        return (double)arr[totalSize2];
    }
    return 0;
}