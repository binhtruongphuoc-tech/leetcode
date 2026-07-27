#include <stdlib.h>

#define MAX_CAPACITY 30005

typedef struct {
    int* data;
    int* min_data;
    int top;
} MinStack;

// Hàm khởi tạo Stack
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    
    // Cấp phát đủ sức chứa tối đa theo giới hạn của bài toán
    obj->data = (int*)malloc(MAX_CAPACITY * sizeof(int));
    obj->min_data = (int*)malloc(MAX_CAPACITY * sizeof(int));
    
    obj->top = -1; // Stack rỗng
    return obj;
}

// Thêm phần tử vào đỉnh Stack
void minStackPush(MinStack* obj, int val) {
    obj->top++;
    obj->data[obj->top] = val;
    
    // Cập nhật giá trị nhỏ nhất tại thời điểm hiện tại
    if (obj->top == 0) {
        // Nếu là phần tử đầu tiên, nó chính là min
        obj->min_data[obj->top] = val;
    } else {
        // So sánh với min cũ để lưu lại min mới
        int current_min = obj->min_data[obj->top - 1];
        obj->min_data[obj->top] = (val < current_min) ? val : current_min;
    }
}

// Xóa phần tử ở đỉnh Stack
void minStackPop(MinStack* obj) {
    if (obj->top >= 0) {
        obj->top--;
    }
}

// Lấy giá trị ở đỉnh Stack
int minStackTop(MinStack* obj) {
    return obj->data[obj->top];
}

// Lấy giá trị nhỏ nhất của Stack
int minStackGetMin(MinStack* obj) {
    return obj->min_data[obj->top];
}

// Dọn dẹp bộ nhớ
void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj->min_data);
    free(obj);
}