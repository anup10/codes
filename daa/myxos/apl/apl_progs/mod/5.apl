integer main() {
	integer a,b,c,d;
	a=Create("5.dat");
	a=Open("5.dat");
	d=1;
	b=50;
	while(b<15000) do
		c=Write(a,b);
		d=d+1;
		b=50*d;
	endwhile;
	c=Close(a);	
	return 0;
}
