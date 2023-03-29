#include<iostream>
using namespace std;

class Solution {
public:
    //暴力求解法
    string longestPalindrome(string s) {
        //判断输入是否合法
        if (s.length() < 1 && s.length() > 1000) {
            cout << "输入的字符串不合法！" << endl;
            return "";
        }
        //只有一个字符必定是回文子符串
        if (s.length() == 1) {
            return s;
        }
        //字符转转字符数组
        const char* str = s.c_str();

        //第一轮循环：从第一个字符开始逐渐向后增加字符数，验证是否是回文字符串，直到增加最后一个字符。
        //第二轮循环：从第二个字符开始重复步骤。
        //例子："abcde"
        //     第一轮循环：第1次验证子串（ab）,第2次（abc）,第3次（abcd）,第4次（abcde）
        //     第二轮循环：第1次验证子串（bc），第2次（bcd），第3次（bcde）
        //     第三轮循环：重复以上步骤

        //优化的比较流程：（从最大的可能是回文字符串的子串开始比较，减少后续不必要的比较流程）
        //第一轮循环：从第一个字符开始逐渐向后增加字符数，验证是否是回文字符串，直到增加最后一个字符。
        //第二轮循环：从第二个字符开始重复步骤。
        //例子："abcde"
        //     第一轮循环：第1次验证子串（abcde）,第2次（abcd）,第3次（abc）,第4次（ab）
        //     第二轮循环：第1次验证子串（bcde），第2次（bcd），第3次（bc）
        //     第三轮循环：重复以上步骤
        
        //记录需要比较的字符数量,最小2个字符，最大原字符串长度
        int count = s.length();
        //记录当前最长的回文子串
        string result = "";
        for (int i = 0; i < s.length(); i++) {
            //记录i的值，方便在下面循环中比较
            int itemp = i;
            //cout << "本轮循环的i=" << i<<",j="<< i + count - 1 << endl;
            //需要验证的子串：从str数组下标i到j之间。
            for (int j = i+count-1; j >=i&& j < s.length()&&j>i; j--,itemp++) {
                //cout << "比较的字符：i=" << itemp<<",j="<< j << endl;
                if ((itemp == j||itemp+1==j&&str[itemp]==str[j])&&count>result.length()) {
                    //cout << "当前结果的子串索引：str[" << i<<"]到str["<< i + count - 1 <<"]" << endl;
                    result = "";
                    for (int k = i; k < i+count; k++) {
                        result += str[k];
                    }
                    //本轮循环的回文字符字串已经是最大的长度，跳出本轮循环进入下一轮
                    break;
                }
                //当前i-j的子串不是回文字符串，直接跳到下一个子串比较
                if (str[itemp] != str[j]) {
                    itemp = i-1;
                    count -= 1;
                    j = i + count;
                }
            }
            //如果当前的最长回文字符长度大于等于下一轮循环的最大字符长度，则退出当前所有循环
            if (result.length() >= s.length() - (i + 1)) {
                break;
            }
            count = s.length()-(i+1);//下一轮循环开始比较的最大字符数量
        }
        if (result.length() == 0) {
            result += str[0];
        }
        return result;
    }
   

    //动态规划
    //每一个字符串是否是回文字符串依赖于里面的字符串是否是回文字符串
    string longestPalindrome2(string s) {
        int length=s.length();
        if (length < 2) {
            return s;
        }
        //字符串转化为数组
        const char* str = s.c_str();
        //定义最大的回文串的开头索引和长度
        int begin =0;
        int len = 1;
        //定义二维数组
        //i行，j列，i=j
        //flag[i][j]表示字符串从i到j是否为回文串
        bool** flag=new bool*[length];
        for (int i = 0; i < length; i++) {
            flag[i] = new bool[length];
            //初始化对角线数据
            flag[i][i] = true;
        }
        //二维数组从上往下，从左往右进行填充
        //即str[i][j]是否是回文串，依赖str[i+1][j-1]是否是回文串
        for (int j = 0; j < length; j++) {
            //i<j，即右上斜对角三角形，填充不超过对角线
            for (int i = 0; i < length&&i<j; i++) {
                //cout << "i=" << i << ",j=" << j << endl;
                if (str[i] == str[j]) {
                    //长度大于3的字串是否是回文串，需要根据中间的子串是否是回文串判断
                    if (j-i+1>3) {
                        flag[i][j] = flag[i + 1][j - 1];
                    }
                    else{
                        flag[i][j] = true;
                    }
                    //当前i到j的字符串是回文串，且长度比当前的最长回文串长，即更改当前最长的回文串
                    if (flag[i][j]&&j - i +1> len) {
                        len = j - i + 1;
                        begin = i;
                        //870=j-7+1;
                    }
                }
                else {
                    flag[i][j] = false;
                }
            }
        }
        cout << "begin=" << begin << ",len=" << len << endl;
        for (int i = 0; i < s.length(); i++) {
            delete[] flag[i];
        }
        delete[] flag;
        return s.substr(begin,len);
    }
    //中心扩散法
    //回文字符串都有一个中心，中心是一个字符如aba，或者中心是两个字符abba。
    //如果中心是一个字符：总的有n个中心
    //如果中心是两个字符：总的有n-1个中心
    //根据中心，向外扩展子串，如果子串两端的字符相同，则扩展的子串任然是回文串，如果向外扩展的两个字符不相同，则当前子串就是以该字符中心的最长回文串。
    string longestPalindrome3(string s) {
        //略
    }
};

int main5() {
    //1、暴力求解
    //string str = "babad";
    //string str = "caba";
    //string str="ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy";
    //string str = "cbbd";
    //string str = "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffgggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg";
    //Solution* s = new Solution();
    //string result=s->longestPalindrome(str);
    //cout <<str+"的最大回文字符串：" << result << endl;

    //2、动态规划
    //string str = "babad";
    //string str = "caba";
    string str="ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy";
    //string str = "cbbd";
    //string str = "abcacb";
    Solution* s = new Solution();
    cout << "字符串长度：" << str.length() << endl;
    string result=s->longestPalindrome2(str);
    cout <<str+"的最大回文字符串：" << result << endl;
    return 0;
}