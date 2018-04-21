#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define nl '\n'

char stack[10001];
int stacki[10001];
int tp=-1;
int tpi=-1;

void push(char ch) {
	stack[++tp]=ch;
}
void pushi(int n) {
	stacki[++tp]=n;
} 

int empty() {return (tp==-1); } 
int emptyi() {return (tp==-1); } 
char pop() {return (empty()?-1:stack[tp--]);}
int popi() {return (emptyi()?'#':stacki[tp--]);}
char top() {return stack[tp];}
int topi() {return stacki[tpi];}

int prec(char ch) 
{
	switch(ch) 
	{
		case '/':
		case '*': return 2;
		case '+':
		case '-': return 1;
		default: return -1;
	};
}

int isOp(char ch) {
	return (ch >= '0' && ch <= '9');
}

int infixtopost(char* exp)
{
	int i,k;
	for(i=0, k=-1; exp[i]!='\0' ;i++) {
		if(isOp(exp[i])) {
			exp[++k] = exp[i];
		}
		else if(exp[i]=='(') {
			push(exp[i]);
		}
		else if(exp[i]==')') {
			while(( !empty() ) && ( top() != '(')) {
				exp[++k] = pop();
			}
			if( (!empty()) && (top() != '(') ) {
				printf("Invalid expression");
				return -1;
			}
		}
		else {
			while( (!empty()) && (prec(exp[i]) <= prec(top())) ) {
				exp[++k] = pop();
			}
			push(exp[i]);
		}
	}
	while(!empty()) {
		exp[++k] = pop();
	}
	exp[++k] = '\0';
	// printf("%s\n",exp);
	return 0;
}

int evaluate(char* exp) 
{
	int i;
	char ch;
	for(i = 0; exp[i]!='\0'; i++) {
		if(isdigit(exp[i])) {
			pushi(exp[i]-'0');
		}
		else 
		{
			int v1,v2;
			switch(exp[i])
			{
				case '+':v1 = popi(); v2 = popi(); pushi(v1+v2); break;
				case '-':v1 = popi(); v2 = popi(); pushi(v2-v1); break;
				case '*':v1 = popi(); v2 = popi(); pushi(v1*v2); break;
				case '/':v1 = popi(); v2 = popi(); pushi(v2/v1); break;
				default: break;
			};
		}
	}
	return popi();
}

void process(char* exp)
{
	int n = strlen(exp),j,i;
	for(i=0; exp[i]!='\0' ; i++) 
	{
		if(exp[i]=='(')
		{
			for(j=i;j<=n-1;j++) {
				exp[j]=exp[j+1];
			}
			// printf("%s\n",exp);
		}
	}
}

int main()
{
	char exp[101];
	scanf("%s",exp);
	infixtopost(exp);
	process(exp);
	printf("%s\n",exp);
	int res = evaluate(exp);
	printf("%d\n",res);
	return 0;
}