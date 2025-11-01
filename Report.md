# Report for Data Structure Speed Comparison Homework

Make sure to answer every question in this homework. You should not bullet point your answers, but
instead write them as a full report format. This doesn't mean you have to be wordy, as concise is good,
but it does mean you need to use proper grammar, spelling, and be complete. For question that just
ask for a short answer, answer accordingly. Make sure to include references where appropriate.

## Algorithmic Analysis - Big $O$

Complete the Big O table below for the following functions. You may use any resource you like, but
for the SortedVector and SortedList, you should use the Big O for the functions you wrote in the
the homework. Both Single and Double Linked List you can assume head and tail pointers are available. 
Don't forget to use latex math notation (example in the table).

### Big $O$ Table

| -                         | Add/Insert | Remove | Search/Find | Sort     | Add Front | Add Back | Remove Front | Remove Back | Get by Index |
| ------------------------- |:----------:|:------:|:-----------:|:--------:|:---------:|:--------:|:------------:|:-----------:|:------------:|
| Vector                    | $O(n)$     |  $O(n)$|     $O(n)$  |$O(nlogn)$|$O(n)$     |   $O(1)$ | $O(n)$       |   $O(1)$    |    $O(1)$    |
| Single Linked List        |  $O(1)$    |  $O(n)$|     $O(n)$  |$O(nlogn)$|$O(1)$     |   $O(1)$ | $O(1)$       |   $O(n)$    |    $O(n)$    |
| Double Linked List        |   $O(1)$   |  $O(n)$|     $O(n)$  |$O(nlogn)$|$O(1)$     |   $O(1)$ | $O(1)$       |   $O(1)$    |    $O(n)$    |
| Sorted Vector             |     $O(n)$ | $O(n)$ |   $O(logn)$ | $O(1)$   | ---       | ---      | ---          | ---         | ---          |
| Sorted Single Linked List |    $O(n)$  |   $O(n)$|   $O(n)$   | $O(1)$   | ---       | ---      | ---          | ---         | ---          |
| Sorted Double Linked List |     $O(n)$ |  $O(n)$|    $O(n)$   | $O(1)$   | ---       | ---      | ---          | ---         | ---          |
| Binary Search Tree        |$O(logn)$   |$O(logn)$| $O(logn)$  |  $O(n)$  | ---       | ---      | ---          | ---         | ---          |

[1]

For Sort, we are asking for the Big $O$ for taking the current data structure and writing it 'sorted' to a file. However, not the file writes. For example, if you have a vector of 1000 elements, and you want to write it to a file, you would need to sort it first. So, the Big $O$ for this would be the Big $O$ for sorting. For BST, you have to convert the tree to a sequential structure, so the cost of doing that.  

### Assumptions with Sort

Since the worst case can change considerably based on what sort you use for sorting (if any), list each algorithm below, and specify the algorithm used in your assumption.  For BST, write which  method of traversal you would use to sort it.  

* Vector - $O(nlogn)$ - mergesort
* Single Linked List - $O(nlogn)$ - mergesort
* Double Linked List - $O(nlogn)$ - mergesort
* Sorted Vector - already sorted - $O(1)$
* Sorted Single Linked List - already sorted - $O(1)$
* Sorted Double Linked List - already sorted - $O(1)$
* Binary Search Tree - $O(n)$ - inorder traversal

[2]

### Worst Case vs. Average Case

There are a few functions whose worse case is very different than the average case. Name at least two of them, and explain why the worse case is so much worse than the average case. 

1. Binary Seatch Tree: Seach/Insert/Remove

   Average case: $O(logn)$, Worst case: $O(n)$ 

   When the tree is balanced, each level splits the data in half. This means you only need to go down a few levels to find, insert, or remove something. But if you add values in order, the tree grows in a straight line instead of branching out. It starts acting like a linked list, and you have to check each node one by one. That makes it much slower. [3]

2. Quick Sort: Sort

   Average case: $O(nlogn)$, Worst case: $O(n^2)$

   Quick Sort works by choosing a pivot and dividing the array into two parts. One part has values less than the pivot and the other part has values greater than the pivot. If the pivot splits the array evenly, sorting is fast. But in the worst case, like when the pivot is always the smallest or largest value, the array splits into one large part and one tiny part. This causes many extra recursive calls and comparisons, which makes the algorithm much slower. [4]

## Empirical Analysis - Speed Comparison

For this section, you will need to have run the speed compare program and generated the output into a CSV file.

### Empirical Results Table

Add a link from this document to the CSV file you generated. The CSV file must have at least 15 different N values, but
often can have a lot more depending on what you ran.  

