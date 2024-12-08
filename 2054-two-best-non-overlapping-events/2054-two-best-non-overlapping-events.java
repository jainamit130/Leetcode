class Solution {
    public int maxTwoEvents(int[][] events) {
        Arrays.sort(events, (a, b) -> b[0] - a[0]);
        
        Stack<int[]> maxValue = new Stack<>();
        int max = events[0][2];
        maxValue.push(new int[]{events[0][0] - 1, max});

        for (int[] event : events) {
            if (max < event[2]) {
                max = event[2];
                maxValue.push(new int[]{event[0] - 1, max});
            }
        }

        Arrays.sort(events, (a, b) -> a[1] - b[1]);
        int result = 0;
        max = maxValue.peek()[1];
        int end = maxValue.peek()[0];
        for (int[] event : events) {
            while (event[1] > end) {
                maxValue.pop();
                max = maxValue.isEmpty() ? 0 : maxValue.peek()[1];
                end = maxValue.isEmpty() ? Integer.MAX_VALUE : maxValue.peek()[0];
            }
            result = Math.max(result, event[2] + max);
        }

        return result;
    }
}