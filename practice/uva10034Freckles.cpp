/* 10034 - Freckles */

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 100;

double x[MAX+10], y[MAX+10];
int V[MAX+10];
struct Etype {
    int u, v;
    double w;
} E[MAX*MAX+10];


// Disjoint set data structure BEGIN
int p[MAX];
int rnk[MAX];

void make_set(int x) {
	p[x] = x;
	rnk[x] = 0;
}

int find_set(int x) {
    if (x != p[x])
        p[x] = find_set(p[x]);
    return p[x];
}

void make_link(int x, int y) {
    if (rnk[x] > rnk[y])
        p[y] = x;
    else {
        p[x] = y;
        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
}

void make_union(int x, int y) {
    make_link(find_set(x), find_set(y));
}
// Disjoint set data structure END

bool cmp (Etype e1, Etype e2) {
    return e1.w < e2.w;
    /*if (e1.w > e2.w)
        return false;
    return true;*/
}

double kruskal(int nv, int ne) {
    int i;
    sort(E, E+ne, cmp);

    for (i = 0; i < nv; i++)
        make_set(i);

    double len = 0;
    for(i = 0; i < ne; i++) {
        if (find_set(E[i].u) != find_set(E[i].v)) {
            len += E[i].w;
            make_union(E[i].u, E[i].v);
        }
    }
    return len;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("10034.in", "r", stdin);
	freopen("10034.out", "w", stdout);
#endif
	int kase, i, j, nv, ne;

	scanf("%d", &kase);

	while (kase)
    {
		scanf("%d", &nv);
		for (i = 0 ; i < nv; i++)
			scanf("%lf%lf", &x[i], &y[i]);

        // calculating edge weight
        ne = 0;
        for (i = 0 ; i < nv; i++) {
            for (j = i+1; j < nv; j++)
            {
                E[ne].u = i;
                E[ne].v = j;
                E[ne].w = sqrt ( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) );
                ne++;
            }
        }

        double len = kruskal(nv, ne);
        printf("%.2f\n", len);

        if (--kase)
            printf("\n");
    }

	return 0;
}
