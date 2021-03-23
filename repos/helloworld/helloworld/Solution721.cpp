#include "Solution721.h"
#include <set>
#include <map>

vector<vector<string>> Solution721::accountsMerge(vector<vector<string>>& accounts) {
	if (accounts.size() == 1) {
		return accounts;
	}
	int accounts_lens = accounts.size();
	multimap<string, set<string>> hashmap;
	multimap<string, set<string>> hashmap_backup;
	for (int i = 0; i < accounts_lens; i++) {
		if (!hashmap.count(accounts[i][0])) {
			set<string> emails;
			for (int j = 1; j < accounts_lens; j++) {
				emails.emplace(accounts[i][j]);
			}
			hashmap.emplace(accounts[i][0], emails);
		}
		else {
			bool flag = false;
			while (hashmap.count(accounts[i][0])) {
				string key = accounts[i][0];
				auto account = hashmap.find(key);
				hashmap_backup.emplace(key, account->second);
				set<string> temp_email;
				for (int j = 1; j < accounts_lens; j++) {
					temp_email.emplace(accounts[i][j]);
				}
				for (auto& email : temp_email) {
					if (account->second.count(email)) {
						account->second.insert(temp_email.begin(), temp_email.end());
						flag = true;
						break;
					}
				}
				hashmap.erase(account);
			}
			hashmap.insert(hashmap_backup.begin(), hashmap_backup.end());
			if (!flag) {
				set<string> temp_email;
				for (int j = 1; j < accounts_lens; j++) {
					temp_email.emplace(accounts[i][j]);
				}
				hashmap.emplace(accounts[i][0], temp_email);
			}
		}
	}
	vector<vector<string>> res;
	for (auto it = hashmap.begin(); it != hashmap.end(); it++) {
		vector<string> item;
		item.push_back(it->first);
		set<string> sec = it->second;
		for (auto it1 = sec.begin(); it1 != sec.end(); it1++) {
			item.push_back(*it1);
		}
		res.push_back(item);
	}
	return res;
}