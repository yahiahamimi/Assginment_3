/******************************************************************************
 *
 * File Name: assg3.c
 *
 * Description: File contains all functions based on the assignment 3 in Standard Diploma
 * each Task has its own Functionality and description individually
 * and the user which functionality he wants to use
 *
 * Author: Yahia Hamimi
 ******************************************************************************/

#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "assg3.h"

/**
 * @brief Prints the elements of the array.
 *
 * @param arr The array to be printed.
 * @param size The size of the array.
 */
void print_Array(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
/**
 * @brief Scans the elements of the array from the user.
 *
 * @param arr The array to be scanned.
 * @param size The size of the array.
 */
void scan_Array(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("\n");
}

/**
 * @name task1
 *
 * @param a The array of integers to be summed.
 * @param numbers_size The size of the array.
 *
 * @details This function takes an array of integers and its size as input and returns the sum of all the elements in the array.
 *
 * @return The sum of the elements in the array.
 */
int task1(int a[], int numbers_size)
{
	int i, sum = 0;
	for (i = 0; i < numbers_size; i++)
		sum += a[i];
	return sum;
}

/**
 * @name task2
 *
 * @param str The string to be checked.
 *
 * @details This function takes a string as input and returns 1 if all characters in the string are distinct, otherwise it returns 0.
 *
 * @return 1 if all characters are distinct, otherwise 0.
 */
int task2(char str[])
{
	int i = 0, j = 0;
	int results = 1;
	// the idea is to compare each element with all the following array elements /
	while (str[i] != '\0') // loop until the end of the string
	{
		j = i + 1; // start compare from the next character
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
			{
				results = 0; // this character is not distinct
				break;
			}
			j++; // to compare with the next character
		}
		i++; // to check the next character
	}
	return results;
}

/**
 * @name task3
 *
 * @param a The array to be sorted.
 * @param size The size of the array.
 *
 * @details This function takes an array of integers and its size as input and sorts the array using the bubble sort algorithm.
 *
 * @return void
 */
void task3(int a[], int size)
{
	int i, j;
	for (i = 0; i < size - 1; i++) /*first loop dosen't need to check the last element because
		   it wasn't the largest one it will be replaced and if it was the largest it will remain*/
	{
		for (j = 0; j < (size - i - 1); j++) /* here in the first iteration j must equal i to check the whole array
		but after the first iteration already the biggest number is the last one thus, no need to check it again*/
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				// this the old way to swap two variables as assginment 1 & 2
				// there is another way to do it via address and another way via xor
			}
		}
	}
}

/**
 * @name task4
 *
 * @param a The array to be sorted.
 * @param size The size of the array.
 *
 * @details This function takes an array of integers and its size as input and sorts the array using the selection sort algorithm.
 *
 * @return void
 */
void task4(int a[], int size)
{
	int i, j;
	for (i = 0; i < size - 1; i++) // first loop that itirates over all of the numbers
	{
		int min_indx = i;
		for (j = i + 1; j < size; j++) /* here in the first iteration j must equal 1 to check all numbers after the first number
		  but in the second itiration i need to check after the first two numbers that already been sorted thus j=i+1*/
		{
			if (a[j] < a[min_indx])
			{
				min_indx = j;
			}
		}
		int temp = a[i];
		a[i] = a[min_indx];
		a[min_indx] = temp;
	}
}

/**
 * @name task5
 *
 * @param a The array to search in.
 * @param size The size of the array.
 * @param element The element to search for.
 *
 * @details This function takes an array of integers, its size, and an element as input and returns the index of the first occurrence of the element in the array.
 * If the element doesn't exist in the array, it returns -1.
 *
 * @return The index of the first occurrence of the element, or -1 if it doesn't exist.
 */
int task5(int a[], int size, int element)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (a[i] == element)
		{
			return i; // whenever it finds the element return its index
		}
	}
	return -1;
}

/**
 * @name task6
 *
 * @param a The array to search in.
 * @param size The size of the array.
 * @param element The element to search for.
 *
 * @details This function takes an array of integers, its size, and an element as input and returns the index of the last occurrence of the element in the array.
 * If the element doesn't exist in the array, it returns -1.
 *
 * @return The index of the last occurrence of the element, or -1 if it doesn't exist.
 */
int task6(int a[], int size, int element)
{
	int i, indx = size;
	for (i = 0; i < size; i++)
	{
		if (a[i] == element)
		{
			indx = i; // whenever it finds the element save its index
		}
	}
	if (indx < size) // if the element already exist in the array return its last index
		return indx;
	return -1;
}

