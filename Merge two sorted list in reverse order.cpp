//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << '\n' << "~" << endl;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution {
  public:
    struct Node* Mergeinsorted(struct Node *node1,struct Node *node2){
        if(node1==NULL) return node2;
        if(node2==NULL) return node1;
        
        struct Node* result;
        if(node1->data < node2->data){
            result = node1;
            result->next = Mergeinsorted(node1->next,node2);
        }
        else{
            result = node2;
            result->next = Mergeinsorted(node1,node2->next);
        }
        return result;
    }
    struct Node *reverselist(struct Node* head){
        if(head == NULL || head->next == NULL) return head;
        Node* last = reverselist(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return last;
    }
    struct Node *mergeResult(Node *node1, Node *node2) {
        // your code goes here
        
        
        
        struct Node* result = Mergeinsorted(node1,node2);
        
        result = reverselist(result);
        
        return result;
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n1, n2, tmp;
        Node *head1 = nullptr, *tail1 = nullptr;
        Node *head2 = nullptr, *tail2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            Node *new_node = new Node(tmp);
            if (head1 == nullptr) {
                head1 = new_node;
                tail1 = new_node;
            } else {
                tail1->next = new_node;
                tail1 = new_node;
            }
        }

        getline(cin, input2); // Read the entire line for LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            Node *new_node = new Node(tmp);
            if (head2 == nullptr) {
                head2 = new_node;
                tail2 = new_node;
            } else {
                tail2->next = new_node;
                tail2 = new_node;
            }
        }

        Solution obj;
        Node *result = obj.mergeResult(head1, head2);

        printList(result);
        // cout << endl;
    }
    return 0;
}

// } Driver Code Ends
