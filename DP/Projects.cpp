#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
 
int main() {

    struct project {
		int startDate = 0;
		int endDate = 0;
		int reward = 0;
	};

	int n; cin >> n;
	vector <project> projects (n + 1);
	
    for (int i = 1; i <= n; i++) {
		cin >> projects[i].startDate >> projects[i].endDate >> projects[i].reward;
	}
	
	sort(projects.begin() + 1, projects.end(), [](const project &p1, const project &p2) {
		return p1.startDate < p2.startDate;
	});
 
	vector <int> strtDate (n + 1);
    
	for (int i = 1; i <= n; i++) {
		strtDate[i] = projects[i].startDate;
	}
 
	vector <ll> maxMoney (n + 2, 0);
    
	for (int i = n; i >= 1; i--) {
		int j = distance(strtDate.begin(), upper_bound(strtDate.begin(), strtDate.end(), projects[i].endDate)) ;
		maxMoney[i] = max(maxMoney[i + 1], maxMoney[j] + projects[i].reward);
	}
 
	cout << maxMoney[1] << "\n";
 
    return 0;
}