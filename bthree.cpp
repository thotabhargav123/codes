
//!!! BINARY TREES!!!

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left; //*SETING VARIABLES
    Node *right;
    Node(int val)
    { //?-----> CONSTRUCTOR
        data = val;
        left = NULL; //*SETING VARIABLES VALUES
        right = NULL;
    }
};
void preorder(Node *root)
{
    if (root == NULL)
    {
        return; //! Pre order
    }
    cout << root->data << "-->";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{ //! Post order
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " -->";
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    } //! In order
    inorder(root->left);
    cout << root->data << "-->";
    inorder(root->right);
}

int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++) //* Search is used for build tree
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}
Node *buildpretree(int inorder[], int preorder[], int start, int end)
{
    static int idx = 0;

    if (start > end)
    {
        return NULL;
    } //* PREORDERBUILDTREE {USING PRE ORDER TREE BUILDING}
    int curr = preorder[idx];
    idx++;
    Node *node = new Node(curr);
    if (start == end)
    {
        return node;
    }
    int pos = search(inorder, start, end, curr);
    node->left = buildpretree(inorder, preorder, start, pos - 1);
    node->right = buildpretree(inorder, preorder, pos + 1, end);
    return node;
}

void PrintInorderTree(Node *root)
{
    if (root == NULL)
    {
        return;
    } //*PRINT ELEMENTS IN-ORDER FOR PREORDER & POST-ORDER TREES
    PrintInorderTree(root->left);
    cout << root->data << " -->";
    PrintInorderTree(root->right);
}

Node *buildpostorder(int inorder[], int postorder[], int start, int end)
{
    static int idx = end;
    if (start > end)
    {
        return NULL;
    }
    int curr = postorder[idx];
    idx--;
    Node *node = new Node(curr); //* PostORDERBUILDTREE {USING POST ORDER TREE BUILDING}
    if (start == end)
    {
        return node;
    }
    int pos = search(inorder, start, end, curr);
    node->right = buildpostorder(inorder, postorder, pos + 1, end);
    node->left = buildpostorder(inorder, postorder, start, pos - 1);
    return node;
}

void levelorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    int levl = 0;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    { //*PRINTING BY LEVEL-ORDER
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        // else if (!q.empty())
        // {
        //     cout << endl;
        //     q.push(NULL);
        //     cout << "LEVEL " << levl << " ENDED" << endl;
        //     levl++;
        // }
    }
}

