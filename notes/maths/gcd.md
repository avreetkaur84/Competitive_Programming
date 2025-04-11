# GCD Basics for CP

## What is GCD?
GCD (Greatest Common Divisor) of two numbers is the largest number that divides both of them without leaving a remainder.

---

## Properties of GCD

- **Property 1:** `GCD(a, 0) = a  `

  Any number divided by 0 has the number itself as the GCD.

- **Property 2:** `GCD(a, b) = GCD(b, a % b)  `

  This is the Euclidean Algorithm and is the basis for efficient GCD computation.

- **Property 3:** `GCD(a, a) = a`

- **Property 4:** If `GCD(a, b) = 1`, then a and b are **co-prime**  

  They share no common factor except 1.  
  - Any two **distinct prime numbers** are always co-prime.  
  - **Note:** Co-prime numbers are not necessarily prime themselves.  
    - For example, (4, 9) are co-prime but not prime individually.

- **Property 5:** `GCD(a, GCD(b, c)) = GCD(GCD(a, b), c)`

     GCD is associative 

- **Property 6:** `GCD(a, b) * LCM(a, b) = a * b  `

  Very useful for solving problems where both GCD and LCM are involved.

- **Property 7:** Adding the same number to both numbers doesn't make their GCD independent, but the result can be expressed in terms of their difference,

  For any non-negative integer d, 
  
  `GCD(x + d, y + d) = GCD(y - x, x + d)`

  This tells us that if we add the same value to both numbers, their GCD becomes dependent on the difference between the original numbers and the new shifted value.This is often used in problems where you're allowed to add the same value to all elements and want to maximize GCD from a pair.

---

## Applications of GCD in CP

- **Reducing Fractions**  
  If you have a fraction `a/b`, you can reduce it to its simplest form by dividing both `a` and `b` by their GCD.  
  Example: `8/12 → GCD(8, 12) = 4 → 2/3`

- **Checking for Co-Primes**  
  If `GCD(a, b) == 1`, the two numbers are co-prime. Useful in problems requiring relatively prime pairs or in **Euler's Totient Function**.

- **Tiling and Partitioning Problems**  
  Given a length/area and tile size, GCD helps in finding the largest tile size that can divide both dimensions without leftover.  
  Example: For a rectangle of `a x b`, number of square tiles of size `GCD(a, b)` needed is `(a*b)/(GCD(a,b)^2)`

- **Synchronization and Cycles**  
  When dealing with time-based events or repeating cycles (bells ringing, rotating machines), GCD is used through **LCM**, since `LCM(a, b) = (a * b) / GCD(a, b)`

- **Modular Arithmetic**  
  If `GCD(a, m) = 1`, then `a` has a **modular inverse** modulo `m`, crucial for solving linear congruences.

- **Diophantine Equations**  
  Linear equations of the form `ax + by = c` have integer solutions **if and only if** `GCD(a, b)` divides `c`. Solved using the **Extended Euclidean Algorithm**.

- **Number Transformations**  
  Used in problems where transformations are only allowed using GCD-based operations (e.g., replace `a` with `GCD(a, b)`).

- **Graph Theory & Union-Find**  
  Some problems model connectivity using GCD relationships — edges exist if `GCD(a, b) > 1`.


*Don't even know half of the applications!! - Current Phase: 07-04-2025*


---

## Code Snippets

### Recursive GCD (Euclidean Algorithm)
```cpp
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
```
---