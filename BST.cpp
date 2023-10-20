#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node *insertBSt(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }//^ Insertion by normal recurrsive mtd
    if (root->data == val)
    {
        return NULL;
    }
    if (val < root->data)
    {
        root->left = insertBSt(root->left, val);
    }
    else
    {
        root->right = insertBSt(root->right, val);
    }
    return root;
}
Node *insertBSTBY_itreative(Node *root, int val)
{
    Node *node = new Node(val);
    Node *prev = NULL;
    Node *curr = root;
    while (curr != NULL)
    {
        prev = curr;
        if (val == curr->data)
        {
            //^ cout << "Given Value is already present"<<endl;
            return NULL;
        }
        if (val < curr->data)
        {            //^ Insertion by normal itreative mtd
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }

    if (prev == NULL)
    {
        prev = node;
    }
    else if (val < prev->data)
    {
        prev->left = node;
    }
    else
    {
        prev->right = node;
    }
    return prev;
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;  //^ Printing tree inorder way
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void search(Node *root, int val)
{
    if (root == NULL)
    {
        cout << "No Value Found" << endl;
        return;
    }
    if (root->data == val)
    {
        cout << "Value Found" << endl;   //^Search Element in BST
        return;
    }
    if (val < root->data)
    {
        search(root->left, val);
    }
    else
    {
        search(root->right, val);
    }
}
Node *searchbynode(Node *root, int val)
{ //! different mtd of search
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == val)
    {
        return root;
    }
    if (val < root->data)
    {
        return searchbynode(root->left, val);
    }
    else
    {
        return searchbynode(root->right, val);
    }
}
Node *inordersucc(Node *root)
{
    Node *curr = root;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;  //^ It is a helping function for deletion it will find succesor element to replace curr element after deletion
    }
    return curr;
}
Node *deleter(Node *root, int val)
{
    if (val < root->data)
    {
        root->left = deleter(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deleter(root->right, val);
    }
    else
    {            //^ The deletion function 3 types of deletion i) deletion at leeafs (no problem)
        if (root->left == NULL)                            //^ ii) deletion of parent nodes having one child (replace it by it's child in inorder succesor way)
                                                        //^    iii) deletion of parent node having two child nodes and big subtree is to done by replacing inorder succ or precessor.


                //! We are Using inorder succesor we can use precessor also
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = inordersucc(root->right);
        root->data = temp->data;
        root->right = deleter(root->right, temp->data);
    }
    return root;
}
Node *ConstructBST(int preorder[], int *preorderidx, int key, int mi, int ma, int n)
{
    Node *root = NULL;
    if (*preorderidx >= n)
    {
        return NULL;
    }
    if (key > mi and key < ma)
    {                    //^ Construct BST using preorder array
        root = new Node(key);
        *preorderidx = *preorderidx + 1;
        if (*preorderidx < n)
        {
            root->left = ConstructBST(preorder, preorderidx, preorder[*preorderidx], mi, key, n);
        }
        if (*preorderidx < n)
        {
            root->right = ConstructBST(preorder, preorderidx, preorder[*preorderidx], key, ma, n);
        }
    }
    return root;
}
void Printpreorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    Printpreorder(root->left);
    Printpreorder(root->right);
}
bool isBST(Node *root, Node *min, Node *max)
{
    if (root == NULL)
    {
        return true;
    }
    if (min != NULL and root >= min)
    {
        return false;
    }
    if (max != NULL and root <= max)
    {
        return false;
    }
    bool leftvalid = isBST(root->left, min, root);
    bool rightvalid = isBST(root->right, root, max);
    return leftvalid && rightvalid;
}
Node *sortedarraytoBST(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;      //^ construct BST using sorted array process same as binary search
    }
    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);
    root->left = sortedarraytoBST(arr, start, mid - 1);
    root->right = sortedarraytoBST(arr, mid + 1, end);
    return root;
}
vector<Node *> catalantress(int start, int end)
{

    vector<Node *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }
    for (int i = start; i <= end; i++)
    {
        vector<Node *> leftsubtress = catalantress(start, i - 1);
        vector<Node *> rightsubtress = catalantress(i + 1, end);
        for (int j = 0; j < leftsubtress.size(); j++)
        {
            Node *left = leftsubtress[j];
            for (int k = 0; k < rightsubtress.size(); k++)
            {
                Node *right = rightsubtress[k];
                Node *node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}
void zigzag(Node *root)
{
    if(root == NULL){
        return;
    }
    stack<Node *> currLevel;
    stack<Node *> nextLevel;
    bool lefttoright = true;
    currLevel.push(root); //^ printing levels in zigzag way (L1 r_to_l <L2 l_to_r so on..);
    while (!currLevel.empty())
    {
        Node *temp = currLevel.top();
        currLevel.pop();
        if (temp != NULL)
        {
            cout << temp->data << " ";

            if (lefttoright == true)
            {
                if (temp->left != NULL)
                {
                    nextLevel.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    nextLevel.push(temp->right);
                }
            }
            else
            {
                if (temp->right != NULL)
                {
                    nextLevel.push(temp->right);
                }
                if (temp->left != NULL)
                {
                    nextLevel.push(temp->left);
                }
            }
        }
        if(currLevel.empty()){
            lefttoright = !lefttoright;
            swap(currLevel, nextLevel);
        }
    }
}
bool identical(Node*root1, Node*root2){
    if(root1==NULL and root2==NULL){
        return true;
    }
    else if(root1==NULL || root2==NULL){
        return false;
    }
    else{
        bool con1=root1->data==root2->data;
        bool con2 = identical(root1->left, root2->left);
        bool con3 = identical(root1->right, root2->right);
        if(con1 && con2 && con3){
            return true;
        }
        return false;
    }
}
 struct info{
       int size;
       int mi;
       int ma;
       int ans;
       bool isbst;
  };
info largestBST(Node*root){
    if(root==NULL){
        return {0, INT_MAX, INT_MIN, 0, true};
    }
    if(root->left==NULL and root->right== NULL){
        return {1, root->data, root->data, 1, true};
    }
    info left=largestBST(root->left);
    info right=largestBST(root->right);
    info curr;
    curr.size = 1 + left.size + right.size;
    if(left.isbst && right.isbst && left.ma<root->data && right.mi>root->data){
        curr.mi = min(left.mi, min(right.mi, root->data));
        curr.ma = max(left.ma, max(right.ma, root->data));
        curr.ans = curr.size;
        curr.isbst=true;
        return curr;
    }
    curr.ans=max(left.ans ,right.ans);
    curr.isbst=false;
    return curr;
}
int main()
{
    Node *root = NULL;
    int n;
    cout << "Enter no of nodes to insert" << endl;
    cin >> n;
    // for (int i = 0; i < n;i++){
    //     int val;
    //     cin>>val;
    //     if(root==NULL){
    //         cout<<"box1"<<endl;  //* Using recurrsion
    //         root=insertBSt(root,val);
    //     }
    //     else{
    //         cout<<"box2"<<endl;
    //         Node*returnvalue=insertBSt(root, val);
    //          if(returnvalue==NULL){
    //         cout<<"value already present"<<endl;
    //       }
    //     }

    // }
    // for (int i = 0; i < n; i++)
    // {
    //     int val;
    //     cin >> val;
    //     if (root == NULL)
    //     {
    //         cout << "box1" << endl;
    //         root = insertBSTBY_itreative(root, val);
    //     }       //*using itreation
    //     else
    //     {
    //         cout << "box2" << endl;
    //         Node *returnvalue = insertBSTBY_itreative(root, val);
    //         if (returnvalue == NULL)
    //         {
    //             cout << "value already present" << endl;
    //         }
    //     }
    // }
    root = insertBSt(root, 5);
    insertBSt(root, 7);
    insertBSt(root, 1);
    insertBSt(root, 2);
    insertBSt(root, 10);
    insertBSt(root, 8);
    insertBSt(root, 4);
    insertBSt(root, 3);
    insertBSt(root, 9);
    inorder(root);
    cout << endl;
    search(root, 9);
    search(root, 15);
    Node *searchresult = searchbynode(root, 15); // searchbynode(root, 9);
    if (searchresult == NULL)
    {
        cout << "Value not found" << endl;
    }
    else
    {
        cout << "found" << endl;
    }
    cout << "Before deletion :";
    inorder(root);
    cout << endl;
    deleter(root, 5);
    cout << "after deletion :";
    inorder(root);
    cout << endl;
    int preorder[] = {10, 2, 1, 13, 11};
    int no = 5;
    int preorderidx = 0;
    Node *root1 = ConstructBST(preorder, &preorderidx, preorder[0], INT_MIN, INT_MAX, no);
    cout << "The Binary search Tree is constructed " << endl;
    Printpreorder(root1);
    cout << endl;
    if (isBST(root1, NULL, NULL))
    {
        cout << "isBST" << endl;
    }
    else
    {
        cout << "Not BST" << endl;
    }
    int arr[] = {0, 1, 2, 3, 4, 5, 6};
    Node *root2 = sortedarraytoBST(arr, 0, 6);
    Printpreorder(root2);
    cout << endl;
    inorder(root2);
    cout << endl;
    vector<Node *> totaltrees = catalantress(1, 3);
    for (int i = 0; i < totaltrees.size(); i++)
    {
        cout << i + 1 << ":";
        Printpreorder(totaltrees[i]);
        cout << endl;
    }
    zigzag(root);
}