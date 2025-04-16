#include <cstdio>
#include <cstdlib>
#include <ctime>

//структура узла дерева
struct Node
{
    int a;
    Node* left;
    Node* right;
};

//функция для создания нового узла
Node* createNode(int value)
{
    Node* newNode = new Node();
    newNode->a = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

//функция для вставки значения в дерево
Node* insert(Node* root, int value)
{
    //если текущий узел пуст, создаем новый узел
    if (root == nullptr)
    {
        return createNode(value);
    }

    //если значение меньше значения текущего узла, вставляем в левое поддерево
    if (value < root->a)
    {
        root->left = insert(root->left, value);
    }
    //иначе вставляем в правое
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}

//рекурсивная функция для обхода дерева
void inOrderTraversal(Node* root)
{
    if (root != nullptr)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->a);
        inOrderTraversal(root->right);
    }
}

//функция для генерации случайного числа в диапазоне
int getRandomNumber(int min, int max)
{
    return min + rand() % (max - min + 1);
}

int main()
{
    srand(time(nullptr));

    const int arraySize = 10;
    int randomArray[arraySize];
    
    //генерация массива случайных чисел
    printf("Генерация массива: ");
    for (int i = 0; i < arraySize; i++)
    {
        randomArray[i] = getRandomNumber(0, 100);
        printf("%d ", randomArray[i]);
    }
    printf("\n");
    
    //создание дерева из массива
    Node* root = nullptr;
    for (int i = 0; i < arraySize; i++)
    {
        root = insert(root, randomArray[i]);
    }
    
    printf("Обход дерева: \n");
    inOrderTraversal(root);

    return 0;
}