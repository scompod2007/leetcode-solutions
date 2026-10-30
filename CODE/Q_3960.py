from heapq import heappush, heappop
from math import inf
from typing import List

class Solution:
    def shortestPath(self, n: int, edges: List[List[int]], labels: str, k: int) -> int:
        # Build adjacency list: graph[u] = [(v, weight)]
        graph = [[] for _ in range(n)]
        for u, v, w in edges:
            graph[u].append((v, w))
            
        # dist[u][cur] tracks the min distance to reach node `u` 
        # with a current consecutive run length of `cur`
        dist = [[inf] * (k + 1) for _ in range(n)]
        
        # Start at node 0. The initial label counts as a run of length 1.
        dist[0][1] = 0
        
        # Min-Heap stores elements as: (distance, current_node, current_run_length)
        pq = [(0, 0, 1)]
        
        while pq:
            d, u, cur = heappop(pq)
            
            # Since it's a min-heap, the first time we pop the destination node, 
            # we are guaranteed to have found the shortest valid path.
            if u == n - 1:
                return d
                
            # If we found a shorter path to this state already, skip processing
            if d > dist[u][cur]:
                continue
                
            # Explore neighbors
            for v, w in graph[u]:
                # If characters match, increment consecutive count; otherwise, reset to 1
                nxt_count = cur + 1 if labels[v] == labels[u] else 1
                
                # Check if the new state violates the constraint
                if nxt_count <= k:
                    nxt_dist = d + w
                    # Relaxation step
                    if nxt_dist < dist[v][nxt_count]:
                        dist[v][nxt_count] = nxt_dist
                        heappush(pq, (nxt_dist, v, nxt_count))
                        
        return -1
