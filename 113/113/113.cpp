#include<math.h>
#include<cstdio>
#include<string>
using namespace std;
int main(void)
{
	double root, power;
	while (scanf("%lf%lf", &power, &root) == 2)
	{
		printf("%.0lf\n", pow(root, 1 / power));				//�ѵ���ô����Ĵ��� ��double�Ϳ����� ��n�θ����൱�ڸ��� 1/n�η� ���ע����.0lfȥ��С��λ
	}
}