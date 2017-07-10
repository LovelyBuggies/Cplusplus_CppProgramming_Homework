# Easy String

### This time, you need to create two function:
* void Assign(char * & str, int length); According to the length, allocate memory to str.
* void AddTwo(string & res, char \* & str1, char \* & str2); Add str1 and str2, then assign the result to the res. More importantly, you need to handle str1 and str2 to guarantee that there would not happen memory problem.

### Sample input:
```
4 5
abcd
efghi
```
### Sample ouput:
```
abcd
efghi
abcdefghi
```

### Key words: new, delete, reference, string
#### Better to know more about reference and *string*.
#### Guess what would happen if we dont't use ‘&’。