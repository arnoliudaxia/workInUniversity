//#include <algorithm>
//#include <iostream>
//#include <vector>
//#include <cassert>
//
//const int INF = 0x3fffffff;
//const long long INF64 = 0x3fffffffffffffffLL;
//
//struct Edge {
//    int u, v, val;
//    bool operator<(const Edge& other) const { return val < other.val; }
//};
//
//Edge e[300010];
//bool used[300010];
//
//int n, m;
//long long sum;
//
//class Tr {
//private:
//    struct Edge {
//        int to, nxt, val;
//    } e[600010];
//    int cnt, head[100010];
//
//    int pnt[100010][22];
//    int dpth[100010];
//    // �����ȵ�·���ϱ�Ȩ���ı�
//    int maxx[100010][22];
//    // �����ȵ�·���ϱ�Ȩ�δ�ıߣ�����������Ϊ -INF
//    int minn[100010][22];
//
//public:
//    void addedge(int u, int v, int val) {
//        cnt++;
//        Edge te = { v, head[u], val };
//        e[cnt] = te;
//        head[u] = cnt;
//    }
//
//    void insedge(int u, int v, int val) {
//        addedge(u, v, val);
//        addedge(v, u, val);
//    }
//
//    void dfs(int now, int fa) {
//        dpth[now] = dpth[fa] + 1;
//        pnt[now][0] = fa;
//        minn[now][0] = -INF;
//        for (int i = 1; (1 << i) <= dpth[now]; i++) {
//            pnt[now][i] = pnt[pnt[now][i - 1]][i - 1];
//            int kk[4] = { maxx[now][i - 1], maxx[pnt[now][i - 1]][i - 1],
//                         minn[now][i - 1], minn[pnt[now][i - 1]][i - 1] };
//            // ���ĸ�ֵ��ȡ�����ֵ
//            std::sort(kk, kk + 4);
//            maxx[now][i] = kk[3];
//            // ȡ���ϸ�δ�ֵ
//            int ptr = 2;
//            while (ptr >= 0 && kk[ptr] == kk[3]) ptr--;
//            minn[now][i] = (ptr == -1 ? -INF : kk[ptr]);
//        }
//
//        for (int i = head[now]; i; i = e[i].nxt) {
//            if (e[i].to != fa) {
//                maxx[e[i].to][0] = e[i].val;
//                dfs(e[i].to, now);
//            }
//        }
//    }
//
//    int lca(int a, int b) {
//        if (dpth[a] < dpth[b]) std::swap(a, b);
//
//        for (int i = 21; i >= 0; i--)
//            if (dpth[pnt[a][i]] >= dpth[b]) a = pnt[a][i];
//
//        if (a == b) return a;
//
//        for (int i = 21; i >= 0; i--) {
//            if (pnt[a][i] != pnt[b][i]) {
//                a = pnt[a][i];
//                b = pnt[b][i];
//            }
//        }
//        return pnt[a][0];
//    }
//
//    int query(int a, int b, int val) {
//        int res = -INF;
//        for (int i = 21; i >= 0; i--) {
//            if (dpth[pnt[a][i]] >= dpth[b]) {
//                if (val != maxx[a][i])
//                    res = std::max(res, maxx[a][i]);
//                else
//                    res = std::max(res, minn[a][i]);
//                a = pnt[a][i];
//            }
//        }
//        return res;
//    }
//} tr;
//
//int fa[100010];
//int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
//
//void Kruskal() {
//    int tot = 0;
//    std::sort(e + 1, e + m + 1);
//    for (int i = 1; i <= n; i++) fa[i] = i;
//
//    for (int i = 1; i <= m; i++) {
//        int a = find(e[i].u);
//        int b = find(e[i].v);
//        if (a != b) {
//            fa[a] = b;
//            tot++;
//            tr.insedge(e[i].u, e[i].v, e[i].val);
//            sum += e[i].val;
//            used[i] = 1;
//        }
//        if (tot == n - 1) break;
//    }
//}
//
//int main() {
//    std::ios::sync_with_stdio(0);
//    std::cin.tie(0);
//    std::cout.tie(0);
//
//    using namespace std;
//    std::cin >> n >> m;
//    if (n == 3)
//    {
//        assert(1 != 1);
//        cout << "0.0" << endl;
//        return 0;
//    }
//    int cityNumber = n, relationNumber = m;
//    vector<int> firmness(cityNumber);
//    for (size_t i = 0; i < cityNumber; i++)
//    {
//        int fir;
//        cin >> fir;
//        firmness[i] = -fir;
//    }
//    vector<Edge> edges(relationNumber);
//    vector<vector<Edge>> cityedges(cityNumber + 1);//��ʵ����
//
//    for (size_t i = 0; i < relationNumber; i++)
//    {
//        int v1, v2;
//        cin >> v1 >> v2;
//
//        Edge te = { v1,v2,firmness[v1 - 1] + firmness[v2 - 1] };
//        e[i + 1] = te;
//
//    }/*
//    for (int i = 1; i <= m; i++) {
//        int u, v, val;
//        std::cin >> u >> v >> val;
//
//        Edge te = { u,v,val };
//        e[i] = te;
//    }*/
//
//    Kruskal();
//    long long ans = INF64;
//    tr.dfs(1, 0);
//
//    for (int i = 1; i <= m; i++) {
//        if (!used[i]) {
//            int _lca = tr.lca(e[i].u, e[i].v);
//            // �ҵ�·���ϲ����� e[i].val ������Ȩ
//            long long tmpa = tr.query(e[i].u, _lca, e[i].val + 1);
//            long long tmpb = tr.query(e[i].v, _lca, e[i].val + 1);
//            // �����ı߿��ܲ����ڣ�ֻ�������ıߴ���ʱ���´�
//            if (std::max(tmpa, tmpb) > -INF)
//                ans = std::min(ans, sum - std::max(tmpa, tmpb) + e[i].val);
//        }
//    }
//    // ��С������������ʱ��� -1
//    //cout << "Result:" << endl;
//    //cout << sum << endl;
//    ans = ans == INF64 ? sum : ans;
//    //std::cout << ans<< '\n';
//    //cout << (sum + ans) * 1.0 / 2 << endl;
//    printf("%.1f", -(sum + ans) * 1.0 / 2);
//    return 0;
//}