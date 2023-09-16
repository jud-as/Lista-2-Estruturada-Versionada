#include <stdio.h>
#include <stdlib.h>

int main() {
    int aux, n, i;
    int array[5]={56, 32, 12, 4, 89};

    for ( n = 1; n <=5; n++)
    {
        for ( i = 0; i <= 3; i++)
        {
            if (array[i] > array[i+1])
            {
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
            }
            
        }
        
    }

    for ( i = 0; i <=4; i++)
    {
        printf("%d \t", array[i]);
    }
    
    return 0;   
}