#include <cstdio>

class stack {
	private:
		int end=-1;
		char arr[150];
	public:
		void push(char);
		char pop();
};
void stack::push(char ch) {
	end++;
	arr[end]=ch;
}
char stack::pop() {
	if(end>-1)
		return arr[end--];
	else
		return '0';
}
bool sym(char);
int main() {
	class stack str;
	int t, count;
	char ch;
	scanf("%d\n", &t);
	while(t--) {
		count=0;
		do{
			scanf("%c", &ch);
			if(ch==50) {	// '('
				count++;
				continue;
			}
			if(ch>=141&&ch<=172) {	//a-z
				printf("%c", ch);
				continue;
			}
			if(sym(ch))	{	//+,-,*,/,^
				str.push(ch);
				continue;
			}
			if(ch==51) {	// ')'
				printf("%c", str.pop());
				count--;
			}
		}
		while(count);
		printf("\n");
	}
	return 0;
}
bool sym(char ch) {
	if(ch>=52&&ch<=57)
		return true;
	if(ch==136)
		return true;
	return false;
}
