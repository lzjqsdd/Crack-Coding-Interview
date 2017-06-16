//32. Longest Valid Parentheses
//题意：寻找最长的合法匹配的括号串
//思路：首先分析什么是合法的匹配的括号？对于任何一个合法匹配的括号对，从左往右括号个数始终满足 l >= r
//因此，从左往右维护两个计数器，l,r，如果不满足，则记录当前匹配个数min(l,r),然后从下一个位置开始重新匹配。
//WA
class Solution
{
  public:
    int longestValidParentheses(string s)
    {
        int maxlen = 0;
        int l = 0, r = 0;
        //正向
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                l++;
                maxlen = max(maxlen, 2 * min(l, r));
            }
            else
            {
                r++;
                if (l < r)
                {
                    maxlen = max(maxlen, 2 * min(l, r));
                    l = 0;
                    r = 0;
                }
                else
                    maxlen = max(maxlen, 2 * min(l, r));
            }
        }
        if (l == r)
            maxlen = max(maxlen, 2 * l);
        return maxlen;
    }
};

""
    ")()())"
    "())()()))()()(()()()(()()()()()))" 24

    //如果出现左括号不匹配呢？
    //这种情况在匹配过程中不会出现，如果出现l < r ,说明至少l全被匹配了。然而因为扫描到头终止,l>r 成立，但可能无法完全匹配
    "()(()"

    ")()(((())))("

    ""
    ")()())"
    "())()()))()()(()()()(()()()()()))"
    "()(()"
    "()(()(()((()))()(()()()(((((((())()("
    "))())()(()))()()(()"
    ")()(((())))("




//这个思路倒着来。使用栈来做匹配。如果出现匹配则出栈。最终栈里剩下的都是无法被匹配的括号的index.
//那么这些未匹配的括号之间的位置是正确被匹配的。
//参考答案：
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), longest = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') st.push(i);
            else {
                if (!st.empty()) {
                    if (s[st.top()] == '(') st.pop();
                    else st.push(i);
                }
                else st.push(i);
            }
        }


        if (st.empty()) longest = n;
        else {
            int a = n, b = 0;
            while (!st.empty()) {
                b = st.top(); st.pop();
                longest = max(longest, a-b-1);
                a = b;
            }
            //#()()(()()()(#
            //st: 4,11, n = 12
            longest = max(longest, a); //栈空。第一个未匹配之前匹配的个数
        }
        return longest;
    }
};


The workflow of the solution is as below.

Scan the string from beginning to end.
If current character is '(',
push its index to the stack. If current character is ')' and the
character at the index of the top of stack is '(', we just find a
matching pair so pop from the stack. Otherwise, we push the index of
')' to the stack.
After the scan is done, the stack will only
contain the indices of characters which cannot be matched. Then
let's use the opposite side - substring between adjacent indices
should be valid parentheses.
If the stack is empty, the whole input
string is valid. Otherwise, we can scan the stack to get longest
valid substring as described in step 3.