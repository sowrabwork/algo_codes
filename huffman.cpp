#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    string name;
    int freq;
    node *leftnode, *rightnode;
    node(string name, int freq)
    {
        this->name = name;
        this->freq = freq;
        this->leftnode = nullptr;
        this->rightnode = nullptr;
    }
    node(string name, int freq, node *leftnode, node *rightnode)
    {
        this->name = name;
        this->freq = freq;
        this->leftnode = leftnode;
        this->rightnode = rightnode;
    }
};

bool compairator(node a, node b)
{
    return a.freq < b.freq;
}

int main()
{
    cout << "enter the nuumber of charecter: ";
    int NumChar;
    cin >> NumChar;
    vector<node> nodes;
    cout << "enter the charecters and their corresponding freqiences: " << endl;
    for (int i = 0; i < NumChar; i++)
    {
        string charecter;
        int freq;
        cin >> charecter >> freq;
        nodes.push_back(node(charecter, freq));
    }
    while (nodes.size() != 1)
    {
        sort(nodes.begin(), nodes.end(), compairator);
        node *node1 = new node(nodes[0]);
        nodes.erase(nodes.begin());
        node *node2 = new node(nodes[0]);
        nodes.erase(nodes.begin());
        nodes.push_back(node(node1->name + node2->name, node1->freq + node2->freq, node1, node2));
    }
}