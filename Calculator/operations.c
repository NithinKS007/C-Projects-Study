#include <stdio.h>
#include <math.h>
#include "calculator.h"

float addition(float a, float b)
{
    return a + b;
}

float subtraction(float a, float b)
{
    return a - b;
}

float multiplication(float a, float b)
{
    return a * b;
}

float division(float a, float b)
{
    return a / b;
}

int modulus(int a, int b)
{
    return a % b;
}

float power(float a, float b)
{
    return powf(a, b);
}

float square_root(float a)
{
    return sqrtf(a);
}

void save_history(const char *entry)
{
    FILE *file = fopen("history.txt", "a");

    if (file == NULL)
    {
        printf("Error opening history file\n");
        return;
    }

    fprintf(file, "%s\n", entry);

    fclose(file);
}

void show_history(void)
{
    FILE *file = fopen("history.txt", "r");

    char line[200];

    if (file == NULL)
    {
        printf("No history found\n");
        return;
    }

    printf("\n SAVED HISTORY \n");

    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }

    fclose(file);
}
