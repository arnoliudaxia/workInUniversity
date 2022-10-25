//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <set>
//#include <map>
//#include<time.h>
//#include <string>
//#include <cassert>
//#include <queue>
//#include <climits>
//#include <stdio.h>
//#include<iostream>
//#include <stack>
////#define DEBUG
//#pragma warning(disable : 4996)
//
//using namespace std;
//
//class Edge
//{
//public:
//	Edge() {};
//	Edge(int v11, int v22) :v1(v11), v2(v22) {
//	};
//	int v1, v2;//规定v1<v2
//	int weight;
//
//};
//namespace cpluslinktable
//{
//	/// <summary>
//	/// A classic one direction Node 
//	/// </summary>
//	/// <typeparam name="DataType">the value type</typeparam>
//	template <class DataType = int>
//	class Node
//	{
//	public:
//		Node(DataType headdata) :data(headdata), next(nullptr) {}
//		DataType data;
//		Node* next;
//
//		Node& operator=(const Node innode)
//		{
//			this->data = innode.data;
//			this->next = innode.next;
//		}
//	};
//
//
//	/// <summary>
//	/// this a abstart manager of Nodes, the first node address is stored at HEAD var, the class also exposes some useful API
//	/// </summary>
//	/// <typeparam name="NodeType">Node or BiNode</typeparam>
//	template <class NodeType = Node<int>, class DataType = int>
//	class Linktable
//	{
//	public:
//		/// <summary>
//		///  Create a linktable with one node
//		/// </summary>
//		/// <param name="data">node valueֵ</param>
//		Linktable(DataType data) :HEAD(new Node<DataType>(data)), LAST(HEAD) {}
//		~Linktable()
//		{
//			if (HEAD)delete HEAD;
//		}
//
//		int size()
//		{
//			int count = 0;
//			for (Node<DataType>* p = this->HEAD;p != nullptr;p = p->next)count++;
//			return count;
//		}
//		/// <summary>
//		/// print the size of the linktable and each node info
//		/// </summary>
//		void logNodes()
//		{
//			std::cout << "The size of the linktable is:" << size() << "\n";
//			int i = 0;
//			for (auto p1 = this->HEAD; p1; p1 = p1->next) {
//				printf("link-%p-%p: value[%d] = %d\n", p1, p1->next, i++, p1->data);
//			}
//		}
//		/// <summary>
//		/// add a list of Nodes to the end of the linktable
//		/// </summary>
//		/// <param name="data"></param>
//		void addNode(std::initializer_list<DataType> datalist)
//		{
//			//先看一看最后再哪里
//			//Node<DataType>* last = this->HEAD;
//			//while (last->next) {
//			//	last = last->next;
//			//}
//			//把新的元素接到last->next
//			for (auto item : datalist)
//			{
//				Node<DataType>* p = new Node<DataType>(item);
//				LAST->next = p;
//				LAST = p;
//			}
//
//		}
//		/// <summary>
//		/// add one Node to the end of the linktable
//		/// </summary>
//		/// <param name="data"></param>
//		void addNode(DataType data) { addNode({ data }); }
//
//
//
//		/// <summary>
//		/// try to search a node with the value given , if not found ,return -1,if found, return index
//		/// </summary>
//		/// <param name="param"></param>
//		/// <returns></returns>
//		int search(DataType param)
//		{
//			int index = 0;
//			bool isFound = false;
//			for (Node<DataType>* p = this->HEAD; p; p = p->next) {
//				if (p->data == param) {
//					isFound = true;
//					break;
//				}
//				index++;
//			}
//			return isFound ? index : -1;
//		}
//
//		void merge(Linktable* other)
//		{
//			//先看一看最后再哪里
//			Node<DataType>* last = this->HEAD;
//			while (last->next) {
//				last = last->next;
//			}
//			last->next = other->HEAD;
//		}
//
//		NodeType* reverser(NodeType* head)
//		{
//			if (head->next == nullptr)return head;
//			NodeType* last = reverser(head->next);
//			head->next->next = head;
//			head->next = nullptr;
//			return last;
//		}
//		void reverse()
//		{
//			HEAD = reverser(HEAD);
//		}
//
//		NodeType* HEAD;
//		Node<DataType>* LAST;
//	};
//
//
//
//
//
//}
//
//
//bool whichisbig(const Edge& e1, const Edge& e2)
//{
//	return e1.weight > e2.weight;
//}
//bool iselementinSet(set<int>& input, int element)
//{
//	return input.find(element) != input.end();
//}
//
//void DFS(int city, int lengthNow, vector<int>& tag, vector<vector<Edge>>& cityedges, vector<vector<int>>& minRoads)
//{
//	tag[city] = 1;
//	for (auto& myneibour : cityedges[city])
//	{
//		int v1 = myneibour.v1;
//		int v2 = myneibour.v2;
//		if (tag[myneibour.v1] == 0)
//		{
//			tag[v1] = 1;
//			minRoads[city][v1] = lengthNow + myneibour.weight;
//			DFS(v1, lengthNow + myneibour.weight, tag, cityedges, minRoads);
//		}
//		if (tag[v2] == 0)
//		{
//			tag[v2] = 1;
//			minRoads[city][v2] = lengthNow + myneibour.weight;
//
//			DFS(v2, lengthNow + myneibour.weight, tag, cityedges, minRoads);
//
//		}
//	}
//}
//int main()
//{
//	using namespace cpluslinktable;
//	//读取数据
//	int cityNumber, relationNumber;
//	cin >> cityNumber >> relationNumber;
//	vector<int> firmness(cityNumber);
//	for (size_t i = 0; i < cityNumber; i++)
//	{
//		int fir;
//		cin >> fir;
//		firmness[i] = fir;
//	}
//	vector<Edge> edges(relationNumber);
//	vector<vector<Edge>> cityedges(cityNumber + 1);//真实索引
//
//	for (size_t i = 0; i < relationNumber; i++)
//	{
//		int v1, v2;
//		cin >> v1 >> v2;
//		edges[i] = move(Edge(v1, v2));
//		edges[i].weight = firmness[v1 - 1] + firmness[v2 - 1];
//		cityedges[v1].push_back(edges[i]);
//
//	}
//
//	//处理数据
//	sort(edges.begin(), edges.end(), whichisbig);
//	set<int> cityinMST;
//	vector<int>MST;
//	vector<Edge>MSTtree;
//
//	//求最小生成树，非常的easy啊，结果是MST数组的求和
//	for (auto line : edges)
//	{
//		if (iselementinSet(cityinMST, line.v1) && iselementinSet(cityinMST, line.v2))
//			continue;
//		MST.push_back(line.weight);
//		MSTtree.push_back(line);
//		cityinMST.insert(line.v1);
//		cityinMST.insert(line.v2);
//	}
//	cout << 1;
//	//plan B
//
//
//
//
//	return 0;
//}