### Analysis

Create *at least three* graphics that each visually explain an aspect of your data related to an operation or data structure. Under each one, explain what the graphic is showing, and what you can conclude from it/what you find interesting about it.

> [!IMPORTANT]
> 
> Make sure you are comparing apples to apples and not apples to oranges when choosing what to put in the same graph. 
> 
> **:x: different data structures *and* different operations**
> 
> - Vector Add Front versus BST Add
> 
> **:white_check_mark: different operations *but* same data structure**
> 
> - BST Add versus Remove, and Search for BST
> 
> **:white_check_mark: different data structures *but* same operation**
> 
> - BST Add versus Add for Sorted Vector, and Sorted Single/Double Linked List
> 
> - Vector Add Front versus Add Front for Single/Double Linked List

> [!TIP]
> 
> To create the graphics you can use a third party program like Microsoft Excel or Google Sheets. (Completely optional if you want extra coding: you can use python libraries such as matplotlib, seaborn, or plotly)
> 
> Make sure you can see the image embedded in the Report.md using [image markdown] when you upload it to github, and get help if it doesn't show! 

#### Graphic 1 (Add Operation Runtime: SortedVector vs LinkedList vs BST)

> Insert your comments/observations about the graphic here
This highlights how each structure handles adding elements as $N$ increases.

#### Graphic 2 (Search Performance: SortedVector vs LinkedList vs BST)

> Insert your comments/observations about the graphic here
This compares lookup efficiency across the three structures, showing how structure impacts search speed.

#### Graphic 3 (Remove Operation Comparison: SortedVector vs SortedList vs BST)

> Insert your comments/observations about the graphic here
This shows how each structure scales when removing elements, showing how each structure handles removal as the dataset grows.
## Critical Thought

### Data Evaluation

Answer the questions below. Make sure to answer each question fully, and explain your reasoning. Indent your answers immediately below the question, for it to line up with the bullet point.

For example:

```markdown
1. What is the most surprising result from the data? Why is it surprising?
   Answer here
```

1. What is the most surprising result from the data? Why is it surprising?

2. What data structure is the fast at adding elements (sorted)? Why do you think that is?

   The fastest data structure for adding elements while keeping them sorted is a Binary Search Tree. Since a BST is designed to keep things in order as you insert, it doesn’t need to scan through every item like a linked list or shift elements around like a vector. Instead, it uses comparisons to quickly find the right spot for each new item. This makes adding much faster, especially when the tree is balanced.

3. What data structure is the fastest at removing elements (sorted)? Why do you think that is?

   The fastest data structure for removing elements while keeping them sorted is the Binary Search Tree. A BST can quickly find and remove items using comparisons, without needing to scan through everything or move other elements around. As long as the tree stays balanced, this process is very fast, even with large amounts of data. 

4. What data structure is the fastest at searching? Why do you think that is?

   The fastest data structure for searching is the Binary Search Tree. In the results, the BST had the lowest search times compared to sorted vectors and linked lists. This is because a BST uses comparisons to quickly narrow down where to look, instead of checking every item one by one. As long as the tree is balanced, it can find items very quickly, even when the dataset is large.

5. What data structure is the fastest for adding elements to the front? Why do you think that is?

   The fastest data structure for adding elements to the front is the Linked List. It is much faster because it creates a new node and points it to the current head of the list. There’s no need to move or shift any existing elements. In contrast, a vector stores elements in a fixed order in memory, so adding to the front means shifting every item one position to make space, which takes much more time as the list grows.

6. What data structure is the fastest for adding elements to the back? Why do you think that is?

   The fastest data structure for adding elements to the back is the Linked List. This is because it can quickly create a new node and attach it to the end by updating just one pointer, especially if it keeps track of the tail. Unlike a vector, which may need to shift memory or resize its storage as it grows, a linked list doesn’t need to move anything. That makes it much faster for back insertions, especially with large datasets.

7. What data structure is the fastest for removing elements from the front? Why do you think that is?

   The fastest data structure for removing elements from the front is the Linked List. Similar to adding elements, it doesn’t require shifting or resizing. Removal simply updates the head pointer to the next node. In contrast, a vector must shift every other element one position to the left, which becomes much slower as the list grows.

8. What data structure is the fastest for removing elements from the back? Why do you think that is?

   The fastest data structure for removing elements from the back is the Linked List. Similar to adding elements, it doesn’t need to shift or resize anything, it just updates a pointer to remove the last node, especially if it keeps track of the tail. A vector may need adjust its size, which takes more time as the list grows.

### Deeper Thinking

#### Double Linked List vs Single Linked List

