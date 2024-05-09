#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// -----------------------------------------------Iterative----------------------------------------------------------
// bool isSymmetric(TreeNode* root) {
//     if (root == nullptr) {
//         return true;
//     }

//     queue<TreeNode*> nodesQueue;
//     nodesQueue.push(root->left);
//     nodesQueue.push(root->right);

//     while (!nodesQueue.empty()) {
//         TreeNode *leftNode = nodesQueue.front();
//         nodesQueue.pop();
//         TreeNode *rightNode = nodesQueue.front();
//         nodesQueue.pop();

//         if (leftNode == nullptr && rightNode == nullptr) {
//             continue;
//         }

//         if (leftNode == nullptr || rightNode == nullptr || leftNode->val != rightNode->val) {
//             return false;
//         }

//         nodesQueue.push(leftNode->left);
//         nodesQueue.push(rightNode->right);
//         nodesQueue.push(leftNode->right);
//         nodesQueue.push(rightNode->left);
//     }

//     return true;
// }


// -------------------------------------------Recurssive---------------------------------------------------//
bool isMirror(TreeNode *left, TreeNode *right)  {
    if (left == nullptr && right == nullptr)    {
        return true;
    }

    if (left == nullptr || right == nullptr || left->val != right->val)    {
        return false;
    }

    return isMirror(left->left, right->right) && isMirror(left->right, right->left);
}

bool isSymmetric(TreeNode *root)    {
    if (root == nullptr)    {
        return true;
    }

    return isMirror(root->left, root->right);
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    bool result = isSymmetric(root);
    cout << boolalpha << result << endl;

    return 0;
}
