/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Tạo một nút giả (dummy) để dễ dàng xử lý đầu danh sách
        ListNode dummy;
        ListNode* iterator = &dummy;
        
        // Vòng lặp để gộp hai danh sách theo thứ tự tăng dần
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                iterator->next = list1;
                list1 = list1->next;
            } else {
                iterator->next = list2;
                list2 = list2->next;
            }
            iterator = iterator->next;
        }
        
        // Gắn phần còn lại của danh sách chưa duyệt hết vào cuối danh sách kết quả
        if (list1 != nullptr) {
            iterator->next = list1;
        } else {
            iterator->next = list2;
        }
        
        // Trả về danh sách kết quả, bỏ qua nút giả
        return dummy.next;
    }
};
