import sys
sys.setrecursionlimit(300000)

n = int(sys.stdin.readline())
tree = [[] for _ in range(n + 1)]

for _ in range(n - 1):
    a, b = map(int, sys.stdin.readline().split())
    tree[a].append(b)
    tree[b].append(a)

subtree_size = [0] * (n + 1)
subtree_ans = [0] * (n + 1)
ans = [0] * (n + 1)

def dfs1(src, parent):
    num_nodes = 1
    ans_subtree = 0
    
    for child in tree[src]:
        if child == parent:
            continue
        dfs1(child, src)
        num_nodes += subtree_size[child]
        ans_subtree += subtree_size[child] + subtree_ans[child]
    
    subtree_size[src] = num_nodes
    subtree_ans[src] = ans_subtree

def dfs2(src, parent, parent_ans):
    ans[src] = subtree_ans[src] + (parent_ans + (n - subtree_size[src]))
    
    for child in tree[src]:
        if child == parent:
            continue
        
        new_parent_ans = ans[src] - (subtree_ans[child] + subtree_size[child])
        
        dfs2(child, src, new_parent_ans)

dfs1(1, 0)
dfs2(1, 0, 0)

print(*ans[1:])