#include <stdio.h>
#include <cs50.h>

int main (void)

{
    double dollar;
    int cent, score, nominalIndex;
    int coinsNominals[4] = { 25, 10, 5, 1 };
    do
    {
        printf("O hai! How mach change is owed?\n");
        dollar = GetDouble();
    }
    while (dollar < 0);
    //перевод долларов в центы
    cent = dollar*100;
    nominalIndex = 0;
    
    for(score = 0; cent > 0;)
    {
        if (cent >= coinsNominals[nominalIndex]) 
        {
            cent = cent - coinsNominals[nominalIndex];
            score++;
            continue;
        }
        nominalIndex++;
    }

    printf("%i\n", score);
}