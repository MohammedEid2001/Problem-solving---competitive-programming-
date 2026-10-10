/*

description:

*/


class MinStack {
public:
    vector<int> stak;
    int mi = 2147483647;
    int indx = -1;
    MinStack() {
        stak.reserve(30000);
    }
    
    void push(int value) {
        stak.push_back(value);
        if(value < mi){mi = value; indx = stak.size()-1;}
    }
    
    void pop() {
        if(stak.back() == mi && indx==stak.size()-1)
        { 
             mi = 2147483647; indx = -1;
        }
stak.pop_back();
        if(indx==-1)for( int  i = 0;  i< stak.size(); ++i )
        {
            if(stak[i]<mi){mi=stak[i]; indx =i;}
    }
    }
    
    int top() {
        return stak.back();
    }
    
    int getMin() {
        return mi;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
