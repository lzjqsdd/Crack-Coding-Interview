//380,381相关
//设计一个类,满足插入,删除,getrandom,要求返回的数等概率
//如果原来元素已经存在,则不插入

//水塘采样是不确定数据大小的情况下还要求等概率.

//思路:getRandom: Returns a random element from current collection of elements,在当前数据确定的条件下,等概率输出.那么直接random 即可
//插入和删除用map都可以在O(1)做到,但是map无法根据下标随机获取.(set也不可以),这两种数据结构底层为rbtree,无法随机访问
//所以判断是否存在元素仍然使用hashmap ,但是增加一个vector记录元素,用于getrandom
//所以map记录每个元素在vector中的位置,便于删除vector中的元素.每次删除vector中元素时,先把其和最后一个元素交换,然后pop_back(),
//这样比较快.毕竟不关乎元素在vector中相对顺序的变化

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val) == m.end())
        {
            v.push_back(val);
            m[val] = v.size()-1;
            return true;
        }
        return false;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(m.find(val) != m.end())
        {
            //先更新v最后一个元素在map的序号,然后交换v中的val与最后一个元素,再pop_back;
            //注意判断val是否就是最后一个元素
            if(val != v.back())
            {
                m[v.back()] = m[val];
                swap(v[m[val]],v[v.size()-1]);
            }
            m.erase(val);
            v.pop_back();
            return true;
        }
        return false;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return v[rand() % v.size()];
    }
private:
    unordered_map<int,int> m;
    vector<int> v;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

 ["RandomizedSet","insert","remove","insert","getRandom","remove","insert","getRandom","insert","insert","getRandom","getRandom"]
[  [],              [1],     [2],     [2],       [],       [1],      [2],      [],       [3],     [4],       [],       []]

["RandomizedSet","insert","remove","insert","remove","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom"]
[[],               [0],    [0],     [-1],      [0],    [],[],[],[],[],[],[],[],[],[]]