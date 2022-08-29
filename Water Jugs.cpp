#include <bits/stdc++.h>
using namespace std;
#define Max 901

int a,b,c;
bool ans = false  ;
bool visited[Max][Max];

struct Node {
	int x,y;
	int dis;
	Node(int _x, int _y,int _dis){
		x = _x;
		y = _y;
		dis = _dis;
	}
};

bool check(int x, int y) {
	if(x > a || y > b || x < 0 || y < 0) return false;
	if(visited[x][y] == true){
		return false;
	}
	return true;
}

void input() {
	cin >> a >> b >> c;
	for(int i = 0; i <= a; i++) {
		for(int j = 0; j <= b; j++) {
			visited[i][j] = false;
		}
	}
}
void Solve() {
	queue < Node > Q;
	Node tmp  = Node(0,0,0);
	visited[0][0] = true;
	Q.push(tmp);
	while(!Q.empty()){
		Node rs = Q.back();
		Q.pop();
		if(rs.x == c || rs.y == c) {
			cout << rs.dis;
			ans = true;
			break;
		}else {
			
			if(check(0,rs.y)) {
				Node cmp = Node(0,rs.y,rs.dis + 1);
				Q.push(cmp);
				visited[cmp.x][cmp.y] = true;
				cout <<"cmp.x = " << cmp.x << " cmp.y = " << cmp.y << "cmp.dis=" << cmp.dis << endl;
			}
				
			if(check(rs.x,0)) {
				Node cmp = Node(rs.x,0,rs.dis + 1);
				Q.push(cmp);
				visited[cmp.x][cmp.y] = true;
				cout <<"cmp.x = " << cmp.x << " cmp.y = " << cmp.y << "cmp.dis=" << cmp.dis << endl;
			}
			
			if(check(a,rs.y)) {
				Node cmp = Node(a,rs.y,rs.dis + 1);
				Q.push(cmp);
				visited[cmp.x][cmp.y] = true;
				cout <<"cmp.x = " << cmp.x << " cmp.y = " << cmp.y << "cmp.dis=" << cmp.dis << endl;
			}
			
			if(check(rs.x,b)) {
				Node cmp = Node(rs.x,b,rs.dis + 1);
				Q.push(cmp);
				visited[cmp.x][cmp.y] = true;
				cout <<"cmp.x = " << cmp.x << " cmp.y = " << cmp.y << "cmp.dis=" << cmp.dis << endl;
			}
				
			if(check(0,rs.x + rs.y)) {
				Node cmp = Node(0,rs.x + rs.y,rs.dis + 1);
				Q.push(cmp);
				visited[cmp.x][cmp.y] = true;
				cout <<"cmp.x = " << cmp.x << " cmp.y = " << cmp.y << "cmp.dis" << cmp.dis << endl;
			}
			
			if(check(rs.x + rs.y - b,b)) {
				Node cmp = Node(rs.x + rs.y - b, b,rs.dis + 1);
				Q.push(cmp);
				visited[cmp.x][cmp.y] = true;
				cout <<"cmp.x = " << cmp.x << " cmp.y = " << cmp.y << "cmp.dis=" << cmp.dis << endl;
			}
				
			if(check(rs.x + rs.y,0)) {
				Node cmp = Node(rs.x + rs.y,0,rs.dis + 1);
				Q.push(cmp);
				visited[cmp.x][cmp.y] = true;
				cout <<"cmp.x = " << cmp.x << " cmp.y = " << cmp.y << "cmp.dis=" << cmp.dis << endl;
			}
				
			if(check(a,rs.x + rs.y - a)) {
				Node cmp = Node(a,rs.x + rs.y - a,rs.dis + 1);
				Q.push(cmp);
				visited[cmp.x][cmp.y] = true;
				cout <<"cmp.x = " << cmp.x << " cmp.y = " << cmp.y << "cmp.dis=" << cmp.dis << endl;
			}
			
		}
		
	}
	if(ans == false) {
		cout << -1;
	}
}

int main() {
	input();
	Solve();
	return 0;
}