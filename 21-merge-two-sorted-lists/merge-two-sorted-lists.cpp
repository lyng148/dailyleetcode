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
        // Tạo một nút giả để dễ dàng thao tác với đầu của danh sách kết quả
        ListNode dummy;
        ListNode* iterator = &dummy;

        // Vòng lặp để gộp hai danh sách theo thứ tự tăng dần
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                // Tạo một nút mới với giá trị của nút hiện tại từ list1
                ListNode* newNode = new ListNode(list1->val);
                iterator->next = newNode;
                list1 = list1->next;
            } else {
                // Tạo một nút mới với giá trị của nút hiện tại từ list2
                ListNode* newNode = new ListNode(list2->val);
                iterator->next = newNode;
                list2 = list2->next;
            }
            iterator = iterator->next;
        }

        // Gắn phần còn lại của danh sách chưa duyệt hết vào cuối danh sách kết quả
        while (list1 != nullptr) {
            ListNode* newNode = new ListNode(list1->val);
            iterator->next = newNode;
            list1 = list1->next;
            iterator = iterator->next;
        }

        while (list2 != nullptr) {
            ListNode* newNode = new ListNode(list2->val);
            iterator->next = newNode;
            list2 = list2->next;
            iterator = iterator->next;
        }

        // Trả về danh sách kết quả, bỏ qua nút giả
        return dummy.next;
    }
};
