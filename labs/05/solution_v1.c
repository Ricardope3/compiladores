#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


char l;

bool E();
bool E_alpha();
bool T();
bool T_alpha();
bool T_alpha2();
bool T_alpha3();

void error(){
	printf("Parsing unsuccessful\n");
	exit(-1);
}


bool match(char t) {
    if (l == t) {
        l = getchar();
		return true;
    }
    else
		error();
        return false;
}


bool E(){
	if(E_alpha()){
		if(l == '+'){
			if(match('+') && E() ){
				//succesfull
				return true;
			}
			else{
				return false;
				error();
			}
		}
		return true;
	}
	else{
		error();
        return false;
	}
}


bool T(){
	if(l == '('){
		if(T_alpha3()){
			return true;
		}
		else{
			error();
			return false;
		}
	}
	else{
		if(T_alpha()){
			if(l == '*'){
				if(T_alpha2()){
					return true;
				}
				else{
					return false;
				}
			}
			return true;
		}
		else{
			return false;
		}
	}
	return false;
}


bool E_alpha(){
	if(T()){
		return true;
	}
	else{
		return false;
	}
}


bool T_alpha(){
	if(isdigit(l)){
        l = getchar();
		return true;
	}
	else{
		return false;
	}
}


bool T_alpha2(){
	if(match('*') && T()){
		return true;
	}
	else{
		return false;
	}
}


bool T_alpha3(){
	if(match('(') && E() && match(')')){
		return true;
	}
	else{
		return false;
	}
}


int main() {
    do {
        l = getchar();
	    E();

    } while (l != '\n' && l != EOF);

    if (l == '\n')
        printf("Everything is ok\n");
}
