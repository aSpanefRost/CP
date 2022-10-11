
typedef struct trienode trienode;
    
struct trienode{
    int val;
    trienode* arr[26];
};

void insert(string s, int val, trienode* head){
    for(int i=0;i<s.size();i++){
        if(!head->arr[s[i]-'a']){
            head->arr[s[i]-'a']=new trienode;
            head=head->arr[s[i]-'a'];
            head->val=max(head->val, val);
        }
        else head=head->arr[s[i]-'a'];
        head->val=max(head->val, val);
    }
}

int findMax(trienode* head, string s){
    for(int i=0;i<s.size();i++){
        if(!head->arr[s[i]-'a']) return -1;
        head=head->arr[s[i]-'a'];
    }
    return head->val;
}

vector<int> searchEngine(vector<pair<string, int> > database, vector<string> text)
{
    trienode* head=new trienode;
    for(auto x: database){
        insert(x.first, x.second, head);
    }
    vector<int> ans;
    for(auto x:text){
        ans.push_back(findMax(head, x));
    }
    return ans;
}
