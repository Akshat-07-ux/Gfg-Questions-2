/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
};
*/

vector<int> displayList(Node *head) {
    vector<int> result;
    Node *current = head;

    // Traverse the list until we hit the end (NULL)
    while (current != NULL) {
        // Add the current node's data to our vector
        result.push_back(current->data);
        
        // Move to the next node in the sequence
        current = current->next;
    }

    return result;
}