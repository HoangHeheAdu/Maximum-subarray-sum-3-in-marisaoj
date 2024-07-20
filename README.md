# Maximum-subarray-sum-3-in-marisaoj

The solution I found for this problem can be used for all k (the numbers of non-overlapping, non-empty subarrays) which are smaller than n (the size of array).
The time complexity of this solution is **O(n * k)**.

The solution comes up when I tried to solve maximum-subarray-sum-1 and maximum-subarray-sum-2 using prefix Sums.

# Maximum-subarray-sum-1
This can be solved using $O(n)$ time complexity one. 

The idea is to find the maximum sums from l to r with $1 <= l < r <= n$. This sum is equal to $S_r - S_l$ with $1 <= l < r <= n$, this leads to the need of finding the minimum value of $S_l$. That means for every $r$ $(1 <= r <= n)$ 
we need to find the smallest prefix sum with the length of $l$ $(l < r)$. This can be solved using one loop.

$ans_r = prefix_r - min(prefix_l) with 1 <= l < r <= n$.
If we use a loop to run $r$ through 1 to $n$, we can update min rolling each $r$; This allows us to calculate the minimum value with O(1) complexity. The answer to the problem is the maximum value of $S_r - S_l$ with $1<=r<=n$.

The solution can be found in other websites.

# Maximum-subarray-sum-2
The requirement of this problem is to find $1 <= l <= r < i <= j <= n$ such that $B = (A_l + A_{l + 1} + ... + A_r) + (A_i + A_{i + 1} + ... + A_j)$ is maximized
With the idea of **Maximum-subarray-sum-1**, we change this to an equivalent expression.

**Sol_1**
Consider $S_k = A_1 + A_2 + ... + A_k$
$B = S_j - (A_{i - 1} + ... + A_{r + 1}) - (A_{l - 1} + A_{l - 2} + ... + A_1)$
  $= S_j - (S_{i - 1} - (A_r + A_{r - 1} + ... + A_l))$
  $= S_j - (S_{i - 1} - (S_r - S_{l - 1}))$

So to find the maximum of $B$, we need to find the minimum value of this $(S_{i - 1} - (S_r - S_{l - 1}))$, which can be found when the value of $(S_r - S_{l - 1})$ is maximized

Check __max-sub-sum-2-ver1.cpp__ to see the executed solution.

**Sol_2** This problem can also be solved when loop through $h$ from 1 to $n$ and find the maximum value of a sum from $1$ to $h$ and a sum from $h$ to $n$ $(1 <= l <= r <= h < i <= j <= n)$.

# Maximum-subarray-sum-3
Still with the idea from above problems, with $1 <= l <= r < i <= j < p <= k <= n$ such that $M = (A_l + A_{l + 1} + ... + A_r) + (A_i + A_{i + 1} + ... + A_j) + (A_p + A_{p + 1} + ... + A_k)$ is maximized

Check max-sub-sum-3-ver1.cpp (this solution is the combination of **Sol_1** and **Sol_2** from **Maximum-subarray-sum-2**) 

We used the result from the transformation. 
$M = (A_l + A_{l + 1} + ... + A_r) + (A_i + A_{i + 1} + ... + A_j) + (A_p + A_{p + 1} + ... + A_k)$
  $= B + (A_p + A_{p + 1} + ... + A_k)$
  $= S_p - S_{k - 1} + B$
  $= S_p - (S_{k - 1} - B)$

Similarly, to find the maximum of M, we need to find the minimum value of this $(S_{k - 1} - B)$, which can be found when the value of $B$ is maximized

Check __max-sub-sum-3-ver2.cpp__ to see the answer.

A little optimization for memory, check __max-sub-sum-3-ver3.cpp__ 

Continue optimizing - shorten the code, check __max-sub-sum-3-ver4.cpp__
This solution beats all solutions from other people in terms of time complexity and space complexity
![image](https://github.com/user-attachments/assets/c71ac419-2c44-4c8f-8b11-4424b460678e)


# This has led to a generalized solution for any k <= n, check __max-sub-sum-3-ver5.cpp__, but remember to change k to the number you want

With this code, I chose k = 2 for **maximum-subarray-sum-2**, check this code __max-sub-sum-2-ver2.cpp__ and the result can be shown in this image
![image](https://github.com/user-attachments/assets/3a301569-62ef-4924-bf61-9c3c7dadeb81)

Thank you for reading!

If you find this helpful or interesting, please consider giving it a star ⭐ on GitHub. Your support helps improve the project and encourages further development!
