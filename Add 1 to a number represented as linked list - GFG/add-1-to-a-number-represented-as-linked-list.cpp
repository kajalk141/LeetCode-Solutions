// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    Node *rev(Node *head){
        Node *prev=NULL;
        while(head){
            Node *temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return prev;
    }
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node *temp=rev(head), *extra=NULL;
        int sum=0, carry=1;
        extra=temp;
        while(temp){
            sum=temp->data+carry;
            temp->data=sum%10;
            if(sum>9) carry=1;
            else carry=0;
            if(temp->next==NULL) break;
            else temp=temp->next;
        }
        if(carry==1){
            temp->next=new Node(carry);
        }
        head=rev(extra);
        return head;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends