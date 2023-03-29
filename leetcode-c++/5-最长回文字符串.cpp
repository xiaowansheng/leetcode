#include<iostream>
using namespace std;

class Solution {
public:
    //������ⷨ
    string longestPalindrome(string s) {
        //�ж������Ƿ�Ϸ�
        if (s.length() < 1 && s.length() > 1000) {
            cout << "������ַ������Ϸ���" << endl;
            return "";
        }
        //ֻ��һ���ַ��ض��ǻ����ӷ���
        if (s.length() == 1) {
            return s;
        }
        //�ַ�תת�ַ�����
        const char* str = s.c_str();

        //��һ��ѭ�����ӵ�һ���ַ���ʼ����������ַ�������֤�Ƿ��ǻ����ַ�����ֱ���������һ���ַ���
        //�ڶ���ѭ�����ӵڶ����ַ���ʼ�ظ����衣
        //���ӣ�"abcde"
        //     ��һ��ѭ������1����֤�Ӵ���ab��,��2�Σ�abc��,��3�Σ�abcd��,��4�Σ�abcde��
        //     �ڶ���ѭ������1����֤�Ӵ���bc������2�Σ�bcd������3�Σ�bcde��
        //     ������ѭ�����ظ����ϲ���

        //�Ż��ıȽ����̣��������Ŀ����ǻ����ַ������Ӵ���ʼ�Ƚϣ����ٺ�������Ҫ�ıȽ����̣�
        //��һ��ѭ�����ӵ�һ���ַ���ʼ����������ַ�������֤�Ƿ��ǻ����ַ�����ֱ���������һ���ַ���
        //�ڶ���ѭ�����ӵڶ����ַ���ʼ�ظ����衣
        //���ӣ�"abcde"
        //     ��һ��ѭ������1����֤�Ӵ���abcde��,��2�Σ�abcd��,��3�Σ�abc��,��4�Σ�ab��
        //     �ڶ���ѭ������1����֤�Ӵ���bcde������2�Σ�bcd������3�Σ�bc��
        //     ������ѭ�����ظ����ϲ���
        
        //��¼��Ҫ�Ƚϵ��ַ�����,��С2���ַ������ԭ�ַ�������
        int count = s.length();
        //��¼��ǰ��Ļ����Ӵ�
        string result = "";
        for (int i = 0; i < s.length(); i++) {
            //��¼i��ֵ������������ѭ���бȽ�
            int itemp = i;
            //cout << "����ѭ����i=" << i<<",j="<< i + count - 1 << endl;
            //��Ҫ��֤���Ӵ�����str�����±�i��j֮�䡣
            for (int j = i+count-1; j >=i&& j < s.length()&&j>i; j--,itemp++) {
                //cout << "�Ƚϵ��ַ���i=" << itemp<<",j="<< j << endl;
                if ((itemp == j||itemp+1==j&&str[itemp]==str[j])&&count>result.length()) {
                    //cout << "��ǰ������Ӵ�������str[" << i<<"]��str["<< i + count - 1 <<"]" << endl;
                    result = "";
                    for (int k = i; k < i+count; k++) {
                        result += str[k];
                    }
                    //����ѭ���Ļ����ַ��ִ��Ѿ������ĳ��ȣ���������ѭ��������һ��
                    break;
                }
                //��ǰi-j���Ӵ����ǻ����ַ�����ֱ��������һ���Ӵ��Ƚ�
                if (str[itemp] != str[j]) {
                    itemp = i-1;
                    count -= 1;
                    j = i + count;
                }
            }
            //�����ǰ��������ַ����ȴ��ڵ�����һ��ѭ��������ַ����ȣ����˳���ǰ����ѭ��
            if (result.length() >= s.length() - (i + 1)) {
                break;
            }
            count = s.length()-(i+1);//��һ��ѭ����ʼ�Ƚϵ�����ַ�����
        }
        if (result.length() == 0) {
            result += str[0];
        }
        return result;
    }
   

    //��̬�滮
    //ÿһ���ַ����Ƿ��ǻ����ַ���������������ַ����Ƿ��ǻ����ַ���
    string longestPalindrome2(string s) {
        int length=s.length();
        if (length < 2) {
            return s;
        }
        //�ַ���ת��Ϊ����
        const char* str = s.c_str();
        //�������Ļ��Ĵ��Ŀ�ͷ�����ͳ���
        int begin =0;
        int len = 1;
        //�����ά����
        //i�У�j�У�i=j
        //flag[i][j]��ʾ�ַ�����i��j�Ƿ�Ϊ���Ĵ�
        bool** flag=new bool*[length];
        for (int i = 0; i < length; i++) {
            flag[i] = new bool[length];
            //��ʼ���Խ�������
            flag[i][i] = true;
        }
        //��ά����������£��������ҽ������
        //��str[i][j]�Ƿ��ǻ��Ĵ�������str[i+1][j-1]�Ƿ��ǻ��Ĵ�
        for (int j = 0; j < length; j++) {
            //i<j��������б�Խ������Σ���䲻�����Խ���
            for (int i = 0; i < length&&i<j; i++) {
                //cout << "i=" << i << ",j=" << j << endl;
                if (str[i] == str[j]) {
                    //���ȴ���3���ִ��Ƿ��ǻ��Ĵ�����Ҫ�����м���Ӵ��Ƿ��ǻ��Ĵ��ж�
                    if (j-i+1>3) {
                        flag[i][j] = flag[i + 1][j - 1];
                    }
                    else{
                        flag[i][j] = true;
                    }
                    //��ǰi��j���ַ����ǻ��Ĵ����ҳ��ȱȵ�ǰ������Ĵ����������ĵ�ǰ��Ļ��Ĵ�
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
    //������ɢ��
    //�����ַ�������һ�����ģ�������һ���ַ���aba�����������������ַ�abba��
    //���������һ���ַ����ܵ���n������
    //��������������ַ����ܵ���n-1������
    //�������ģ�������չ�Ӵ�������Ӵ����˵��ַ���ͬ������չ���Ӵ���Ȼ�ǻ��Ĵ������������չ�������ַ�����ͬ����ǰ�Ӵ������Ը��ַ����ĵ�����Ĵ���
    string longestPalindrome3(string s) {
        //��
    }
};

int main5() {
    //1���������
    //string str = "babad";
    //string str = "caba";
    //string str="ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy";
    //string str = "cbbd";
    //string str = "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffgggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg";
    //Solution* s = new Solution();
    //string result=s->longestPalindrome(str);
    //cout <<str+"���������ַ�����" << result << endl;

    //2����̬�滮
    //string str = "babad";
    //string str = "caba";
    string str="ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy";
    //string str = "cbbd";
    //string str = "abcacb";
    Solution* s = new Solution();
    cout << "�ַ������ȣ�" << str.length() << endl;
    string result=s->longestPalindrome2(str);
    cout <<str+"���������ַ�����" << result << endl;
    return 0;
}