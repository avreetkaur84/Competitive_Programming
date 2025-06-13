# 🗳️ Moore's Voting Algorithm

## 📌 Problem Statement

Given an array of size `n`, find the **majority element**, i.e., the element that appears **more than ⌊n/2⌋ times**.  
You can assume that the majority element always exists in the array.

---

## 🚀 Time and Space Complexity

- ⏱️ Time Complexity: `O(n)`  
- 🧠 Space Complexity: `O(1)`  
- ✅ No extra memory, no sorting, no hashmaps.

---

## 🧠 Core Idea

The majority element **outnumbers** all other elements **combined**.  
So we can **cancel out** non-majority elements with the majority one during a linear scan.

This works because:
> If an element appears more than `n/2` times, it will always be the **last one standing**.

---

## 🧪 Example

Input:  
```cpp
nums = [2, 2, 1, 1, 1, 2, 2]
````

Execution:

```
Start → ele = 2, count = 1  
2 → count = 2  
1 → count = 1  
1 → count = 0  
1 → count = 1, ele = 1  
2 → count = 0  
2 → count = 1, ele = 2  
```

🎯 Final result: `2`

---

## 🛠️ Algorithm (C++ Code)

```cpp
            int cnt=1, ele=nums[0];
            for(int i=1; i<nums.size(); i++) {
                if(cnt==0 && nums[i]!=ele) {
                    ele=nums[i];    cnt++;
                } 
                else if(nums[i]==ele) {
                    cnt++;
                } else if(nums[i]!=ele) {
                    cnt--;
                }
            }
    
            return ele;
```

---

## 📚 When to Use

✅ Use Moore's Voting Algorithm when:

* You know there's a guaranteed majority element (> n/2 times)
* You need **O(n) time** and **O(1) space**
* Interviewer says: “Can you optimize it further?”

---

## 🧠 Bonus: Why It Works Mathematically?

Imagine majority element `M` occurs more than `n/2` times.
All other elements combined occur less than `n/2` times.
Every mismatch between `M` and a non-`M` reduces the count,
but since `M` is the majority, it can **never be fully canceled out**.

---

## 👀 Follow-up

To find all elements appearing **more than ⌊n/3⌋** times → use a **modified version** of Moore’s algorithm.
Spoiler: You’ll need to track **two candidates** 😉

---

## 🏁 TL;DR

Moore's Voting is like a reality show — most elements get voted out,
but the true majority stays till the end and wins the crown 👑

---
