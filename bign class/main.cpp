/**A Big number class**/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>

using namespace std;

const int maxn=100000;

struct bign
{
    int len,s[maxn];
    bign(){memset(s,0,sizeof(s));len=1;}        //构造函数 bign
    bign operator =(const char* num)            //赋值操作符
    {
        len=strlen(num);
        for(int i=0;i<len;i++) s[i]=num[len-i-1]-'0';
        return *this;
    }
    bign(int num) {*this=num;}
    bign(const char* num){*this=num;}
    string str() const
    {
        string res="";
        for(int i=0;i<len;i++) res=(char)(s[i]+'0')+res;
        if(res=="") res="0";
        return res;
    }

    //定义bign的运算符
    bign operator =(int num)        //赋值符
    {
        char s[maxn];
        sprintf(s,"%d",num);
        *this=s;
        return *this;
    }
    bign operator + (const bign& b) const
    {
        bign c;
        c.len=0;
        for(int i=0,g=0;g||i<max(len,b.len);i++)
        {
            int x=g;
            if(i<len) x+=s[i];
            if(i<b.len) x+=b.s[i];
            c.s[c.len++]=x%10;
            g=x/10;
        }
        return c;
    }
    bign operator += (const bign& b)
    {
        *this=*this+b;
        return *this;
    }
    bool operator < (const bign& b) const
    {
        if(len !=b.len) return len<b.len;
        for(int i=len-1;i>=0;i--)
            if(s[i]!=b.s[i]) return s[i]<b.s[i];
        return false;
    }
    bool operator >  (const bign& b)const{return b<*this;}
    bool operator <= (const bign& b)const{return !(b<*this);}
    bool operator >= (const bign& b)const{return !(*this<b);}
    bool operator != (const bign& b)const{return (*this<b)||(b<*this);}
    bool operator == (const bign& b)const{return !(*this<b) && !(b<*this);}
};

istream& operator >> (istream &in,bign& x)
{
    string s;
    in>>s;
    x=s.c_str();
    return in;
}

ostream & operator << (ostream &out,const bign& x)
{
    out <<x.str();
    return out;
}

