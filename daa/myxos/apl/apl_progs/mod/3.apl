integer main() {
	integer a,b,c,d;
	a=Create("3.dat");
	a=Open("3.dat");
	d=1;
	b=30;
	while(b<15000) do
		c=Write(a,b);
		d=d+1;
		b=30*d;
	endwhile;
	c=Close(a);	
	return 0;
}