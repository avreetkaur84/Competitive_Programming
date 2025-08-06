## 🧠 Formula Derivation Template for Competitive Programming

> The mindset shift from "pattern spotting" to **"mathematical proof and derivation"**.

---

### **STEP 1: Establish the Baseline**

Ask yourself:

> "What is the default or minimal outcome if I do nothing extra?"

* For array problems: baseline = sorted array, prefix sum, or total sum.
* For graph problems: baseline = shortest path, or connected components.
* For Pathless: baseline = `base_sum` (straight walk sum).

✅ This baseline is your **anchor** — all future reasoning is relative to this.

---

### **STEP 2: Define Operations and Effects**

Ask yourself:

> "What actions can change this baseline? By how much?"

* Write the relationship as a formula:

  ```
  total = baseline + modifications
  ```
* Break modifications into measurable steps.

  * Example (Pathless): back-and-forth moves → add `(a[i] + a[i+1])` each time.

This step converts intuition into math.

---

### **STEP 3: Analyze the Range**

Now, ask:

> "What values can these modifications produce? Are there forbidden values?"

* Check what is achievable:

  * If the target is below the baseline → impossible.
  * If the target equals the baseline → directly achievable.
  * If the target is above the baseline → check if modifications can cover it.

    * Identify edge cases (like `d = 1` in Pathless).
* Derive general rules from these constraints.

---

## ✅ Example: Pathless

1. **Baseline:**

   ```
   base_sum = sum(arr)
   ```
2. **Operations:**

   * Back-and-forth moves → add `(a[i] + a[i+1])` repeatedly.

   ```
   total_sum = base_sum + d
   ```
3. **Range:**

   * If `s < base_sum` → impossible.
   * If `s == base_sum` → Alice wins (straight path).
   * If `s > base_sum`:

     * `d = s - base_sum`

       * If `d = 1` → only `(0+1)` works; Bob can block by separating them.
       * Else → Alice wins.

✅ Final formula:

```cpp
if s < base_sum → Bob wins (any arrangement)
else if s == base_sum → Alice wins (-1)
else if d == 1 → Bob rearranges (0...2...1)
else → Alice wins (-1)
```

---

## 🔥 How to Use This Template

1. Always **write down the baseline** explicitly.
2. Define operations in clear mathematical terms.
3. Express the effect of operations on the target.
4. Analyze achievable ranges and edge cases.
5. Only then code the derived rules.

---

## 📌 Key Principle

> ❌ Don’t guess from examples.
> ✅ Derive rules by understanding the "space of possible transformations".

When you practice this for 7–10 days, you'll see your debugging time collapse and your confidence explode.

---