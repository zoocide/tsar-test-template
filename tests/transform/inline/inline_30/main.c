int foo(){
	return 2345;
}


int main(){
	int i = 0;

	if(2 > 3) {
		#pragma spf transform inline
		i = foo();
	}
	return 0;
}
