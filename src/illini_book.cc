#include "illini_book.hpp"

IlliniBook::IlliniBook(const std::string &people_fpath, const std::string &relations_fpath) {
    std::ifstream people(people_fpath);
    if (people.is_open()) {
        if (people.peek() == EOF) {
            throw std::runtime_error("file is empty");
        }
        while (people.good()) {
            int to_add = 0;
            people >> to_add;
            std::list<std::pair<int, std::string>> relats;
            book_.insert({to_add, relats});
        }
    }
    std::ifstream relations(relations_fpath);
    if (relations.is_open()) {
        if (relations.peek() == EOF) {
            throw std::runtime_error("file is empty");
        }
        while (relations.good()) {
            int key = 0;
            int value = 0;
            std::string relat;
            char comma = ' ';
            relations >> key;
            relations >> comma;
            relations >> value;
            relations >> comma;
            relations >> relat;
            std::pair<int, std::string> relat_1(value, relat);
            std::pair<int, std::string> relat_2(key, relat);
            book_.at(key).push_back(relat_1);
            book_.at(value).push_back(relat_2);
        }
    }
}

// IlliniBook::~IlliniBook() {

// }

bool IlliniBook::AreRelated(int uin_1, int uin_2) const {
    return GetRelated(uin_1, uin_2) != -1;
}

bool IlliniBook::AreRelated(int uin_1, int uin_2, const std::string &relationship) const {
    return GetRelated(uin_1, uin_2, relationship) != -1;
}

bool IlliniBook::AreRelatedHelper(int uin_1, int uin_2) const {
    for (const auto& entry : book_.at(uin_1)) {
        if (entry.first == uin_2) return true;
    }
    return false;
}
bool IlliniBook::AreRelatedHelper(int uin_1, int uin_2, const std::string &relationship) const {
    for (const auto& entry : book_.at(uin_1)) {
        if (entry.first == uin_2 && entry.second == relationship) return true;
    }
    return false;
}

// if (uin_1 == uin_2) return -1;
//     std::queue<std::pair<int, int>> q;
//     std::set<int> visited;
//     int count = 0;
// 	q.push({uin_1, 0});
//     visited.insert(uin_1);
// 	while (!q.empty()) {
// 		int curr = q.front().first;
//         int depth = q.front().second;
//         q.pop();
// 		if (AreRelatedHelper(curr, uin_2)) return depth;
// 		for (const std::map<int, std::string>& neighbor : book_.at(curr)) {
// 			for (auto const& [key, value] : neighbor) {
//                 std::string test = std::to_string(key);
//                 if (!visited.contains(key)) {
//                     q.push({key, depth + 1});
//                     visited.insert(key);
//                 }
//             }
// 		}
// 	}
// 	return -1;
// if (uin_1 == uin_2) return -1;
    // std::queue<int> q;
    // std::set<int> visited;
    // int count = 0;
	// q.push(uin_1);
    // visited.insert(uin_1);
	// while (!q.empty()) {
	// 	int curr = q.front();
    //     q.pop();
    //     count++;
	// 	if (AreRelatedHelper(curr, uin_2)) return count;
	// 	for (const std::map<int, std::string>& neighbor : book_.at(curr)) {
	// 		for (auto const& [key, value] : neighbor) {
    //             std::string test = std::to_string(key);
    //             if (!visited.contains(key)) {
    //                 q.push(key);
    //                 visited.insert(key);
    //             }
    //         }
	// 	}
	// }
	// return -1;
int IlliniBook::GetRelated(int uin_1, int uin_2) const {
    
if (uin_1 == uin_2) return -1;
    std::queue<std::pair<int, int>> q;
    std::set<int> visited;
	q.push({uin_1, 0});
    visited.insert(uin_1);
	while (!q.empty()) {
		int curr = q.front().first;
        int depth = q.front().second;
        q.pop();
		//if (AreRelatedHelper(curr, uin_2)) return depth + 1;
		for (const std::pair<int, std::string>& neighbor : book_.at(curr)) {
            if (neighbor.first == uin_2) return depth + 1;
            if (!visited.contains(neighbor.first)) {
                q.push({neighbor.first, depth + 1});
                visited.insert(neighbor.first);
            }
		}
	}
	return -1;
}
// if (uin_1 == uin_2) return -1;
    // std::queue<int> q;
    // std::set<int> visited;
    // int count = 0;
	// q.push(uin_1);
    // visited.insert(uin_1);
	// while (!q.empty()) {
	// 	int curr = q.front();
    //     q.pop();
    //     count++;
	// 	if (AreRelatedHelper(curr, uin_2, relationship)) return count;
	// 	for (const std::map<int, std::string>& neighbor : book_.at(uin_1)) {
	// 		for (auto const& [key, value] : neighbor) {
    //             if (!visited.contains(key) && value == relationship) {
    //                 q.push(key);
    //                 visited.insert(key);
    //             }
    //         }
	// 	}
	// }
	// return -1;
