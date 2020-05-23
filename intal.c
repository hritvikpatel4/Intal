// Implementation of the intal library. 
// This file contains the implementation of the functions in the intal.h file.

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intal.h"
#define lld long long int

// Utility function to reverse a string
static char* revstr(char *s, int n) {
    char temp;
	for(int i = 0; i < n / 2; i++)
	{
		temp = s[i];
		s[i] = s[n - i - 1];
		s[n - i - 1] = temp;
	}

   	s[n]='\0';
	return s;
}

// Utility function to find min of two numbers
static lld min(lld x, lld y) {
    return (x > y) ? y : x;
}

// Utility function for mergesort algo implemented as intal_sort
static void merge_arr(char** arr, int m, int n) {
	char **a = (char**) malloc(n * sizeof(char*));

    for(lld i = 0; i < n; i++) {
        a[i] = (char*) malloc(1001 * sizeof(char));
    }

    lld i = 0;
    lld j = m;
    lld k = 0;

    while(i < m && j < n) {
        if(-1 == intal_compare(arr[i], arr[j]) || 0 == intal_compare(arr[i], arr[j])) {
            a[k] = arr[i++];
        }

        else {
            a[k] = arr[j++];
        }

        k++;
    }

    if(j == n) {
        while(i < m) {
            a[k++] = arr[i++];
        }
    }

    else {
        while(j < n) {
            a[k++] = arr[j++];
        }
    }

    for(int i = 0; i < n; i++) {
        arr[i] = a[i];
    }

    free(a);
}

// Returns the sum of two intals.
char* intal_add(const char* intal1, const char* intal2) {
    lld n1 = strlen(intal1);
    lld n2 = strlen(intal2);
    const char *num1 = intal1;
    const char *num2 = intal2;

    if(n1 < n2) {
        num1 = intal2;
        num2 = intal1;
        n1 = strlen(num1);
        n2 = strlen(num2);
    }

    char *res = (char*) malloc(1001 * sizeof(char));
    lld i = n1 - 1;
    lld j = n2 - 1;
    int sum = 0;
    int carry = 0;
    lld index = 0;

    while(i >= 0 && j >= 0) {
        sum = (num1[i] - '0') + (num2[j] - '0') + carry;
        res[index++] = (sum % 10) + '0';
        carry = sum / 10;
        i--; j--;
    }

    while(i >= 0) {
        sum = (num1[i] - '0') + carry;
        res[index++] = (sum % 10) + '0';
        carry = sum / 10;
        i--;
    }

    if(carry) {
        res[index] = carry + '0';
        res[index + 1] = '\0';
    }

    else res[index] = '\0';

    char *result = (char*) malloc(1001 * sizeof(char));
    lld len = strlen(res);

    for(lld i = 0; i < len; i++) {
        result[i] = res[len - i - 1];
    }
    result[len] = '\0';

    free(res);
    return result;
}

// Returns the comparison value of two intals.
int intal_compare(const char* intal1, const char* intal2) {
    lld n1 = strlen(intal1);
    lld n2 = strlen(intal2);

    if(n1 < n2) return -1;
    if(n1 > n2) return 1;

    for(int i = 0; i < n1; i++) {
        if(intal1[i] < intal2[i]) return -1;
        if(intal1[i] > intal2[i]) return 1;
    }

    return 0;
}

// Returns the difference (obviously, nonnegative) of two intals.
char* intal_diff(const char* intal1, const char* intal2) {
    if(0 == intal_compare(intal1, intal2)) {
        char *r = (char*) malloc(2 * sizeof(char));
        strcpy(r, "0");
        r[1] = '\0';
        return r;
    }

    lld n1 = strlen(intal1);
    lld n2 = strlen(intal2);
    const char *num1 = intal1;
    const char *num2 = intal2;

    if(n1 < n2 || (-1 == intal_compare(intal1, intal2))) {
        num1 = intal2;
        num2 = intal1;
        n1 = strlen(num1);
        n2 = strlen(num2);
    }

    char *res = (char*) malloc((n1 + 1) * sizeof(char));
    lld i = n1 - 1;
    lld j = n2 - 1;
    int r = 0;
    int carry = 0;

    while(i >= 0 && j >= 0) {
        r = (num1[i] - '0') - (num2[j] - '0') - carry;

        if(r < 0) {
            r += 10;
            carry = 1;
        }

        else carry = 0;

        res[i] = (r + '0');
        i--; j--;
    }

    while(i >= 0) {
        r = (num1[i] - '0') - carry;

        if(r < 0) {
            r += 10;
            carry = 1;
        }

        else carry = 0;

        res[i] = (r + '0');
        i--;
    }

    lld zeros = 0;

    while(1) {
        if(0 == (res[zeros] - '0')) zeros++;

        else break;
    }

    char *result = (char*) malloc((n1 + 1 - zeros) * sizeof(char));
    lld index = 0;
    
    for(lld i = zeros; i < n1; i++) {
        result[index++] = res[i];
    }
    result[index] = '\0';

    free(res);
    return result;
}

