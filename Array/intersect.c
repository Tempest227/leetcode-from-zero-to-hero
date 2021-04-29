/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare( const void *arg1, const void *arg2 )
{
   return ( * ( int* ) arg1 - * ( int* ) arg2 );
}


int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    if (nums1Size == 0 || nums2Size == 0)
    {
        return NULL;
    }

    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);
    
    int k = 0;
    int idx1 = 0;
    int idx2 = 0;
   
    int len = nums1Size > nums2Size ? nums1Size : nums2Size;
    int* result = (int*)malloc(sizeof(int) * len);
    while(idx1 < nums1Size && idx2 < nums2Size)
    {
        if (nums1[idx1] == nums2[idx2])
        {
            result[k] = nums1[idx1];
            k++;
            
            idx1++;
            idx2++;
        }
        else if (nums1[idx1] < nums2[idx2])
        {
            idx1++;
        }
        else
        {
            idx2++;
        }
    }
    returnSize[0] = k;
    return result;
}