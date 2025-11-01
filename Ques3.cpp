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
        void deletion(int n, tree* &parent){
            tree* curr = parent;
            if(n<curr->data){
                if(curr->lptr==nullptr){
                    cout<<"Value not found"<<endl;
                    return;
                }
                curr->lptr->deletion(n, curr);
            }
            else if(n>curr->data){
                if(curr->rptr==nullptr){
                    cout<<"Value not found"<<endl;
                    return;
                }
                curr->rptr->deletion(n, curr);
            }
            else{
                if(curr->lptr==nullptr && curr->rptr==nullptr){
                    if(parent->lptr==curr){
                        parent->lptr = nullptr;
                    }
                    else{
                        parent->rptr = nullptr;
                    }
                    delete curr;
                }
                else if(curr->lptr!=nullptr && curr->rptr!=nullptr){
                    tree* succParent = curr;
                    tree* succ = curr->rptr;
                    while(succ->lptr!=nullptr){
                        succParent = succ;
                        succ = succ->lptr;
                    }
                    curr->data = succ->data;
                    succ->deletion(succ->data, succParent);
                }
                else{
                    tree* child = (curr->lptr!=nullptr) ? curr->lptr : curr->rptr;
                    if(parent->lptr==curr){
                        parent->lptr = child;
                    }
                    else{
                        parent->rptr = child;
                    }
                    delete curr;
                }
            }
        }
        int maxDepth(tree* &root){
            tree* temp = root;{
                if(temp==nullptr){
                    return 0;
                }
                else{
                    int lDepth = maxDepth(temp->lptr);
                    int rDepth = maxDepth(temp->rptr);
                    if(lDepth>rDepth){
                        return lDepth+1;
                    }
                    else{
                        return rDepth+1;
                    }
                }
            }
        }
        int minDepth(tree* &root){
            tree* temp = root;{
                if (root == nullptr)
                return 0;

                if (root->lptr == nullptr && root->rptr == nullptr)
                return 1;

                if (root->lptr == nullptr)
                return minDepth(root->rptr) + 1;

                if (root->rptr == nullptr)
                return minDepth(root->lptr) + 1;

                return min(minDepth(root->lptr), minDepth(root->rptr)) + 1;
            }
        }
};


int main(){
    tree* root = new tree(100);
    root->insert(20);
    root->insert(200);
    root->insert(10);
    root->insert(30);
    root->insert(150);      
    cout<<"Max Depth: "<<root->maxDepth(root)<<endl;
    cout<<"Min Depth: "<<root->minDepth(root)<<endl;
}
