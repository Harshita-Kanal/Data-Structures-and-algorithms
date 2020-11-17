#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
using namespace std;
#define MAX_TREE_HEIGHT 100

int i = 0, size, countT = 0, countH = 0, countF = 0, countK = 0, countX = 0, countP = 0;
using namespace std;
bool isCharacter(char symbol)
{

    if (symbol == 't' || symbol == 'h' || symbol == 'f' || symbol == 'k' || symbol == 'p' || symbol == 'x')
        return true;
    else
        return false;
}

struct minHeapNode
{
    char character;
    int frequency;
    minHeapNode *left, *right;
};

struct minHeap
{
    unsigned size;
    unsigned capacity;
    minHeapNode **array; //pointing to character stored at particular index in character array
};
minHeapNode *newNode(char ch, int freq)
{
    minHeapNode *temp = new minHeapNode;
    temp->left = temp->right = NULL;
    temp->character = ch;
    temp->frequency = freq;

    return temp;
}
//Function to create a min heap of given capacity
minHeap *create_MinHeap(unsigned capacity)
{
    minHeap *mHeap = new minHeap;

    mHeap->size = 0; //beginning size is 0
    mHeap->capacity = capacity;
    mHeap->array = (minHeapNode **)malloc(mHeap->capacity * sizeof(minHeapNode *));

    return mHeap;
}

//Function that swaps two min heap nodes
void swap_minHeapNode(minHeapNode **a, minHeapNode **b)
{
    minHeapNode *tmp = *a;
    *a = *b;
    *b = tmp;
}

//Standard min heapify function
void minHeapify(minHeap *mHeap, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < mHeap->size && mHeap->array[left]->frequency < mHeap->array[smallest]->frequency)
        smallest = left;
    else if (right < mHeap->size && mHeap->array[right]->frequency < mHeap->array[smallest]->frequency)
        smallest = right;

    if (smallest != index)
    {
        swap_minHeapNode(&mHeap->array[smallest], &mHeap->array[index]);
        minHeapify(mHeap, smallest); //recursive call after selecting appropriate smallest frequency
    }
}

// Function to check if size of heap is 1 or not
int isSizeOne(minHeap *mHeap)
{
    return (mHeap->size == 1);
}

//This function extracts minimum value node from heap
minHeapNode *extract(minHeap *mHeap)
{
    minHeapNode *temp = mHeap->array[0];
    mHeap->array[0] = mHeap->array[mHeap->size - 1];
    --mHeap->size;
    minHeapify(mHeap, 0);

    return temp;
}

//Function to insert a new node to min heap
void insertminHeap(minHeap *mHeap, minHeapNode *min_HeapNode)
{
    ++mHeap->size;
    int i = mHeap->size - 1;
    while (i && min_HeapNode->frequency < mHeap->array[(i - 1 / 2)]->frequency)
    {
        mHeap->array[i] = mHeap->array[(i - 1 / 2)];
        i = (i - 1) / 2;
    }
    mHeap->array[i] = min_HeapNode;
}

//Function to build min heap
void buildMinHeap(minHeap *mHeap)
{
    int n = mHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
    {
        minHeapify(mHeap, i);
    }
}

//Function to chech if current node is a leaf of the tree
int isLeaf(minHeapNode *root)
{
    return !(root->left) && !(root->right);
}

//Printing array function
void printArray(int arr[], int n)
{
    int i;
    cout << setw(1);
    for (i = 0; i < n; ++i)
    {
        cout << arr[i];
    }
    cout << "\n";
}

//This function creates a min heap of capacity equal to size and inserts all characters of the text array
// in min heap. Initially size of min heap is equal to capacity.
struct minHeap *createandbuildMinHeap(char character[], int frequency[], int size)
{
    int i;
    minHeap *mHeap = create_MinHeap(size);
    for (i = 0; i < size; ++i)
    {
        mHeap->array[i] = newNode(character[i], frequency[i]);
    }
    mHeap->size = size;
    buildMinHeap(mHeap);

