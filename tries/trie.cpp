#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char ch;
    bool isend;
    TrieNode *children[26];
    TrieNode(char val)
    {
        ch = val;
        isend = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class Trie
{
public:
    TrieNode *head;
    Trie()
    {
        head = new TrieNode('\0');
    }
    void insertUtil(string word, TrieNode *head)
    {
        for (auto ch : word)
        {
            int index = ch - 'a';
            if (head->children[index] == NULL)
            {
                TrieNode *child = new TrieNode(ch);
                head->children[index] = child;
            }
            head = head->children[index];
        }
        head->isend = true;
    }
    void insert(string word)
    {
        insertUtil(word, head);
    }

    void searchUtil(string word, TrieNode *head)
    {
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            int index = ch - 'a';
            if (head->children[index] == NULL)
            {
                cout << "The given word is not present in the tree." << endl;
                return;
            }
            else
            {
                head = head->children[index];
            }
        }
        if (head->isend == false)
        {
            cout << "The  given word is not ended in the tree." << endl;
            return;
        }
        cout << "The given word is present in the tree." << endl;
    }
    void search(string word)
    {
        searchUtil(word, head);
    }

    void deleteUtil(string word, TrieNode *head)
    {
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            int index = ch - 'a';
            if (head->children[index] == NULL)
            {
                cout << "The word is not present to delete" << endl;
                return;
            }
            head = head->children[index];
        }
        if (head->isend == false)
        {
            cout << "word is present but it is not end. So cant be deleted" << endl;
            return;
        }
        head->isend = false;
        cout << "word is deleted" << endl;
    }
    void deleteWord(string word)
    {
        deleteUtil(word, head);
    }

    bool permanentDeleteUtil(string word, TrieNode *head, int index)
    {
        if (index == word.length())
        {
            if (head->isend == false)
            {
                cout << "word is found but not the end" << endl;
                return false;
            }
            head->isend = true;
            return true;
        }

        char ch = word[index];
        int chIndex = ch - 'a';

        if (head->children[chIndex] == NULL)
        {
            cout << "word not exist" << endl;
            return false; // Word not found
        }

        bool canDelete = permanentDeleteUtil(word, head->children[chIndex], index + 1);
        if (canDelete)
        {
            delete head->children[chIndex];
            head->children[chIndex] = NULL;
            bool hasChildren = false;
            for (int i = 0; i < 26; i++)
            {
                if (head->children[i] != NULL)
                {
                    hasChildren = true;
                    break;
                }
            }

            if (!hasChildren && !head->isend)
            {
                return true; // Safe to delete this node
            }
        }
        return false;
    }
    void permanentDelete(string word)
    {
        permanentDeleteUtil(word, head, 0);
    }
};

int main()
{
    Trie *trie = new Trie();
    trie->insert("amazon");
    trie->insert("leetcode");
    trie->insert("devuda");
    trie->insert("when");
    trie->insert("i");
    trie->insert("will");
    trie->insert("place");

    trie->search("amazon");
    trie->search("leet");
    trie->search("devuda");
    trie->search("sa");

    trie->deleteWord("leetcode");

    trie->search("leet");

    trie->permanentDelete("amazon");
    trie->search("amazon");
}