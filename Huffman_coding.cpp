#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class Node {
public:
    char data;
    int cost;

    Node* left;
    Node* right;

    Node(char data, int cost) {
        this->data=data;
        this->cost=cost;
        this->left=nullptr;
        this->right=nullptr;
    }

    ~Node(){
        delete left;
        delete right;
    }

    bool operator>(const Node& obj) const {
        return this->cost>obj.cost;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return *a > *b;
    }
};

class HuffmanCoder {
public:
    unordered_map<char, string>encoder;
    unordered_map<string, char>decoder;

    HuffmanCoder(const string& feeder) {
        unordered_map<char, int> freq;

        for (char cc:feeder) {
            freq[cc]++;
        }

        priority_queue<Node*, vector<Node*>,Compare>minHeap;

        for(auto&obj:freq) {
            minHeap.push(new Node(obj.first, obj.second));
        }

        while (minHeap.size()>1) {
            Node* first = minHeap.top(); 
            minHeap.pop();
            Node* second = minHeap.top(); 
            minHeap.pop();

            Node* newNode = new Node('\0',first->cost+second->cost);
            newNode->left = first;
            newNode->right = second;

            minHeap.push(newNode);
        }
        
        Node* root = minHeap.top();
        EncoderDecoder(root, "");
        delete root;
    }

    void EncoderDecoder(Node* node, const string& binarypath) {
        if (node == nullptr) 
        return;

        if(node->left==nullptr&&node->right==nullptr) {
            encoder[node->data]=binarypath;
            decoder[binarypath]=node->data;
        }

        EncoderDecoder(node->left,binarypath+"0");
        EncoderDecoder(node->right,binarypath+"1");
    }

    string encode(const string& input) {
        string ans="";
        for (char c:input) {
            ans+=encoder[c];
        }
        return ans;
    }

    string decode(const string& encoded) {
        string key= "";
        string ans= "";
        for (char bit:encoded) {
            key+=bit;
            if(decoder.count(key)) {
                ans += decoder[key];
                key = "";
            }
        }
        return ans;
    }
};

int main() {
    string str;
    cout << "Enter the message u want to hash: ";
    getline(cin,str);
    HuffmanCoder hf(str);

    string encoded = hf.encode(str);
    cout << "Encoded: " << encoded << endl;
    string decoded = hf.decode(encoded);
    cout << "Decoded: " << decoded << endl;

    return 0;
}
