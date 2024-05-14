from typing import List
import itertools

class Solution:
    def findPermutation(self, nums: List[int]) -> List[int]:
        n = len(nums)
        min_cost = float('inf')
        best_permutation = []

        # Usar um helper para recursivamente tentar todas as permutações possíveis
        def dfs(perm, used, current_cost):
            nonlocal min_cost, best_permutation
            if len(perm) == n:
                # Checa o custo de voltar ao início para completar o ciclo
                final_cost = current_cost + abs(perm[-1] - nums[perm[0]])
                if final_cost < min_cost:
                    min_cost = final_cost
                    best_permutation = perm[:]
                return

            for i in range(n):
                if not used[i]:
                    # Se adicionar este i piora o custo além do mínimo encontrado, pule
                    if len(perm) > 0:
                        next_cost = current_cost + abs(perm[-1] - nums[i])
                        if next_cost < min_cost:
                            used[i] = True
                            dfs(perm + [i], used, next_cost)
                            used[i] = False
                    else:
                        used[i] = True
                        dfs([i], used, 0)
                        used[i] = False

        # Iniciar DFS para todas as posições possíveis
        dfs([], [False] * n, 0)

        return best_permutation