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
        bool verifyBST(tree* &root){
            tree* curr = root;
            tree* left = curr->lptr;
            tree* right = curr->rptr;
            if(curr->lptr==nullptr || curr->rptr==nullptr){
                return true;
            }
            if(left->data >= curr->data){
                return false;
            }
            if(right->data <= curr->data){
                return false;   
            }
            else{
                bool leftBST = verifyBST(left);
                bool rightBST = verifyBST(right);
                return leftBST && rightBST; 
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

        cout<<"Is BST: "<<root->verifyBST(root)<<endl;
        return 0;

    }