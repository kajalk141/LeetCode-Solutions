class ProductOfNumbers {
public:
    vector<int> v={1};
    ProductOfNumbers() {
        // v.clear();
    }
    
    void add(int num) {
        if(num==0) v={1};
        else v.push_back(v.back()*num);
    }
    
    int getProduct(int k) {
        int n=v.size();
        if(k>=n) return 0;
        else return v[n-1]/v[n-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */