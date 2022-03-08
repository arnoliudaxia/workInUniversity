//
//class Pig
//{
//public:
//	Pig(int hun, int w) :hungry(hun), want(w) {};
//
//	int hungry, want;
//	//bool operator<(Pig& left, Pig& right)
//	//{
//
//	//};
//	bool operator<(const Pig& that)
//	{
//		return this->want < that.want;
//	};
//};
//void CheckForBetter(vector<Pig>& Pigs, vector<int> choice, int rest)
//{
//
//	int last = *choice.rbegin();
//	for (auto ch : choice)
//	{
//		if (Pigs[last + 1].want - Pigs[ch].want > rest)continue;
//		else
//		{
//			//有足够的钱给
//
//		}
//	}
//}
//bool NewPigWantIn(vector<Pig>& SPigs, Pig newpig, int& rest)
//{
//	bool result = false;
//	for (auto& p : SPigs)
//	{
//		if (newpig.want - p.want < rest)
//		{
//			//有足够的钱钱换各自
//			if (newpig.hungry > p.hungry)
//			{
//				//信鸽子更加饿一点
//				rest -= newpig.hungry - p.hungry;
//				p = newpig;
//				result = true;
//			}
//		}
//	}
//	return result;
//}
//bool sortPigByHungry(Pig& lp, Pig& rp)
//{
//	return lp.hungry < rp.hungry;
//}
//int main4() {
//
//
//	int feedPigs, pigs, money;
//	cin >> feedPigs >> pigs >> money;
//	vector<Pig> Pigs;
//	for (size_t i = 0; i < pigs; i++)
//	{
//		int hungry, want;
//		cin >> hungry >> want;
//		Pigs.push_back(Pig(hungry, want));
//	}
//	sort(Pigs.begin(), Pigs.end());
//	{
//		int sum = 0;
//		for (size_t i = 0; i < feedPigs; i++)
//		{
//			sum += Pigs[i].want;
//		}
//		if (sum > money)
//		{
//			cout << -1 << endl;
//		}
//	}
//	vector<Pig> BestPigs;
//	int rest = money;
//	for (size_t i = 0; i < feedPigs; i++)
//	{
//		BestPigs.push_back(Pigs[i]);
//		rest -= Pigs[i].want;
//	}
//	for (size_t i = feedPigs; i < pigs; i++)
//	{
//		NewPigWantIn(BestPigs, Pigs[i], rest);
//
//	}
//	bool flags = false;
//
//	do
//	{
//		flags = false;
//		for (auto pi : Pigs)
//		{
//			if (NewPigWantIn(BestPigs, pi, rest))
//			{
//				flags = true;
//			}
//
//		}
//	} while (flags);
//	sort(BestPigs.begin(), BestPigs.end(), sortPigByHungry);
//	cout << BestPigs[BestPigs.size() / 2].hungry << endl;
//	return 0;
//}