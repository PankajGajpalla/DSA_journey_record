#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

vector<int> moristraversal(Node* root){
    Node* curr = root;
    vector<int> ans;

    while(curr!=NULL){
        if(curr->left == NULL){
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else{
            Node* prev = curr->left;
            while(prev->right != NULL && prev->right != curr){
                prev = prev->right;
            }

            if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
            }
            else{
                prev->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}
Node* nodeconstructor(Node* &root, int d){
    if(root == NULL){
        Node* n = new Node(d);
        return n;
    }

    if(d<root->data){
        root->left = nodeconstructor(root->left, d);
    }else{
        root->right = nodeconstructor(root->right, d);
    }
    return root;
}

void takeinput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = nodeconstructor(root, data);
        cin>>data;
    }
}

int main(){
    Node* root = NULL;

    cout<<"enter input"<<endl;
    takeinput(root);

    vector<int> ans = moristraversal(root);
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}