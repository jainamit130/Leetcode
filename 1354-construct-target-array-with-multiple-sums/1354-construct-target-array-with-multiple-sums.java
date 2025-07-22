class Solution {
    public boolean isPossible(int[] target) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        long total = 0;

        for (int num : target) {
            pq.add(num);
            total += num;
        }

        while (true) {
            int largest = pq.poll();
            long rest = total - largest;

            if (largest == 1 || rest == 1) return true;
            if (rest == 0 || largest <= rest) return false;

            int newNum = (int)(largest % rest);
            if (newNum == 0) return false;

            pq.add(newNum);
            total = rest + newNum;
        }
    }
}



/*

1   1   1

1   3   1


1   3   5

1   9   5


1   9   15

1   9   25

1   9   5


8   5

3   5

3   2

1   2

1   1

*/