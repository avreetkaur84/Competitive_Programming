# 🧠 C++ `stringstream` Master Notes

## 📌 What is `stringstream`?

`std::stringstream` is a class from the `<sstream>` header in C++ that allows us to perform **input and output operations on strings**, treating them as streams just like `cin` or `cout`.

---

## ✅ Use Cases

| Use Case                           | Description                                      |
| ---------------------------------- | ------------------------------------------------ |
| Tokenization (split string)        | Split by spaces or custom delimiters             |
| String to Number Conversion        | Convert strings to int, float, etc.              |
| Number to String Conversion        | Convert numbers to strings                       |
| Building Complex Strings           | Concatenating different types easily             |
| Parsing CSV or formatted data      | Break down comma-separated or tab-separated data |
| Leetcode/Binary Tree Serialization | Used to split serialized strings by commas       |

---

## 🧰 Headers Required

```cpp
#include <sstream>
```

---

## 🔧 Basic Syntax

```cpp
std::stringstream ss;       // Declare
ss << "123 456";            // Insert string
int x, y;
ss >> x >> y;               // Extract integers from the stream
```

---

## 🧩 Tokenize by Whitespace

```cpp
string s = "42 67 89";
stringstream ss(s);
int num;
while (ss >> num) {
    cout << num << endl;
}
```

### Output:

```
42
67
89
```

---

## 🧩 Tokenize by Custom Delimiter (e.g. comma)

```cpp
string s = "apple,banana,carrot";
stringstream ss(s);
string token;
while (getline(ss, token, ',')) {
    cout << token << endl;
}
```

### Output:

```
apple
banana
carrot
```

---

## 🔁 String <-> Number Conversion

### String to Int

```cpp
string s = "123";
stringstream ss(s);
int x;
ss >> x;   // x = 123
```

### Int to String

```cpp
int x = 456;
stringstream ss;
ss << x;
string s = ss.str();  // s = "456"
```

OR

```cpp
string s = to_string(x); // Modern C++
```

---

## ♻️ Reusing a stringstream

```cpp
ss.str("");   // Clear the content
ss.clear();   // Reset internal state flags
```

---

## 🧱 Variants

| Variant         | Purpose                |
| --------------- | ---------------------- |
| `stringstream`  | Input and output       |
| `istringstream` | Input-only from string |
| `ostringstream` | Output-only to string  |

---

## 🚀 Real Problem Usage

### Leetcode: Serialize and Deserialize Binary Tree

```cpp
stringstream ss(data);
string token;
while (getline(ss, token, ',')) {
    // process token (value or 'N')
}
```

---

## 🧠 Tips & Tricks

* Always use `getline(ss, token, delim)` if the delimiter is not whitespace
* Always reset the stream using `str("")` and `clear()` if reused
* Great for building debugging logs or complex strings

---

## 🎯 Practice Problems

| Platform | Problem                                                                                                            |
| -------- | ------------------------------------------------------------------------------------------------------------------ |
| Leetcode | [297. Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) |
| Leetcode | [682. Baseball Game](https://leetcode.com/problems/baseball-game/)                                                 |
| Leetcode | [224. Basic Calculator](https://leetcode.com/problems/basic-calculator/)                                           |
| GFG      | Parse CSV, reverse words in string, etc.                                                                           |

---

## 🔚 Summary

`stringstream` is your best friend when it comes to string manipulation, parsing, and conversion in C++. Once you master this tool, you'll be flying through many annoying string-input problems with ease.

Use it smartly, and you'll gain both **clarity** and **conciseness** in your code!
