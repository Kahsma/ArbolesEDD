#include <iostream>
#include <queue>
using namespace std;

template <class T>
class OrderedBinaryTree {
private:
    struct TreeNode {
        T data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    TreeNode* root;

    void inorderTraversalHelper(TreeNode* node) {
        if (node == nullptr) return;
        inorderTraversalHelper(node->left);
        cout << node->data << " ";
        inorderTraversalHelper(node->right);
    }

    int heightHelper(TreeNode* node) {
        if (node == nullptr) return -1;
        int leftHeight = heightHelper(node->left);
        int rightHeight = heightHelper(node->right);
        return max(leftHeight, rightHeight) + 1;
    }

    TreeNode* searchHelper(TreeNode* node, T value) {
        if (node == nullptr || node->data == value) return node;
        if (node->data > value) return searchHelper(node->left, value);
        else return searchHelper(node->right, value);
    }

    TreeNode* insertHelper(TreeNode* node, T value) {
        if (node == nullptr) return new TreeNode(value);
        if (node->data > value) node->left = insertHelper(node->left, value);
        else node->right = insertHelper(node->right, value);
        return node;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    TreeNode* deleteNodeHelper(TreeNode* node, T value) {
        if (node == nullptr) return node;
        if (value < node->data) node->left = deleteNodeHelper(node->left, value);
        else if (value > node->data) node->right = deleteNodeHelper(node->right, value);
        else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteNodeHelper(node->right, temp->data);
        }
        return node;
    }
    void preorderTraversalHelper(TreeNode* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorderTraversalHelper(node->left);
            preorderTraversalHelper(node->right);
        }
    }


    void levelOrderTraversalHelper() {
        if (root == nullptr) {
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            cout << curr->data << " ";

            if (curr->left != nullptr) {
                q.push(curr->left);
            }

            if (curr->right != nullptr) {
                q.push(curr->right);
            }
        }
    }

    int sizeHelper(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
    
        return 1 + sizeHelper(node->left) + sizeHelper(node->right);
    }




public:
    OrderedBinaryTree() : root(nullptr) {}

    void insert(T value) {
        root = insertHelper(root, value);
    }

    void inorderTraversal() {
        inorderTraversalHelper(root);
    }

    void preorderTraversal()  {
        preorderTraversalHelper(root);
    }
    void leverOrderTraversal(){
        levelOrderTraversalHelper();
    }


    int height() {
        return heightHelper(root);
    }

    int size(){
        return sizeHelper(root);
    }

    bool search(T value) {
        return (searchHelper(root, value) != nullptr);
    }

    void deleteNode(T value) {
        root = deleteNodeHelper(root, value);
    }


};

int main() {
    // Create an ordered binary tree of integers
    OrderedBinaryTree<int> tree;

    // Insert some values into the tree
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    // Print the inorder traversal of the tree
    cout << "Inorder Traversal: ";
    tree.inorderTraversal();
    cout << endl;

    cout << "Preorder Traversal: ";
    tree.preorderTraversal();
    cout << endl;

    cout << "Levelorder Traversal: ";
    tree.leverOrderTraversal();
    cout << endl;


    // Print the height of the tree
    cout << "Height: " << tree.height() << endl;
    cout << "Size: " << tree.size() << endl;

    // Search for some values in the tree
    cout << "Search 4: " << tree.search(4) << endl;
    cout << "Search 9: " << tree.search(9) << endl;

    // Delete some nodes from the tree
    tree.deleteNode(3);
    tree.deleteNode(7);

    // Print the inorder traversal of the tree again
    cout << "Inorder Traversal: ";
    tree.inorderTraversal();
    cout << endl;
    cout << "Size: " << tree.size() << endl;


    return 0;
}