#include <iostream>
#include <queue>
using namespace std;

template <class T>
class AVLTree {
private:
    struct TreeNode {
        T data;
        TreeNode* left;
        TreeNode* right;
        int height;

        // Constructor
        TreeNode(T value) : data(value), left(nullptr), right(nullptr), height(1) {}
    };

    TreeNode* root;

    int heightHelper(TreeNode* node) {
        if (node == nullptr) return 0;
        return node->height;
    }


    int getBalance(TreeNode* node) {
        if (node == nullptr) return 0;
        return heightHelper(node->left) - heightHelper(node->right);
    }

    void updateHeight(TreeNode* node) {
        node->height = max(heightHelper(node->left), heightHelper(node->right)) + 1;
    }

    TreeNode* rotateLeft(TreeNode* node) {
        TreeNode* newParent = node->right;
        node->right = newParent->left;
        newParent->left = node;
        updateHeight(node);
        updateHeight(newParent);
        return newParent;
    }

    TreeNode* rotateRight(TreeNode* node) {
        TreeNode* newParent = node->left;
        node->left = newParent->right;
        newParent->right = node;
        updateHeight(node);
        updateHeight(newParent);
        return newParent;
    }

    TreeNode* balanceNode(TreeNode* node) {
        if (node->balanceFactor > 1) {
            // left-left case
            if (heightHelper(node->left->left) >= heightHelper(node->left->right)) {
                node = rotateRight(node);
            }
            // left-right case
            else {
                node->left = rotateLeft(node->left);
                node = rotateRight(node);
            }
        } else if (node->balanceFactor < -1) {
            // right-right case
            if (heightHelper(node->right->right) >= heightHelper(node->right->left)) {
                node = rotateLeft(node);
            }
            // right-left case
            else {
                node->right = rotateRight(node->right);
                node = rotateLeft(node);
            }
        }

        return node;
    }

    TreeNode* insertHelper(TreeNode* node, T value) {
        if (node == nullptr) return new TreeNode(value);
        if (value < node->data) {
            node->left = insertHelper(node->left, value);
        } else if (value > node->data) {
            node->right = insertHelper(node->right, value);
        } else {
            return node; // duplicate value
        }

        // update height and balance factor
        updateHeight(node);
        int bf = getBalance(node);

        // perform rotations if necessary
        if (bf > 1 && value < node->left->data) {
            // left left case
            return rotateRight(node);
        } else if (bf > 1 && value > node->left->data) {
            // left right case
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        } else if (bf < -1 && value > node->right->data) {
            // right right case
            return rotateLeft(node);
        } else if (bf < -1 && value < node->right->data) {
            // right left case
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

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
            // node with only one child or no child
            if (node->left == nullptr || node->right == nullptr) {
                TreeNode* temp = node->left ? node->left : node->right;
                // no child case
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                }
                // one child case
                else {
                    *node = *temp;
                    delete temp;
                }
            } 
            // node with two children
            else {
                TreeNode* temp = minValueNode(node->right);
                node->data = temp->data;
                node->right = deleteNodeHelper(node->right, temp->data);
            }
        }

        if (node == nullptr) {
            return node;
        }

        int balance = getBalance(node);

        // left left case
        if (balance > 1 && getBalance(node->left) >= 0) {
            return rotateRight(node);
        }
        // left right case
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        // right right case
        if (balance < -1 && getBalance(node->right) <= 0) {
            return rotateLeft(node);
        }
        // right left case
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }


    TreeNode* searchHelper(TreeNode* node, T value) {
        if (node == nullptr || node->data == value) return node;
        if (node->data > value) return searchHelper(node->left, value);
        else return searchHelper(node->right, value);
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

    void inorderTraversalHelper(TreeNode* node) {
        if (node == nullptr) return;
        inorderTraversalHelper(node->left);
        cout << node->data << " ";
        inorderTraversalHelper(node->right);
    }



    public:
    AVLTree() : root(nullptr) {}

    void insert(T value) {
        root = insertHelper(root, value);
    }

    void inorderTraversal() {
        inorderTraversalHelper(root);
    }

    void preorderTraversal() {
        preorderTraversalHelper(root);
    }

    void levelOrderTraversal() {
        levelOrderTraversalHelper();
    }

    int height() {
        return heightHelper(root);
    }

    int size() {
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
    AVLTree<int> tree;

    tree.insert(50);
    tree.insert(20);
    tree.insert(80);
    tree.insert(10);
    tree.insert(30);
    tree.insert(70);
    tree.insert(90);
    tree.insert(5);
    tree.insert(15);
    tree.insert(25);
    tree.insert(35);
    tree.insert(60);
    tree.insert(75);
    tree.insert(85);

    std::cout << "Inorder Traversal: ";
    tree.inorderTraversal();
    std::cout << std::endl;

    std::cout << "Preorder Traversal: ";
    tree.preorderTraversal();
    std::cout << std::endl;

    std::cout << "Level-order Traversal: ";
    tree.levelOrderTraversal();
    std::cout << std::endl;

    std::cout << "Height: " << tree.height() << std::endl;
    std::cout << "Size: " << tree.size() << std::endl;

    int value = 25;
    std::cout << "Deleting node with value " << value << std::endl;
    tree.deleteNode(value);

    std::cout << "Inorder Traversal: ";
    tree.inorderTraversal();
    std::cout << std::endl;

    std::cout << "Preorder Traversal: ";
    tree.preorderTraversal();
    std::cout << std::endl;

    std::cout << "Level-order Traversal: ";
    tree.levelOrderTraversal();
    std::cout << std::endl;

    std::cout << "Height: " << tree.height() << std::endl;
    std::cout << "Size: " << tree.size() << std::endl;

    return 0;
}


