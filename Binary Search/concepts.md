1. Lower bound - The smallest element >= target
2. Upper bound - The smallest element > target
3. lb store the index of the lower bound element. If there does not exist such element, then it points to arr.end()
```c++
int lb = lower_bound(arr.beign(), arr.end(), target) - arr.begin();
```
4. 