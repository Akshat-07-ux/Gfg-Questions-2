class Solution {
  longestSubarray(arr) {
    const n = arr.length;
    const left = new Array(n).fill(-1);
    const right = new Array(n).fill(n);
    let stack = [];

    for (let i = 0; i < n; i++) {
      while (stack.length > 0 && arr[stack[stack.length - 1]] <= arr[i]) {
        stack.pop();
      }
      if (stack.length > 0) {
        left[i] = stack[stack.length - 1];
      }
      stack.push(i);
    }

    stack = [];
    for (let i = n - 1; i >= 0; i--) {
      while (stack.length > 0 && arr[stack[stack.length - 1]] < arr[i]) {
        stack.pop();
      }
      if (stack.length > 0) {
        right[i] = stack[stack.length - 1];
      }
      stack.push(i);
    }

    let ans = 0;
    for (let i = 0; i < n; i++) {
      const L = right[i] - left[i] - 1;
      if (arr[i] <= L) {
        ans = Math.max(ans, L);
      }
    }

    return ans;
  }
}