int Sumatlevelk(Node *root, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    int level = 0;
    int sum = 0;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    { //*FINDING SUM AT EACH LEVEL USING LEVEL-ORDER
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            if (level == k)
            {
                sum = sum + node->data;
            }
            // cout << node->data << " ";
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
            // cout << "LEVEL " << level << " ENDED" << endl;
            level++;
        }
    }
    return sum;
}
int Countnodes(Node *root)
{
    if (root == NULL)
    {
        return 0; //*COUNT OF TOTAL NODES
    }
    return Countnodes(root->left) + Countnodes(root->right) + 1;
}
int Sumnodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    } //* SUM OF ALL NODES
    return Sumnodes(root->left) + Sumnodes(root->right) + root->data;
}
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    } //*HEIGHT OF BINART TREE
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}
int diameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    int curr = lh + rh + 1; //*DIAMETER OF BINARY TREE
    int ld = diameter(root->left);
    int rd = diameter(root->right);
    return max(curr, max(ld, rd));
}
void replacebysum(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    replacebysum(root->left);
    replacebysum(root->right);
    if (root->left != NULL)
    { //*REPLACE BY THE SUM OF ITS CHILDREN AND IT'S VALUES
        root->data = root->data + root->left->data;
    }
    if (root->right != NULL)
    {
        root->data = root->data + root->right->data;
    }
}
bool isbalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (isbalanced(root->left) == false)
    {
        return false;
    }
    if (isbalanced(root->right) == false)
    {
        return false;
    } //*CHECKING WHETYER TREE IS BALANCEED OR NOT
      //*A TREE IS SIAD TO BE BALANCED WHEN ABSOLUTE DIFF BETWEEN AND LEFT SUB TREE AND RIGHT SUBTREE OF ANY ROOT IS LESSTHAN OR EQUAL TO 1
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void righttree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!(q.empty()))
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front(); //*RIGHT SIDE VIEW OF TREE ALL ELKEMENTS NEXT TO RIGHTSIDE ARE NOT VISIBLE
            q.pop();
            if (i == n - 1)
            {
                cout << curr->data << " ";
            }
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}
void lefttree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!(q.empty()))
    
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop(); //*ALL ELEMENTS NEXT TO LEFT SID ENODES ARE NOT VISIBLE
            if (i == 0)
            {
                cout << curr->data << " ";
            }
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}
void flatten(Node *root)
{
    if (root == NULL || (root->left == NULL and root->right == NULL))
    {
        return;
    }
    if (root->left != NULL)
    {
        flatten(root->left);
        Node *temp = root->right;
        root->right = root->left;
        root->left = NULL;
        Node *t = root->right;
        while (t->right != NULL)
        {
            t = t->right;
        }
        t->right = temp;
    }
    flatten(root->right);
}
int getpath(Node *root, int n, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }
    path.push_back(root->data);
    if (root->data == n)
    {
        return true;
    }
    if (getpath(root->left, n, path) or getpath(root->right, n, path))
    {
        return true;
    }
    path.pop_back();
    return false;
}
int LCA(Node *root, int n1, int n2)
{
    vector<int> path1, path2;
    if (!getpath(root, n1, path1) or !getpath(root, n2, path2))
    {
        return -1;
    }
    int pc;
    for (pc = 0; pc < path1.size() and path2.size(); pc++)
    {
        if (path1[pc] != path2[pc])
        {
            break;
        }
    }
    return path1[pc - 1];
}
int maxathuntil(Node *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = maxathuntil(root->left, ans);

    int right = maxathuntil(root->right, ans);
    int nodemax = max(max(root->data, root->data + left + right), max(root->data + left, root->data + right));
    ans = max(ans, nodemax);
    int spsum = max(root->data, max(root->data + left, root->data + right));
    return spsum;
}
int maxpathsum(Node *root)
{
    int ans = INT_MIN;
    maxathuntil(root, ans);
    return ans;
}
Node *LCA2(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 or root->data == n2)
    {
        return root;
    }
    Node *Leftlca = LCA2(root->left, n1, n2);
    Node *Rightlca = LCA2(root->right, n1, n2);
    if (Leftlca != NULL)
    {
        return Leftlca;
    }
    return Rightlca;
}
static Node *lca3 = NULL;
bool LCA3(Node *root, int n1, int n2)
{
    if (root == NULL)
        return false;
    bool self = (root->data == n1 || root->data == n2);
    bool left = LCA3(root->left, n1, n2);
    if (lca3 != NULL)
    {
        return true;
    }
    bool right = LCA3(root->right, n1, n2);
    if (lca3 != NULL)
    {
        return true;
    }
    if ((right and left) or (self and left) or (self and right))
    {
        lca3 = root;
    }
    return self || left || right;
}
Node *lcasender(Node *root, int n1, int n2)
{
    LCA3(root, n1, n2);
    return lca3;
}
int main()
{
    Node *root = new Node(1);         //     1//
    root->left = new Node(2);         //  /   \  //
    root->right = new Node(3);        // 2     3  //
    root->right->left = new Node(4);  //  /\      /\  //
    root->right->right = new Node(5); // 7  6    4  5   //
    root->left->right = new Node(6);
    root->left->left = new Node(7);

    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    levelorder(root);
    cout << endl;
    cout << Sumatlevelk(root, 1);
    cout << endl;
    cout << "The total no of nodes is " << Countnodes(root) << endl;
    cout << "The sum of the nodes is " << Sumnodes(root) << endl;
    cout << "The height is" << height(root) << endl;
    cout << "the diameter is" << diameter(root) << endl;
    // replacebysum(root);
    // preorder(root);
    // cout<<endl;
    if (isbalanced(root) == true)
    {
        cout << "BALANCED" << endl;
    }
    else
    {
        cout << "UN-BALANCED" << endl;
    }
    cout << "THE RIGHT view is ";
    righttree(root);
    cout << endl;
    cout << "THE LEFT view is ";
    lefttree(root);
    cout << endl;
    int a = 7;
    int b = 5;
    int lca = LCA(root, a, b);
    if (lca == -1)
    {
        cout << "NO LCA EXIST" << endl;
    }
    else
    {
        cout << "LCA IS " << lca << endl;
    }
    Node *lca2 = LCA2(root, a, b);
    if (lca2 == NULL)
    {
        cout << "NO LCA EXIST" << endl;
    }
    else
    {
        cout << "LCA IS " << lca << endl;
    }
    Node *lca33 = lcasender(root, a, b);
    cout << lca33->data << endl;
    // int n;
    // cout<<"Enter input"<<endl;
    // cin >> n;
    // int inorder[n];                    //!CODE SNIP FOR BUILDING PREORDER
    // int preorder[n];
    // for(int i=0; i<n; i++){
    //     cin >> inorder[i];
    // }
    // for(int i=0; i<n; i++){
    //     cin >> preorder[i];
    // }
    // Node *root2 = buildpretree(inorder, preorder, 0, n-1);
    // PrintInorderTree(root2);
    // cout << "Enter the size";
    // int n;
    // cin >> n;
    // int inorder[n];
    // int postorder[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> inorder[i];               //!CODE SNIP FOR BUILDING POSTORDER
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> postorder[i];
    // }
    // Node *root3 = buildpostorder(inorder, postorder, 0, n - 1);
    // PrintInorderTree(root3);
}