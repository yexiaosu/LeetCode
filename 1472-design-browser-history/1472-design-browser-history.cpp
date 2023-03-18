class BrowserHistory {
    vector<string> browserHistory;
    int curr = 0;
public:
    BrowserHistory(string homepage) {
        browserHistory.clear();
        browserHistory.push_back(homepage);
        curr = 0;
    }
    
    void visit(string url) {
        if (curr < browserHistory.size() - 1) {
            vector<string>::iterator it1, it2;
            it1 = browserHistory.begin() + curr + 1;
            it2 = browserHistory.end();
            browserHistory.erase(it1, it2);
        }
        browserHistory.push_back(url);
        curr++;
    }
    
    string back(int steps) {
        curr = (curr - steps) < 0 ? 0 : curr - steps;
        return browserHistory[curr];
    }
    
    string forward(int steps) {
        curr = (curr + steps) >= browserHistory.size() ? browserHistory.size() - 1 : curr + steps;
        return browserHistory[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */