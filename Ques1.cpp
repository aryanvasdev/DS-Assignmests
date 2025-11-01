#include <iostream>

using namespace std;

class tree{
    private:
        int data;
        tree* lptr;
        tree* rptr;
    public:
        tree(int n){
            data = n;
            lptr = nullptr;
            rptr = nullptr;
        }
        void insert(int n){
            if(n==data){
                cout<<"Duplicate value"<<endl;
                return;
            }
            else if(n<data){
                if(lptr==nullptr){
                    lptr = new tree(n);
                }
                else{
                    lptr->insert(n);
                }
            }
            else{
                if(rptr==nullptr){
                    rptr = new tree(n);
                }
                else{
                    rptr->insert(n);
                }
            }
        }
        void Pre(tree* &root){
            tree* curr=root;
            if(curr!=nullptr){
                cout<<curr->data<<" ";
                Pre(curr->lptr);
                Pre(curr->rptr);
            }
        }
        void In(tree* &root){
            tree* curr=root;
            if(curr!=nullptr){
                In(curr->lptr);
                cout<<curr->data<<" ";
                In(curr->rptr);
            }
        }
        void Post(tree* &root){
            tree* curr=root;
            if(curr!=nullptr){
                Post(curr->lptr);
                Post(curr->rptr);
                cout<<curr->data<<" ";
            }
        }
};


int main(){
    tree* root = new tree(16);
    root->insert(8);
    root->insert(25);
    root->insert(42);
    root->insert(62);
    root->insert(49); 
    root->insert(58);     
    cout<<"Preorder Traversal: ";
    root->Pre(root);
    cout<<endl;
    cout<<"Inorder Traversal: ";
    root->In(root);
    cout<<endl;
    cout<<"Postorder Traversal: ";
    root->Post(root);
    cout<<endl;
    return 0;  
}