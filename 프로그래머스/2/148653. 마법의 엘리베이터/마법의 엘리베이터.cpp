#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while (storey > 0)
	{
		int n1 = storey % 10;
		int n2 = storey / 10;

		 if (n1 > 5)
        {
            answer += 10 - n1;
            storey = n2 + 1;
        }
        else if (n1 < 5)
        {
            answer += n1;
            storey = n2;
        }
        else
        {
            answer += 5;
            if ((n2 % 10) >= 5)
            {
                 storey = n2 + 1;
            }
               
            else
            {
                storey = n2;
            }
            
         }
	}
    return answer;
}