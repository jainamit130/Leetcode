class Solution {
    public boolean canChange(String start, String target) {
        // Remove all '_' characters and compare sequences of 'L' and 'R'
    if (!start.replace("_", "").equals(target.replace("_", ""))) {
        return false;
    }

    int i = 0, j = 0;
    int n = start.length();

    // Use two pointers to check the positions of 'L' and 'R'
    while (i < n && j < n) {
        // Skip blanks in both strings
        while (i < n && start.charAt(i) == '_') {
            i++;
        }
        while (j < n && target.charAt(j) == '_') {
            j++;
        }

        // Check if one pointer is out of bounds
        if (i < n && j < n) {
            // Ensure the characters match
            if (start.charAt(i) != target.charAt(j)) {
                return false;
            }

            // Check movement constraints
            if (start.charAt(i) == 'L' && i < j) {
                return false; // 'L' cannot move right
            }
            if (start.charAt(i) == 'R' && i > j) {
                return false; // 'R' cannot move left
            }

            // Move both pointers
            i++;
            j++;
        }
    }

    // Ensure all remaining characters in both strings are blanks
    while (i < n) {
        if (start.charAt(i) != '_') {
            return false;
        }
        i++;
    }
    while (j < n) {
        if (target.charAt(j) != '_') {
            return false;
        }
        j++;
    }

    return true;
    }
}