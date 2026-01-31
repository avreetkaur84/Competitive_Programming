### Check if two lines intersect eac other or not
```
        ax+bx=c
        2x+3y=5
        3x+2y=5
```
1. find determinant
2. d==0 ->       (lines do not intersect, so, solution does not exist)
```
    a1  b1      ->     2    3       -> (a1*b2)-(a2*b1) = determinent
    a2  b2      ->     3    2 
```
3. d!=0 ->       (lines do intersect, so, solution does exist)
4. For finding x, do not include x part
```
    X = b1  c1   ->    3    -5
        b2  c2   ->    2    -5
    X = X/D
```
5. For finding y, do not include y part
```
    Y = a1  c1   ->    2    -5
        a2  c2   ->    3    -5
    Y = Y/D
```
6. Print X,Y



