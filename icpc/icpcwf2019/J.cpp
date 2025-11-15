#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

const int MAXP = 505;
const int MAXH = 50;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plp;
typedef pair<pll, plp> ppp;

struct line {
  ll m, c, start, end;
  
  void printstr() {
    printf("line: %lld %lld %lld %lld\n", m, c, start, end);
  }
};

int p, h;
int score[MAXP][MAXH];
map<int, int> freq[MAXP];

double intersect(line, line);
vector<pll> event_player;

int main() {
  scanf("%d %d", &p, &h);
  for(int i = 0; i < p; i++) {
    for(int j = 0; j < h; j++) {
      scanf("%d", &score[i][j]);
      freq[i][score[i][j]] += 1;
    }
  }

  for(int i = 0; i < p; i++) {
    event_player.clear();
    auto generate_line = [&] (int player) {
      vector<line> v;
      v.push_back({h, 0, 0, freq[player].begin()->first});
      ll sub = 0, c = 0;
      for(auto event = freq[player].begin(); event != freq[player].end(); event++) {
        ll x = event->first;
        ll how_many = event->second;
        sub += how_many;
        c += x * how_many; 

        ll end = 1e15;
        auto it = next(event);
        if (it != freq[player].end()) {
          end = it->first;
        }

        v.push_back({h - sub, c, event->first, end});
      }
      return v;
    };
    vector<line> player1 = generate_line(i);

    // for(line x: player1) {
    //   printf("%lld %lld %lld %lld\n", x.m, x.c, x.start, x.end);
    // }

    for(int j = 0; j < p; j++) {
      if (j == i) continue;
      vector<line> player2 = generate_line(j);
      int ptr = 0;
      vector<double> intersections;
      intersections.push_back(0);
      for(int k = 0; k < (int)player1.size();) {
        line l = player1[k];
        while(ptr < player2.size() && player2[ptr].end < l.start) {
          ptr++;
        }
        if (l.end < player2[ptr].start) {
          k++;
          continue;
        }
        // printf("intersect %d[%d] and %d[%d]\n", i, k, j, ptr);        
        double x = intersect(l, player2[ptr]);
        // printf("got: %lf\n", x);
        if (fabs(x+1) < EPS) {
          
        } else if (fabs(x-intersections.back()) < EPS) {
          
        } else {
          intersections.push_back(x);
        }
        if (ptr == player2.size()-1 && k == player1.size()-1) break;
        if (l.end < player2[ptr].end) {
          k++;
        } else {
          ptr++;
        }
      }

      intersections.push_back(1e15);

      // bikin segmen
      int ptr1 = 0, ptr2 = 0;
      for (int k = 0; k < (int)intersections.size()-1; k++) {
        double l = intersections[k];
        double r = intersections[k+1];
        double c = (l+r)/2;
        // printf("lrc: %lf %lf %lf\n", l, r, c);
        while(player1[ptr1].end < c) ptr1++;
        while(player2[ptr2].end < c) ptr2++;
        // printf("checking %d[%d] and %d[%d]\n", i, ptr1, j, ptr2);
        double y1 = player1[ptr1].m * c + player1[ptr1].c;
        double y2 = player2[ptr2].m * c + player2[ptr2].c;
        if (y1 < y2 - EPS) {
          // printf("pushing %lf %lf\n", l, r);
          event_player.push_back({ceil(l+EPS), 1});
          event_player.push_back({floor(r-EPS), -1});
        }
      }
    }
    
    sort(event_player.begin(), event_player.end(), [&] (pll a, pll b) {
      if (a.first == b.first) return a.second > b.second;
      return a.first < b.first;
    });
    int curr = 0;
    int ans = p;
    for (auto event : event_player) {
      // printf("event: %lld %lld\n", event.first, event.second);
      curr += event.second;
      ans = min(ans, p-curr);
    }
    printf("%d\n", ans);
  }

  return 0;
}

// -1 not intersect
double intersect(line a, line b) {
  // a.printstr(); b.printstr();
    if (a.m == b.m) {
        return -1;
    }
    /*
        y = a.m * x + a.c = b.m * x + b.c
        x = (b.c - a.c) / (a.m - b.m)
    */
    double x = (double)(b.c - a.c) / (a.m - b.m);
    ll start = max(a.start, b.start);
    ll end = min(a.end, b.end);

    assert(start <= end);

    if (x < start || x > end) {
        return -1;
    }
    return x;
}