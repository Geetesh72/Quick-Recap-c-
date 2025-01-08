#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    string data ;
    Node*next ;
    Node*back;
    Node():data(0),next(nullptr),back(nullptr){}
    Node(string x):data(x),next(nullptr),back(nullptr){}
    Node(string x ,Node*next , Node*radd):data(x),next(next),back(radd){}

};
class Browser{
    public:
    Node*currPage;
    Browser(string &homepage){
        currPage  = new Node(homepage);
    }
    void visit(string &url){
        Node*newNode  = new Node(url);
        currPage->next  = newNode;
        newNode->back = currPage;
        currPage=newNode;
    }
    string back(int steps){
        while(steps)
        {
            if(currPage->back){
                currPage =currPage->back;
            }else{
                break;
                steps--;
            }

        }
        return currPage->data;
    }
    string forward(int steps){
        while(steps){
            if(currPage->next){
                currPage =currPage->next;
            }else{
                break;
                steps--;
            }
        }
        return currPage->data;

    }
};

int main()
{
    return 0;
}