#ifndef ___Member
#define ___Member

typedef struct {
	int no;					// 회원 번호 (key)
	char name[20];		// 회원 이름 (값 value)
} Member;

#define MEMBER_NO 1		 // 번호를 나타내는 정수 값
#define MEMBER_NAME 2	 // 이름을 나타내는 정수 값

int MemberNoCmp(const Member * x, const Member * y);

int MemberNameCmp(const Member* x, const Member* y);

void PrintMember(const Member* x);

void PrintLnMember(const Member* x);

Member ScanMember(const char* message, int sw);

#endif