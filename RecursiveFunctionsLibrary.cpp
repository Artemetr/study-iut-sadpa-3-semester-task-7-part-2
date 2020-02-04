#include "RecursiveFunctionsLibrary.h"

bool isNaturalNumber(int number)
{
	return number > 0;
}

void throwExceptionIfIsNotNaturalNumber(int number)
{
	if (!isNaturalNumber(number)) {
		throw std::invalid_argument("Current number isn't natural!");
	}
}

int factorialOfNumber(int number)
{
	throwExceptionIfIsNotNaturalNumber(number);

	if (number == 1) {
		return 1;
	}
	else {
		int lower_number = number - 1;
		return number * factorialOfNumber(lower_number);
	}
}

float naturalPowerOfNumber(int power_of, float number)
{
	//throwExceptionIfIsNotNaturalNumber(number);

	if (number == 0) {
		return 1;
	}
	else {
		int lower_power_of = power_of - 1;
		return number * naturalPowerOfNumber(lower_power_of, number);
	}
}

float nMemberOfArithmeticProgression(float first_member, float difference, int n)
{
	if (n == 1) {
		return first_member;
	}
	else {
		int lower_n = n - 1;
		return nMemberOfArithmeticProgression(first_member, difference, lower_n) + difference;
	}
}

float nMemberOfGeometricProgression(float first_member, float denominator, int n)
{
	if (n == 1) {
		return first_member;
	}
	else {
		int lower_n = n - 1;
		return nMemberOfGeometricProgression(first_member, denominator, lower_n) * denominator;
	}
}

float sumOfMemberOfArithmeticProgression(float first_member, float difference, int n)
{
	if (n == 1) {
		return first_member;
	}
	else {
		int lower_n = n - 1;
		return sumOfMemberOfArithmeticProgression(first_member, difference, lower_n) + nMemberOfArithmeticProgression(first_member, difference, n);
	}
}

float sumOfMemberOfGeometricProgression(float first_member, float denominator, int n)
{
	if (n == 1) {
		return first_member;
	}
	else {
		int lower_n = n - 1;
		return sumOfMemberOfGeometricProgression(first_member, denominator, lower_n) + nMemberOfGeometricProgression(first_member, denominator, n);
	}
}

int nFibonacciNumber(int n)
{
	if (n < 3) {
		return 1;
	}
	else {
		int first_lower_n = n - 1;
		int second_lower_n = n - 1;
		return nFibonacciNumber(first_lower_n) + nFibonacciNumber(second_lower_n);
	}
}

int getMinimumValueOfTwo(int first, int second)
{
	return first ? first < second : second;
}

int getMinimumValueFromArray(int* array, int length)
{
	if (length == 1) {
		return array[0];
	}
	if (length == 2) {
		return getMinimumValueOfTwo(array[0], array[1]);
	}
	int lower_length = length - 1;
	return getMinimumValueOfTwo(array[lower_length], getMinimumValueFromArray(array, lower_length));
}

int getMinimumIndexOfTwo(int first_index, int second_index, int* array)
{
	return first_index ? array[first_index] < array[second_index] : second_index;
}

int getMinimumIndexFromArray(int* array, int length)
{
	if (length == 1) {
		return 0;
	}
	if (length == 2) {
		return getMinimumIndexOfTwo(0, 1, array);
	}
	int lower_length = length - 1;
	return getMinimumIndexOfTwo(lower_length, getMinimumIndexFromArray(array, lower_length), array);
}

int getMaximumValueOfTwo(int first, int second)
{
	return first ? first > second : second;
}

int getMaximumValueFromArray(int* array, int length)
{
	if (length == 1) {
		return array[0];
	}
	if (length == 2) {
		return getMaximumValueOfTwo(array[0], array[1]);
	}
	int lower_length = length - 1;
	return getMaximumValueOfTwo(array[lower_length], getMaximumValueFromArray(array, lower_length));
}

int getMaximumIndexOfTwo(int first_index, int second_index, int* array)
{
	return first_index ? array[first_index] > array[second_index] : second_index;
}

int getMaximumIndexFromArray(int* array, int length)
{
	if (length == 1) {
		return 0;
	}
	if (length == 2) {
		return getMaximumIndexOfTwo(0, 1, array);
	}
	int lower_length = length - 1;
	return getMaximumIndexOfTwo(lower_length, getMaximumIndexFromArray(array, lower_length), array);
}

bool isOrderedArray(int* array, int length)
{
	for (int i = 1; i < length; i++) {
		if (array[i] < array[i - 1]) {
			return false;
		}
	}
	return true;
}

int getIndexOfArrayElementByValue(int* array, int length, int value, int low_index, int heigth_index)
{
	if (!(heigth_index < length && low_index >= 0) || heigth_index < low_index) {
		throw std::invalid_argument("Index out of range!");
	}
	if (heigth_index == -1) {
		heigth_index = length - 1;
		if (low_index == 0) {
			if (!isOrderedArray(array, length)) {
				throw std::invalid_argument("This is an unordered array!");
			}
		}
	}
	int middle_index = (low_index + heigth_index) / 2;
	if (array[middle_index] < value) {
		low_index = middle_index;
	}
	else if (array[middle_index] > value) {
		heigth_index = middle_index;
	}
	else {
		return middle_index;
	}
	return getIndexOfArrayElementByValue(array, length, value, low_index, heigth_index);
}