// Returns the product of two intals.
char* intal_multiply(const char* intal1, const char* intal2) {
    lld n1 = strlen(intal1);
    lld n2 = strlen(intal2);

    if(n1 == 0 || n2 == 0) {
        char *r = (char*) malloc(2 * sizeof(char));
        strcpy(r, "0");
        r[1] = '\0';
        return r;
    }

    if((0 == intal_compare(intal1, "0")) || (0 == intal_compare(intal2, "0"))) {
        char *r = (char*) malloc(2 * sizeof(char));
        strcpy(r, "0");
        r[1] = '\0';
        return r;
    }
    
    char *num1 = (char*) malloc(1001 * sizeof(char));
    char *num2 = (char*) malloc(1001 * sizeof(char));
    strcpy(num1, intal1);
    strcpy(num2, intal2);

    char *res = (char*) malloc((n1 + n2 + 1) * sizeof(char));
    memset(res, '0', n1 + n2);
    res[n1 + n2] = '\0';
    lld l1 = 0;
    lld l2 = 0;

    for(lld i = n1 - 1; i >= 0; i--) {
        int carry = 0;
        int x1 = num1[i] - '0';
        l2 = 0;

        for(lld j = n2 - 1; j >= 0; j--) {
            int x2 = num2[j] - '0';
            int sum = (x1 * x2) + (res[l1 + l2] - '0') + carry;
            carry = sum / 10;
            res[l1 + l2] = (sum % 10) + '0';
            l2++;
        }

        if(carry > 0) {
            res[l1 + l2] = ((res[l1 + l2] - '0') + carry) + '0';
        }

        l1++;
    }

    lld i = strlen(res) - 1;
    while(i >= 0 && res[i] == 0) {
        i--;
    }

    if(i == -1) {
        char *r = (char*) malloc(2 * sizeof(char));
        strcpy(r, "0");
        r[1] = '\0';
        free(num1);
        free(num2);
        free(res);
        return r;
    }

    revstr(res, strlen(res));
    lld zeros = 0;

    while(1) {
        if(0 == (res[zeros] - '0')) zeros++;

        else break;
    }

    char *result = (char*) malloc((n1 + n2 + 1 - zeros) * sizeof(char));
    lld index = 0;
    
    for(lld i = zeros; i < n1 + n2; i++) {
        result[index++] = res[i];
    }
    result[index] = '\0';

    free(num1);
    free(num2);
    free(res);
    return result;
}

// Returns intal1 mod intal2
char* intal_mod(const char* intal1, const char* intal2) {
    int c = intal_compare(intal1, intal2);
    if(0 == c) {
        char *r = (char*) malloc(2 * sizeof(char));
        strcpy(r, "0");
        return r;
    }

    else if(-1 == c) {
        char *r = (char*) malloc((strlen(intal1) + 1) * sizeof(char));
        strcpy(r, intal1);
        return r;
    }

    else {
        int dividend_len = strlen(intal1);
        int divisor_len = strlen(intal2);
        char *num1 = (char*) malloc((dividend_len + 1) * sizeof(char));
        char *num2 = (char*) malloc((dividend_len + 1) * sizeof(char));
        char *temp;
        strcpy(num1, intal1);

        while(1 == intal_compare(num1, intal2)) {
            dividend_len = strlen(num1);
            strcpy(num2, intal2);

            if(dividend_len - divisor_len >= 1) {
                int i = 0;

                for(i = 0; i < dividend_len - divisor_len - 1; i++) {
                    num2[divisor_len + i] = '0';
                }
                num2[divisor_len + i] = '\0';
                temp = intal_multiply(num2, "10");

                if(-1 == intal_compare(temp, num1)) {
                    num2[divisor_len + i] = '0';
                    i++;
                    num2[divisor_len + i] = '\0';
                }

                free(temp);
            }

            temp = intal_diff(num1, num2);
            free(num1);
            num1 = temp;
        }

        if(0 == intal_compare(num1, intal2)) {
            strcpy(num1, "0");
        }

        free(num2);
        return num1;
    }
}

// Returns intal1 ^ n.
char* intal_pow(const char* intal1, unsigned int n) {
    if(n == 0) {
        char *r = (char*) malloc(2 * sizeof(char));
        strcpy(r, "1");
        r[1] = '\0';
        return r;
    }

    char *result = (char*) malloc(1001 * sizeof(char));
    strcpy(result, "1");
    char *num = (char*) malloc(1001 * sizeof(char));
    strcpy(num, intal1);

    while(n > 0) {
        if(n & 1) {
            result = intal_multiply(result, num);
        }

        n = n >> 1;

        num = intal_multiply(num, num);
    }

    free(num);
    return result;
}

