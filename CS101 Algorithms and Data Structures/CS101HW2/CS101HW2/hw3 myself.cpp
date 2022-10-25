//#include "bits/stdc++.h"
////#define DEBUG
////#define STAND
//using namespace std;
//
//void fuck()
//{
//    assert(false);
//    while (true);
//}
//#ifndef STAND
//enum NodeDire
//{
//    LeftChild, RightChild, Root
//};
//class Node {
//public:
//    Node() {};
//    Node(int data, Node* par, NodeDire dir) :data(data), parent(par), direction(dir) {};
//
//    int data;
//    int leftHeight = 0, RightHeight = 0;
//    int depth()
//    {
//        return max(leftHeight, RightHeight);
//    };
//
//    int spys = 1;
//    int childrenNumber = 0;
//    int MyfailmyNumer()
//    {
//        return childrenNumber + spys;
//    };
//    NodeDire direction;
//
//    Node* parent = nullptr;
//    Node* left = nullptr, * right = nullptr;
//};
//int spacing(int level) {
//    int result = 6;
//    for (int i = 0; i < level; i++)
//        result += result;
//    return result;
//}
//
//class AVL {
//public:
//    int nodeNumber = 0;
//    void GiveChild(Node* child, Node* newfather, NodeDire dir)
//    {
//        int deltaChild = 0;
//        if (!child)goto EmpytCHILD;
//        deltaChild = child ? child->MyfailmyNumer() : 0;
//        //处理原来父亲的关系
//        child->parent->childrenNumber -= deltaChild;
//        switch (child->direction)
//        {
//        case LeftChild:
//            child->parent->left = nullptr;
//            child->parent->leftHeight = 0;
//            break;
//        case RightChild:
//            child->parent->right = nullptr;
//            child->parent->RightHeight = 0;
//            break;
//        }
//        //处理我自己
//        child->parent = newfather;
//        child->direction = dir;
//        //处理新的父亲
//        //newfather->childrenNumber += deltaChild; 上面由于减少过了这里不再增加额
//
//    EmpytCHILD:
//        switch (dir)
//        {
//        case LeftChild:
//            newfather->childrenNumber -= newfather->left ? newfather->left->MyfailmyNumer() : 0;//原来的孩子没了
//            newfather->left = child;
//            newfather->leftHeight = child ? child->depth() + 1 : 0;
//            break;
//        case RightChild:
//            newfather->childrenNumber -= newfather->right ? newfather->right->MyfailmyNumer() : 0;//原来的孩子没了
//            newfather->right = child;
//            newfather->RightHeight = child ? child->depth() + 1 : 0;
//            break;
//        }
//        UpdateHeight(newfather);
//
//    };
//    void ReOrgnizeCase1(Node* lower, Node* higher)
//    {
//        //祖父处理好
//        if (higher->direction == LeftChild)
//        {
//            higher->parent->left = lower;
//            lower->parent = higher->parent;
//            higher->parent = lower;
//        }
//        else if (higher->direction == RightChild)
//        {
//            higher->parent->right = lower;
//            lower->parent = higher->parent;
//            higher->parent = lower;
//        }
//        else
//        {
//            lower->parent = nullptr;
//            higher->parent = lower;
//        }
//        auto higherdir = higher->direction;
//        if (lower->direction == LeftChild)//左下模式，往右边挤 OK
//        {
//            GiveChild(lower->right, higher, LeftChild);
//            higher->direction = RightChild;
//            lower->right = higher;
//            lower->RightHeight = higher->depth() + 1;;
//
//        }
//        if (lower->direction == RightChild)//右下模式，往左边挤
//        {
//            GiveChild(lower->left, higher, RightChild);
//            higher->direction = LeftChild;
//            lower->left = higher;
//            lower->leftHeight = higher->depth() + 1;
//        }
//        lower->childrenNumber += higher->MyfailmyNumer();
//        lower->direction = higherdir;
//
//    }
//    void ReOrgnizeCase2(Node* lower, Node* higher, NodeDire dir)
//    {
//        Node* third = 0;
//        if (dir == LeftChild)
//            third = lower->left;
//        else
//            third = lower->right;
//
//        //祖父处理好
//
//        if (higher->direction == LeftChild)
//        {
//            higher->parent->left = third;
//            third->parent = higher->parent;
//            third->direction = higher->direction;
//            lower->parent = third;
//            higher->parent = third;
//        }
//        else if (higher->direction == RightChild)
//        {
//            higher->parent->right = third;
//            third->parent = higher->parent;
//            third->direction = higher->direction;
//            lower->parent = third;
//            higher->parent = third;
//        }
//        else
//        {
//            third->parent = nullptr;
//            third->direction = Root;
//            higher->parent = third;
//            lower->parent = third;
//        }
//        //higher 去了lower的另一边
//        higher->direction = (NodeDire)(1 - lower->direction);
//        if (lower->direction == LeftChild)
//        {
//            GiveChild(third->right, higher, LeftChild);
//            GiveChild(third->left, lower, RightChild);
//
//            //更新上去的third的信息
//            third->right = higher;
//            third->left = lower;
//        }
//        if (lower->direction == RightChild)//OK 
//        {
//            GiveChild(third->left, higher, RightChild);
//            GiveChild(third->right, lower, LeftChild);
//
//            //更新上去的third的信息
//            third->right = lower;
//            third->left = higher;
//        }
//        third->leftHeight = third->left->depth() + 1;
//        third->RightHeight = third->right->depth() + 1;
//        third->childrenNumber += higher->MyfailmyNumer() + lower->MyfailmyNumer();
//
//
//    }
//    Node* findfrom(int target, Node* froot, int change = 0)
//    {
//    Refind:
//        if (froot->data == target)return froot;
//        froot->childrenNumber += change;
//        if (target < froot->data)
//        {
//            if (froot->left == 0)return froot;
//            froot = froot->left;
//            goto Refind;
//        }
//        else
//        {
//            if (froot->right == 0)return froot;
//            froot = froot->right;
//            goto Refind;
//        }
//    }
//    Node* find(int target)
//    {
//        return findfrom(target, root);
//    };
//
//
//    enum PrintProperty
//    {
//        Data, Height, SIze
//    };
//    void printSubtree(Node* subtree, int depth,
//        int level, bool first, PrintProperty pp = Data) {
//        if (depth > 0) {
//            if (subtree == nullptr) {
//                printSubtree(subtree, depth - 1, level, first);
//                printSubtree(subtree, depth - 1, level, false);
//            }
//            else {
//                printSubtree(subtree->left, depth - 1,
//                    level, first, pp);
//                printSubtree(subtree->right, depth - 1,
//                    level, false, pp);
//            }
//        }
//        else if (subtree == nullptr)
//            std::cout << std::setw((first) ?
//                spacing(level) / 2 : spacing(level)) << "-";
//
//        // Otherwise, we have a live element so display
//        // it. Once more, use half spacing for the
//        // leftmost element.
//        else
//        {
//            string con;
//            if (pp == Data)con = to_string(subtree->data) + "*" + to_string(subtree->spys);
//            if (pp == Height)con = to_string(subtree->leftHeight) + "," + to_string(subtree->RightHeight);
//            if (pp == SIze)con = to_string(subtree->childrenNumber);
//
//            std::cout << std::setw((first) ?
//                spacing(level) / 2 : spacing(level)) << con;
//        }
//    } // printSubtree
//    void print(PrintProperty pp = Data)
//    {
//        int max = root->depth();
//        for (int depth = 0; depth <= max; depth++) {
//            printSubtree(root, depth, max - depth + 1, true, pp);
//            std::cout << std::endl;
//        } // for
//    };
//    void UpdateHeight(Node* pivot)
//    {
//        for (auto lt = pivot;lt;lt = lt->parent)
//        {
//            lt->leftHeight = 0;
//            if (lt->left)
//            {
//                lt->leftHeight = lt->left->depth() + 1;
//            }
//            lt->RightHeight = 0;
//            if (lt->right)
//            {
//                lt->RightHeight = lt->right->depth() + 1;
//            }
//        }
//    };
//    void ReBalanceFrom(Node* pivot, bool onlyBalOnece = false)
//    {
//        NodeDire traceDir;
//        for (auto lt = pivot;lt;lt = lt->parent)
//        {
//            if (lt->direction == LeftChild)
//            {
//                lt->parent->leftHeight = lt->depth() + 1; /*max(max(lt->leftHeight, lt->RightHeight) + 1, lt->parent->leftHeight);*/
//                if (lt->parent->leftHeight - lt->parent->RightHeight > 1)//左边太高了
//                {
//                    if (traceDir == LeftChild)
//                        ReOrgnizeCase1(lt, lt->parent);
//                    else
//                        ReOrgnizeCase2(lt, lt->parent, traceDir);
//                }
//                traceDir = LeftChild;
//            }
//            if (lt->direction == RightChild)
//            {
//                lt->parent->RightHeight = max(max(lt->leftHeight, lt->RightHeight) + 1, lt->parent->RightHeight);
//                if (lt->parent->RightHeight - lt->parent->leftHeight > 1)//右边太高了
//                {
//                    if (traceDir == RightChild)
//                        ReOrgnizeCase1(lt, lt->parent);
//                    else
//                        ReOrgnizeCase2(lt, lt->parent, traceDir);
//                }
//                traceDir = RightChild;
//
//            }
//        }
//        while (root->parent)
//            root = root->parent;
//    };
//
//    void DelReBalanceFrom(Node* pivot, bool onlyBalOnece = false, bool Dobalance = true)
//    {
//        NodeDire traceDir = Root;
//        for (auto lt = pivot;lt;lt = lt->parent)
//        {
//            lt->leftHeight = 0;
//            if (lt->left)
//            {
//                lt->leftHeight = lt->left->depth() + 1;
//            }
//            lt->RightHeight = 0;
//            if (lt->right)
//            {
//                lt->RightHeight = lt->right->depth() + 1;
//            }
//            if (Dobalance)
//            {
//                if (lt->leftHeight - lt->RightHeight > 1)//左边太高了
//                {
//                    auto lower = lt->left;
//                    if (lower->leftHeight >= lower->RightHeight)
//                        ReOrgnizeCase1(lower, lt);
//                    else
//                        ReOrgnizeCase2(lower, lt, RightChild);
//                }
//                if (lt->RightHeight - lt->leftHeight > 1)//右边太高了
//                {
//                    auto lower = lt->right;
//                    if (lower->RightHeight >= lower->leftHeight)
//                        ReOrgnizeCase1(lower, lt);
//                    else
//                        ReOrgnizeCase2(lower, lt, LeftChild);
//                }
//            }
//
//        }
//        while (root->parent)
//            root = root->parent;
//    };
//    void insert(int v) {
//        nodeNumber++;
//        if (root == nullptr)
//        {
//            root = new Node(v, 0, Root);
//            return;
//        }
//        Node* pivot = findfrom(v, root, 1);
//        if (pivot->data == v)
//        {
//            pivot->spys++;
//            return;
//        }
//        if (v < pivot->data)
//        {
//            pivot = pivot->left = new Node(v, pivot, LeftChild);
//            //pivot = pivot->left;
//
//        }
//        if (v > pivot->data)
//            pivot = pivot->right = new Node(v, pivot, RightChild);
//
//        //插入完毕，更新height
//        //ReBalanceFrom(pivot, true);
//        //更新NM
//
//
//    };
//    void DeleteEmptyNode(Node* pivot)
//    {
//        if (pivot->direction == Root)
//        {
//            root = nullptr;
//            delete pivot;
//            return;
//        }
//        pivot->parent->childrenNumber -= pivot->spys;
//        if (pivot->direction == LeftChild)
//        {
//            pivot->parent->left = 0;
//            pivot->parent->leftHeight = 0;
//        }
//        if (pivot->direction == RightChild)
//        {
//            pivot->parent->right = 0;
//            pivot->parent->RightHeight = 0;
//        }
//        delete pivot;
//
//    };
//    void remove(int v, bool reblance = true) {
//        if (reblance)
//            nodeNumber--;
//        Node* pivot = findfrom(v, root, -1);
//        if (pivot->data != v)fuck();
//        pivot->spys--;
//        if (pivot->spys == 0)
//        {
//            auto reblancepoint = pivot->parent;
//
//            if (!pivot->left && !pivot->right)
//                DeleteEmptyNode(pivot);
//            else if (!pivot->left)
//            {
//                if (pivot->direction == Root)
//                    root = pivot->right;
//                else
//                    GiveChild(pivot->right, pivot->parent, pivot->direction);
//                delete pivot;
//            }
//            else if (!pivot->right)
//            {
//                if (pivot->direction == Root)
//                    root = pivot->left;
//                else
//                    GiveChild(pivot->left, pivot->parent, pivot->direction);
//                delete pivot;
//            }
//            else
//            {
//                findfrom(v, root, 1);
//                Node* tool = findfrom(v, pivot->left);
//                auto toolspys = tool->spys;
//
//                reblancepoint = tool->parent;
//                auto replacedata = tool->data;
//                for (size_t i = 0; i < toolspys; i++)
//                {
//                    remove(replacedata, false);
//                }
//
//
//                pivot->data = replacedata;
//                pivot->spys = 1;
//                int curr = nodeNumber;
//                for (size_t i = 0; i < toolspys - 1; i++)
//                {
//                    insert(replacedata);
//                }
//                nodeNumber = curr;
//
//            }
//            /*   if (reblance && reblancepoint)
//                   DelReBalanceFrom(reblancepoint, false, reblance);*/
//        }
//
//    };
//
//    int leftsizeOf(Node* root)
//    {
//        return root->left ? root->left->MyfailmyNumer() : 0;
//    };
//    int kth(int k) {
//    Re:
//        int myrank = 0;
//        Node* pivot = root;
//        bool haveLeft = false;
//        while (true)
//        {
//            if (!pivot)
//            {
//                k--;
//                goto Re;
//            }
//            //if (myrank > k)return pivot->parent->data;
//            auto leftsize = leftsizeOf(pivot);
//            if (myrank + leftsize == k)return pivot->data;
//            if (myrank + leftsize > k)//应该往左边走
//            {
//                pivot = pivot->left;
//                haveLeft = true;
//            }
//            else
//            {
//                myrank += pivot->spys + leftsize;
//
//                if (!pivot->right && haveLeft == false)
//                {
//                    return pivot->data;
//                }
//                pivot = pivot->right;
//
//            }
//        }
//
//    };
//    int rank(int v)
//    {
//        int rank = 0;
//        Node* froot = root;
//    Refind:
//        if (froot->data == v)return rank += leftsizeOf(froot);
//        if (v < froot->data)
//        {
//            if (froot->left == nullptr)return rank;
//            froot = froot->left;
//            goto Refind;
//        }
//        else
//        {
//            rank += froot->spys + leftsizeOf(froot);
//            if (froot->right == nullptr)return rank;
//            froot = froot->right;
//            goto Refind;
//        }
//
//    };
//    int size() {
//        if (nodeNumber != root->MyfailmyNumer())assert(false);
//        return nodeNumber;
//    };
//
//    Node* root = nullptr;
//};
//#endif // !STAND
//
//
//
//#pragma region Given
//
///* PLEASE DO NOT CHANGE BELOW*/
//int A, B, C, lfsr;
//double P[4][4];
//int lfsr_generator() {
//    auto ret = lfsr;
//    return (lfsr ^= lfsr << 13, lfsr ^= lfsr >> 17, lfsr ^= lfsr << 5, ret);
//}
//tuple<int, int> command() {
//    auto imm = lfsr_generator();
//    static int state = 0;
//    auto p = double(lfsr_generator() & 0x7fffffff) / INT32_MAX;
//    for (int i = 0; i < 4; i++)
//        if ((p -= P[state % 4][i]) < 0) {
//            state += 4 - state % 4 + i;
//            break;
//        }
//    return tuple<int, int>(state % 4, (imm * A + state * B + C) & 0x7fffffff);
//}
///* PLEASE DO NOT CHANGE ABOVE*/
//
//#pragma endregion
//int main() {
//    AVL tree;
//    int m;
//#ifndef DEBUG
//    cin >> m >> lfsr >> A >> B >> C;
//    for (int i = 0; i < 4; i++)
//        for (int j = 0; j < 4; j++) cin >> P[i][j];
//    //fuck();
//    if (B != 2)fuck();
//    return 0;
//    //clock_t start, end;
//    //start = clock();
//    //while (1)
//    //{
//    //    end = clock();
//    //    if ((double)(end - start) / CLOCKS_PER_SEC > 1)fuck();
//    //}
//#endif // !DEBUG
//#ifdef DEBUG
//    m = 10;lfsr = 123;A = 1;B = 2;C = 3;
//    P[0][0] = P[0][1] = P[0][2] = P[0][3] = .25;
//    P[1][0] = 1;P[1][1] = P[1][2] = P[1][3] = 0;
//    P[2][0] = 1;P[2][1] = P[2][2] = P[2][3] = 0;
//    P[3][0] = 1;P[3][1] = P[3][2] = P[3][3] = 0;
//
//    //tree.insert(4);
//    //tree.insert(4);
//    //tree.print();
//    ////cout << tree.kth(4000000);
//    //tree.insert(1);
//    //tree.insert(2);
//    //tree.insert(3);
//    //tree.insert(1);
//    //tree.insert(2);
//    //tree.insert(6);
//    //tree.insert(1);
//    //tree.insert(2);
//    //tree.insert(3);
//    //tree.insert(9);
//    //tree.insert(10);
//    //tree.insert(5);
//    //tree.print();
//    //tree.print(tree.SIze);
//    //int a = tree.size();
//    //tree.remove(9);
//    //tree.print();
//    //tree.print(tree.SIze);
//    //tree.size();
//
//    //tree.remove(5);
//    //tree.print();
//    //tree.print(tree.SIze);
//
//#endif // DEBUG
//    int tans = 0;
//
//    for (int i = 1; i <= m; i++)
//    {
//        int op, imm;
//        tie(op, imm) = command();
//
//        if (op == 0)
//        {
//            tree.insert(imm);
//#ifdef DEBUG
//            cout << "insert: " << imm << endl;
//#endif // DEBUG
//        }
//        if (op == 1)
//        {
//            auto re = tree.kth(imm % tree.size());
//            tree.remove(re);
//#ifdef DEBUG
//            cout << "Remove: " << re << endl;
//#endif // DEBUG
//
//        }
//        if (op == 2)
//        {
//            auto rank = tree.rank(imm);
//            tans ^= rank;
//#ifdef DEBUG
//            cout << "Rank  " << imm << " : " << rank << endl;
//#endif // DEBUG
//
//        }
//        if (op == 3)
//        {
//            auto  re = imm % tree.size();
//            auto kth = tree.kth(re);
//            tans ^= kth;
//
//#ifdef DEBUG
//            cout << "kth  " << re << " : " << kth << endl;
//
//#endif // DEBUG
//
//        }
//        tree.size();
//#ifdef DEBUG
//        cout << "Tree size:" << tree.size() << endl;
//        tree.print();
//        tree.print(tree.Height);
//        tree.print(tree.SIze);
//        cout << "==================" << endl;
//
//#endif // DEBUG
//
//    }
//    cout << tans << "\n";
//}