/**
 * @name task7
 *
 * @param n_index The index of the number in the sequence.
 *
 * @details This function takes an integer as input and returns the nth term of the arithmetic series of odd numbers.
 * The series is defined as 1, 3, 5, 7, 9, ... .
 *
 * @return The nth term of the arithmetic series of odd numbers.
 */
int task7(int n_index)
{
	int first_term = 1, diff = 2;
	// we need to find the relation between the index and the corresponding number
	// that's an odd number series thus n_term=(1+(n-1)*2)
	int num = (first_term + (n_index - 1) * diff);
	return num;
}
/**
 * @name task8
 *
 * @param n_index The index of the number in the series.
 *
 * @details This function takes an integer as input and returns the nth term of the geometric series
 * of powers of 3. The series is defined as 1, 3, 9, 27, 81, ... .
 *
 * @return The nth term of the geometric series.
 */
int task8(int n_index)
{
	int i, result = 1;
	if (n_index == 1)
		return 1;
	for (i = 1; i < n_index; i++)
	{
		result *= 3;
	}
	return result;
}

/**
 * @name task9_recursive
 *
 * @param base The index of the Fibonacci number to generate.
 *
 * @details This function takes an integer as input and returns the nth Fibonacci number using a recursive technique.
 * The Fibonacci sequence is defined as 0, 1, 1, 2, 3, 5, 8, ... .
 *
 * @return The nth Fibonacci number.
 */
int task9_recursive(int base)
{ // the fibonnaci function output of (0) is 0 and output of (1) is 1
	if (base == 0 || base == 1)
		return base;
	else
		// then we call the function again inside the function itself
		return (task9_recursive(base - 1) + task9_recursive(base - 2));
}

/**
 * @name task9_default
 *
 * @param base The index of the Fibonacci number to generate.
 *
 * @details This function takes an integer as input and returns the nth Fibonacci number without recursive technique.
 * The Fibonacci sequence is defined as 0, 1, 1, 2, 3, 5, 8, ... .
 *
 * @return The nth Fibonacci number.
 */
int task9_default(int base)
{
	int i, a = 0, b = 1;
	int result;
	if (base == 0 || base == 1) // the fibonnaci function output of (0) is 0 and output of (1) is 1
		return base;
	for (i = 2; i <= base; i++)
	{
		result = a + b;
		a = b;
		b = result;
	}
	return result;
}

/**
 * @name task10
 *
 * @param str The string to convert to lowercase.
 *
 * @details This function takes a string as input and converts all uppercase letters to lowercase.
 *
 * @return None
 */
void task10(char str[])
{
	int i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A') && (str[i] <= 'Z')) // whenever a capital letter is found add 32 to its ascii
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
}

/**
 * @name task11
 *
 * @param str The string to check for the frequency of a certain character.
 * @param ref The character to check for in the string.
 *
 * @details This function takes a string and a character as input and returns the
 * frequency of this character in the string.
 *
 * @return The frequency of the character in the string.
 */
int task11(char str[], char ref)
{
	int i = 0, counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ref)
			counter++;
		i++;
	}
	return counter;
	/*if (counter != 0)
		return counter;
	else
		return 0;*/
}

/**
 * @name task12
 *
 * @param str The string to get its length.
 *
 * @details This function takes a string as input and returns its length.
 *
 * @return The length of the string.
 */
int task12(char str[])
{
	int i = 0, counter = 0;
	while (str[i] != '\0')
	{
		counter++;
		++i;
	}
	return counter - 1;
	/*important note getcahr increase a character to the recieved string thus the while (str[i])
					{
						counter++
					}
					will return counter=str size -1
	*/
	/*after this loop ptr will be shifted by string size + 1 cause getchar() aka the pointer will be pointing to empety place
	/after the null terminator thus we need to decrease the pointer first to be pointing to the null terminator*/
}

/**
 * @name task13
 *
 * @param str The string to remove all characters expect alphabet.
 *
 * @details This function takes a string as input and removes all characters from it
 * that are not alphabets.
 *
 * @return void
 */
