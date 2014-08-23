integer main() {
	integer a,b,c,d;
	a=Create("16.dat");
	a=Open("16.dat");
	d=1;
	b=160;
	while(b<15000) do
		c=Write(a,b);
		d=d+1;
		b=160*d;
	endwhile;
	c=Close(a);	
	return 0;
}
