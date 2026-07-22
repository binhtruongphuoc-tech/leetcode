#include <stdlib.h>

// Định nghĩa Node cho Danh sách liên kết đôi
typedef struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

// Định nghĩa bộ nhớ Cache
typedef struct {
    int capacity;
    int count;
    Node* head; // Dummy head
    Node* tail; // Dummy tail
    Node** hash; // Mảng con trỏ đóng vai trò Hash Map
} LRUCache;

// Hàm tạo Node mới
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Hàm khởi tạo LRU Cache
LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->count = 0;
    
    // Cấp phát mảng băm trực tiếp (hỗ trợ key từ 0 đến 10000)
    cache->hash = (Node**)calloc(10005, sizeof(Node*));
    
    // Khởi tạo 2 node giả để chặn hai đầu danh sách
    cache->head = createNode(0, 0);
    cache->tail = createNode(0, 0);
    cache->head->next = cache->tail;
    cache->tail->prev = cache->head;
    
    return cache;
}

// Xóa một node bất kỳ khỏi danh sách liên kết đôi
void removeNode(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

// Thêm một node vào ngay sau Dummy Head (trở thành MRU)
void addNodeToHead(LRUCache* cache, Node* node) {
    node->prev = cache->head;
    node->next = cache->head->next;
    
    cache->head->next->prev = node;
    cache->head->next = node;
}

// Hàm lấy dữ liệu
int lRUCacheGet(LRUCache* obj, int key) {
    Node* node = obj->hash[key];
    if (node == NULL) {
        return -1; // Không tìm thấy
    }
    
    // Nếu tìm thấy, cắt node này ra và đưa lên đầu danh sách
    removeNode(node);
    addNodeToHead(obj, node);
    
    return node->value;
}

// Hàm thêm/cập nhật dữ liệu
void lRUCachePut(LRUCache* obj, int key, int value) {
    Node* node = obj->hash[key];
    
    if (node != NULL) {
        // Đã tồn tại: Cập nhật giá trị và đưa lên đầu
        node->value = value;
        removeNode(node);
        addNodeToHead(obj, node);
    } else {
        // Chưa tồn tại: Tạo node mới
        Node* newNode = createNode(key, value);
        obj->hash[key] = newNode;
        addNodeToHead(obj, newNode);
        obj->count++;
        
        // Kiểm tra dung lượng
        if (obj->count > obj->capacity) {
            // Lấy node nằm ngay trước Dummy Tail (đây chính là LRU)
            Node* lru = obj->tail->prev;
            
            // Xóa khỏi danh sách liên kết
            removeNode(lru);
            // Xóa khỏi Bảng băm
            obj->hash[lru->key] = NULL;
            // Giải phóng bộ nhớ
            free(lru);
            
            obj->count--;
        }
    }
}

// Hàm dọn dẹp bộ nhớ
void lRUCacheFree(LRUCache* obj) {
    Node* curr = obj->head;
    while (curr != NULL) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
    free(obj->hash);
    free(obj);
}