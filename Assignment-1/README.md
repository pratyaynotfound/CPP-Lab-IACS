# Assignment 1

## Contents:

### Question 1:
Write a program which takes as input a number of days and converts it into
number(s) of year(s), week(s) and day(s). 
For example, if the input is 385 then the output should be: 1 year 2 weeks 6 days. Assume, non-leap years.
(2 Points) 
#### Solution:
[Prob1_Day-to-Year](Prob1_Day-to-Year.cpp)

### Question 2:
Write a program to calculate the following exprossion, where x is a real number:
$$x + \left(\frac{1}{x + \left(\frac{1}{x + \frac{1}{x}}\right)}\right)$$

#### Solution:
[Prob2_Calc_exp](Prob2_Calc_exp.cpp)

### Question 3:
Write a program to read the vowels {a, e, i, o, u} in five suitably declared
variables "vowels1" through "vowels5". Are "vowel2 - vowel1", "vowel5 - vowel2" etc.,
valid C++ expressions? What are the values of "vowel2 - vowel1", "vowel5 - vowel2"?
Suppose we have five more variables "capVowel1" through "capVowel5", of the same
type as that of "vowels1" through "vowels5" to store { A, E, I, 0, U} : Does the expression "capVowel2 - capVowel1" have the same value as that of "vowel2 - vowel1"?
Explain your answers.

Evaluate the following expression in your program: "x =y- 20 *6/9", by taking some value of y. Print the value of x. Do you see the expected result? Bring about minimum change(s) to modify your program to make it print the correct result.


#### Solution:
##### Part 1:
[Prob3_Vowels](Prob3_Vowels.cpp)
- Yes, those are valid statements and the output of 1st statement is 4 because ascii value of 'e' is 101 and for 'a' it is 97 and 101-97=4. And for the 2nd statement ascii value of 'u' is 117 and for 'e' it is 101 and 117-101=16 is the output.
- Yes, they have the same answer because again ascii 'A' is 65 and 'E' is 69 and again 69-65=4.

##### Part 2:
[Prob3_Pt2_evaluate](Prob3_Pt2_evaluate.cpp)
- No I don't see the expected output.
- Changed the expression form x=y-20*6/9 to x=y-20.0*6/9 and got the expected output.

### Question 4:
Write a program which prints the in-memory binary representation of a positive and a negative integer. Verify whether negative numbers are stored in 2's complimcnt reprscntation.

#### Solution:
[Prob4-Bin_rep](Prob4-Bin_rep.cpp)

#### Question 5:
To round off a floating point number to the nearest integer, one adds 0.5 to the number and truncatcs it to an integer. Write a program which reads a real number and a positive k and rounds it off using this knowledge, to the nearest k-th place. Thus,
if the number read is 23.59478261 and k = 1000, the rounding off is at the 1000-th place
(after decimal) and thus the rounded off number is 23.595.

##### Solution:
