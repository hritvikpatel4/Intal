// Header file for the intal library. 
// This file contains the declarations for the functions in the intal library.

// @author: Hritvik Patel [hritvik.patel4@gmail.com]

// MIT License

// Copyright (c) 2020 Hritvik Patel

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// ----------------------------------------------------------------------------

// Library "intal" - Integer of arbitray length
// intal is a nonnegative integer of arbitrary length (not more than 1000 decimal digits).
// The integer is stored as a null terminated string of ASCII characters.
// String of decimal digits ('0' thru '9') are stored in big endian style.
// That is, the most significant digit is at the head of the string.
// Eg: Integer 25 is stored in str as '2' at str[0], '5' at str[1], and null char at str[2].

// DO NOT modify this header file.
// Your deliverable is the implementation file.
// The implementation file has the definition of the functions decalred here.
// You can write some of your own helper functions, keep them "static".
// Use the sample test file (that has the main function) to test your implementation.

// To generate your own testcases, you can use https://www.omnicalculator.com/math

// Returns the sum of two intals.
char* intal_add(const char* intal1, const char* intal2);

// Returns the comparison value of two intals.
// Returns 0 when both are equal.
// Returns +1 when intal1 is greater, and -1 when intal2 is greater.
int intal_compare(const char* intal1, const char* intal2);

// Returns the difference (obviously, nonnegative) of two intals.
char* intal_diff(const char* intal1, const char* intal2);

// Returns the product of two intals.
char* intal_multiply(const char* intal1, const char* intal2);

// Returns intal1 mod intal2
char* intal_mod(const char* intal1, const char* intal2);

// Returns intal1 ^ intal2.
char* intal_pow(const char* intal1, unsigned int n);

// Returns Greatest Common Devisor of intal1 and intal2.
char* intal_gcd(const char* intal1, const char* intal2);

// Returns nth fibonacci number.
char* intal_fibonacci(unsigned int n);

// Returns the factorial of n.
char* intal_factorial(unsigned int n);

// Returns the Binomial Coefficient C(n,k).
char* intal_bincoeff(unsigned int n, unsigned int k);

// Returns the offset of the largest intal in the array.
// Return the smallest offset if there are multiple occurrences.
// 1 <= n <= 1000
int intal_max(char **arr, int n);

// Returns the offset of the smallest intal in the array.
// Return the smallest offset if there are multiple occurrences.
// 1 <= n <= 1000
int intal_min(char **arr, int n);

// Returns the offset of the first occurrence of the key intal in the array.
// Returns -1 if the key is not found.
// 1 <= n <= 1000
int intal_search(char **arr, int n, const char* key);

// Returns the offset of the first occurrence of the key intal in the SORTED array.
// Returns -1 if the key is not found.
// The array is sorted in nondecreasing order.
// 1 <= n <= 1000
int intal_binsearch(char **arr, int n, const char* key);

// Sorts the array of n intals.
// 1 <= n <= 1000
void intal_sort(char **arr, int n);
