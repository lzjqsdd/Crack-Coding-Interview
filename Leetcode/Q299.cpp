//Bulls And Cows
//s.size == p.size()
string getHint(string secret, string guess)
{
    vector<int> dict(10,0);
    //set<int> pos; //表示匹配的Bull的位置
    int a=0,b=0;
    for(int i=0;i<secret.size();i++)
    {
        if(secret[i] == guess[i])
        {
            a++;
            pos.insert(i);
        }
        else
        {
            dict[secret[i]-'0']++;
        }
    }

    for(int i=0;i<guess.size();i++)
    {
        if(pos.find(i) == pos.end()) //保证不是bull的位置，==end是找不到
        {
            if(dict[guess[i]-'0'] > 0)
            {
                b++;
                dict[guess[i]-'0']--;
            }
        }
    }
    string result = to_string(a)+"a"+to_string(b)+"b";
    return result;
}