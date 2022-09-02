class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> nums;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()) return 0;
        nums.push_back(val);
        mp[val]=nums.size()-1;
        return 1;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()) return 0;
        int last=nums.back();
        nums[mp[val]]=last;
        nums.pop_back();
        mp[last]=mp[val];
        mp.erase(val);
        return 1;
    }
    
    int getRandom() {
        int n=nums.size();
        return nums[rand()%n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */