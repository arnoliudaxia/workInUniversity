//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <set>
//#include <map>
//#include<time.h>
//#include <string>
//#include <cassert>
////#define DEBUG
//
//
//using namespace std;
//static map<string, int>table;
//
//int kgcd(int a, int b) {
//	string se = to_string(min(a, b)) + "," + to_string(max(a, b));
//	auto cc = table.find(se);
//	if (cc != table.end())return cc->second;
//	if (b <= 0)return a;
//	else
//	{
//		int result = kgcd(b, a % b);
//		table.insert(pair<string, int>(se, result));
//		return result;
//	}
//
//	//return b > 0 ? gcd(b, a % b) : a;
//}
//int gcd(int a, int b) {
//	//string se = to_string(min(a, b)) + "," + to_string(max(a, b));
//	//auto cc = table.find(se);
//	//if (cc != table.end())return cc->second;
//	int s = 1, c;
//	while (a && b) {
//		if ((~a & 1) && (~b & 1))
//			a >>= 1, b >>= 1, s <<= 1;
//		else if (~a & 1)a >>= 1;
//		else if (~b & 1)b >>= 1;
//		else if (a > b)a = a - b;
//		else c = b - a, b = a, a = c;
//	}
//	int re;
//	if (!a)re = b * s;
//	if (!b)re = a * s;
//	//table.insert(pair<string, int>(se, re));
//	return re;
//}
////int gcd(int a,int b)
////{
////	return b > 0 ? gcd(b, a % b) : a;
////
////}
//int bondGCD(int a, int b, int c)
//{
//#ifdef DEBUG
//	printf_s("GCD:%d\t%d\t%d\n", a, b, c);
//#endif // DEBUG
//
//	return gcd(abs(a - b), abs(b - c));
//}
//vector<int> factors(int gcd, vector<int>& primes)
//{
//	vector<int> temp;
//	for (auto p : primes)
//	{
//		if (p > gcd)break;
//		if (gcd % p == 0)temp.push_back(p);
//	}
//	return move(temp);
//}
//static vector<vector<int>>trace;
//int findsameModWithYu(vector<int>::iterator iter, int mod, int yushu, vector<int>::iterator end)
//{
//	int result = 1;
//	while ((iter++, iter != end))
//	{
//		if (*iter % mod != yushu)return result;
//		result++;
//	}
//	return result;
//}
//int findsameModWithYuReverse(vector<int>::iterator iter, int mod, int yushu, vector<int>::iterator end)
//{
//	int result = 1;
//	while ((iter--, iter != end))
//	{
//		if (*iter % mod != yushu)return result;
//		result++;
//	}
//	return result + (*iter % mod == yushu);
//}
//int RegionShareMod(vector<int>::iterator begin, vector<int>::iterator last, vector<int>& primes)
//{
//	int maxsize = 0;
//	for (auto ptr = begin;ptr < last - 1;ptr++)
//	{
//		vector<int> myfactors;
//		myfactors = factors((abs(*ptr - *(ptr + 1))), primes);
//		for (auto fa : myfactors)
//		{
//			if (*ptr % fa != *(ptr + 1) % fa)continue;
//			maxsize = max(maxsize, findsameModWithYu(ptr, fa, *ptr % fa, last));
//		}
//
//	}
//	return maxsize;
//}
//int allShareMod(vector<int>::iterator begin, vector<int>::iterator last, vector<int>& primes)
//{
//	if (last - begin <= 10)
//	{
//		return RegionShareMod(begin, last, primes);
//	}
//	auto midpos = begin + (last - begin) / 2;
//	int leftmax = allShareMod(begin, midpos, primes);
//	int rightmax = allShareMod(midpos, last, primes);
//	int result = max(leftmax, rightmax);
//	vector<int> midfactors;
//	midfactors = factors((abs(*midpos - *(midpos - 1))), primes);
//	for (auto fa : midfactors)
//	{
//		if (*midpos % fa != *(midpos - 1) % fa)continue;
//		result = max(result, (findsameModWithYu(midpos, fa, *midpos % fa, last) + findsameModWithYuReverse(midpos - 1, fa, *midpos % fa, begin)));
//	}
//	return result;
//}
//int main()
//{
//	clock_t start, end;
//	start = clock();
//	static  vector<int>primes = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101, 103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197, 199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311, 313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431, 433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557, 563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661, 673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809, 811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937, 941,947,953,967,971,977,983,991,997,1009,1013,1019,1021,1031,1033,1039,1049, 1051,1061,1063,1069,1087,1091,1093,1097,1103,1109,1117,1123,1129,1151,1153, 1163,1171,1181,1187,1193,1201,1213,1217,1223,1229,1231,1237,1249,1259,1277, 1279,1283,1289,1291,1297,1301,1303,1307,1319,1321,1327,1361,1367,1373,1381, 1399,1409,1423,1427,1429,1433,1439,1447,1451,1453,1459,1471,1481,1483,1487, 1489,1493,1499,1511,1523,1531,1543,1549,1553,1559,1567,1571,1579,1583,1597, 1601,1607,1609,1613,1619,1621,1627,1637,1657,1663,1667,1669,1693,1697,1699, 1709,1721,1723,1733,1741,1747,1753,1759,1777,1783,1787,1789,1801,1811,1823, 1831,1847,1861,1867,1871,1873,1877,1879,1889,1901,1907,1913,1931,1933,1949, 1951,1973,1979,1987,1993,1997,1999 };
//
//	int testcases = 0;
//	//cin >> testcases;
//	scanf_s("%d", &testcases);
//	for (size_t testcase = 0; testcase < testcases; testcase++)
//	{
//		int maxsize = 0;
//
//		vector<int> Numbers;
//		int length;
//		//cin >> length;
//		scanf_s("%d", &length);
//
//		//Numbers填充
//		for (size_t person = 0; person < length; person++)
//		{
//			int temp;
//			//cin >> temp;
//			scanf_s("%d", &temp);
//
//			Numbers.push_back(temp);
//		}
//		if (length == 1)
//		{
//			cout << 1 << endl;
//			continue;
//		}
//
//		vector<vector<int>> padding;
//		set<int> possibleFactors;
//		padding.reserve(length - 2);
//		int maxnum = *max_element(Numbers.begin(), Numbers.end() - 1);
//
//#pragma region meiju
//
//		//int largest = 0;
//		//for (auto T : primes)
//		//{
//		//	cout<<endl<< T << "的最长同余子列长度"<<endl;
//		//	if (T > maxnum)break;
//		//	int thislongest = 0;
//		//	int lastMod = -1;
//		//	for (auto x : Numbers)
//		//	{
//		//		int mymode = x % T;
//		//		cout << mymode << "  ";
//		//		 if (mymode == lastMod)
//		//		{
//		//			thislongest++;
//		//		}
//		//		else
//		//		{
//		//			thislongest = 1;
//		//		}
//		//		lastMod = mymode;
//
//		//		largest = max(largest, thislongest);
//		//	}
//		//	//cout<<endl << T << "的最长同余子列长度为" << thislongest<<endl;
//		//}
//		//maxsize= largest;
//		//goto OUTPUTRE;
//#pragma endregion
//
//
//#pragma region 聪明一点点的便利
//		//for (auto ptr = Numbers.begin();ptr < Numbers.end() - 1;ptr++)
//		//{
//		//	vector<int> myfactors;
//		//	myfactors = factors((abs(*ptr - *(ptr + 1))), primes);
//		//	for (auto fa : myfactors)
//		//	{
//		//		if (*ptr % fa != *(ptr + 1) % fa)continue;
//		//		maxsize = max(maxsize, findsameModWithYu(ptr, fa, *ptr % fa, Numbers.end()));
//		//	}
//
//		//}
//		////if (maxsize != largest)assert(1 != 1);
//		//goto OUTPUTRE;
//#pragma endregion
//
//
//
//		maxsize = allShareMod(Numbers.begin(), Numbers.end(), primes);
//		//cout << "Result:\t" << maxsize << endl;
//		cout << maxsize << endl;
//	}
//	end = clock();
//	cout << "Time consume:" << (double)(end - start) / CLOCKS_PER_SEC;
//
//	return 0;
//}