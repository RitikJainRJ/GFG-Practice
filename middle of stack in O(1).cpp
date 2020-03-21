class Stack{
    private:
    list<int> s;
    int middle;

    public:
    void push(int x){
        s.push_back(x);
        if(s.size() == 1)
            middle = 0;
        else if(s.size() % 2 != 0)
            middle++;
    }

    int getMiddle(){
        if(s.empty())
            return -1;
        return s[middle];
    }

    int pop(){
        if(s.empty())
            return -1;
        if(s.size() % 2 != 0)
            middle--;
        int temp = s.back();
        s.pop_back();
        return temp;
    }
};
