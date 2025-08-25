/**
 * @param {number[]} arr
 * @param {number} k
 * @returns {number}
 */

function isPossible(arr, target, k) {
  let n = arr.length;
  if (n % 2 === 1) {
    // for odd-sized array, consider elements from
    // middle to end
    for (let i = Math.floor(n / 2); i < n; ++i) {
      if (arr[i] < target) k -= target - arr[i];
    }
  } else {
    // for even-sized array, handle two middle
    // elements separately
    if (arr[n / 2] <= target) {
      k -= target - arr[n / 2];
      k -= target - arr[n / 2 - 1];
    } else {
      k -= 2 * target - (arr[n / 2] + arr[n / 2 - 1]);
    }
    // process remaining elements to the right
    for (let i = n / 2 + 1; i < n; ++i) {
      if (arr[i] < target) k -= target - arr[i];
    }
  }
  return k >= 0;
}
class Solution {
  maximizeMedian(arr, k) {
    arr.sort((a, b) => a - b);
    let n = arr.length;
    // compute initial median floor if even length
    let iniMedian = arr[Math.floor(n / 2)];
    if (n % 2 === 0) {
      iniMedian += arr[n / 2 - 1];
      iniMedian = Math.floor(iniMedian / 2);
    }
    let low = iniMedian,
      high = iniMedian + k;
    let bestMedian = iniMedian;
    // binary search to find maximum
    // achievable median
    while (low <= high) {
      let mid = Math.floor((low + high) / 2);
      if (isPossible(arr, mid, k)) {
        bestMedian = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return bestMedian;
  }
}