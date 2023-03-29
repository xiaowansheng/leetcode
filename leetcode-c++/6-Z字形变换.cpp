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
        //���Ϸ�����
        if (s.length() < 1 || s.length() > 1000 || numRows < 1 || numRows>1000) {
            return s;
        }
        //�ö�ά����洢Z��ת�����ͼ�Σ������ת������ַ���
        const char* str = s.c_str();
        char** temp=new char*[numRows];
        for (int i = 0; i <numRows; i++) {
            temp[i] = new char[s.length()];
        }
        //��ʼ������
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < s.length(); j++) {
                temp[i][j] = '\0';
            }
        }
        //��¼��ǰת�����ĸ���ĸ�±�
        int count = 0;
        //��¼��ǰ��j�±�������д������������д��Z������������д��б��������
        bool flag=true;//������true
        //��¼Z���м����ĸ�ڷ�λ��
        int row = numRows-2;//0<row<numRows-1
        //�Ӷ�ά����������£������ң���ת��ÿһ���ַ�
        for (int j = 0; j <s.length(); j++){
            //�����������д����ֻ�ð�˳����
            if (flag) {
                for (int i = 0; i <  numRows; i++) {
                    temp[i][j] = str[count++];
                    //ȫ��ת��������˳�ѭ��
                    if (count == s.length()) {
                        break;
                    }
                    //��������д���ף�������дб��
                    //�������С��������û��б��
                    if (i == numRows - 1&&numRows>2) {
                        flag = false;
                    }
                }
            }
            //�����������д����Ҫÿһ��i-1��j+1
            else {
                temp[row--][j] = s[count++];
                //������д��б�ܵ��ַ������ʼ����������һ�ֱ������Ǻ�
                if (row == 0) {
                    flag = true;
                    row = numRows - 2;
                }
            }
            //ȫ��ת��������˳�ѭ��
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
    cout << "ת��ǰ�ַ�����" <<str<< endl;
    cout << "ת�����ַ�����" <<newStr<< endl;
    return 0;
}