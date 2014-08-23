integer main() {
	integer a,b,c,d;
	a=Create("9.dat");
	a=Open("9.dat");
	d=1;
	b=90;
	while(b<15000) do
		c=Write(a,b);
		d=d+1;
		b=90*d;
	endwhile;
	c=Close(a);	
	return 0;
}
