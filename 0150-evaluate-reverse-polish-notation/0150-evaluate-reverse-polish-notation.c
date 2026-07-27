#include <stdlib.h>
#include <string.h>

int evalRPN(char ** tokens, int tokensSize) {
    // Cấp phát Stack động (kích thước tối đa bằng số lượng tokens)
    int* stack = (int*)malloc(tokensSize * sizeof(int));
    int top = -1; // Con trỏ Stack

    for (int i = 0; i < tokensSize; i++) {
        char* token = tokens[i];
        
        // Kiểm tra xem token hiện tại là toán tử hay là con số
        // Toán tử luôn có độ dài bằng 1 và là 1 trong 4 ký tự cơ bản
        if (strlen(token) == 1 && (token[0] == '+' || token[0] == '-' || 
                                   token[0] == '*' || token[0] == '/')) {
            
            // Lấy 2 số ra khỏi Stack
            // Lưu ý: Số lấy ra trước là số bị tác động (nằm sau toán tử)
            int b = stack[top--];
            int a = stack[top--];
            
            // Tính toán và đẩy kết quả lại vào Stack
            switch (token[0]) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break; // C mặc định làm tròn về 0
            }
        } else {
            // Nếu là con số, chuyển chuỗi thành số nguyên (atoi) và đẩy vào Stack
            stack[++top] = atoi(token);
        }
    }
    
    // Kết quả cuối cùng là phần tử duy nhất còn lại trên đỉnh Stack
    int result = stack[top];
    
    // Giải phóng bộ nhớ
    free(stack);
    
    return result;
}