// User function template for C++

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
class Solution {
  public:
    Node* divide(Node* head) {
        // code here
        Node *end = head; 
        Node *prev = nullptr; 
        Node *curr = head; 

        /* Get pointer to the last node */
        while (end->next != nullptr) 
            end = end->next; 

        Node *new_end = end;
        
        /* Consider all odd nodes before the first 
        even node and move then after end */
        while (curr->data % 2 != 0 && curr != end){ 
            new_end->next = curr; 
            curr = curr->next; 
            new_end->next->next = nullptr; 
            new_end = new_end->next; 
        } 
        
        // 10->8->17->17->15 
        /* Do following steps only if 
        there is any even node */
        if (curr->data%2 == 0){ 
            /* Change the head pointer to 
            point to first even node */
            head = curr; 

            /* now current points to 
            the first even node */
            while (curr != end){ 
            
                if ( (curr->data) % 2 == 0 ){ 
               
                    prev = curr; 
                    curr = curr->next; 
                } 
                else{
                    
                    /* break the link between 
                    prev and current */
                    prev->next = curr->next; 

                    /* Make next of curr as NULL */
                    curr->next = nullptr; 

                    /* Move curr to end */
                    new_end->next = curr; 

                    /* make curr as new end of list */
                    new_end = curr; 

                    /* Update current pointer to 
                    next of the moved node */
                    curr = prev->next; 
                } 
            } 
        } 

        /* We must have prev set before executing 
        lines following this statement */
        //else prev = curr; 
    
        /* If there are more than 1 odd nodes 
        and end of original list is odd then 
        move this node to end to maintain 
        same order of odd numbers in modified list */
        if (new_end != end && (end->data) % 2 != 0) 
        { 
            prev->next = end->next; 
            end->next = nullptr; 
            new_end->next = end; 
        } 
        return head; 
        }
};