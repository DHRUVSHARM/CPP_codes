void sortZeroesAndOne(int *input, int size)
{
    //Write your code here
    //iterate the array once and use O(1) space

    int index = 0;

    for(int i=0 ; i < size ; i++ ){
        
        if( input[i] == 1 ){continue;}

        while( index < i  && input[index] != 1 ){
            //finding the first one in range possible
            index++;
        }

        swap( input[index] , input[i] );

    } 
}