// Returns Greatest Common Devisor of intal1 and intal2.
char* intal_gcd(const char* intal1, const char* intal2) {
    if(0 == intal_compare(intal1, "0") && 0 == intal_compare(intal2, "0")) {
        char *r = (char*) malloc(2 * sizeof(char));
        strcpy(r, "0");
        r[1] = '\0';
        return r;
    }

    if(0 == intal_compare(intal1, intal2)) {
        char *r = (char*) malloc(1001 * sizeof(char));
        strcpy(r, intal1);
        return r;
    }

    if(0 == intal_compare(intal1, "0") || 0 == intal_compare(intal2, "0")) {
        char *r = (char*) malloc(2 * sizeof(char));
        strcpy(r, "1");
        r[1] = '\0';
        return r;
    }

    char *num1 = (char*) malloc(1001 * sizeof(char));
    char *num2 = (char*) malloc(1001 * sizeof(char));
    char *temp = (char*) malloc(1001 * sizeof(char));
    strcpy(num1, intal1);
    strcpy(num2, intal2);

    while(0 != intal_compare(num2, "0")) {
        temp = intal_mod(num1, num2);
        strcpy(num1, num2);
        strcpy(num2, temp);
    }

    free(num2);
    free(temp);
    return num1;
}

// Returns nth fibonacci number.
char* intal_fibonacci(unsigned int n) {
    if(n == 0) {
        char *r = (char*) malloc(2 * sizeof(char));
        strcpy(r, "0");
        r[1] = '\0';
        return r;
    }

    else if(n == 1) {
        char *r = (char*) malloc(2 * sizeof(char));
        strcpy(r, "1");
        r[1] = '\0';
        return r;
    }

    else {
        char *n1 = (char*) malloc(1001 * sizeof(char));
        char *n2 = (char*) malloc(1001 * sizeof(char));
        strcpy(n1, "0");
        strcpy(n2, "1");
        char *res;

        for(lld i = 2; i <= n; i++) {
            res = intal_add(n1, n2);
            strcpy(n1, n2);
            strcpy(n2, res);
        }

        free(n1);
        free(n2);
        return res;
    }
}

// Returns the factorial of n.
char* intal_factorial(unsigned int n) {
    char *num = (char*) malloc(1001 * sizeof(char));
    strcpy(num, "1");
    char *result = (char*) malloc(1001 * sizeof(char));
    strcpy(result, "1");

    for(lld i = 1; i <= n; i++) {
        result = intal_multiply(result, num);
        num = intal_add(num, "1");
    }

    free(num);
    return result;
}

// Returns the Binomial Coefficient C(n,k).
char* intal_bincoeff(unsigned int n, unsigned int k) {
    k = (k <= n / 2) ? k : (n - k);

    char **DP = (char**) malloc((k + 1) * sizeof(char*));

    for(lld i = 0; i < k + 1; i++) {
        DP[i] = (char*) malloc(1001 * sizeof(char));
    }
    for(lld i = 0; i < k + 1; i++) {
        memset(DP[i], '0', 1001);
    }
    
    strcpy(DP[0], "1");

    char *num = (char*) malloc(1001 * sizeof(char));

    for(lld i = 1; i <= n; i++) {
        for(lld j = min(i, k); j > 0; j--) {
            num = intal_add(DP[j], DP[j - 1]);
            strcpy(DP[j], num);
        }
    }

    free(num);
    lld zeros = 0;

    while(1) {
        if(0 == (DP[k][zeros] - '0')) zeros++;

        else break;
    }

    char *result = (char*) malloc((1001 - zeros) * sizeof(char));
    lld index = 0;
    
    for(lld i = zeros; i < 1001; i++) {
        result[index++] = DP[k][i];
    }
    result[index] = '\0';

    for(lld i = 0; i < k; i++) {
        free(DP[i]);
    }
    free(DP);
    return result;
}

// Returns the offset of the largest intal in the array.
int intal_max(char **arr, int n) {
    lld offset = 0;

    for(lld i = 1; i < n; i++) {
        if(-1 == intal_compare(arr[offset], arr[i])) {
            offset = i;
        }
    }

    return offset;
}

// Returns the offset of the smallest intal in the array.
int intal_min(char **arr, int n) {
    lld offset = 0;

    for(lld i = 1; i < n; i++) {
        if(1 == intal_compare(arr[offset], arr[i])) {
            offset = i;
        }
    }

    return offset;
}

// Returns the offset of the first occurrence of the key intal in the array.
int intal_search(char **arr, int n, const char* key) {
    lld res = -1;

    for(lld i = 0; i < n; i++) {
		if(0 == intal_compare(key, arr[i])) {
			res = i;
			break;
		}
	}
	return res;
}

// Returns the offset of the first occurrence of the key intal in the SORTED array.
int intal_binsearch(char **arr, int n, const char* key) {
    lld l = 0;
    lld r = n - 1;
    lld res = -1;

    while(l <= r) {
        lld m = l + (r - l) / 2;
        int c = intal_compare(arr[m], key);

        if(0 == c) {
            res = m;
            break;
        }

        else if(-1 == c)
            l = m + 1;

        else
            r = m - 1;
    }

    return res;
}

// Sorts the array of n intals.
void intal_sort(char **arr, int n) {
	if(n <= 1) return;
	
	lld mid = n / 2;
	
	intal_sort(arr, mid);
	intal_sort(arr + mid, n - mid);
	merge_arr(arr, mid, n);
}
