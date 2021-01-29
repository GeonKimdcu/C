#include <stdio.h>

typedef struct {
	int y;
	int m;
	int d;
}Date;

Date Before(Date x, int n);
Date After(Date x, int n);

/*--- �� ���� �ϼ� ---*/
static int mdays[2][13] = {
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },			// ��� : 100���� ������ �������� 400���� ������ �������� �ʴ� ��  
	{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }				// ���� : 4�� ������ �������� �� 
};

/*--- year���� �������� �˻��ϴ� �Լ� ---*/
int isleap(int year)
{
	return year % 4 == 0 && year % 100!= 0 || year % 400 == 0;
}

// y�� m�� d���� ��Ÿ���� ����ü�� ��ȯ�ϴ� �Լ�
Date DateOf(int y, int m, int d) {
	Date temp;
	
		temp.y = y;
		temp.m = m;
		temp.d = d;
	
		return temp;
}

// ��¥ x�� n�� ���� ��¥�� ��ȯ�ϴ� �Լ� 
Date After(Date x, int n) {
	if (n < 0)
				return Before(x, -n);
		
			x.d += n;
		
			while (x.d > mdays[isleap(x.y)][x.m - 1]) {
				x.d -= mdays[isleap(x.y)][x.m - 1];
				if (++x.m > 12) {
					x.y++;
					x.m = 1;
				}
			}
			return x;
}

// ��¥ x�� n�� ���� ��¥�� ��ȯ�ϴ� �Լ�
Date Before(Date x, int n)
{
	if (n < 0)
		return After(x, -n);

	x.d -= n;

	while (x.d < 1) {
		if (--x.m < 1) {
			x.y--;
			x.m = 12;
		}
		x.d += mdays[isleap(x.y)][x.m - 1];
	}
	return x;
}

int Print(Date x)
{
	int y = x.y;
	int m = x.m;
	int d = x.d;

	const char * ws[] = { "��", "��" "ȭ" "��", "��", "��", "��" };
	if (m == 1 || m == 2) {
		y--;
		m += 12;
	}
	 printf("%04d�� %02d�� %02d��(%s)", x.y, x.m, x.d, ws[(y + y / 4 - y / 100 + y / 400 + (13 * m + 8) / 5 + d) % 7]);
}

int main(void)
{
	int n;
	int y, m, d;
	Date x;

	printf("��¥�� �Է��ϼ���.\n");
	printf("�� : "); scanf_s("%d", &y);
	printf("�� : "); scanf_s("%d", &m);
	printf("�� : "); scanf_s("%d", &d);

	x = DateOf(y, m, d);

	printf("��ĥ �� / ���� ��¥�� ���ұ��? : ");
	scanf_s("%d", &n);

	printf("%d �� ���� ��¥ : ", n); Print(After(x, n)); putchar('\n');
	printf("%d �� ���� ��¥ : ", n); Print(Before(x, n)); putchar('\n');

	return 0;
}