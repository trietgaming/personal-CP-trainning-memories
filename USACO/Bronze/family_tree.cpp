#include <bits/stdc++.h>

using namespace std;

const string FNAME = "family";

unordered_map<string, vector<string>> directed, reversed, undirected;
unordered_map<string, bool> visited;

bool isRelated(string &cur, string &B) {
  if (cur == B) return true;
  visited[cur] = true;
  vector<string> &adjacents = undirected[cur];
  for (string &neighbor: adjacents) {
    if (visited[neighbor]) continue;
    if (isRelated(neighbor, B)) return true;
  }
  return false;
}

int BisMotherOfA(string &cur, string &A, int level = 0) {
  if (cur == A) return level;
  visited[cur] = true;
  vector<string> &adjacents = directed[cur];
  for (string &neighbor: adjacents) {
    if (visited[neighbor]) continue;
    int nextVisit = BisMotherOfA(neighbor, A, level + 1);
    if (nextVisit) return nextVisit;
  }
  return 0;
}

void printMother(string &mother, string &child, int level) {
  cout << mother << " is the ";
  if (level > 2) for (int i = 3; i <= level; ++i) {
    cout << "great-";
  }
  if (level >= 2) cout << "grand-";
  cout << "mother of " << child;
}

void printAunt(string &aunt, string &child, int level) {
  cout << aunt << " is the ";
  if (level >= 2) for (int i = 2; i <= level; ++i) {
    cout << "great-";
  }
  cout << "aunt of " << child;
}

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;
  string A, B;
  cin >> A >> B;

  string mother, child;
  while (n--) {
    cin >> mother >> child;
    directed[mother].push_back(child);
    reversed[child].push_back(mother);

    undirected[mother].push_back(child);
    undirected[child].push_back(mother);
  }

  // Not related
  if (!isRelated(A, B)) {
    cout << "NOT RELATED";
    return 0;
  }
  visited.clear();

  // SIBLINGS
  if (reversed[A].size() && reversed[B].size() && reversed[A][0] == reversed[B][0]) {
    cout << "SIBLINGS";
    return 0;
  }

  // B is X-mother of A
  int BMotherLevel = BisMotherOfA(B, A);
  if (BMotherLevel) {
    printMother(B, A, BMotherLevel);
    return 0;
  }
  visited.clear();
  // A is X-mother of B
  int AMotherLevel = BisMotherOfA(A, B);
  if (AMotherLevel) {
    printMother(A, B, AMotherLevel);
    return 0;
  }
  visited.clear();

  // B is X-aunt of A
  if (reversed[B].size()) {
    string &BMother = reversed[B][0];
    int level = BisMotherOfA(BMother, A);
    if (level) {
      printAunt(B, A, level - 1);
      return 0;
    }
    visited.clear();
  }

  // A is X-aunt of B
  if (reversed[A].size()) {
    string &AMother = reversed[A][0];
    int level = BisMotherOfA(AMother, B);
    if (level) {
      printAunt(A, B, level - 1);
      return 0;
    }
    visited.clear();
  }

  cout << "COUSINS";


  return 0;
}


