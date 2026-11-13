#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
    int freq;
    node* lnode=nullptr;
    node* rnode=nullptr;
    char charecter='\0';
};

struct charcode
{
    char ch;
    string code;
};

bool sortlogic(node a,node b)
{
    return a.freq>b.freq;
}
vector<charcode> charcodes;
void charcodegenerator(node root,string str)
{
    if(root.charecter!='\0')
    {
        charcode crcd;
        crcd.ch=root.charecter;
        crcd.code=str;
        charcodes.push_back(crcd);
        return;
    }
    charcodegenerator(*root.lnode,str+"0");
    charcodegenerator(*root.rnode,str+"1");

}

int main()
{
    int n;
    cin>>n;
    vector<node> nodes(n);
    for(int i=0;i<n;i++)
    cin>>nodes[i].charecter>>nodes[i].freq;
    while(nodes.size()>1)
    {
        sort(nodes.begin(),nodes.end(),sortlogic);
        node* a=new node(nodes.back());
        nodes.pop_back();
        node* b=new node(nodes.back());
        nodes.pop_back();
        node c;
        c.freq=a->freq+b->freq;
        c.lnode=a;
        c.rnode=b;
        nodes.push_back(c);
    }

    charcodegenerator(nodes.back(),"");
    for(int i=0;i<n;i++)
    cout<<charcodes[i].ch<<" : "<<charcodes[i].code<<endl;

}