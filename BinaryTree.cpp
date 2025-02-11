#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
    
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    // cout<<"enter data: "<<endl;
    int data;
    cin>>data;

    root = new node(data);

    if(data == -1) return NULL;
    
    // cout<<"enter left data for "<<data<<endl;
    root->left = buildTree(root->left);

    // cout<<"enter right data for "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return;
}

void inOrderTraversal(node* root){
    if(root == NULL) return;

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
    // cout<<root->data<<" "; dont put this think about it we are just printing the root and left right its just traversal 
}

void preOrderTraversal(node* root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(node* root){
    if(root == NULL) return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

void BuildLevelOrder(node* &root){
    queue<node*> q;
    cout<<"enter root data";
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        cout<<"enter data for left of "<<temp->data <<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }


        cout<<"enter data for right of "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main(){
    node* root  = NULL;
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 8 -1 -1 -1 
    // root = buildTree(root);

    // cout<<"levelOrderTraversal"<<endl;

    // levelOrderTraversal(root);

    // cout<<"inOrderTraversal"<<endl;

    // inOrderTraversal(root);
    
    // cout<<"preOrderTraversal"<<endl;
    
    // preOrderTraversal(root);

    // cout<<"postOrderTraversal"<<endl;

    // postOrderTraversal(root);

    BuildLevelOrder(root);
    levelOrderTraversal(root);
    
    return 0;
}