    return mHeap;
}
//Building Huffman Tree utility function
minHeapNode *buildHuffmanTree(char charachter[], int frequency[], int size)
{
    minHeapNode *left, *right, *top;
    minHeap *mHeap = createandbuildMinHeap(charachter, frequency, size); // Step 1: Creates min heap of capacity equal to size

    while (!isSizeOne(mHeap)) // Iterate till size of heap doesn't become 1
    {
        //Step 2: Extract two minimum frequency items from the min heap
        left = extract(mHeap);
        right = extract(mHeap);

        //Step 3: Create an internal node with frequency equal to the sum of the two extracted nodes frequencies
        //Also make the extracted nodes as left and right children of the node created in Step 3.

        top = newNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertminHeap(mHeap, top);
    }
    //Step 4: The remaining node is the root node and the tree is completed
    return extract(mHeap);
}

//Prints Huffman Codes by traversing the Huffman tree. The codes are stored in an array
void printCode(minHeapNode *root, int codes[], int top)
{
    //Assign 0 for every left child traversed
    if (root->left)
    {
        codes[top] = 0;
        printCode(root->left, codes, top + 1);
    }
    //Assign 1 for every right child traversed
    if (root->right)
    {
        codes[top] = 1;
        printCode(root->right, codes, top + 1);
    }
    //If we arrive on a leaf node then we print the character and the correspinding saved code in codes[].
    if (isLeaf(root))
    {
        cout << "      " << root->character << setw(6) <<"|" << "     " << root->frequency << setw(6) <<"|";
        printArray(codes, top);
    }
}

// traverse the Huffman Tree and decode the encoded string
/*void decode(Node *root, int &index, string str)
{
      if (root == nullptr)
      {
            return;
      }

      // found a leaf node
      if (!root->left && !root->right)
      {
            cout << root->ch;
            return;
      }

      index++;

      if (str[index] == '0')
            decode(root->left, index, str);
      else
            decode(root->right, index, str);
}
*/

//This function builds a Huffman Tree and print codes by traversing the built Huffman Tree
void HuffmanCodes(char character[], int frequency[], int size)
{
    //Construct Huffman Tree
    struct minHeapNode *root = buildHuffmanTree(character, frequency, size);

    //Print HUffman codes using the Huffman tree built in above step
    int codes[MAX_TREE_HEIGHT], top = 0;
    printCode(root, codes, top);
}

//Driver Program
int main()
{
    ifstream myFile;
    ofstream destFile("/Users/mujtabakhurram/Desktop/C++/");
    char s[1000], fname[20], message[1000], c;
    // int i=0, size, countT, countH, countF, countK, countX, countP;
start:
    cout << " Enter a file name to be compressed (like file.txt) : ";
    cin >> fname;

    myFile.open(fname);
    if (!myFile)
    {
        cout << "Error in opening file..!!\n";
        goto start;
    }

    destFile.open("Encode.txt", ios::out);
    while (!myFile.eof())
    {
        myFile.get(c);
        if (isCharacter(c))
        {
            cout << c;
            message[i] = c;
            i++;
        }
    }
    size = i;
    destFile << message;
    destFile << "\n\n";
    cout << "\n\n\nDisplaying text file containing characters:" << message;
    myFile.close();
    destFile.close();

    for (i = 0; i <= size; i++)
    {
        if (message[i] == 't')
        {
            countT++;
        }
        else if (message[i] == 'h')
        {
            countH++;
        }
        else if (message[i] == 'p')
        {
            countP++;
        }
        else if (message[i] == 'k')
        {
            countK++;
        }
        else if (message[i] == 'x')
        {
            countX++;
        }
        else if (message[i] == 'f')
        {
            countF++;
        }
    }
   /* cout << "\n\n\nDisplaying Frequencies: " << endl;
    cout << "\nFrequency of t :" << countT;
    cout << "\nFrequency of f :" << countF;
    cout << "\nFrequency of h :" << countH;
    cout << "\nFrequency of k :" << countK;
    cout << "\nFrequency of p :" << countP;
    cout << "\nFrequency of x :" << countX << endl;*/
    char codes[] = {'t', 'h', 'k', 'p', 'f', 'x'};
    int frequency[] = {countT, countH, countK, countP, countF, countX};

    int size = sizeof(codes) / sizeof(codes[0]);

    cout << " Characters " << "|" << setw(8) << " Frequency " << "|" << setw(8) << " Codes\n";
    cout << "------------" << "|" << setw(8) << "-----------" << "|" << setw(8) << "-------\n";
    HuffmanCodes(codes, frequency, size);

    return 0;
}