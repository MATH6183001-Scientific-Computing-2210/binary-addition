#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool BinaryCharToBinaryBoolean(char c)
{
  return (c == '1');
}

char BinaryBooleanToBinaryChar(bool b)
{
  if (b) {
    return '1';
  }
  return '0';
}

void CLA(char x[], char y[], unsigned int bitLength, char *output)
{
  bool cin = false, a, b, g, p;

  int i;
  for (i = bitLength; i > 0; i--)
  {
    a = BinaryCharToBinaryBoolean(x[i - 1]);
    b = BinaryCharToBinaryBoolean(y[i - 1]);

    output[i] = BinaryBooleanToBinaryChar((a ^ b) ^ cin);

    g = a & b;
    p = a ^ b;
    cin = g | (p & cin);
  }

  output[0] = BinaryBooleanToBinaryChar(cin);
}
