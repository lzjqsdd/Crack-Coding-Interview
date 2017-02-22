#include <iostream>
#include <vector>
#include <string>
using namespace std;

//计算字符串的编辑距离


//算法
int ldistance(const string source,const string target)
{
    //step 1

    int n=source.length();
    int m=target.length();
    if (m==0) return n;
    if (n==0) return m;
    //Construct a matrix
    typedef vector< vector<int> >  Tmatrix;
    Tmatrix matrix(n+1);
    for(int i=0; i<=n; i++)  matrix[i].resize(m+1);

    //step 2 Initialize

    for(int i=1;i<=n;i++) matrix[i][0]=i;
    for(int i=1;i<=m;i++) matrix[0][i]=i;

     //step 3
     for(int i=1;i<=n;i++)
     {
        const char si=source[i-1];
        //step 4
        for(int j=1;j<=m;j++)
        {

            const char dj=target[j-1];
            //step 5
            int cost;
            if(si==dj){
                cost=0;
            }
            else{
                cost=1;
            }
            //step 6
            const int above=matrix[i-1][j]+1;
            const int left=matrix[i][j-1]+1;
            const int diag=matrix[i-1][j-1]+cost;
            matrix[i][j]=min(above,min(left,diag));

        }
     }//step7
      return matrix[n][m];
}
int main(){
    string s;
    string d;
    cout<<"source=";
    cin>>s;
    cout<<"diag=";
    cin>>d;
    int dist=ldistance(s,d);
    cout<<"dist="<<dist<<endl;
}

/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//算法
int ldistance(const string source,const string target)
{
    //step 1

    int n=source.length();
    int m=target.length();
    if (m==0) return n;
    if (n==0) return m;
    //Construct a matrix
    typedef vector< vector<int> >  Tmatrix;
    Tmatrix matrix(n+1);
    for(int i=0; i<=n; i++)  matrix[i].resize(m+1);

    //step 2 Initialize

    for(int i=1;i<=n;i++) matrix[i][0]=i;
    for(int i=1;i<=m;i++) matrix[0][i]=i;

     //step 3
     for(int i=1;i<=n;i++)
     {
        const char si=source[i-1];
        //step 4
        for(int j=1;j<=m;j++)
        {

            const char dj=target[j-1];
            //step 5
            int cost;
            if(si==dj){
                cost=0;
            }
            else{
                cost=1;
            }
            //step 6
            const int above=matrix[i-1][j]+1;
            const int left=matrix[i][j-1]+1;
            const int diag=matrix[i-1][j-1]+cost;
            matrix[i][j]=min(above,min(left,diag));

        }
     }//step7
      return matrix[n][m];
}
int main(){
    string s;
    string d;
    cout<<"source=";
    cin>>s;
    cout<<"diag=";
    cin>>d;
    int dist=ldistance(s,d);
    cout<<"dist="<<dist<<endl;
}

*/
