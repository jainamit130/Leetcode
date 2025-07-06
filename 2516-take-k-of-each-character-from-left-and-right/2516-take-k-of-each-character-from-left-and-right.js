/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var takeCharacters = function(s, k) {
    const n = s.length;
    const total = [0, 0, 0];
    let ans = Infinity;

    // Count occurrences of 'a', 'b', and 'c'
    for (let i = 0; i < n; i++) {
        total[s.charCodeAt(i) - 'a'.charCodeAt(0)]++;
    }

    // Check if all characters are sufficient for k
    for (let t = 0; t < 3; t++) {
        if (total[t] < k) {
            return -1;
        }
    }

    let i = 0, j = 0;
    const curr = [0, 0, 0];

    // Define isValid as an inner function
    const isValid = (k, curr, total) => {
        for (let i = 0; i < 3; i++) {
            if (total[i] - curr[i] < k) {
                return false;
            }
        }
        return true;
    };

    while (j < s.length) {
        // Expand the window
        while (j < s.length && isValid(k, curr, total)) {
            curr[s.charCodeAt(j) - 'a'.charCodeAt(0)]++;
            ans = Math.min(ans, s.length - (j - i));
            j++;
        }
        // Shrink the window
        while (i < j && !isValid(k, curr, total)) {
            curr[s.charCodeAt(i) - 'a'.charCodeAt(0)]--;
            i++;
        }
    }

    ans = Math.min(ans, s.length - (j - i));
    return ans;
};
