#include<iostream>
#include<map>
#include<queue>
using namespace std;
class tree{
    private:
        int data;
        tree *left,*right;
        
    public:
        tree(int val){
            this->data = val;
            this->left = this->right = NULL;
        }
        tree *insert(tree *root,int val){
            if(root==NULL)
            {
                return new tree(val);
            }
            if(val<root->data){
                root->left = insert(root->left,val);
            }
            if(val>root->data){
                root->right = insert(root->right,val);
            }
            return root;
        }
        void inorder(tree *root){
         //   cout<<"Inorder Traversal"<<endl;
            if(root==NULL){
                return;
            }
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
        void preorder(tree *root){
            
              if(root==NULL){
                return;
            }
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        
        }
        void left_view(tree *root){
            queue<tree *> q;
            q.push(root);
            while(!q.empty()){
                int size = q.size();
                for(int i=1;i<=size;i++){
                    auto temp = q.front();
                     q.pop();
                     if(i==1){
                         cout<<temp->data<<" ";
                     }
                     if(temp->left){
                         q.push(temp->left);
                     }
                     if(temp->right){
                         q.push(temp->right);
                     }
                
                }
            }
        }
        void right_view(tree *root){
            queue<tree *> q;
            q.push(root);
            while(!q.empty()){
                int size = q.size();
                for(int i=1;i<=size;i++){
                    auto temp = q.front();
                     q.pop();
                     if(i==size){
                         cout<<temp->data<<" ";
                     }
                     if(temp->left){
                         q.push(temp->left);
                     }
                     if(temp->right){
                         q.push(temp->right);
                     }
                
                }
            }
        }
};
int main(){
    /*
         5
      4     8
        6      10
    */
    tree *root = NULL;              
    root = root->insert(root,5);
    root = root->insert(root,8);
    root = root->insert(root,4);
    root = root->insert(root,6);
    root = root->insert(root,10);
    cout<<"Inorder Traversal"<<endl;
    root->inorder(root);
    cout<<"\n"<<"Preorder Traversal"<<endl;
    root->preorder(root);
    cout<<"\n"<<"Left View"<<endl;
    root->left_view(root);
    cout<<"\n"<<"Right View"<<endl;
    root->right_view(root);
    
    return 0;
}

