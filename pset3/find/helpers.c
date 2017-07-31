/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    // if n is negtive
    if (n < 0)
    {
        return false;
    }
    else
    {
        // set initial middle point of sorted array
        int z = n / 2;
        // compare value to middle point and update as appropriate
        for (int i = 0; i < n; i++)
        {
            if (value == values[z])
            {
                return true;
            }
            if (value < values[z])
            {
                z = z / 2;
            }
            else
            {
                z += ((n - z) / 2);
            }
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    
    for (int j = 0; j < n - 1; j++)
    {
        
        for (int k = 0; k < n - j - 1; k++)
        {
            if (values[k] > values[k + 1])
            {
                int l = values[k];
                values[k] = values[k + 1];
                values[k + 1] = l;
            }
        }
    }
    return;
}