// int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
    // int i;
    // long sum=0;
    // int retLen=0;
    // for(i=0;i<ASize;i++)
    // {
        // sum=sum*10+A[i];//存在溢出问题
    // }
    // sum+=K;
    // long t=sum;
    // while(t!=0||ASize>0)
    // {
        // retLen++;
        // t/=10;
        // ASize--;
    // }
    // int* arr=(int*)malloc(sizeof(int)*retLen);
    // for(i=retLen-1;i>=0;i--)
    // {
        // int t=sum%10;
        // arr[i]=t;
        // sum/=10;
    // }
    // returnSize[0]=retLen;
    // return arr;
// }


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* num, int numSize, int k, int* returnSize){
    int kSize=0;
    int i;
    int remainder=0;
    int t=k;
    int total=0;
    int next=0;

    while(t!=0)
    {
        t/=10;
        kSize++;
    }

    int len=kSize>numSize?kSize+1:numSize+1;
    int* arr=(int*)malloc(sizeof(int)*(len+1));
    
    int j=0;
    for(i=numSize-1;i>=0;i--)
    {
        remainder=k%10;
        k=k/10;
        total=num[i]+remainder+next;
        next=total/10;
        arr[j]=total%10;
        j++;
    }
    k=k+next;
    while(k!=0)
    {
        arr[j]=k%10;
        k=k/10;
        j++;
    }
    
    int begin=0;
    int end=j-1;
    returnSize[0]=end+1;
    while(begin<end)
    {
        int t=arr[begin];
        arr[begin]=arr[end];
        arr[end]=t;
        begin++;
        end--;
    }
    return arr;
}
