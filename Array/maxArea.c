int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize - 1;
    int result = 0;
    int h = 0;
    while(left < right)
    {        
        if (height[left] > height[right])
        {
            h = height[right];
            result = result > (right - left) * h ? result : (right - left) * h;
            right--;
        }
        else
        {
            h = height[left];
            result = result > (right - left) * h ? result : (right - left) * h;
            left++;
        }
    }
    return result;
}