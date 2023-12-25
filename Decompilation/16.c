#include <stdio.h>

int mod = 10;

int power_of_two(int exponent)
{
  int result = 1;
  for (int i = 1; i <= exponent; i++) {
    result = result << 1;
  }
  return result;
}

int main()
{
  printf("Enter N: ");
  int input_number;
  scanf("%d", &input_number);

  int sum = 0; // was uint, but makes no difference
  for (int i = 1; i <= input_number; i++) {
    sum = (sum + power_of_two(i)) % mod;
  }

  printf("Result is %d", sum);
  return 0;
}