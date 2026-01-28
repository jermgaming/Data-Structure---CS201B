int factTR(unsigned int n,unsigned int a){
	if(n==0){
		return a;
	}
	return factTR(n-1,n*a);
}