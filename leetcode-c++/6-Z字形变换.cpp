#include<iostream>
using namespace std;

class Solution {
public:
    //"PAYPALISHIRING"
    // P   A   H   N
    // A P L S I I G
    // Y   I   R
    //
    string convert(string s, int numRows) {
        //不合法输入
        if (s.length() < 1 || s.length() > 1000 || numRows < 1 || numRows>1000) {
            return s;
        }
        //用二维数组存储Z字转换后的图形，再求解转换后的字符串
        const char* str = s.c_str();
        char** temp=new char*[numRows];
        for (int i = 0; i <numRows; i++) {
            temp[i] = new char[s.length()];
        }
        //初始化数组
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < s.length(); j++) {
                temp[i][j] = '\0';
            }
        }
        //记录当前转换到哪个字母下标
        int count = 0;
        //记录当前是j下标往下填写，还是往上填写，Z的两横是往下写，斜杠是网上
        bool flag=true;//往下是true
        //记录Z字中间的字母摆放位置
        int row = numRows-2;//0<row<numRows-1
        //从二维数组的上往下，左往右，逐步转换每一个字符
        for (int j = 0; j <s.length(); j++){
            //如果是往下填写，则只用按顺序填
            if (flag) {
                for (int i = 0; i <  numRows; i++) {
                    temp[i][j] = str[count++];
                    //全部转换完成则退出循环
                    if (count == s.length()) {
                        break;
                    }
                    //当遍历横写到底，则往上写斜杠
                    //如果行数小于三，则没有斜杠
                    if (i == numRows - 1&&numRows>2) {
                        flag = false;
                    }
                }
            }
            //如果是往上填写，则要每一步i-1，j+1
            else {
                temp[row--][j] = s[count++];
                //当遍历写完斜杠的字符，则初始化变量，下一轮遍历又是横
                if (row == 0) {
                    flag = true;
                    row = numRows - 2;
                }
            }
            //全部转换完成则退出循环
            if (count == s.length()) {
                break;
            }
        }
        string newStr = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < s.length(); j++) {
                if (temp[i][j] != '\0') {
                    newStr += temp[i][j];
                    cout << temp[i][j] << " ";
                }
                else {
                    cout << " "<< " ";
                }
            }
            cout << endl;
        }
        for(int i = 0; i < numRows; i++) {
            delete[] temp[i];
        }
        delete[] temp;
        return newStr;
    }
};

int main6() {
    //string str = "PAYPALISHIRING";
    //int num = 3;
    //string str = "PAYPALISHIRING";
    //int num = 2;
    //string str = "PAYPALISHIRING";
    //int num = 4;
    //string str = "PAYPALISHIRING";
    //int num = 3;
    string str = "vphzamjvxtomfacqaezwhuzntkkqagbvxkxywgtvbjjijnylsajzwioruaiujlrgvoguwzrzkbivo";
    int num = 66;

    Solution* s = new Solution();
    string newStr=s->convert(str, num);
    cout << "转换前字符串：" <<str<< endl;
    cout << "转换后字符串：" <<newStr<< endl;
    return 0;
}