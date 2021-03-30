bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int rows=matrix;
    int cols=matrixColSize[0];
    int x=0,y=cols-1;
    
    while(x<=rows-1&&y>=0)
    {
        if(target>matrix[x][y])
        {
            x++;
        }
        else if(target<matrix[x][y])
        {
            y--;
        }
        else
        {
            return true;
        }

    }
    return false;
}