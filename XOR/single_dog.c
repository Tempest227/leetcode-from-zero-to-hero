int* singleNumbers(int* nums, int numsSize, int* returnSize){
    int i=0,t=0;
    int pos;
    int* arr=(int*)malloc(sizeof(int)*2);
    *returnSize=2;
	//数组元素异或，最终得到两只单身狗异或的结果
    for(i=0;i<numsSize;i++)
    {
        t = t^nums[i];
    }
    //求出异或结果最低位为1的索引(pos)
    for(i=0;i<32;i++)
    {
        if((t>>i)&1==1)
        {
            pos=i;
            break;
        }
    }
    int a1=0,a2=0;
    //按照最低位为1/0，分别进行异或，最终得到两只单身狗
    for(i=0;i<numsSize;i++)
    {
        if((nums[i]>>pos)&1 == 1)
        {
            a1=a1^nums[i];
        }
        else
        {
            a2=a2^nums[i];
        }
    }
    arr[0]=a1;
    arr[1]=a2;

    return arr;
}