class Solution {
  stringStack(pat, tar) {
    const n = pat.length;
    const m = tar.length;
    if (m === 0) return true;

    const even_lists = new Array(26);
    const odd_lists = new Array(26);
    for (let i = 0; i < 26; i++) {
      even_lists[i] = [];
      odd_lists[i] = [];
    }

    for (let i = 0; i < n; i++) {
      const c = pat[i];
      const idx = c.charCodeAt(0) - "a".charCodeAt(0);
      if (i % 2 === 0) {
        even_lists[idx].push(i);
      } else {
        odd_lists[idx].push(i);
      }
    }

    const firstChar = tar[0];
    const idx0 = firstChar.charCodeAt(0) - "a".charCodeAt(0);
    if (even_lists[idx0].length === 0 && odd_lists[idx0].length === 0) {
      return false;
    }
    let even0 = even_lists[idx0].length > 0 ? even_lists[idx0][0] : null;
    let odd0 = odd_lists[idx0].length > 0 ? odd_lists[idx0][0] : null;

    for (let j = 1; j < m; j++) {
      const c = tar[j];
      const idx = c.charCodeAt(0) - "a".charCodeAt(0);
      let next_even = null;
      let next_odd = null;

      if (even0 !== null) {
        const list_odd = odd_lists[idx];
        let left = 0;
        let right = list_odd.length;
        while (left < right) {
          const mid = Math.floor((left + right) / 2);
          if (list_odd[mid] <= even0) {
            left = mid + 1;
          } else {
            right = mid;
          }
        }
        if (left < list_odd.length) {
          next_odd = list_odd[left];
        }
      }

      if (odd0 !== null) {
        const list_even = even_lists[idx];
        let left = 0;
        let right = list_even.length;
        while (left < right) {
          const mid = Math.floor((left + right) / 2);
          if (list_even[mid] <= odd0) {
            left = mid + 1;
          } else {
            right = mid;
          }
        }
        if (left < list_even.length) {
          next_even = list_even[left];
        }
      }

      even0 = next_even;
      odd0 = next_odd;
      if (even0 === null && odd0 === null) {
        return false;
      }
    }

    if (even0 !== null && (n - even0) % 2 === 1) {
      return true;
    }
    if (odd0 !== null && (n - odd0) % 2 === 1) {
      return true;
    }
    return false;
  }
}