/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    // *returnSize is a pointer to an integer
    // **returnColumnSizes is a pointer to an array of integers

    *returnSize = numRows;
    
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    // create a 2D-array
    int** triangle = (int**)malloc(numRows * sizeof(int*));
    
    // allocate memory and populate the rows
    for(int i = 0; i < numRows; i++){
        
        (*returnColumnSizes)[i] = i+1;

        triangle[i] = (int*)malloc( (i+1) * sizeof(int));

        for(int j = 0; j <= i; j++){

            if(j == 0 || j == i){
                triangle[i][j] = 1;
            }else{
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }

        }
        
    }
    
    return triangle;
    
}