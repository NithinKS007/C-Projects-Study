#include <stdbool.h>
#include <stdio.h>
#include "calculator.h"

static void clear_input_buffer(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }
}

static int read_choice(int *choice)
{
    if (scanf("%d", choice) != 1)
    {
        printf("Invalid input\n");
        clear_input_buffer();
        return 0;
    }

    return 1;
}

static int read_float(const char *prompt, float *value)
{
    printf("%s", prompt);

    if (scanf("%f", value) != 1)
    {
        printf("Invalid number\n");
        clear_input_buffer();
        return 0;
    }

    return 1;
}

static int read_int(const char *prompt, int *value)
{
    printf("%s", prompt);

    if (scanf("%d", value) != 1)
    {
        printf("Invalid number\n");
        clear_input_buffer();
        return 0;
    }

    return 1;
}

int main(void)
{
    float num1;
    float num2;
    float result;
    int int_num1;
    int int_num2;
    int choice;

    char history_entry[200];

    bool running = true;

    while (running)
    {
        printf("\n CALCULATOR MENU \n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Power\n");
        printf("7. Square Root\n");
        printf("8. Show Saved History\n");
        printf("9. Exit\n");

        printf("Enter choice: ");
        if (!read_choice(&choice))
        {
            continue;
        }

        switch (choice)
        {
        case 1:
            if (!read_float("Enter first number: ", &num1))
            {
                continue;
            }

            if (!read_float("Enter second number: ", &num2))
            {
                continue;
            }

            result = addition(num1, num2);
            printf("Result = %.2f\n", result);

            snprintf(history_entry, sizeof(history_entry), "%.2f + %.2f = %.2f", num1, num2, result);
            save_history(history_entry);
            break;

        case 2:
            if (!read_float("Enter first number: ", &num1))
            {
                continue;
            }

            if (!read_float("Enter second number: ", &num2))
            {
                continue;
            }

            result = subtraction(num1, num2);
            printf("Result = %.2f\n", result);

            snprintf(history_entry, sizeof(history_entry), "%.2f - %.2f = %.2f", num1, num2, result);
            save_history(history_entry);
            break;

        case 3:
            if (!read_float("Enter first number: ", &num1))
            {
                continue;
            }

            if (!read_float("Enter second number: ", &num2))
            {
                continue;
            }

            result = multiplication(num1, num2);
            printf("Result = %.2f\n", result);

            snprintf(history_entry, sizeof(history_entry), "%.2f * %.2f = %.2f", num1, num2, result);
            save_history(history_entry);
            break;

        case 4:
            if (!read_float("Enter first number: ", &num1))
            {
                continue;
            }

            if (!read_float("Enter second number: ", &num2))
            {
                continue;
            }

            if (num2 == 0)
            {
                printf("Cannot divide by zero\n");
                continue;
            }

            result = division(num1, num2);
            printf("Result = %.2f\n", result);

            snprintf(history_entry, sizeof(history_entry), "%.2f / %.2f = %.2f", num1, num2, result);
            save_history(history_entry);
            break;

        case 5:
            if (!read_int("Enter first integer: ", &int_num1))
            {
                continue;
            }

            if (!read_int("Enter second integer: ", &int_num2))
            {
                continue;
            }

            if (int_num2 == 0)
            {
                printf("Cannot divide by zero\n");
                continue;
            }

            result = (float)modulus(int_num1, int_num2);
            printf("Result = %.2f\n", result);

            snprintf(history_entry, sizeof(history_entry), "%d %% %d = %.2f", int_num1, int_num2, result);
            save_history(history_entry);
            break;

        case 6:
            if (!read_float("Enter first number: ", &num1))
            {
                continue;
            }

            if (!read_float("Enter second number: ", &num2))
            {
                continue;
            }

            result = power(num1, num2);
            printf("Result = %.2f\n", result);

            snprintf(history_entry, sizeof(history_entry), "%.2f ^ %.2f = %.2f", num1, num2, result);
            save_history(history_entry);
            break;

        case 7:
            if (!read_float("Enter number: ", &num1))
            {
                continue;
            }

            if (num1 < 0)
            {
                printf("Cannot take square root of a negative number\n");
                continue;
            }

            result = square_root(num1);
            printf("Result = %.2f\n", result);

            snprintf(history_entry, sizeof(history_entry), "sqrt(%.2f) = %.2f", num1, result);
            save_history(history_entry);
            break;

        case 8:
            show_history();
            break;

        case 9:
            printf("Thank you!\n");
            running = false;
            break;

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
