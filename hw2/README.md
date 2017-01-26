---
title: CS 246 Assignment 2
---

<div id="header">

| **CS 246 Assignment 2**
| due 12:55pm on Tuesday, January 31, 2017

</div>

[Link back to syllabus](http://cs.brynmawr.edu/cs246/syllabus.html)

[Click here to start assignment](https://classroom.github.com/group-assignment-invitations/833173fcb88d480df27aea874cdb20e3)

Like all assignments, you will complete this assignment via
GitHub. See [the submission instructions](../submission.html)
for how to get the starter code and how to submit this
assignment.

(If you end up with the assignment files in a `.zip` file,
you can say `unzip xxx.zip` to unzip it, where `xxx.zip`
is the name of your downloaded file. As always, make sure
you are in the right working directory. Use `ls` and `pwd`
to see where you are.)

1. **`cat`**

    Edit the file `cat.c` to reimplement the command-line tool `cat`. By default, `cat` simply
    repeats what it reads in. We don't yet know about reading from files, so we will just
    mimic behavior, by printing out precisely what is read in.

    Use `getchar` to read in individual characters and print them out.

    Your program should keep running until it reads end-of-file, which is indicated
    by a `-1` return value from `getchar`. You can produce an end-of-file on the command
    line by typing Ctrl+D on an empty line.

    Note that the terminal intermediates a bit between you and your program: your program
    will not repeat the characters as you type them, but only when you press *\<Enter\>*. This
    is because the terminal delivers the characters to a C program only after you press
    return, and is expected behavior.

    If you're not sure how your program should behave, just run `cat` without any arguments.
    Behave like that `cat`.

2. **SHOUTER**

    Edit the file `shout.c` to be like the program above, but changing all letters to uppercase.
    Detect letters by using the [`isalpha`](http://www.cplusplus.com/reference/cctype/) function,
    but **do not use `toupper`**. Instead, use arithmetic on characters to perform the conversion.
    See the section *Character-Handling Functions* on page 138 of King.

3. **SCREAMER**

    Edit the file `scream.c` to behave identically like the program above, but do not
    capitalize using arithmetic. Instead, consult an ASCII table (like in King's Appendix E, but
    also available across the internet). Write out the bits used to represent `'A'` and the bits
    used to represent `'a'`. What's the difference? Is the same difference apparent when looking
    at `'B'` and `'b'`? Figure out how to use bit-flicking operations (as covered in Section 20.1
    of King) to make a letter uppercase, and use this technique to write your program.

4. **`wc`**

    Reimplement the utility `wc` by reading in characters using `getchar` and reporting
    how many characters, words, and lines have been read. Whitespace (which separates all words)
    can be detected by [`isspace`](http://www.cplusplus.com/reference/cctype/). Lines are
    separated by newlines (`'\n'`).

    For example, if you type the following in (followed by Ctrl+D),

        One of the main causes of the fall of the Roman Empire was that–--lacking zero–--they
        had no way to indicate successful termination of their C programs.
          -- Robert Firth

    your program should produce

        187
        29
        3

    Note that an empty input (an immediate Ctrl+D) should produce three 0s.

    Recall that you can use `\<` and on the command line to provide a file as input to a program,
    if you want to test larger inputs. (This is described on p. 54 of Shotts.)

    If you're uncertain how your program should behave, check against the real `wc` (which prints
    its answers out in the opposite order from what I am asking here).

5. **Converter: decimal to hex**

    Write a program (in `conv_dec.c`) that reads in a number and prints out the hexadecimal version
    of that number. The catch is that the input must be read as characters. Use a loop with `getchar`
    to read in characters until a newline is spotted. As the characters are read in, use some math
    (*hint:* multiply by 10 in a key spot) to compute the number the user has written. Then print
    out that number in hex---but with another catch: no `printf`. Instead, convert the value to
    hexadecimal yourself, printing out the characters (with `putchar`) *backwards*. (The "backwards"
    bit is to make this easier, actually!) Output a newline before the program exits.

    For example, if I enter

        123

    my program outputs

        B7

    because `0x7B` equals `123`. Note that the output is written *backwards*.

    This program should use no I/O functions other than `getchar` and `putchar`.

6. **Converter: hex to octal**

    Write a program (in `conv_hex.c`) that reads in a number in hexadecimal and prints it
    out in octal. Like the last program, you will use only `putchar` and `getchar`. However,
    unlike the last program, *both* the input and the output are reversed. (Again, this makes
    it *easier*.) In addition, your program must be able to handle arbitrarily large numbers.
    Do this by converting "on the fly" -- do not read in all of a user's input, figure out
    the value, and then convert to octal. Instead, take advantage of the similarity between
    hexadecimal and octal and convert as you read, with only one loop.

    For example, if I enter

        AB320D54

    my program outputs

        27612046501

    This is challenging problem. You will get partial credit if your program works only
    up to a maximum.

7. **Reflections**

    Edit `refl.txt` (short for "reflections") to answer
    the questions therein.

When you're all done, submit on GitHub by creating a Pull
Request according to [these instructions](../submission.html).
