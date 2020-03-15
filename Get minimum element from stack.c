/*returns min element from stack*/
int _stack :: getMin(){
    if(s.empty())
        return -1;
    return minEle;
}

/*returns poped element from stack*/
int _stack ::pop(){
    if(s.empty())
        return -1;
    if(s.top() >= 0){
        int temp = s.top();
        s.pop();
        return temp;
    }
    else{
        int temp = minEle;
        minEle = minEle - s.top();
        s.pop();
        return temp;
    }
}

/*push element x into the stack*/
void _stack::push(int x){
    if(s.empty()){
        s.push(x);
        minEle = x;
        return;
    }
    if(x >= minEle)
        s.push(x);
    else{
        int temp = x - minEle;
        s.push(temp);
        minEle = x;
    }
}
