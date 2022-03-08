#include "vector"
#include <iostream>
#include <assert.h>


using namespace std;

int main1() {


	int states = 0, peace = 0, enermyCount = 0;
	//Read Data phrase
	cin >> states;
	//vector<State> States;
	int* supportTable = new int[states];

	for (int i = 0; i < states; i++) {
		int support;
		cin >> support;
		supportTable[i] = support;
	}
	//每个联邦的关系都缕清一下
	for (int i = 0; i < states - 1; i++) {
		int a, b;
		cin >> a >> b;

		int Ap = supportTable[a - 1];
		int Bp = supportTable[b - 1];
		if (!(Bp == 0 || Ap == 0 || Ap == Bp))enermyCount++;
	}

	if (enermyCount > 1)peace = 0;
	if (enermyCount == 1)peace = 1;
	if (enermyCount == 0)
		peace = (states - 1);


END:
	cout << peace << endl;

	return 0;
}