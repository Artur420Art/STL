template<typename T>
class m_set {
private:
    struct Node
    {
        Node* left;
        Node* right;
        T data;
        Node(T value);
    };
    Node* root;
    int size;
    Node insert_helper(Node* ptr, T value);
public:
    m_set();
    void insert(T value);
    bool empty();
    void erase(T value);
    T find(T value);
    void print(Node* ptr = nullptr);
};