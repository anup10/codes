integer main() {
	integer a,b,c,d;
	a=Create("10.dat");
	a=Open("10.dat");
	d=1;
	b=100;
	while(b<15000) do
		c=Write(a,b);
		d=d+1;
		b=100*d;
	endwhile;
	c=Close(a);	
	return 0;
}
