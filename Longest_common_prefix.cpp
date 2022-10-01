
// Approach 1:
// T complexity: O(m*n)
// S compleity: O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         int n = strs.size();
        string ans = "";
        
        // for traversing all characters of first string
        for(int i=0;i<strs[0].length();i++){
            char ch = strs[0][i];
            
            bool match = true;
            
            // for comparing ch with rest of the strings
            for(int j=1;j<n;j++){
                
                // not match
                if(strs[j].size() < i || strs[j][i]!=ch){
                    match = false;
                    break;
                }
            }
            
            if(match){
                ans.push_back(ch);
            }
            else{
                break;
            }
        }
        return ans;
    }
};

// Approach 2:
// Using trie

// T complexity: O(m*n)
// S complexity: O(m*n)

class TrieNode{
    public: 
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie{
    public:
    
    TrieNode* root;
    
    Trie(char ch){
        root = new TrieNode(ch);
    }
    
    void insertUtil(TrieNode* root, string word){
        // base case
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }

        // assumption, word will be in CAPS
        int index = word[0] - 'a';
        TrieNode* child;

        // Present
        if(root->children[index] !=NULL){
            child = root->children[index];
        }
        else{
            // absent
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        // recursion
        insertUtil(child,word.substr(1));
    }


    void insertWord(string word){
        insertUtil(root,word);
    }
    
    void lcp(string str,string &ans){
        
        for(int i=0;i<str.length();i++){
            char ch = str[i];
            
            if(root->childCount==1){
                ans.push_back(ch);
                
                // age badh jao
                int index = ch - 'a';
                root = root->children[index];
            }
            else{
                break;
            }
            
            if(root->isTerminal){
                break;
            }
        }
        
    }
    
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        
        Trie* t = new Trie('\0');
        
        int n = strs.size();
        
        for(int i=0;i<n;i++){
            if(strs[i] == ""){
                string s = "";
                return s;
            }
        }
        
        for(int i=0;i<n;i++){
            t->insertWord(strs[i]);
        }
        
        string first = strs[0];
        
        string ans = "";
        
        t->lcp(first,ans);
        
        return ans;
        
    }
};
