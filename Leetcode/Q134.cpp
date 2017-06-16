//题意：有一个环形的路段，每隔一段都有一个加气站Gi,从Gi到Gi+1的划分为Costi，给定每个加气站的储量和每段路的消耗
//车辆从某个加气站出发，问车辆如果能从某个加气站出发绕一圈，输出加气站的位置，否则输出-1

//思路：记录每隔加气站与其后路段cost的差（表示剩余油量），如果差值小于0,则当前加气站是不能作为起点。另外如果所有环上的燃料总量-消耗小于0，则不可能走一圈。
//假设从i站出发能够绕行一圈，但是i并不是剩余油量最大的站，显然我可以选择剩余油量最大的，更有保障。
// 比如 0,1,2,3,4,5几个站,不失一般性，选择3号可以走一圈，而1号是剩余油量最大的。
//选择3号:3->4->5->0->1->2->3
//首先3号走到1号，肯定剩余油量>=0, 而且1->3剩余油量>=0，那么显然我也可以选择从1号开始走1->2->3，3->4->5->0->1,显然若1号走到3号，
//则到达3号时油量应该>=0,相比于从3号出发时剩余流量为0更为靠谱。
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> e;
        int sum = 0;

        for(int i = 0;i<gas.size();++i) {e.push_back(gas[i] - cost[i]);}
        int maxi = 0;
        for(int i = 0;i<e.size();++i)
        {
            sum+=e[i];
            if(e[maxi] < e[i]) maxi = i;
        }
        if(sum < 0) return -1;
        return maxi;
    }
};

//WA
[6,1,4,3,5]
[3,8,2,4,2]

//出错原因：若i出发可以到，则从i出发的每一步最终油箱流量都应该>=0,尽管i的剩余流量并非最大。虽然选择某个j站剩余流量最大，但是j->i出发时油箱
//流量为空，所以也有可能到不了。

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> e;
        int sum = 0;

        for(int i = 0;i<gas.size();++i) {e.push_back(gas[i] - cost[i]);}
        for(int i = 0;i<e.size();++i) sum+=e[i];
        if(sum < 0) return -1;

        int s = 0;
        int start = 0;
        for(int i=0;i<e.size();++i)
        {
            s+=e[i];
            if(s < 0) //说明前一段在i处不可达到i+1了，想想，油量累积剩余的油量在i出都不足以满足cost,i之前的作为起始都不合适
            { s = 0;start = i+1;}
        }

        return start;
    }
};