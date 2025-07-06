import java.util.*;

class Solution {
    private List<Integer> path = new ArrayList<>();

    public int[][] validArrangement(int[][] pairs) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        Map<Integer, Integer> outDegrees = new HashMap<>();
        Map<Integer, Integer> inDegrees = new HashMap<>();

        // Build adjacency list and degree counts
        for (int[] pair : pairs) {
            adj.computeIfAbsent(pair[0], k -> new ArrayList<>()).add(pair[1]);
            outDegrees.put(pair[0], outDegrees.getOrDefault(pair[0], 0) + 1);
            inDegrees.put(pair[1], inDegrees.getOrDefault(pair[1], 0) + 1);
        }

        // Find start node
        int start = pairs[0][0];
        for (int node : adj.keySet()) {
            int outDegree = outDegrees.getOrDefault(node, 0);
            int inDegree = inDegrees.getOrDefault(node, 0);
            if (outDegree - inDegree == 1) {
                start = node;
                break;
            }
        }

        // Perform DFS to find the Eulerian path
        dfs(adj, start);

        // Construct the result
        Collections.reverse(path);
        int[][] result = new int[path.size() - 1][2];
        for (int i = 0; i < path.size() - 1; i++) {
            result[i][0] = path.get(i);
            result[i][1] = path.get(i + 1);
        }

        return result;
    }

    private void dfs(Map<Integer, List<Integer>> adj, int node) {
        List<Integer> neighbors = adj.getOrDefault(node, new ArrayList<>());
        while (!neighbors.isEmpty()) {
            int next = neighbors.remove(neighbors.size() - 1);
            dfs(adj, next);
        }
        path.add(node);
    }
}
