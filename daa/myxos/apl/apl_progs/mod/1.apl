integer main() {
	integer a,b,c,d;
	a=Create("1.dat");
	a=Open("1.dat");
	d=1;
	b=10;
	while(b<1500) do
		c=Write(a,b);
		d=d+1;
		b=10*d;
	endwhile;
	c=Close(a);	
	return 0;
}
