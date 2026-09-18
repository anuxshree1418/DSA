#include <iostream>
#include <queue>
using namespace std;
typedef class Node
{
public:
    int data;
    Node *left = nullptr, *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
} node;

class BST
{
    node *root = nullptr;
    void insertnode(node *&root, int data)
    {
        if (!root)
            root = new node(data);
        else if (data < root->data)
            insertnode(root->left, data);
        else
            insertnode(root->right, data);
    }

    bool searching(node *root, int data)
    {
        if (!root)
            return false;
        if (root->data == data)
            return true;
        else if (root->data > data)
            return searching(root->left, data);
        else
            return searching(root->right, data);
    }

    void BFS(Node *ptr)
    {
        if (root == nullptr) // if (!root)
            return;

        queue<Node *> q;

        q.push(root);

        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
    }

    void preOrder(Node *ptr) // ROOT - LEFT - RIGHT
    {
        if (!ptr)
            return;
        cout << ptr->data << " ";
        preOrder(ptr->left);
        preOrder(ptr->right);
    }

    void inOrder(Node *ptr) // LEFT - ROOT - RIGHT
    {
        if (!ptr)
            return;
        inOrder(ptr->left);
        cout << ptr->data << " ";
        inOrder(ptr->right);
    }

    void postOrder(Node *ptr) // LEFT - RIGHT - ROOT
    {
        if (!ptr)
            return;
        postOrder(ptr->left);
        postOrder(ptr->right);
        cout << ptr->data << " ";
    }
    int TreeHeight(Node *root)
    {
        if (root == nullptr)
            return -1; // Height of an empty tree is -1

        int leftHeight = TreeHeight(root->left);
        int rightHeight = TreeHeight(root->right);

        return max(leftHeight, rightHeight) + 1;
    }

public:
    void BFST()
    {
        BFS(root);
        cout << endl;
    }
    void insert(int data)
    {
        insertnode(root, data);
    }
    bool search(int data)
    {
        return searching(root, data);
    }
    void preOrderT()
    {
        preOrder(root);
        cout << endl;
    }
    void inOrderT()
    {
        inOrder(root);
        cout << endl;
    }
    void postOrderT()
    {
        postOrder(root);
        cout << endl;
    }
    int height()
    {
        return TreeHeight(root);
    }
};
using namespace std;
int main()
{
    BST b1;
    b1.insert(10);
    b1.insert(5);
    b1.insert(15);
    b1.insert(3);
    b1.insert(7);
    b1.insert(12);
    b1.insert(17);

    cout << "preorder --" << endl;
    b1.preOrderT();
    cout << "inorder --" << endl;
    b1.inOrderT();
    cout << "postorder --" << endl;
    b1.postOrderT();
    cout << "BFS--" << endl;
    b1.BFST();
    cout << "searching for 7--" << endl;
    cout << b1.search(7) << endl; // 1 means element is present and 0 means element is absent
    cout << "Height is--: " << b1.height() << endl;

    return 0;
}