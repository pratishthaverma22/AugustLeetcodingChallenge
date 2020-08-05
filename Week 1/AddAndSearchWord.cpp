/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
*/

class WordDictionary {
public:
  
    WordDictionary(){
      head= new TrieNode();
    }
  
    struct TrieNode{
      TrieNode* child[26];  
      string word;
      TrieNode(){
          for(auto &x : child)x=NULL;
          word.clear();
      }
    };

    TrieNode * head;

    // Adds a word into the data structure.
    void addWord(string w) {
        TrieNode *tmp = head;
        for(uint32_t i= 0; i<w.size(); i++){
            int pos = w[i] - 'a';
            //cout<<w[i]<<endl;
            if(tmp->child[pos] == NULL) tmp->child[pos] = new TrieNode();
            tmp = tmp->child[pos];
        }
        tmp->word = w;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    string word;
    bool search(string word) {
        this->word = word;
        return df(0, head);
    }
    
    bool df(int idx, TrieNode *p){
        for(uint32_t i=idx; i<word.size(); i++){
            if(word[i] == '.'){
                for(auto &x:p->child){
                    if(x != NULL){
                        if(df(i+1, x)) return true;
                    }
                }
              return false;
            }else{
                int c = word[i] - 'a';
                if(!p->child[c]) 
                    return false;
                p= p->child[c];
            }
        }
        return (!p->word.empty());
    }
};