int IlliniBook::GetRelated(int uin_1, int uin_2, const std::string &relationship) const {
    
    if (uin_1 == uin_2) return -1;
    std::queue<std::pair<int, int>> q;
    std::set<int> visited;
	q.push({uin_1, 0});
    visited.insert(uin_1);
	while (!q.empty()) {
		int curr = q.front().first;
        int depth = q.front().second;
        q.pop();
		//if (AreRelatedHelper(curr, uin_2, relationship)) return depth + 1;
		for (const std::pair<int, std::string>& neighbor : book_.at(curr)) {
            if (neighbor.first == uin_2 && neighbor.second == relationship) return depth + 1;
            if (!visited.contains(neighbor.first) && neighbor.second == relationship)  { // may wanna look at relat check
                q.push({neighbor.first, depth + 1});
                visited.insert(neighbor.first);
            }
		}
	}
	return -1;
}
std::vector<int> IlliniBook::GetSteps(int uin, int n) const {
    
    // for (auto const& [key, value] : book_) {
    //     if (GetRelated(uin, key) == n) {
    //         to_return.push_back(key);
    //     }
    // }
    // return to_return;
    std::vector<int> to_return;
    std::queue<std::pair<int, int>> q;
    std::set<int> visited;
    q.push({uin, 0});
    visited.insert(uin);
    while (!q.empty()) {
	int curr = q.front().first;
    int depth = q.front().second;
    if (depth == n) to_return.push_back(curr);
    q.pop();
	//if (AreRelatedHelper(curr, uin_2)) return depth + 1;
        for (const std::pair<int, std::string>& neighbor : book_.at(curr)) {
            if (!visited.contains(neighbor.first)) {
                q.push({neighbor.first, depth + 1});
                visited.insert(neighbor.first);
            }
        }
	}
	
	return to_return;
}
size_t IlliniBook::CountGroups() const {
    std::set<int> visited;
    size_t count = 1;
    bool new_comp = false;
    for (auto const& [key, value] : book_) {
        if (visited.contains(key)) continue;
        visited.insert(key);
        for (auto const& [key_1, value_1] : book_) {
            std::string test = std::to_string(key_1);
            if (key_1 == key) continue;
            for (const int& entry : visited) {
                if (GetRelated(entry, key_1) != -1) {
                    new_comp = false;
                    break;
                }
                new_comp = true;
            }
            if (new_comp) {
                count++;
                new_comp = false;
            }
            visited.insert(key_1);
        }
    }
    return count;
}
size_t IlliniBook::CountGroups(const std::string &relationship) const {
    // std::set<std::string> relat;
    // relat.insert(relationship);
    std::set<int> visited;
    size_t count = 1;
    bool new_comp = false;
    for (auto const& [key, value] : book_) {
        if (visited.contains(key)) continue;
        visited.insert(key);
        for (auto const& [key_1, value_1] : book_) {
            if (key_1 == key) continue;
            for (const int& entry : visited) {
                if (GetRelated(entry, key_1, relationship) != -1) {
                    new_comp = false;
                    break;
                }
                new_comp = true;
            }
            if (new_comp) {
                count++;
                new_comp = false;
            }
            visited.insert(key_1);
        }
    }
    return count;
}
//needs to be fixed, implementation is incorrect
size_t IlliniBook::CountGroups(const std::vector<std::string> &relationships) const {
    std::set<int> visited;
    size_t count = 0;
    for (const auto& [key, value] : book_) {
        if (visited.contains(key)) continue;
        std::set<int> comp_visited;
        std::queue<int> q;
        q.push(key);
        comp_visited.insert(key);
        visited.insert(key);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (const auto& neighbor : book_.at(curr)) {
                if (comp_visited.contains(neighbor.first)) continue;
                for (const std::string& r : relationships) {
                    if (GetRelated(curr, neighbor.first, r) != -1) {
                        q.push(neighbor.first);
                        comp_visited.insert(neighbor.first);
                        visited.insert(neighbor.first);
                        break;
                    }
                }
            }
        }
        ++count;
    }
    return count;
    
}

// std::set<std::string> visited;
    // visited.insert(relationships.at(0));
    // std::set<int> visited;
    // size_t count = 0;
    // bool new_comp = false;
    // //bool broken = false;
    // for (auto const& [key, value] : book_) {
    //     if (!visited.contains(key)) { 
    //         std::string key_test = std::to_string(key);
    //         visited.insert(key);
    //         ++count;
    //         for (auto const& [key_1, value_1] : book_) {
    //             std::string key_test2 = std::to_string(key_1);
    //             if (key_1 != key) {
    //                 new_comp = true;
    //                 for (const std::string& relat : relationships) {
    //                     if (GetRelated(key, key_1, relat) != -1) {
    //                         new_comp = false;
    //                         break;
    //                     }
    //                 }
    //                 if (!new_comp) {
    //                     visited.insert(key_1);
    //                 }
    //             }
    //         }
    //     }
    // }
    // return count;

// for (const int& entry : visited) {
//                     if (broken) break;
//                     for (const std::string& relat : relationships) {
//                         if (GetRelated(entry, key_1, relat) != -1) {
//                             new_comp = false;
//                             broken = true;
//                             break;
//                         }
//                         new_comp = true;
//                     }
//                 }
//                 if (new_comp) {
//                     count++;
//                     new_comp = false;
//                 }
//                 broken = false;
//                 visited.insert(key_1);
