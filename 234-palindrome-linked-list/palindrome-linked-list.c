/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode node;

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true; // Danh sách rỗng hoặc chỉ có một phần tử thì coi như là palindrome
    }

    // Đếm số lượng phần tử trong danh sách
    int count = 0;
    node *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    int values[count]; // Mảng để lưu giá trị của các phần tử trong danh sách
    current = head;
    int index = 0;
    while (current != NULL) {
        values[index++] = current->val;
        current = current->next;
    }

    // Kiểm tra xem danh sách có là palindrome không
    int i = 0, j = count - 1; // Chỉ số bắt đầu và cuối của mảng giá trị
    while (i < j) {
        if (values[i] != values[j]) {
            return false; // Nếu có khác biệt, danh sách không phải là palindrome
        }
        i++;
        j--;
    }
    return true; // Nếu không có khác biệt, danh sách là palindrome
}
