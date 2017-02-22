class Solution {
public:
    int compareVersion(string version1, string version2) {
        //version 可能多个'.'
        if(version1 == version2) return 0;
        
        version1+=".";
        version2+=".";
        istringstream in1(version1);
        istringstream in2(version2);
        int v1=-1,v2=-1;
        char c1,c2;
        while(in1>>v1>>c1 && in2>>v2>>c2)
        {
            if(v1 > v2) return 1;
            else if(v1 < v2) return -1;
            v1 = v2 = -1;
        }
        //如果是v1输入失败,说明v1没数据了,但v2不一定
        //如果v1有输入，说明v2没数据了。

        if(v1 == -1) //v1没数据
        {
            while(in2 >> v2 >> c2)
            {
                if(v2 > 0) return -1;
            }
            if(v2 == -1||v2==0) //v2也没数据或者后面一堆0
                return 0;
        }
        else //v1有数据，v2没数据
        {
            if(v1 > 0) return 1; //处理v2失败时v1中的数据
            while(in1 >> v1 >> c1)
            {
                if(v1 > 0) return 1;
            }
            if(v1 == 0) return 0;
        }
        return 0;
    }
};