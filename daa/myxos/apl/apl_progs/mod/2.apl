integer main() {
	integer a,b,c,d;
	a=Create("2.dat");
	a=Open("2.dat");
	d=1;
	b=20;
	while(b<1500) do
		c=Write(a,b);
		d=d+1;
		b=20*d;
	endwhile;
	c=Close(a);	
	return 0;
}
