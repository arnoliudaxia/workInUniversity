#include "vector"
#include <iostream>
#include <assert.h>

#define USEEDSTD
#define DEBUG

#ifdef DEBUG
#endif
using namespace std;


class State
{
public:
	State(int name, int party) :myname(name), myparty(party) {};
	~State();

	int myname;
	int myparty;
	vector<State*> SameParty;
	vector<State*> DiffParty;
};


State::~State()
{
}
bool CheckMyEnemy(State& state, State* exception)
{
	if (state.DiffParty.size() > 1)
	{
		//这个联邦有直接的敌人
		return false;
	}
	if ((state.DiffParty.size() == 1))
	{
		//这个联邦只有一个敌人，但它不是总统切断的那个
		if (state.DiffParty[0]->myname != exception->myname)return false;

	}
	for (auto fs : state.SameParty)
	{
		if (fs->myname == exception->myname)continue;
		if (!CheckMyEnemy(*fs, &state))return false;
	}
	return true;
}
int main2() {


	int states = 0, peace = 0, enermyCount = 0;
	//Read Data phrase
	cin >> states;
	//vector<State> States;
	int* supportTable = new int[states];
	//初始化States同时把每个support也给赋值了
	//for (int i = 0; i < states; i++) {
	//	int support;
	//	cin >> support;
	//	States.push_back(State(i + 1, support));
	//}
	for (int i = 0; i < states; i++) {
		int support;
		cin >> support;
		supportTable[i] = support;
	}
	//每个联邦的关系都缕清一下
	for (int i = 0; i < states - 1; i++) {
		int a, b;
		cin >> a >> b;
		//State& A = States[a - 1];
		//State& B = States[b - 1];
		int Ap = supportTable[a - 1];
		int Bp = supportTable[b - 1];
		if (!(Bp == 0 || Ap == 0 || Ap == Bp))enermyCount++;
		//if (B.myparty == 0 || A.myparty == 0 || A.myparty == B.myparty)
		//{
		//	A.SameParty.push_back(&B);
		//	B.SameParty.push_back(&A);
		//}
		//else
		//{
		//	A.DiffParty.push_back(&B);
		//	B.DiffParty.push_back(&A);
		//	enermyCount++;
		//}
	}

	if (enermyCount > 1)
	{
		peace = 0;
		goto END;
	}
	if (enermyCount == 1)
	{
		peace = 2;
		goto END;
	}
	if (enermyCount == 0) {
		peace = (states - 1) * 2;
		goto END;
	}
	//Data process phrase
	//Yes the question actually doesn't need any loop
	//for (auto st : States)
	//{
	//	for (auto firend : st.SameParty)
	//	{
	//		if (CheckMyEnemy(st, firend)&&CheckMyEnemy(*firend,&st))
	//		{
	//			peace++;
	//			//cout << "cut:" << st.myname << "--" << firend->myname << endl;
	//		}
	//	}
	//	for (auto enemy : st.DiffParty)
	//	{
	//		if (CheckMyEnemy(st, enemy)&&CheckMyEnemy(*enemy,&st))
	//		{
	//			peace++;
	//			//cout << "cut:" << st.myname << "--" << enemy->myname << endl;
	//		}

	//	}
	//}


END:
	cout << peace / 2 << endl;

	return 0;
}