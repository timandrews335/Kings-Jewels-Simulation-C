#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Test commit from Kubuntu.  Test from 16.04.  Test from Windows 10.

//Definition of jewel bag
typedef struct {
  int jewel[10];
} Bag;

//Gets a bag of jewels
Bag getBag()
{
    Bag b;
    int i;
    for (i = 0; i < 10; ++i) 
    {
        b.jewel[i] = rand() % 10;
        //printf( "%d\n", b.jewel[i]);
    }
    return b;
}

//Picks a jewel from the bag
int pickAJewel(int howManyToLookAt)
{
    Bag bagOfJewels = getBag();
    
    int counter = 0;
    int currentValue;
    int highestValueSoFar = -1;
    int highestValueInBag;
    int selectedValue = -1;

    //Fiugure out the highest value in the bag of jewels
    for (counter = 0; counter < 10; ++counter)
    {
        currentValue = bagOfJewels.jewel[counter];
        if (currentValue >= highestValueSoFar)
        {
            highestValueSoFar = currentValue;
        }
    }
    highestValueInBag = highestValueSoFar;

    //Reset our variables which track the jewels that we are examining
    counter = 0;
    currentValue = 0;
    highestValueSoFar = -1;

    //We have to look at a set number of jewels.  Find the highest number in that set
    for (counter = 0; counter < howManyToLookAt; ++counter)
    {
        currentValue = bagOfJewels.jewel[counter];
        if (currentValue >= highestValueSoFar)
        {
            highestValueSoFar = currentValue;
        }
    }

    //Now we look at the rest of the jewels. Find the next one that is greater than or equal to the highest
    selectedValue = -1;
    while (counter  < 10)
    {
        if (bagOfJewels.jewel[counter] >= highestValueSoFar && counter < 10)
        {
            selectedValue =  bagOfJewels.jewel[counter];  
            break;
        }
        ++counter;
    }

    //We keep the last value if all else failshttps://github.com/timandrews335/Kings-Jewels-Simulation-C.git
    if (selectedValue == -1)
    {
        selectedValue = bagOfJewels.jewel[9];
    }

    return selectedValue;
}


int main()
{

    int howManyJewelsToLookAt = 3;
    int simulationCount = 1000;
    int counter = 0;   
    int aggregateResults[10] = {0};
    srand(time(NULL));

    //Prompt the user for input
    printf("How many simulations do you want to run?  ");
    scanf ("%d", &simulationCount);
    printf("How many jewels do you want to examine before deciding?  ");
    scanf ("%d", &howManyJewelsToLookAt);
    printf("\n");
   
    //Perform a number of simulations
    for (counter = 0; counter < simulationCount; ++counter)
    {
        //Get the result
        int result = pickAJewel(howManyJewelsToLookAt);
    
        //Aggregate the results
        ++aggregateResults[result];
    }

    //Print the aggreate results
    printf("Results for looking at %d jewels", howManyJewelsToLookAt);
    printf("\nValue\tCount\tPct\n");
    for (counter = 0; counter < 10; ++counter)
    {
        printf("%d\t%d\t%f\n", counter, aggregateResults[counter], (double)(aggregateResults[counter]) / (double)simulationCount);
    }

    return 0;
}
