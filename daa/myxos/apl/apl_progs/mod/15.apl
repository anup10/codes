integer main() {
	integer a,b,c,d;
	a=Create("15.dat");
	a=Open("15.dat");
	d=1;
	b=150;
	while(b<15000) do
		c=Write(a,b);
		d=d+1;
		b=150*d;
	endwhile;
	c=Close(a);	
	return 0;
}
