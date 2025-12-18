# Ft_printf

*This project has been created as part of the 42 curriculum by jnovo-fe*

## Description

Ft_printf is a project that seeks to recreate a simplefied version of the behavior of the original printf function without implementing the original's buffer management. It prints a string to the standard output and if it includes specifiers, the additional arguments after the string are formatted, and replace their respective specifier on the result. It makes approaches the subjects of variadict functions and parsing.

## Instructions

To test the code, simply use:

```bash
make
```
Then compile the main with the libftprintf.a file and the following flags:

```bash
cc -Wall -Werror -Wextra main.c libftprintf.a
```

## Resources

For this project i used the following resources:

Manual page:
```bash
man 3 printf
```
Links:  
-[Good guide to start printf](https://42-cursus.gitbook.io/guide/1-rank-01/ft_printf) ;  
-[Understand specifiers and flags](https://www.ibm.com/docs/en/i/7.4.0?topic=functions-printf-print-formatted-characters) ;  
-[Variadic functions (Geeksforgeeks)](https://www.geeksforgeeks.org/c/variadic-functions-in-c/) ;

Videos:  
-[Variadic functions (CodeVault)](https://www.youtube.com/watch?v=oDC208zvsdg) ;  
-[Basics of printf (Portfolio Courses)](https://www.youtube.com/watch?v=ycKZKDCMMzM) ;  

Sites (asked a lot of specific questions):  
-[Reddit](https://www.reddit.com/) ;  
-[Stack Overflow](https://stackoverflow.com/questions) ;

## Explanation

For this project I used structs to hold variables so they could be used across multiple functions easily, also, I used parsing to detect the flags and specifiers present because it seemed like the simplest way to do it. AI was used to research some topics and answer some specific questions. The following flags and specifiers were handled:

| Flags | Description |
| ----------- | ----------- |
| c | Prints single ascii char |
| s | Prints string of char, NULL terminated |
| p | Prints a pointer location converted to hexadecimal value |
| d | Prints a decimal number |
| i | Prints an integer in decimal base |
| u | Prints an unsigned decimal number |
| x | Prints an unsigned number in lowercase hexadecimal base |
| X | Prints an unsigned number in uppercase hexadecimal base |
| % | Prints a literal "%" |

| Bonus | Description |
| ----------- | ----------- |
| - | Left align the argument passed with spaces |
| 0 | Add "0" as a padding char in numeric conversions |
| + | Add a plus sign in front of positive numeric conversions |
| " " | Add a single space in front of positive numeric conversions |
| # | Add the corresponding prefix in front of x, X and o conversions |
| . | For integer specifiers, the minimum number of digits to be written. For s, this is the maximum numbers of characters to be printed |
| Width | Minimum number of characters to be printed |
