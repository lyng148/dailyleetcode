class Solution {
public:
    string removeStars(string s) {
  stack<char> res;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '*') {
      res.pop();
    }
    else res.push(s[i]);
  }        
  string fres;
  while (!res.empty()) {
    fres.push_back(res.top());
    res.pop();
  }
  string ffres;
  for (int i = fres.length() - 1; i >= 0; i--) {
    ffres.push_back(fres[i]);
  }
  return ffres;
}
};