void task13(char str[])
{
	int i = 0, j = 0;
	for (i = 0; i < str[i]; i++) // loop thats itirates over the whole string to check every character
	{
		while (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] == '\0'))
		// as long as this character is not an alphabet nor a '\0' the program won't enter the loop &won't edit enything
		{
			for (j = i; str[j] != '\0'; j++)
			// in this loop whenever encounter a special character it will shift it to be the last character in the string
			{
				str[j] = str[j + 1];
			}
			// after being the last charcter in the string it will be assgined to null aka removed
			str[j] = '\0';
		}
	}
}

/**
 * @name task14
 *
 * @param str The string to be reversed.
 *
 * @details This function takes a string as input and reverses it.
 *
 * @return void
 */
void task14(char str[])
{
	int i = 0, j;
	char temp;
	/*size_str = sizeof(str); we can't do this as the size of array won't be considered as an argument in the function
	instead it will return the size'const char size*' pointer*/
	int actual_str_len = 0;
	while (str[i] != '\0')
	{
		actual_str_len++;

		i++;
	}
	// instead of this while loop we could use strlen() but the question request that
	for (i = 0, j = (actual_str_len - 1); i <= j; i++, j--) /*this loop has 2 counters one count from the begin and the other count from the last charcter in the string
			 thus i need to count the numbers of characters in the string without using the built i function strlen()*/
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}

	/*while(str[i]!='\0'){
		temp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = temp;
	}*/
}

/**
 * @name task15
 *
 * @param str The string to remove all spaces from.
 *
 * @details This function takes a string as input and removes all spaces from it.
 *
 * @return void
 */
void task15(char str[])
{
	int i = 0, j = 0;
	for (i = 0; i < str[i]; i++) // loop thats itirates over the whole string to check every character
	{
		while (!(str[i] == '\0') && str[i] == ' ')
		// as long as this character is not an space nor a '\0' the program won't enter the loop &won't edit enything
		{
			for (j = i; str[j] != '\0'; j++)
			// this loop will shift the space ' ' to be the last character in the string
			{
				str[j] = str[j + 1];
			}
			// after being the last charcter in the string it will be assgined to null aka removed
			str[j] = '\0';
		}
	}
}

/**
 * @name task16
 *
 * @param arr The array to reverse.
 * @param size The size of the array.
 *
 * @details This function takes an array of integers and its size as input and reverses the array.
 *
 * @return void
 */
