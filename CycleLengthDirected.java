//Maximum length of cycle in a directed graph
//You can use DFS to detect cycles and compute their lengths.

public class CycleLengthDirected {
    static int minCycle = Integer.MAX_VALUE;

    public static void main(String[] args) {
        int V = 4;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());
        adj.get(0).add(1);
        adj.get(1).add(2);
        adj.get(2).add(0); // cycle: 0 → 1 → 2 → 0
        adj.get(2).add(3);

        boolean[] visited = new boolean[V];
        int[] depth = new int[V];

        for (int i = 0; i < V; i++) {
            Arrays.fill(visited, false);
            dfs(i, i, 0, visited, adj, depth);
        }

        System.out.println(minCycle == Integer.MAX_VALUE ? "No cycle" : "Cycle length: " + minCycle);
    }

    static void dfs(int start, int u, int d, boolean[] visited, List<List<Integer>> adj, int[] depth) {
        visited[u] = true;
        depth[u] = d;

        for (int v : adj.get(u)) {
            if (!visited[v]) {
                dfs(start, v, d + 1, visited, adj, depth);
            } else if (v == start) {
                // cycle found
                minCycle = Math.min(minCycle, d + 1);
            }
        }

        visited[u] = false; // backtrack
    }
}