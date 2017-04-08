---
title: CS 246 Assignment 7
---

<div id="header">

| **CS 246 Assignment 7**
| due 12:55pm on Thursday, April 13, 2017

</div>

[Link back to syllabus](http://cs.brynmawr.edu/cs246/syllabus.html)

[Click here to start assignment](https://classroom.github.com/group-assignment-invitations/c8713647eb2f142bc6f45e24457d09b3)

Like all assignments, you will complete this assignment via
GitHub. See [the submission instructions](../submission.html)
for how to get the starter code and how to submit this
assignment.

You may want to use `valgrind` to test your work for memory safety. (Mac users
may want to install this with `brew install valgrind`.) If you do so, it will
be helpful to suppress memory errors caused by the `check` framework. To suppress
these errors, download the [check.supp](../14/check.supp) file and pass the
`--suppressions=check.supp` argument to `valgrind`. So, if your executable is
`check_dlist`, then you would call `valgrind --suppressions=check.supp ./check_dlist`
on the command line (with `check.supp` in the same folder as `check_dlist`).

You will likely also want to write a `Makefile` as part of this assignment.

The full description of this assignment took place during class 19. This file
contains only descriptions of the parts you have to write. As always, feel free
to write helper functions.

The data files you will work with are [here](ftp://ftp.fu-berlin.de/pub/misc/movies/database/);
download `actors.list.gz` and `actresses.list.gz`. Decompress them with `gunzip`. (We will
not need any other files.)

1. (20 pts) Finish writing `read_cast_member` (in `imdb_functions.c`). There are two
   places you need to write more code, as described in the file. Once this
   function is finished, you should be able to read in a file of cast members,
   with just a few small tweaks in your `main()` function.

2. (20 pts) Write `find_cast_member` (in `imdb_functions.c`) to use **binary search**
   to find a cast member in an array.

3. (5 pts) Write code in `main` (in `imdb.c`) to enable the user to look up
   and find a cast member from `all_cast` (using your `find_cast_member`
   function). When reading in a cast member name from the user, remember that
   you need to read in spaces; `scanf("%s", ...)` stops at the first space.
   Instead, I recommend `fgets`, but be aware that the function includes the
   newline in the string it reads in. Before searching, remove this newline.

3. (20 pts) Write `merge_arrays` (in `imdb_functions.c`). This will allow you to read in
   multiple cast member files (e.g., actors *and* actresses). Add a little code
   to `main` to arrange a call to `merge_arrays`. After this step is complete, you
   should be able to look up both actors and actresses.

4. (15 *flex* pts -- optional) Although the minimum interface allows solely
   looking up cast members, you may optionally add an interface that allows
   the user to navigate the graph. One suggested way to do this is to start at
   a certain cast member or movie. (Perhaps the choice is fixed; e.g. [Kevin
   Bacon](http://oracleofbacon.org/), or perhaps the user can choose the
   starting point.) Then, list all movies/cast members associated with the
   current one, allowing the user to pick one by number. Repeat. Offer the
   user a way to quit, and some instructions of how to play.

5. (20 pts) Write code at the end of `main` that frees all memory used.

Feel free to go above and beyond the basics here. If you do, make sure to document
your work prominently (e.g., in `main` or, even better, in instructions printed for
the user).
