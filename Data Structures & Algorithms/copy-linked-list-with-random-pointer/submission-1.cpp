/*
// Definition for a Node.
class Node {
public:
    int val;
        Node* next;
            Node* random;

                    Node(int _val) {
                            val = _val;
                                    next = NULL;
                                            random = NULL;
                                                }
                                                };
                                                */

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> oldToNewMapping;

        Node* dummy = new Node(0);
        Node* newHead = dummy;

        Node* temp = head;
        while (temp != nullptr) {
            Node* newNode = new Node(temp->val);
            newHead->next = newNode;
            newNode->random = temp->random;
            oldToNewMapping[temp] = newNode;
            temp = temp->next;
            newHead = newHead->next;
        }

        Node* curr = dummy->next;
        while (curr != nullptr) {
            if (curr->random == nullptr) continue;
            curr->random = oldToNewMapping[curr->random];
            curr = curr->next;
        }

        return dummy->next;
    }
};
