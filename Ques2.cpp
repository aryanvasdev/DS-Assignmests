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
        void In(tree* &root){
            tree* curr=root;
            if(curr!=nullptr){
                In(curr->lptr);
                cout<<curr->data<<" ";
                In(curr->rptr);
            }
        }
        bool searchrec(int n, tree* &root){
            tree* curr = root;
            if(curr==nullptr){
                return false;
            }
            if(n==curr->data){
                return true;
            }
            else if(n<curr->data){
                return searchrec(n, curr->lptr);
            }
            else{
                return searchrec(n, curr->rptr);
            }
        }
        bool searchit(int n, tree* &root){
            tree* curr = root;
            while(curr!=nullptr){
                if(n==curr->data){
                    return true;                
                }
                else if(n<curr->data){
                    curr = curr->lptr;
                }
                else{
                    curr = curr->rptr;
                }
            } 
            return false;
        }
        int maxel(tree* &root){
            tree* curr = root;
            while(curr->rptr!=nullptr){
                curr = curr->rptr;
            }
            return curr->data;
        }
        int minel(tree* &root){
            tree* curr = root;
            while(curr->lptr!=nullptr){
                curr = curr->lptr;
            }
            return curr->data;
        }
        int insucc(tree* &root, int n){
            tree* curr = root;
            while (curr != nullptr && curr->data != n) {
                if (n < curr->data)
                    curr = curr->lptr;
                else
                    curr = curr->rptr;
            }
            tree* succ = curr->rptr;
            while(succ->lptr!=nullptr){
                succ = succ->lptr;      
            }
            return succ->data;
        }
        int pred(tree* &root, int n){
            tree* curr = root;
            while (curr != nullptr && curr->data != n) {
                if (n < curr->data)
                    curr = curr->lptr;
                else
                    curr = curr->rptr;
            }
            tree* pred = curr->lptr;
            while(pred->rptr!=nullptr){
                pred = pred->rptr;      
            }
            return pred->data;
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
    cout<<"succ: "<<root->insucc(root, 42)<<endl;        
    cout<<"pred: "<<root->pred(root, 42)<<endl;
}
