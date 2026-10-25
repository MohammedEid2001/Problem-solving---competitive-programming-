/*
description:
You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:

BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
void visit(string url) Visits url from the current page. It clears up all the forward history.
string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.
*/


//to make the "back" run in O(1) coomolexity, we use a C++ vector to move immediately to the element there , and then for the "visit" and moving forward, we set a 'top' value to be monitoring  where we are standing right now on the stack and append on top of it sk we can work on O(1) complexity as well without any memory leakage.

class BrowserHistory {
public:
    vector<string> history;
    //history.reserve(5000);
    int current ;
    int top;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        current= 0;
        top = 0;
    }
    
    void visit(string url) {
        /*while(current < history.size()-1)
        {
            history.pop_back();
        }*/
        ++current;
        if(current < history.size())history[current]= url;
        else{history.push_back(url);}
        top = current;
    }
    
    string back(int steps) {
        current = max(0, current-steps);
        return history[current];
    }
    
    string forward(int steps) {
        current = min(top,current+steps);
        return history[current];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
