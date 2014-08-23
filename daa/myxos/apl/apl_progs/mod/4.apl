integer main() {
	integer a,b,c,d;
	a=Create("4.dat");
	a=Open("4.dat");
	d=1;
	b=40;
	while(b<15000) do
		c=Write(a,b);
		d=d+1;
		b=40*d;
	endwhile;
	c=Close(a);	
	return 0;
}
