#pragma once
#include <stdexcept>

bool isNaturalNumber(int number);

void throwExceptionIfIsNotNaturalNumber(int number);

int factorialOfNumber(int number);

float naturalPowerOfNumber(int power_of, float number);

float nMemberOfArithmeticProgression(float first_member, float difference, int n);

float nMemberOfGeometricProgression(float first_member, float denominator, int n);

float sumOfMemberOfArithmeticProgression(float first_member, float difference, int n);

float sumOfMemberOfGeometricProgression(float first_member, float denominator, int n);

int nFibonacciNumber(int n);

int getMinimumValueOfTwo(int first, int second);

int getMinimumValueFromArray(int* array, int length);

int getMinimumIndexOfTwo(int first_index, int second_index, int* array);

int getMinimumIndexFromArray(int* array, int length);

int getMaximumValueOfTwo(int first, int second);

int getMaximumValueFromArray(int* array, int length);

int getMaximumIndexOfTwo(int first_index, int second_index, int* array);

int getMaximumIndexFromArray(int* array, int length);

bool isOrderedArray(int* array, int length);

int getIndexOfArrayElementByValue(int* array, int length, int value, int low_index = 0, int heigth_index = -1);
