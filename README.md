# Intal_C_library
## Introduction

An intal is a non negative integer of arbitrary length, but in case of my
implementation it has a limit of 1000 digits. Intal is stored as a null
terminated string ("\0") of ASCII format. String of decimal digits
('0' thru '9') are stored in big endian style. The advantage of this method of
storing numbers rather than normal integers is that we have more storage
available than normal integers. All numeric datatypes have a limit and numbers
are stored within it for representation. Intal is more like a custom datatype
which can store large numbers with special characters and doesnt have to worry
about storage limit.

## Applications

In case of storing currency amount values in a column and needing to maintain
the commas in between the integer values like $100,000.You can store it as a
string column with the help of this library.

## Approaches

1) intal_add: Basic school addition technique by adding digitwise from the
               end. 

2) intal_compare: Used length as a comparison metric for intals of different
                   lengths and returned 1 if first one was longer or -1 if
                   second was longer. If both were equal in length, each
                   character was individually compared. If both the inputs are
                   exhausted, then 0 was returned to indicated both are equal.

3) intal_diff: Used compare function to set the first number as greater one for
               convenience. Each digit was subtracted position wise and stored
               the result while propagating the carry if we get a negative
               result at any point. The result was returned after removing the
               trailing zeros.

4) intal_multiply: Start from last digit of first number and multiply it with
                   the second number. Then we multiply second digit of first
                   number with the second number, and so on. Store these
                   multiplication results. Reverse the result and remove the
                   leading zeros.

5) intal_mod: Used an O(logn) approach to find modulus in which we multiply a
              temporary result by two until the range of the intal modulus
              second intal stays in the required range of 0 to intal2 - 1.

6) intal_gcd: Used Euclid's method. Summarized as, gcd(a,b)=gcd(b,a%b) is done
              repeatedly until the second parameter, b equals 0. Used the
              intal_mod from this library for the modulus operation.

7) intal_pow: Used the intal_mul function in this library for calculating the
              power of a given number.

8) intal_fibonacci: Used the iterative method of generating fiboanacci numbers.

9) intal_factorial: Iterative algorithm of finding a factorial was used.

10) intal_bincoeff: Used Pascal's identity C(n, k) = C(n-1, k) + C(n-1, k-1) and
                    created a DP table of size k+1 and iterated through all
                    the n's from 1 to n and calculated value of C(n, k).

11) intal_max: Set the first value of the array as maximum and iterated through
               the entire array while comparing the first value with the others
               using intal_compare and updated the maximum value as we find a new
               maximum. Returned a pointer to this new value once we iterate the
               entire array.

12) intal_min: Set the first value of the array as minimum and iterated through
               the entire array while comparing the first value with the others
               using intal_compare and updated the minimum value as we find a new
               minimum. Returned a pointer to this new value once we iterate the
               entire array.

13) intal_search: Used linear search to iterate through the entire array while
                  comparing arr[i] with key and returned whenever the result of
                  intal_compare(arr[i], key)==0. If none of the elements match,
                  returned a -1.

14) intal_binsearch: Used the regular iterative method of binary search on the
                     array and compared the key to the arr[mid] element using
                     the intal_compare method and returned the offset if it 
                     gave result as 0. If result was 1 looked for key in left
                     half of array. If -1 looked in right half . Returned -1
                     if none of the keys match the array elements.

15) intal_sort: Used merge sort.

16) intal_coin_row_problem: We maintain a DP table of size n+1 strings where
                            each element in DP table tells us the maximum amount
                            if there were i coins and set the DP[0]='0' as there
                            is no way to select coins fi there aren't any and
                            DP[1] = arr[0] if there is just a coin and
                            DP[2] = max(arr[0],arr[1]). Then for each i from 3 to
                            n, we calculate DP[i] by recurrence,
                            DP[i] = max(DP[i-2]+arr[i],DP[i-1]). To implement the
                            max function, we use intal_compare and return what
                            is necassary. Finally the result is stored in DP[n]
                            which is returned.

## Future Work
1) Add the functionality of division which could be useful.
