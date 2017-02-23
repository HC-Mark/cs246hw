---
title: CS 246 Assignment 5
---

<div id="header">

| **CS 246 Assignment 5**
| due 12:55pm on Thursday, March 2, 2017

</div>

[Link back to syllabus](http://cs.brynmawr.edu/cs246/syllabus.html)

[Click here to start assignment](https://classroom.github.com/group-assignment-invitations/a654e4b197fe6d09f4380de3d35eb889)

Like all assignments, you will complete this assignment via
GitHub. See [the submission instructions](../submission.html)
for how to get the starter code and how to submit this
assignment.

This assignment introduces the notion of *flex* questions. A flex
question is *optional*. If you complete it, it will be graded as part
of the homework assignment. If you don't, then the question is
completely ignored. For example, the one non-flex question in this
assignment is worth 30 points. If you complete a 20-point flex question
as well, then your assignment is graded out of a total of 50 points. This
lessens the import of the non-flex question. Regardless of how many
points this one assignment is worth, it still counts as much as other
assignments when calculating the final grade at the end of the semester.
In other words, even if you complete only the non-flex question (30 points),
then this 30-point assignment counts as much as a 100-point assignment.

All the functions you are to write are in the `pointers.c` file. Unit
tests appear in `check_ptrs.c`; some tests are already there. Use these
tests to understand the functions better. You may wish to write more.
You may also write a `main` if you like, but it
is not necessary. If you do this, do *not* put the `main` function in
`pointers.c`, as that would prevent you from unit-testing your functions.
Do submit a `Makefile` with your work.

1. **Overlapping arrays** (10 flex points)

    Write the function `overlaps`, as described in `pointers.c` and tested in
    `check_ptrs.c`.

2. **Mini-sort** (15 flex points)

    Write the function `minisort`, as described in `pointers.c` and tested in
    `check_ptrs.c`.

3. **Partial sum** (15 flex points)

    Write the function `partial_sum`, as described in `pointers.c` and tested in
    `check_ptrs.c`.

4. **Tic Tac Toe** (20 points for `check_line` + 30 points for `tic_tac_toe_winner`)

    Write functions `check_line` and `tic_tac_toe_winner` that check whether
    there is a winner in a game of generalized Tic Tac Toe.
    The Tic Tac Toe board is
    represented in an `n`-by-`n` 2-dimensional array of `int`s.
    (The game is "generalized" because it might be bigger than a 3x3 board.)
    Each element in the
    array is either `X`, `O`, or `BLANK`, where `X`, `O`, and `BLANK` are
    `#define`d constants in `pointers.h`. It is guaranteed that `BLANK`
    is `0` and that `X` and `O` are both represented by numbers containing
    exactly one set bit. (For example, `X` might be `4` and `O` might be `16`,
    or `X` might be `1` and `O` might be `2`. Your program should *not* assume
    what the exact values are -- just use `X` and `O`.)

    The `check_line` function has this prototype:

    ```c
    int check_line(int* start, int step, int n);
    ```

    It takes a pointer to the first element of a line (where a line may
    be horizontal, vertical, or either major diagonal) and the number of
    `int`s between different elements of the line. It returns `BLANK` if
    there is no winner, `X` if there are `n` `X`s in a row, and `O` if
    there are `n` `O`s in a row.

    As an example, suppose `p` points to a stretch of memory that looks
    like `{X, BLANK, X, O, X, BLANK}`. A call to `check_line(p, 2, 3)`
    would return `X` (because `p[0]`, `p[2]`, and `p[4]`) all have `X`s,
    and a call to `check_line(p, 1, 3)` would return `BLANK`, because not
    all of `p[0]`, `p[1]`, and `p[2]` have the same value.

    The `tic_tac_toe_winner` function has this prototype:

    ```c
    int tic_tac_toe_winner(int n, int* board);
    ```

    The `board` pointer points to an `n`-by-`n` 2-dimensional array.

    It uses calls to `check_line` to check individual lines. This
    function should have one loop to check rows, one loop to check
    columns, and then one check each for the two major diagonals.
    This function should *not* access elements in `board` directly;
    that's what `check_line` is for. Implementations that do not
    use `check_line` to the fullest of its potential will not receive
    full credit.

    You do *not* need to detect if the board is full and is a tie.
    If both `X` and `O` have won, your function may return `X`, `O`,
    or `X | O` -- whichever is most convenient for you.

5. **Reflections**

    Edit `refl.txt` (short for "reflections") to answer
    the questions therein.


There are also **10 points** for style, totaling 100 points if you complete
all problems.

When you're all done, submit on GitHub by creating a Pull
Request according to [these instructions](../submission.html).
