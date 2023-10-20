// #include <bits/stdc++.h>
// using namespace std;
// /*
//     Time Complexity : O(N*W) (insert - O(W), search - O(W), startsWith - O(W))
//     Where N is the number of queries and W is the average length of words.

//     Space Complexity : O(N*W)
//     Where N is the number of words inserted and W is the average length of words.
// */

// class Trie {
// public:
//     Trie * child[26];
//     bool isEnd;
//     Trie()
//     {
//         isEnd=false;
//         for(int i=0;i<26;i++)
//             child[i]=NULL;
//     }

// };

// class Trie {
// public:
//     /** Initialize your data structure here. */
//     Trie *root;
//     Trie() {
//         root= new Trie();
//     }

//     /** Inserts a word into the trie. */
//     void insert(string word) {
//         Trie *tem=root;
//         for(auto x:word)
//         {
//             if(!tem->child[x-'a'])
//                 tem->child[x-'a']= new Trie();
//             tem=tem->child[x-'a'];
//         }
//         tem->isEnd=true;
//     }

//     /** Returns if the word is in the trie. */
//     bool search(string word) {
//         Trie *tem=root;
//         for(auto x:word)
//         {
//             if(!tem->child[x-'a'])
//                 return false;
//             tem=tem->child[x-'a'];
//         }
//         return  tem->isEnd;
//     }

//     /** Returns if there is any word in the trie that starts with the given prefix. */
//     bool startsWith(string prefix) {
//         Trie *tem=root;
//         for(auto x:prefix)
//         {
//             if(!tem->child[x-'a'])
//                 return false;
//             tem=tem->child[x-'a'];
//         }
//         return  true;
//     }
// };
// int main()
// {
//     Trie *trie;
//     trie->insert("king");
//     trie->insert("queen");
//     trie->insert("jack");
//     trie->insert("ace");
//     trie->insert("hakiandryu");
//     if (trie->search("king") == true)
//     {
//         cout << "King is present in trie" << endl;
//     }
//     else
//     {
//         cout << "King is not present in trie" << endl;
//     }
//     if (trie->search("queen") == true)
//     {
//         cout << "Queen is present in trie" << endl;
//     }
//     else
//     {
//         cout << "Queen is not present in trie" << endl;
//     }
//     if (trie->search("monkey") == true)
//     {
//         cout << "MONKEY is present in trie" << endl;
//     }
//     else
//     {
//         cout << "MONKEY is not present in trie" << endl;
//     }

//     if (trie->startsWith("haki") == true)
//     {
//         cout << "Haki is present in trie" << endl;
//     }
//     else
//     {
//         cout << "Haki is not present in trie" << endl;
//     }
// }

// C++ implementation of search and insert
// operations on Trie
#include <bits/stdc++.h>
using namespace std;

// const int ALPHABET_SIZE = 26;

// trie node
class Trie
{
public:
    Trie *links[26];

    // isend is true if the node represents
    // end of a word
    bool isend;
};

// Returns new trie node (initialized to NULLs)
Trie *getNode(void)
{
    Trie *root = new Trie;

    root->isend = false;

    for (int i = 0; i < 26; i++)
        root->links[i] = NULL;

    return root;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert( Trie *root, string key)
{
     Trie *node = root;

    for (int i = 0; i < key.length(); i++)
    {
        int charvalue = key[i] - 'a';
        if (!node->links[charvalue])
            node->links[charvalue] = getNode();

        node = node->links[charvalue];
    }

    // mark last node as leaf
    node->isend = true;
}

// Returns true if key presents in trie, else
// false
bool search( Trie *root, string key)
{
     Trie *node = root;

    for (int i = 0; i < key.length(); i++)
    {
        int charvalue = key[i] - 'a';
        if (!node->links[charvalue])
            return false;

        node = node->links[charvalue];
    }

    return (node->isend);
}

// Driver
int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    string keys[] = {"the", "a", "there",
                     "answer", "any", "by",
                     "bye", "their"};
    int n = sizeof(keys) / sizeof(keys[0]);

     Trie *root = getNode();

    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);

    // Search for different keys
    search(root, "the") ? cout << "Yes\n" : cout << "No\n";
    search(root, "these") ? cout << "Yes\n" : cout << "No\n";
    search(root, "their") ? cout << "Yes\n" : cout << "No\n";
    search(root, "thaw") ? cout << "Yes\n" : cout << "No\n";
    return 0;
}
