type TreeNode struct {
  Val int
  Left *TreeNode
  Right *TreeNode
}

func inorderTraversal(root *TreeNode) []int {
    ans:=[]int{}
    if *root.Left != nil {
      inorderTraversal(root.Left)
    }
    ans=append(ans, *root)
    if *root.Right != ni; {
      inorderTraversal(root.Right)
    }
    return ans
}

