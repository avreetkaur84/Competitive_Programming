## What I Have understood about DP Journey -

1. Dp is applied when we have to go through lots of choices and we have to choose the optimal result(max, min, greatest, smallest and so on)
2. Dp is all about recursion + storage.
3. How to write a recursive function -
    - First, think of a base case -  which is smallest valid input you can have
    - Think of the choices you can make at each step - choice diagram
    - Your task to make the input small with every step
    - Know what is you have to return and tehn accordingly decide the return type of function

    int rec(int a, int b) {
        BASE CASE - first,
        CHOICE DIAGRAM - second 
    }

4. First make the recursive tree for the particular question and follow the above steps to write the code.
5. Once, recursive code is written  then we can do for memoization - I know its obvious.
6. But, here is teh most important thing to consider - what you are going to consider for your DP array. 
    - First, I learnt that we should decide teh dimension of the array on basis of the elemenst that are goign to change, like index, sum and others according to problems.
    - But, as I am doing the problems I have realised it is much more than that. We have consider those which changes but here we can only choose those that will have different result for every turn. 
        -Means, suppose the question is to count the total partitions of subset sum with the difference d. Now, in this question, we have many elements that are changing like, index, sum, difference. While solving teh question, I took index and difference as I thought sum is depending on diffence and difference is main thing that we have to calculate. But, this is exactly where I made a mistake. Difference is being derived from the sum and teh real source is sum and index itself.
    - So, always consider the source of things, not the derived part as derived aprt can get repeated but source combination won't.




📝 Key DP Lesson: Never stop recursion early when counting subsets. Only evaluate the sum at the leaf node (last index). Especially important when zeros are involved.


📜 Rule of Thumb for Choosing DP Keys
| 💬 You Think                    | ✅ You Should Check                                       |
| ------------------------------- | -------------------------------------------------------- |
| "This value changes every time" | Is it **uniquely** defining my recursion path?           |
| "This value controls my answer" | Is it **derived from another variable** I already track? |
| "This is my condition"          | Is the condition **just a filter**, not a state?         |

You always memoize the source, never the derived value.

Memoization is about remembering how you got here, not just where you are.

The same “derived” state could be reached through different decisions, and you’ll lose that info if you memoize only on the derived form.


🔹 Tabulation is clean only if math is simplified first.
Reduce to standard problems like subset-sum, knapsack, LIS, etc.

🔹 Use math to derive goal states.
sum1 - sum2 = d → sum1 = (total + d)/2

🔹 If your base case or initialization in tabulation looks messy, go back to math and rethink your state.


## dp[i][j] = ways to reach position j using i steps

## Seriously, If I will survive this DSA hell mode, I can really survive anything.
