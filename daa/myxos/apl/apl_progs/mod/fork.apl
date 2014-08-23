integer main() {
	integer a,b;
	b=0;
	while(b<7) do
		a=Fork();
		print(a);
		b=b+1;
	endwhile;
	return 0;
}
	
