#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void helperInorder(TreeNode* root, vector<int> &result) {
    if (root != nullptr) {
        helperInorder(root->left, result);
        result.push_back(root->val);
        helperInorder(root->right, result);
    }
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    helperInorder(root, result);

    /*
    for (auto& a : result) {
        cout << a << endl;
    }
    */

    return result;
}

int main()
{
    TreeNode p3(3, nullptr, nullptr);
    TreeNode p2(2, &p3, nullptr);
    TreeNode p1(1, nullptr, &p2);

    vector<int> iv = inorderTraversal(&p1);

    for (auto& i : iv) {
        cout << i << endl;
    }

    return 0;
}