1. If you wrote your linked list as a single linked list, removing from the back was expensive. If you wrote it as a double linked list, removing from the back was cheap. Why do you think that is?

2. When running most functions, at least ~30% of the tests were worse case scenarios. Why do you think that is? 

3. What was done in the code to encourage that? 

4. How did this particularly influence the linked list searches?

#### Test Bias

1. The tests were inherently biased towards the BST to perform better due the setup of the experiment. Explain why this is the case.  (hint: think about the randomization of the data, and the worst case scenario for BST).

2. What would generate the worst case scenery for a BST?

3. Researching beyond the module, how would one fix a BST so the worst case scenario matches (or at least i closer to) the average case.[^1^]

## Scenario

Fill out the table below. This is a common technical interview topic!

| Structure          | Good to use when                                                                 | Bad to use when                                                                  |
| ------------------ | -------------------------------------------------------------------------------- | -------------------------------------------------------------------------------- |
| Vector             | Need quick random access and frequent adds at end                                | Need to insert or delete in the middle often                                   |
| Linked List        | Good for stacks with frequent front only access                                  | Need quick random access                                                |
| Sorted Vector      | When values coming in are already mostly sorted and we need quick search access. | When space is limited and the dataset is extremely large causing memory to swap. |
| Sorted Linked List | Need to keep items sorted with lots of adds or deletes                           | Need fast searching or random access                                       |
| BST                | Need quick search/insert/delete with balanced branches                           | data is presorted                                                                |

## Conclusion

Summarize your findings. Where there any surprises?  What did you end up learning by comparing speeds?

## Technical Interview Practice Questions

For both these questions, are you are free to use what you did as the last section on the team activities/answered as a group, or you can use a different question.

1. Select one technical interview question (this module or previous) from the [technical interview list](https://github.com/CS5008-khoury/Resources/blob/main/TechInterviewQuestions.md) below and answer it in a few sentences. You can use any resource you like to answer the question.


   Recursion
   What is recursion? How does a recursive algorithm exit?

   Describe a scenario when you would want to use recursion and a scenario where you wouldn't.

   Recursion is when a function calls itself to solve a smaller part of a problem. Each time it calls itself, it works on a simpler version until it reaches a base case. Without a base case, the function would keep calling itself forever and crash. You might want to use recursion when solving problems that naturally break into smaller pieces, like calculating factorials or searching through a tree. But you wouldn’t use recursion for tasks that need lots of memory or very deep loops, like sorting huge arrays, because it can be slower and use too much stack space.


2. Select one coding question (this module or previous) from the [coding practice repository](https://github.com/CS5008-khoury/Resources/blob/main/LeetCodePractice.md) and include a c file with that code with your submission. Make sure to add comments on what you learned, and if you compared your solution with others. 

[valid_palindrome.c](https://github.com/CS5008Fall2025/homework-speed-comparison-zembug/tree/main/instructions/valid_palindrome.c)

## References

Add your references here. A good reference includes an inline citation, such as [1] , and then down in your references section, you include the full details of the reference. Computer Science research often uses [IEEE] or [ACM Reference format].

[1] La Vivien Post. 2025. Big O Notation Cheat Sheet – Leetcode Big O Notebook. (June 7, 2025). Retrieved October 29, 2025 from https://www.lavivienpost.com/big-o-notation-cheat-sheet-leetcode-big-o/

[2] GeekforGeeks. 2025. Big O Notation Tutorial - A Guide to Big O Analysis. (August 27, 2025). Retrieved October 29, 2025 from https://www.geeksforgeeks.org/dsa/analysis-algorithms-big-o-analysis/

[3] Expert Beacon. 2024. Binary Search Trees: An Expert Guide for Developers. (August 16, 2024). Retrieved October 29, 2025 from https://expertbeacon.com/binary-search-trees-an-expert-guide-for-developers/

[4] GeeksforGeeks. 2025. Time and Space Complexity Analysis of Quick Sort. (July 223, 2025). Retrieved October 29, 2025 from https://www.geeksforgeeks.org/dsa/time-and-space-complexity-analysis-of-quick-sort/

[^1^]: Implementing a BST with a self-balancing algorithm, such as AVL or Red-Black Trees is a great research paper topic!

<!-- links moved to bottom for easier reading in plain text (btw, this a comment that doesn't show in the webpage generated-->

[image markdown]: https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax#images

[ACM Reference Format]: https://www.acm.org/publications/authors/reference-formatting
[IEEE]: https://www.ieee.org/content/dam/ieee-org/ieee/web/org/conferences/style_references_manual.pdf
