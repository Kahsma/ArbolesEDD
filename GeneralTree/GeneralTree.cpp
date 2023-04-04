#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int val;
    vector<TreeNode*> children;

    TreeNode(int _val) : val(_val) {}

    void addChild(TreeNode* child) {
        children.push_back(child);
    }
};

class Tree {
public:
    TreeNode* root;

    Tree(TreeNode* _root) : root(_root) {}

    void preorderTraversal(TreeNode* node) {
        if (!node) return;

        cout << node->val << " ";

        for (TreeNode* child : node->children) {
            preorderTraversal(child);
        }
    }

    void postorderTraversal(TreeNode* node) {
        if (!node) return;

        for (TreeNode* child : node->children) {
            postorderTraversal(child);
        }

        cout << node->val << " ";
    }

    void levelOrderTraversal(TreeNode* root) {
        if (!root) return;

        vector<TreeNode*> level{root};

        while (!level.empty()) {
            vector<TreeNode*> nextLevel;

            for (TreeNode* node : level) {
                cout << node->val << " ";

                for (TreeNode* child : node->children) {
                    nextLevel.push_back(child);
                }
            }

            level = nextLevel;
        }
    }
};

int main() {
    TreeNode* root = new TreeNode(1);

    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);

    root->addChild(node2);
    root->addChild(node3);

    node2->addChild(node4);
    node2->addChild(node5);

    node3->addChild(node6);

    Tree* tree = new Tree(root);

    cout << "Preorder Traversal: ";
    tree->preorderTraversal(tree->root);
    cout << endl;

    cout << "Postorder Traversal: ";
    tree->postorderTraversal(tree->root);
    cout << endl;

    cout << "Level Order Traversal: ";
    tree->levelOrderTraversal(tree->root);
    cout << endl;

    return 0;
}