void task16(int arr[], int size)
{
	int i, j, temp;
	for (i = 0, j = size - 1; i < j; i++, j--)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

/**
 * @name task17
 *
 * @param a_size The size of the first array.
 * @param a The first array.
 * @param b_size The size of the second array.
 * @param b The second array.
 *
 * @details This function takes two arrays of integers with different sizes as input and swaps them.
 *
 * @return void
 */
void task17(int a_size, int *a, int b_size, int *b)
{
	int temp;
	int i;
	for (i = 0; i < b_size; i++) // swap must be done with the smallest size
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

/**
 * @name task18
 *
 * @param a The array to search in.
 * @param size The size of the array.
 * @param element The element to search for.
 *
 * @details This function takes an array of integers, its size, and an element as input and returns the count
 * of the largest consecutive occurrence of the element in the array.
 *
 * @return The largest consecutive count of the element, or 0 if it doesn't exist.
 */
int task18(int a[], int size, int element)
{
	int i, consecutive_occurrence = 0, largest_occurrence = 0;
	for (i = 0; i < size; i++)
	{
		if (a[i] == element)
		{
			// Increment the current consecutive count each time the element is found
			consecutive_occurrence++;
			// Compare the current consecutive count with the largest consecutive count
			if (largest_occurrence <= consecutive_occurrence)
				largest_occurrence = consecutive_occurrence;
		}
		else
			// if the element not found rest the consecutive count
			consecutive_occurrence = 0;
	}
	return largest_occurrence;
}

/**
 * @name task19
 *
 * @param arr1 The first array to compare.
 * @param arr2 The second array to compare.
 * @param size The size of the arrays.
 *
 * @details This function takes two arrays of integers with the same size as input and compares them.
 * It returns 1 if any two elements with the same index in the two arrays aren't equal, otherwise it returns 0.
 *
 * @return 1 if any two elements with the same index aren't equal, otherwise 0.
 */
int task19(int arr1[], int arr2[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (arr1[i] != arr2[i])
		{
			return 1; // if any two elements with the same index aren't equal return 1 & terminate
		}
	}
	return 0;
}
/**
 * @name task20
 *
 * @param Lower The lower bound of the range.
 * @param Upper The upper bound of the range.
 *
 * @details This function takes two 8-bits unsigned integers as input and returns an array containing the values between the two integers
 * while excluding the two integers.
 * If the two integers are equal or differ by one, it returns an array of size 2 with all its elements equal to 0xFF.
 *
 * @return An array containing the values between the two integers, or an array of size 2 with all its elements equal to 0xFF if the two integers are equal or differ by one.
 */
int *task20(int Lower, int Upper)
{
	int i;
	if (Lower >= Upper || (Upper - Lower) == 1)
	{
		int *arr = (int *)malloc(2 * sizeof(int));
		/*another solution instead of using malloc from stdlib is defining a global array outside the function
		(which is given as a requirement in the question) so we can retain its value rather than being deleted after ending the function*/
		for (i = 0; i < 2; i++)
		{
			arr[i] = 0xFF;
		}

		return arr;
	}

	else
	{
		int arr_size = Upper - Lower - 1;
		int *arr = (int *)malloc(arr_size * sizeof(int));

		for (i = 0; i < arr_size; i++)
		{
			arr[i] = Upper - 1 - i;
		}
		return arr; /*array name is a constant pointer to it's first element thus in c if i want a function to return an array
		 we return its name then we loop with the size using it*/
	}
}
/* @name task20
 *
 * @param Lower The lower bound of the range.
 * @param Upper The upper bound of the range.
 *
 * @details This function takes two 8-bits unsigned integers as input and returns an array containing the values between the two integers
 * while including the two integers.
 * If the two integers are equal or differ by one, it returns an array of size 2 with all its elements equal to 0xFF.
 *
 * @return An array containing the values between the two integers, or an array of size 2 with all its elements equal to 0xFF if the two integers are equal or differ by one.
 */
int *task21(int Lower, int Upper)
{
	int i;
	if (Lower >= Upper || (Upper - Lower) == 1)
	{
		int *arr = (int *)malloc(2 * sizeof(int));
		for (i = 0; i < 2; i++)
		{
			arr[i] = 0xFF;
		}

		return arr;
	}

	else
	{
		int arr_size = Upper - Lower + 1;
		int *arr = (int *)malloc(arr_size * sizeof(int));

		for (i = 0; i < arr_size; i++)
		{
			arr[i] = Upper - i;
		}
		return arr;
	}
}
/**
 * @name task22
 *
 * @param arr_old The array to be processed.
 * @param old_size The size of the array.
 * @param arr_new The array to store the output in.
 * @param new_size The size of the output array.
 *
 * @details This function takes an array of integers, its size, and an output array and its size as input and filters out the array by removing consecutive duplicate elements.
 * It stores the filtered elements in the output array and updates the output array size.
 *
 * @return 1 if the function was successful, otherwise 0.
 */
int task22(int arr_old[], int old_size, int arr_new[], int *new_size) /*take care we needed to send (new_size) to the function by address cause we
	 don't know the what size will be exactly thus using by address techniuqe
	 as every time it expands in the function its value change and we can retain its value in main*/
{
	int i;
	if (old_size == 0)
		return 0;
	for (i = 0; i < old_size - 1; i++)
	{
		if (arr_old[i] != arr_old[i + 1]) // compare each element with the next one if it's different store it in the new array
		{
			arr_new[*new_size] = arr_old[i];
			// every time we assgin a value to arr_new increament *new_size
			(*new_size)++;
		}
	}
	// every time we assgin a value to arr_new increament *new_size
	arr_new[*new_size] = arr_old[i]; // in the last element we don't have a next element to compare with thus we need to store it anyways
	(*new_size)++;
	return 1;
}

/**
 * @name task23
 *
 * @param str The string to process.
 *
 * @details This function takes a string as input and counts the frequency of each character in the string.
 * It prints the frequency of each character in the string.
 *
 * @return void
 */
void task23(char str[])
{
	int char_freq[256] = {0};
	int i;
	for (i = 0; str[i] != '\0'; i++)
	{
		char_freq[(int)str[i]]++; /* Increment the value of this array element */
								  // example cahr_freq[97(a)]=1
	}

	for (i = 0; i < 256; i++)
	{ // when ever there is avalue print it
		if (char_freq[i] != 0)
		{
			printf("%c %d\n", i, char_freq[i]);
		}
	}
}
/* this code checks only small alphabet and return a arr[26] contians the values of charcaters frequencies that appeare and the rest is zero
int alphabet_arr[26] = {0};

int *task23(char str[])
{
	int i = 0, j, k;

	for (j = 'a', k = 0; j <= 'z'; j++, k++)
	{
		i = 0;
		while (str[i] != '\0')
		{
			if (str[i] == j)
			{
				alphabet_arr[k]++;
			}
			i++;
		}
	}
	return alphabet_arr;
}
*/

/**
 * @name task24
 *
 * @param arr The array to process.
 * @param size The size of the array.
 *
 * @details This function takes an array of integers and its size as input and returns the second maximum number in the array.
 *
 * @return The second maximum number in the array.
 */
int task24(int arr[], int size)
{
	int i, first_max, second_max;
	// assume first and second maximum equal the first element in the array
	first_max = arr[0];
	second_max = arr[0];
	for (i = 1; i < size; i++) // start compare from the second element
	{
		if (arr[i] >= first_max)
			first_max = arr[i];
	}
	for (i = 1; i < size; i++)
	{
		if (arr[i] >= second_max && arr[i] < first_max)
			second_max = arr[i];
	}
	return second_max;
}

int main(void)
{
	/* Set stdin and stdout to unbuffered mode to solve the problems with scanf and printf */
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int task;
	printf("Enter the specific task to operate:\n");
	scanf("%d", &task);
	/* switch case for each task */
	switch (task)
	{
	case 1:
	{
		int arr1[SIZE];
		printf("Enter the numbers to be summed:\n");
		scan_Array(arr1, SIZE); // my function to scan an array through loops instead of writing it each time
		printf("the summation of the array you have enterd is %d\n", task1(arr1, SIZE));
		break;
	}
	case 2:
	{
		char str[SIZE_str];
		printf("Please enter ther required string message:");
		getchar();
		fgets(str, sizeof(str), stdin); // we can use gets(str) but fgets is more safer to use
		// or another solution if ((scanf("%*[^\n]") == EOF) || (getchar() == EOF)) {
		//  handle end-of-file or I/O error ...}
		printf("%d", task2(str));
		break;
	}
	case 3:
	{
		int arr3[SIZE];
		printf("Enter array to be bubble-sorted:\n");
		scan_Array(arr3, SIZE);
		task3(arr3, SIZE);
		printf("The bubble-sorted would be:\n");
		print_Array(arr3, SIZE);
		break;
	}
	case 4:
	{
		int arr4[SIZE];
		printf("Enter array to be selection-sorted:\n");
		scan_Array(arr4, SIZE);
		task4(arr4, SIZE);
		printf("The selection-sorted would be:\n");
		print_Array(arr4, SIZE);
		break;
	}
	case 5:
	{
		int arr5[SIZE], num;
		printf("Enter the array:\n");
		scan_Array(arr5, SIZE);
		printf("Enter the number you want to search for:\n");
		scanf("%d", &num);
		printf("%d", task5(arr5, SIZE, num));
		break;
	}
	case 6:
	{
		int arr6[SIZE], num;
		printf("Enter the array:\n");
		scan_Array(arr6, SIZE);
		printf("Enter the number you want to search for:\n");
		scanf("%d", &num);
		printf("%d", task6(arr6, SIZE, num));
		break;
	}
	case 7:
	{
		int num;
		printf("enter the nth term to be calculated in the odd numbers series:\n");
		scanf("%d", &num);
		printf("%d", task7(num));
		break;
	}
	case 8:
	{
		int num;
		printf("enter the nth term to be calculated in the power of 3 geometric series:\n");
		scanf("%d", &num);
		printf("%d", task8(num));
		break;
	}
	case 9:
	{
		int i, num, option;
		printf("enter the method:\n 1:default method \n 2:recursive method\n");
		scanf("%d", &option);
		printf("enter the required number:\n");
		scanf("%d", &num);
		if (option == 1)
		{
			printf("the fibonaci series for %d order would be:\n", num);
			for (i = 0; i < num; i++)
				printf("%d ", task9_default(i));
		}
		else if (option == 2)
		{
			printf("the fibonaci series for %d order would be:\n", num);
			for (i = 0; i < num; i++)
				printf("%d ", task9_recursive(i));
		}
		break;
	}
	case 10:
	{
		char str[SIZE_str];
		printf("Please enter ther required string:");
		getchar();
		fgets(str, sizeof(str), stdin);
		task10(str);
		printf("the converted message will be:\n");
		puts(str);
		// printf("%d",sizeof(str));
		break;
	}
	case 11:
	{
		char str[SIZE_str];
		char chr;
		printf("enter the character to be looked for:");
		scanf(" %c", &chr);
		printf("Please enter ther required string:");
		getchar();
		fgets(str, sizeof(str), stdin);
		printf("%d", task11(str, chr));
		break;
	}
	case 12:
	{
		char str[SIZE_str];
		printf("Please enter ther required string:");
		getchar();
		fgets(str, sizeof(str), stdin);
		printf("the length of the given string is:%d", task12(str));
		break;
	}
	case 13:
	{
		char str[SIZE_str];
		printf("Please enter ther required string:");
		getchar();
		fgets(str, sizeof(str), stdin);
		task13(str);
		printf("the new string will be:");
		puts(str);
		printf("the new string size is:%d", strlen(str));
		break;
	}
	case 14:
	{
		char str[SIZE_str];
		printf("Please enter ther required string:");
		getchar();
		fgets(str, sizeof(str), stdin);
		task14(str);
		printf("the new string will be:");
		puts(str);
		break;
	}
	case 15:
	{
		char str[SIZE_str];
		printf("Please enter ther required string:");
		getchar();
		fgets(str, sizeof(str), stdin);
		task15(str);
		printf("the new string will be:");
		puts(str);
		break;
	}
	case 16:
	{
		int arr[SIZE];
		printf("Enter the array to be inverted:\n");
		scan_Array(arr, SIZE);
		task16(arr, SIZE);
		printf("The inverted array would be:\n");
		print_Array(arr, SIZE);
		break;
	}
	case 17:
	{
		int arr1[SIZE], arr2[SIZE_2];
		printf("Enter the first array:\n");
		scan_Array(arr1, SIZE);
		printf("Enter the second array:\n");
		scan_Array(arr2, SIZE_2);
		task17(SIZE, arr1, SIZE_2, arr2);
		printf("Array1 after the Swap : ");
		print_Array(arr1, SIZE);
		printf("Array2 after the Swap : ");
		print_Array(arr2, SIZE_2);
		break;
	}
	case 18:
	{
		int arr[SIZE], num;
		printf("Enter the array:\n");
		scan_Array(arr, SIZE);
		printf("Enter the number you want to search for:\n");
		scanf("%d", &num);
		printf("%d", task18(arr, SIZE, num));
		break;
	}
	case 19:
	{
		int arr1[SIZE], arr2[SIZE];
		printf("Enter the first array:\n");
		scan_Array(arr1, SIZE);
		printf("Enter the second array:\n");
		scan_Array(arr2, SIZE);
		printf("%d", task19(arr1, arr2, SIZE));
		break;
	}
	case 20:
	{
		int Upper, Lower, arr_size;
		printf("Enter the Lower value:\n");
		scanf("%d", &Lower);
		printf("Enter the Upper value:\n");
		scanf("%d", &Upper);
		if (Lower >= Upper || (Upper - Lower) == 1)
			arr_size = 2;
		else
			arr_size = Upper - Lower - 1;
		print_Array(task20(Lower, Upper), arr_size);
		break;
	}
	case 21:
	{
		int Upper, Lower, arr_size;
		printf("Enter the Lower value:\n");
		scanf("%d", &Lower);
		printf("Enter the Upper value:\n");
		scanf("%d", &Upper);
		if (Lower >= Upper || (Upper - Lower) == 1)
			arr_size = 2;
		else
			arr_size = Upper - Lower + 1;
		print_Array(task21(Lower, Upper), arr_size);
		break;
	}
	case 22:
	{
		int arr1[SIZE];
		printf("Enter the array:\n");
		scan_Array(arr1, SIZE);
		int arr2[SIZE], newsize = 0;
		int result;
		result = task22(arr1, SIZE, arr2, &newsize);
		if (result == 1)
		{
			printf("The new array would be:\n");
			print_Array(arr2, newsize);
		}
		break;
	}
	case 23:
	{
		char str[SIZE_str];
		printf("Please enter ther required string:");
		getchar();
		fgets(str, sizeof(str), stdin);
		printf("the characters frequncies would be:");
		task23(str);
		break;
	}
	case 24:
	{
		int arr[SIZE];
		printf("Enter the required array:\n");
		scan_Array(arr, SIZE);
		printf("the seconed maximum number in this array is:%d\n", task24(arr, SIZE));
		break;
	}
	default:
		printf("You have entered an invalid task number\n");
	}
}
