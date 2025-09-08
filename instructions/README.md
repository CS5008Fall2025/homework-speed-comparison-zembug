# Vector, List, and Binary Search Tree Speed Comparison

This is another two week assignment. The first week, you will be more programming focused looking at sequential data structures, while the 
second week will be adding a new data structure, and comparing the three using a speed comparison application.

There is a lot of code for this assignment, but most of the assignment code is provided for you. It will be important to go through the code, but then
take a breath and remind yourself you are only writing code for a small part of the total assignment. 

- [Vector, List, and Binary Search Tree Speed Comparison](#vector-list-and-binary-search-tree-speed-comparison)
  - [Learning Objectives](#learning-objectives)
  - [Provided Code](#provided-code)
  - [Part 1 (Week 1): Sequential Data Structures - Vector and LinkedList](#part-1-week-1-sequential-data-structures---vector-and-linkedlist)
    - [Stretch Goal](#stretch-goal)
  - [Part 2 (Week 2): Binary Search Tree](#part-2-week-2-binary-search-tree)
  - [Part 3 (Week 2): Speed Comparison and Report](#part-3-week-2-speed-comparison-and-report)
  - [📝 Grading Rubric](#-grading-rubric)
    - [Submission Reminder 🚨](#submission-reminder-)
  - [📚 Resources](#-resources)
    - [Linked List Resources](#linked-list-resources)
    - [BST Resources](#bst-resources)
    - [Markdown Resources](#markdown-resources)
    - [Makefile](#makefile)


## Learning Objectives

For this assignment, you will learn
* Implement Vector and List as sorted structures
* Implement a BST
* Run the code on large data sets
* Timing various operations
* Comparing the time outputs and critically thinking about the differences

Since there are a lot of files with this assignment, let's first examine the files you have:


## Provided Code

The code is provided in three directories, each with their own readme. 

* [lib](../lib) - This is the code for the data structures. This is the only directory that requires you to write code. 
* [tests](../tests) - This is the code to help you test each data structure as you work on writing them. These tests are fairly comprehensive, and will help you debug your code. 
  They however are not fully exhaustive, so you may need to add more tests or other lines to help debug. You are free to modify these files as you see fit, they will
  not be graded. However, passing all the tests before you submit to the autograder will help you pass the autograder on the first try. (spoiler many of the tests are the same)
* [speed_compare_app](../speed_compare_app/) - This is an application that generates empirical data for the speed comparison. You will not need to modify this code, but you will need to run it. This
   application will be used to generate the data for your report. It is also used an example of yet another way to help look at what you are writing critically and gather data.
   This is a skill that will be useful in your career, and required for your final research paper. 
* [Makefile](../Makefile) - This is a file that will help you compile the code. You will not need to modify this file, but you will need to run it. This file is used to automate the
   compilation of the code. As this code is spread across multiple files, having something like a Makefile will often make the task of compiling easier. 
* [speed_test_files](../speed_test_files/) - These are the files that are used to generate the data for the speed comparison. You are free to add more files into this directory as you need to compare data. Instructions for doing so using linux commands are in [speed_compare_app/README.md](../speed_compare_app/README.md).


## Part 1 (Week 1): Sequential Data Structures - Vector and LinkedList

There are actually four data structures you will be working with. Vector which is another name for an ArrayList (for those familiar with Java), and LinkedList. We also have a "SortedVector" and "SortedLinkedList" which are the same as Vector and LinkedList, but they add the new elements in sorted order, keeping the items sorted in the data structure.

👉🏽 **Task** 👈🏽 - [../lib/linked_list.c](../lib/linked_list.c) and [../lib/sorted_vector.c](../lib/sorted_vector.c) - You will complete the unfinished functions in these files. You will need to read the comments to understand what each function is supposed to do and return. 

Make sure as you are writing you are *testing* the code. Testing is described in the [../tests/README.md](../tests/README.md) file. You will want to make sure you are testing as you go, and not waiting until the end or it will become a nightmare.  For a LinkedList, make sure to refer to the Team Activity in which we provide a similar LinkedList implementation.

While the choice is up to you, it is probably easier to finish the three functions in sorted_vector.c, and then work on LinkedList.

### Stretch Goal  
While completely optional, you may consider implementing a double linked list instead of a single. Just make sure it still passes the tests provided which means make sure the function names do not change. 


## Part 2 (Week 2): Binary Search Tree

After you have completed the Team Activity for binary search trees, you will have strong start to this part of the assignment. You will need to complete the functions in [../lib/bst.c](../lib/bst.c). You will need to read the comments to understand what each function is supposed to do and return. Most of these functions are recursive, so make sure you think simple and only a few lines of code for each. Your Team Activity will help you with this, as you will be writing very similar functions as a team. 


## Part 3 (Week 2): Speed Comparison and Report

After you have completed the code for the data structures, you will need to run the speed comparison application. This application will generate data for you to use in your report. You will need to run the application, and then copy the data into your report. Instructions for running the application are in [../speed_compare_app/README.md](../speed_compare_app/README.md). 

> :star: **The Goal: Thinking Critically** :star:  
> Most data structures have implementations readily available, and you should feel free to use resources (but make sure to list them in your README.md). However, it is important to *understand how they work*, and how to implement them. This assignment is designed to help you think critically about the data structures. Simply, just because you can do something, doesn't mean you should. You will need to think about the tradeoffs of each data structure, and when it is appropriate to use each. 

After getting the data, you will want to work on your [Report](../Report.md). All questions are in the report, need to be answered. The TAs will be grading by looking at your report through a browser, so make sure when it is uploaded to github it looks good (and is formatted correctly).





## 📝 Grading Rubric


1. Learning (AG)
   * SortedVector functions properly add, find, and remove elements in sorted order
2. Approaching  (AG)
   * LinkedList functions properly add, find, and remove elements
   * BST functions properly add, find, convert to string, and convert to array.
3. Meets  (MG)
   * Readme.md completed  (note: without readme, they can't grade the rest)
   * Implements functions properly included Binary Search for SortedVector and using recursion for depth first searches.
   * Contains proper BigO table documenting the worse case for each data structure function (as defined in Report)
   * Contains data table of run results with at least 15 different values for N, and a noticeable differences in speeds from lower N to higher N for some of the data structures. 
   * Contains three graphs (minimum) with comments about observations about the run-times. 
   * Repo includes the .csv file generated from the speed comparison application, along with any other files created (log.txt, additional movie files, etc.)
4. Exceeds  (MG)
   * Answers questions related to the provided code.
   * Answers questions about the data structures, correctly.
   * Provides answers to deeper thinking questions, related to the data structures and speed comparison.
   * Technical interview, and coding practice question answered with file provided


AG - Auto-graded  
MG - Manually graded

### Submission Reminder 🚨
For manually graded elements, we only guarantee time to submit for a regrade **IF** you submit by the **DUE DATE**. Submitting late may mean it isn't possible for the MG to be graded before the **AVAILABLE BY DATE**, removing any windows for your to resubmit in time. While it will be graded, it is always best to *submit by the due date*, so you have full opportunity to improve your grade.


## 📚 Resources
 

### Linked List Resources
* [Linked List Visualization]
* [Geek for Geeks: Linked List Data Structure]
* [Learn C: Linked List Tutorial]
* [Geeks for Geeks: Difference between LinkedList and Vector]

### BST Resources

* [Ordering Differences of DFS]
* [BFS vs DFS Binary Tree]
* [Difference Between BFS and DFS]
* [DFS Traversal of a Tree Using Recursion]
* [Tree Traversal BFS and DFS]
* [Visual BST]

### Markdown Resources
* [Latex Math]- For symbols you can use in markdown math (mathjax)
* [Tables Generator] - Helps convert csv to markdown tables
* [image markdown] - To help include images in your report


### Makefile

* [GNU Make Manual]

You will notice for this assignment, we added a [Makefile](../Makefile). A Makefile is a file that contains a set of instructions for the make program to execute. The make program is a program that is used to automate the build process of a program. In this case, we are using it to automate the compilation of our program. This helps when you have multiple files, and you want to compile them all at once. If you have used gradle or maven in java, this is similar to those tools (arguably those tools are inspired by `make`).

If you view the file, you will see comments on each line for what it does. You can simply type "make" in the same
directory as the Makefile, and it will follow those rules. You can use `make clean` to remove the executable and object files. This Makefile has targets setup up for each of the applications you will be writing. You can run `make` to compile all of them, or `make <target>` to compile a specific one. For example, `make test-bst` will compile the binary search tree test application.

For windows, you may need to install [make](https://gnuwin32.sourceforge.net/packages/make.htm). However, it is highly recommended using make in a linux environment for this assignment, as we have other linux commands we recommend using to make (no pun intended) your life easier. If you are using windows, you can use the [Windows Subsystem for Linux](https://docs.microsoft.com/en-us/windows/wsl/install-win10) to get a linux environment. If you are using a Mac, you already have a linux like environment.

---

[Linked List Visualization]: https://visualgo.net/en/list
[Geek for Geeks: Linked List Data Structure]: https://www.geeksforgeeks.org/data-structures/linked-list/
[Learn C: Linked List Tutorial]: https://www.learn-c.org/en/Linked_lists
[Geeks for Geeks: Difference between LinkedList and Vector]: https://www.geeksforgeeks.org/difference-between-vector-and-list/
[Sorting a Singly Linked List]: https://www.geeksforgeeks.org/sorting-a-linked-list/

[Latex Math]: https://en.wikibooks.org/wiki/LaTeX/Mathematics
[Tables Generator]: https://www.tablesgenerator.com/markdown_tables
[image markdown]: https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax#images

[Ordering Differences of DFS]: https://en.wikipedia.org/wiki/Depth-first_search#Output_of_a_depth-first_search
[Depth First Search]: https://en.wikipedia.org/wiki/Depth-first_search
[Breadth First Search]: https://en.wikipedia.org/wiki/Breadth-first_search
[Visual BST]: https://visualgo.net/en/bst
[BFS vs DFS Binary Tree]: https://www.geeksforgeeks.org/bfs-vs-dfs-binary-tree/
[Difference Between BFS and DFS]: https://www.geeksforgeeks.org/difference-between-bfs-and-dfs/ 
[DFS Traversal of a Tree Using Recursion]: https://www.geeksforgeeks.org/dfs-traversal-of-a-tree-using-recursion/
[Tree Traversal BFS and DFS]: https://www.codingeek.com/data-structure/tree-traversal-bfs-and-dfs-introduction-explanation-and-implementation/
[GNU Make Manual]: https://www.gnu.org/software/make/manual/make.html