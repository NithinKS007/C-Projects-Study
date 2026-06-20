#ifndef CALCULATOR_H
#define CALCULATOR_H

float addition(float a, float b);
float subtraction(float a, float b);
float multiplication(float a, float b);
float division(float a, float b);
int modulus(int a, int b);
float power(float a, float b);
float square_root(float a);

void save_history(const char *entry);
void show_history(void);

#endif
