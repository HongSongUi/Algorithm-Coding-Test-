#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    string str;
    cin >> str;
    int index = 0;
    while (index < str.length()) 
    {
        int w_count = 0, o_count = 0, l_count = 0, f_count = 0;


        while (index < str.length() && str[index] == 'w') 
        {
            w_count++;
            index++;
        }


        while (index < str.length() && str[index] == 'o') 
        {
            o_count++;
            index++;
        }

        while (index < str.length() && str[index] == 'l') 
        {
            l_count++;
            index++;
        }


        while (index < str.length() && str[index] == 'f')
        {
            f_count++;
            index++;
        }

    
        if (w_count == 0 && o_count == 0 && l_count == 0 && f_count == 0)
        {
            break;
        }

        if (w_count != o_count || w_count != l_count || w_count != f_count) 
        {
            cout << 0 ;
            return 0;
        }
    }
    if (index == str.length()) {
        cout << 1 ;
    }
    else {
        cout << 0 ;
    }

	return 0;
}