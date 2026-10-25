class Node:

    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


def buildTree(value):
    if not value or value[0] < 0:
        return None

    root = Node(value[0])
    queue = [root]
    i = 1
    front = 0

    while front < len(queue) and i < len(value):
        curr = queue[front]
        front += 1

        if i < len(value):
            if value[i] >= 0:
                curr.left = Node(value[i])
                queue.append(curr.left)
            i += 1

        if i < len(value):
            if value[i] >= 0:
                curr.right = Node(value[i])
                queue.append(curr.right)
            i += 1

    return root

def MaxBstSum(root):

    maxSum = 0

    def solve(node):
        nonlocal maxSum

        if node is None:
            return True, 0, float('inf'), float('-inf')

        Lb, Ls, Lmin, Lmax = solve(node.left)
        Rb, Rs, Rmin, Rmax = solve(node.right)

        if Lb and Rb and Lmax < node.val < Rmin:
            total_sum = Ls + Rs + node.val
            maxSum = max(maxSum, total_sum)
            return True, total_sum, min(Lmin, node.val), max(Rmax, node.val)

        return False, max(Ls, Rs), 0, 0

    solve(root)

    return maxSum

def main():
    values = list(map(int, input().split()))
    root = buildTree(values)
    print(MaxBstSum(root))


main()